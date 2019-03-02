// MESSAGE WEATHER support class

#pragma once

namespace mavlink {
namespace ardupilotmega {
namespace msg {

/**
 * @brief WEATHER message
 *
 * Weather Station Status Report. Can originate from aircraft or GCS (Distinguish using SYSIDs)
 */
struct WEATHER : mavlink::Message {
    static constexpr msgid_t MSG_ID = 11040;
    static constexpr size_t LENGTH = 10;
    static constexpr size_t MIN_LENGTH = 10;
    static constexpr uint8_t CRC_EXTRA = 73;
    static constexpr auto NAME = "WEATHER";


    uint8_t wind; /*< [m/s] Wind */
    uint16_t wind_dir; /*< [deg] Wind Direction. (Upwind Heading) */
    int8_t temperature; /*< [degC] Temperature. */
    int32_t raw_press; /*<  Barometric Pressure. */
    uint8_t relative_humidity; /*< [%] Relative Humidity. */
    uint8_t rain_rate; /*< [mm/hr] Rain rate */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  wind: " << +wind << std::endl;
        ss << "  wind_dir: " << wind_dir << std::endl;
        ss << "  temperature: " << +temperature << std::endl;
        ss << "  raw_press: " << raw_press << std::endl;
        ss << "  relative_humidity: " << +relative_humidity << std::endl;
        ss << "  rain_rate: " << +rain_rate << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << raw_press;                     // offset: 0
        map << wind_dir;                      // offset: 4
        map << wind;                          // offset: 6
        map << temperature;                   // offset: 7
        map << relative_humidity;             // offset: 8
        map << rain_rate;                     // offset: 9
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> raw_press;                     // offset: 0
        map >> wind_dir;                      // offset: 4
        map >> wind;                          // offset: 6
        map >> temperature;                   // offset: 7
        map >> relative_humidity;             // offset: 8
        map >> rain_rate;                     // offset: 9
    }
};

} // namespace msg
} // namespace ardupilotmega
} // namespace mavlink
