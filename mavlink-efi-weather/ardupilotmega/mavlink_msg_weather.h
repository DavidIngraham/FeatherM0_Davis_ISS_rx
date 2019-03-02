#pragma once
// MESSAGE WEATHER PACKING

#define MAVLINK_MSG_ID_WEATHER 11040

MAVPACKED(
typedef struct __mavlink_weather_t {
 int32_t raw_press; /*<  Barometric Pressure.*/
 uint16_t wind_dir; /*< [deg] Wind Direction. (Upwind Heading)*/
 uint8_t wind; /*< [m/s] Wind*/
 int8_t temperature; /*< [degC] Temperature.*/
 uint8_t relative_humidity; /*< [%] Relative Humidity.*/
 uint8_t rain_rate; /*< [mm/hr] Rain rate*/
}) mavlink_weather_t;

#define MAVLINK_MSG_ID_WEATHER_LEN 10
#define MAVLINK_MSG_ID_WEATHER_MIN_LEN 10
#define MAVLINK_MSG_ID_11040_LEN 10
#define MAVLINK_MSG_ID_11040_MIN_LEN 10

#define MAVLINK_MSG_ID_WEATHER_CRC 73
#define MAVLINK_MSG_ID_11040_CRC 73



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WEATHER { \
    11040, \
    "WEATHER", \
    6, \
    {  { "wind", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_weather_t, wind) }, \
         { "wind_dir", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_weather_t, wind_dir) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT8_T, 0, 7, offsetof(mavlink_weather_t, temperature) }, \
         { "raw_press", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_weather_t, raw_press) }, \
         { "relative_humidity", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_weather_t, relative_humidity) }, \
         { "rain_rate", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_weather_t, rain_rate) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WEATHER { \
    "WEATHER", \
    6, \
    {  { "wind", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_weather_t, wind) }, \
         { "wind_dir", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_weather_t, wind_dir) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT8_T, 0, 7, offsetof(mavlink_weather_t, temperature) }, \
         { "raw_press", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_weather_t, raw_press) }, \
         { "relative_humidity", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_weather_t, relative_humidity) }, \
         { "rain_rate", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_weather_t, rain_rate) }, \
         } \
}
#endif

