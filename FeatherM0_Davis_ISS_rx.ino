

#include <SPI.h>
//#include <EEPROM.h>

#include <Wire.h>

#include <stdint.h>

#include "DavisRFM69.h"
#include "PacketFifo.h"
#include "mavlink-efi-weather/ardupilotmega/mavlink.h"

#define LED 13
#define SERIAL_BAUD 19200

DavisRFM69 radio(8, 3, true, 3);

// id, type, active
Station stations[1] = {
  { .id = 0,
    .type =  STYPE_VUE,
    .active = true}
};

struct station_status_t{
  int rssi;
  int battery;
  int windvel;
  int winddir;
  int temperature;
  int rel_humidity;
  int rain_rate;
} station_status;

void setup() {
  Serial.begin(SERIAL_BAUD);
  delay(1000);
  
  pinMode(LED, OUTPUT); 
  digitalWrite(LED, LOW);
  
  radio.setStations(stations, 1);
  radio.initialize(FREQ_BAND_US);
  //radio.setBandwidth(RF69_DAVIS_BW_NARROW);
  radio.setBandwidth(RF69_DAVIS_BW_WIDE);
}

void loop() {

  if (radio.fifo.hasElements()) {
    decode_packet(radio.fifo.dequeue());
  }

  if (radio.mode == SM_RECEIVING) {
    digitalWrite(LED, HIGH);
  } else if (radio.mode == SM_SEARCHING){
    Blink(LED, 15);
    Blink(LED, 15);
    Blink(LED, 15);
    delay(100);
  }else{
    digitalWrite(LED, LOW);
  }

  radio.loop();
    
}

void Blink(byte PIN, int DELAY_MS)
{
  pinMode(PIN, OUTPUT);
  digitalWrite(PIN,HIGH);
  delay(DELAY_MS);
  digitalWrite(PIN,LOW);
}



void decode_packet(RadioData* rd) {
  // for more about the protocol see:
  // https://github.com/dekay/DavisRFM69/wiki/Message-Protocol
  int val;
  byte* packet = rd->packet;

  station_status.rssi = -rd->rssi;

  byte id = radio.DATA[0] & 7;
  int stIx = radio.findStation(id);

  // wind data is present in every packet, windd == 0 (packet[2] == 0) means there's no anemometer
  if (packet[2] != 0) {
    if (stations[stIx].type == STYPE_VUE) {
      val = (packet[2] << 1) | (packet[4] & 2) >> 1;
      val = round(val * 360 / 512);
    } else {
      val = 9 + round((packet[2] - 1) * 342.0 / 255.0);
    }
  } else {
    val = 0;
  }
  station_status.windvel = round(packet[1]*0.44704);
  station_status.winddir = val;

  switch (packet[0] >> 4) {

    case VP2P_RAINSECS:
      // light rain:  byte4[5:4] as value[9:8] and byte3[7:0] as value[7:0] - 10 bits total
      // strong rain: byte4[5:4] as value[5:4] and byte3[7:4] as value[3:0] - 6 bits total
      val = (packet[4] & 0x30) << 4 | packet[3];
      if (val == 0x3ff) {
        station_status.rain_rate = -1;
      } else {
        if ((packet[4] & 0x40) == 0) val >>= 4; // packet[4] bit 6: strong == 0, light == 1
        station_status.rain_rate = val;
      }
      break;

    case VP2P_TEMP:
      val = ((int16_t)((packet[3]<<8) | packet[4])) / 16;
      station_status.temperature = val;
      break;

    case VP2P_HUMIDITY:
      val = ((packet[4] >> 4) << 8 | packet[3]) / 10; // 0 -> no sensor
      station_status.rel_humidity = val;
      break;

    case VUEP_VCAP:           
      val = (packet[3] << 2) | (packet[4] & 0xc0) >> 6;    
      station_status.battery = val/100;
      break;
  }
}

void printHex(volatile byte* packet, byte len) {
  for (byte i = 0; i < len; i++) {
    if (!(packet[i] & 0xf0)) Serial.print('0');
    Serial.print(packet[i], HEX);
    if (i < len - 1) Serial.print('-');
  }
}