/**
 * @brief Pack a weather message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param wind [m/s] Wind
 * @param wind_dir [deg] Wind Direction. (Upwind Heading)
 * @param temperature [degC] Temperature.
 * @param raw_press  Barometric Pressure.
 * @param relative_humidity [%] Relative Humidity.
 * @param rain_rate [mm/hr] Rain rate
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_weather_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t wind, uint16_t wind_dir, int8_t temperature, int32_t raw_press, uint8_t relative_humidity, uint8_t rain_rate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WEATHER_LEN];
    _mav_put_int32_t(buf, 0, raw_press);
    _mav_put_uint16_t(buf, 4, wind_dir);
    _mav_put_uint8_t(buf, 6, wind);
    _mav_put_int8_t(buf, 7, temperature);
    _mav_put_uint8_t(buf, 8, relative_humidity);
    _mav_put_uint8_t(buf, 9, rain_rate);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WEATHER_LEN);
#else
    mavlink_weather_t packet;
    packet.raw_press = raw_press;
    packet.wind_dir = wind_dir;
    packet.wind = wind;
    packet.temperature = temperature;
    packet.relative_humidity = relative_humidity;
    packet.rain_rate = rain_rate;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WEATHER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WEATHER;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WEATHER_MIN_LEN, MAVLINK_MSG_ID_WEATHER_LEN, MAVLINK_MSG_ID_WEATHER_CRC);
}

/**
 * @brief Pack a weather message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wind [m/s] Wind
 * @param wind_dir [deg] Wind Direction. (Upwind Heading)
 * @param temperature [degC] Temperature.
 * @param raw_press  Barometric Pressure.
 * @param relative_humidity [%] Relative Humidity.
 * @param rain_rate [mm/hr] Rain rate
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_weather_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t wind,uint16_t wind_dir,int8_t temperature,int32_t raw_press,uint8_t relative_humidity,uint8_t rain_rate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WEATHER_LEN];
    _mav_put_int32_t(buf, 0, raw_press);
    _mav_put_uint16_t(buf, 4, wind_dir);
    _mav_put_uint8_t(buf, 6, wind);
    _mav_put_int8_t(buf, 7, temperature);
    _mav_put_uint8_t(buf, 8, relative_humidity);
    _mav_put_uint8_t(buf, 9, rain_rate);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WEATHER_LEN);
#else
    mavlink_weather_t packet;
    packet.raw_press = raw_press;
    packet.wind_dir = wind_dir;
    packet.wind = wind;
    packet.temperature = temperature;
    packet.relative_humidity = relative_humidity;
    packet.rain_rate = rain_rate;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WEATHER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WEATHER;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WEATHER_MIN_LEN, MAVLINK_MSG_ID_WEATHER_LEN, MAVLINK_MSG_ID_WEATHER_CRC);
}

/**
 * @brief Encode a weather struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param weather C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_weather_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_weather_t* weather)
{
    return mavlink_msg_weather_pack(system_id, component_id, msg, weather->wind, weather->wind_dir, weather->temperature, weather->raw_press, weather->relative_humidity, weather->rain_rate);
}

/**
 * @brief Encode a weather struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param weather C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_weather_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_weather_t* weather)
{
    return mavlink_msg_weather_pack_chan(system_id, component_id, chan, msg, weather->wind, weather->wind_dir, weather->temperature, weather->raw_press, weather->relative_humidity, weather->rain_rate);
}

/**
 * @brief Send a weather message
 * @param chan MAVLink channel to send the message
 *
 * @param wind [m/s] Wind
 * @param wind_dir [deg] Wind Direction. (Upwind Heading)
 * @param temperature [degC] Temperature.
 * @param raw_press  Barometric Pressure.
 * @param relative_humidity [%] Relative Humidity.
 * @param rain_rate [mm/hr] Rain rate
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_weather_send(mavlink_channel_t chan, uint8_t wind, uint16_t wind_dir, int8_t temperature, int32_t raw_press, uint8_t relative_humidity, uint8_t rain_rate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WEATHER_LEN];
    _mav_put_int32_t(buf, 0, raw_press);
    _mav_put_uint16_t(buf, 4, wind_dir);
    _mav_put_uint8_t(buf, 6, wind);
    _mav_put_int8_t(buf, 7, temperature);
    _mav_put_uint8_t(buf, 8, relative_humidity);
    _mav_put_uint8_t(buf, 9, rain_rate);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WEATHER, buf, MAVLINK_MSG_ID_WEATHER_MIN_LEN, MAVLINK_MSG_ID_WEATHER_LEN, MAVLINK_MSG_ID_WEATHER_CRC);
#else
    mavlink_weather_t packet;
    packet.raw_press = raw_press;
    packet.wind_dir = wind_dir;
    packet.wind = wind;
    packet.temperature = temperature;
    packet.relative_humidity = relative_humidity;
    packet.rain_rate = rain_rate;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WEATHER, (const char *)&packet, MAVLINK_MSG_ID_WEATHER_MIN_LEN, MAVLINK_MSG_ID_WEATHER_LEN, MAVLINK_MSG_ID_WEATHER_CRC);
#endif
}

/**
 * @brief Send a weather message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_weather_send_struct(mavlink_channel_t chan, const mavlink_weather_t* weather)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_weather_send(chan, weather->wind, weather->wind_dir, weather->temperature, weather->raw_press, weather->relative_humidity, weather->rain_rate);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WEATHER, (const char *)weather, MAVLINK_MSG_ID_WEATHER_MIN_LEN, MAVLINK_MSG_ID_WEATHER_LEN, MAVLINK_MSG_ID_WEATHER_CRC);
#endif
}

#if MAVLINK_MSG_ID_WEATHER_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_weather_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t wind, uint16_t wind_dir, int8_t temperature, int32_t raw_press, uint8_t relative_humidity, uint8_t rain_rate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, raw_press);
    _mav_put_uint16_t(buf, 4, wind_dir);
    _mav_put_uint8_t(buf, 6, wind);
    _mav_put_int8_t(buf, 7, temperature);
    _mav_put_uint8_t(buf, 8, relative_humidity);
    _mav_put_uint8_t(buf, 9, rain_rate);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WEATHER, buf, MAVLINK_MSG_ID_WEATHER_MIN_LEN, MAVLINK_MSG_ID_WEATHER_LEN, MAVLINK_MSG_ID_WEATHER_CRC);
#else
    mavlink_weather_t *packet = (mavlink_weather_t *)msgbuf;
    packet->raw_press = raw_press;
    packet->wind_dir = wind_dir;
    packet->wind = wind;
    packet->temperature = temperature;
    packet->relative_humidity = relative_humidity;
    packet->rain_rate = rain_rate;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WEATHER, (const char *)packet, MAVLINK_MSG_ID_WEATHER_MIN_LEN, MAVLINK_MSG_ID_WEATHER_LEN, MAVLINK_MSG_ID_WEATHER_CRC);
#endif
}
#endif

#endif

// MESSAGE WEATHER UNPACKING


/**
 * @brief Get field wind from weather message
 *
 * @return [m/s] Wind
 */
static inline uint8_t mavlink_msg_weather_get_wind(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field wind_dir from weather message
 *
 * @return [deg] Wind Direction. (Upwind Heading)
 */
static inline uint16_t mavlink_msg_weather_get_wind_dir(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field temperature from weather message
 *
 * @return [degC] Temperature.
 */
static inline int8_t mavlink_msg_weather_get_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  7);
}

/**
 * @brief Get field raw_press from weather message
 *
 * @return  Barometric Pressure.
 */
static inline int32_t mavlink_msg_weather_get_raw_press(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field relative_humidity from weather message
 *
 * @return [%] Relative Humidity.
 */
static inline uint8_t mavlink_msg_weather_get_relative_humidity(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field rain_rate from weather message
 *
 * @return [mm/hr] Rain rate
 */
static inline uint8_t mavlink_msg_weather_get_rain_rate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Decode a weather message into a struct
 *
 * @param msg The message to decode
 * @param weather C-struct to decode the message contents into
 */
static inline void mavlink_msg_weather_decode(const mavlink_message_t* msg, mavlink_weather_t* weather)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    weather->raw_press = mavlink_msg_weather_get_raw_press(msg);
    weather->wind_dir = mavlink_msg_weather_get_wind_dir(msg);
    weather->wind = mavlink_msg_weather_get_wind(msg);
    weather->temperature = mavlink_msg_weather_get_temperature(msg);
    weather->relative_humidity = mavlink_msg_weather_get_relative_humidity(msg);
    weather->rain_rate = mavlink_msg_weather_get_rain_rate(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WEATHER_LEN? msg->len : MAVLINK_MSG_ID_WEATHER_LEN;
        memset(weather, 0, MAVLINK_MSG_ID_WEATHER_LEN);
    memcpy(weather, _MAV_PAYLOAD(msg), len);
#endif
}
