

/** @file
 *  @brief MAVLink comm protocol testsuite generated from minimal.xml
 *  @see http://qgroundcontrol.org/mavlink/
 */
#ifndef MINIMAL_TESTSUITE_H
#define MINIMAL_TESTSUITE_H

#include "minimal.h"
//void mavlink_test_servo_output_raw(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg);
// void mavlink_test_minimal(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg);



void mavlink_test_servo_output_raw(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
    if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_SERVO_OUTPUT_RAW >= 256)
    {
        return;
    }
#endif
    mavlink_message_t msg;
    uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
    uint16_t i;
    mavlink_servo_output_raw_t packet_in =
    {
        963497464,17443,17547,17651,17755,17859,17963,18067,18171,65,18327,18431,18535,18639,18743,18847,18951,19055
    };
    mavlink_servo_output_raw_t packet1, packet2;
    memset(&packet1, 0, sizeof(packet1));
    packet1.time_usec = packet_in.time_usec;
    packet1.servo1_raw = packet_in.servo1_raw;
    packet1.servo2_raw = packet_in.servo2_raw;
    packet1.servo3_raw = packet_in.servo3_raw;
    packet1.servo4_raw = packet_in.servo4_raw;
    packet1.servo5_raw = packet_in.servo5_raw;
    packet1.servo6_raw = packet_in.servo6_raw;
    packet1.servo7_raw = packet_in.servo7_raw;
    packet1.servo8_raw = packet_in.servo8_raw;
    packet1.port = packet_in.port;
    packet1.servo9_raw = packet_in.servo9_raw;
    packet1.servo10_raw = packet_in.servo10_raw;
    packet1.servo11_raw = packet_in.servo11_raw;
    packet1.servo12_raw = packet_in.servo12_raw;
    packet1.servo13_raw = packet_in.servo13_raw;
    packet1.servo14_raw = packet_in.servo14_raw;
    packet1.servo15_raw = packet_in.servo15_raw;
    packet1.servo16_raw = packet_in.servo16_raw;


#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1)
    {
        // cope with extensions
        memset(MAVLINK_MSG_ID_SERVO_OUTPUT_RAW_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_SERVO_OUTPUT_RAW_MIN_LEN);
    }
#endif
    memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_servo_output_raw_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_servo_output_raw_decode(&msg, &packet2);
    MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

    memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_servo_output_raw_pack(system_id, component_id, &msg, packet1.time_usec, packet1.port, packet1.servo1_raw, packet1.servo2_raw, packet1.servo3_raw, packet1.servo4_raw, packet1.servo5_raw, packet1.servo6_raw, packet1.servo7_raw, packet1.servo8_raw, packet1.servo9_raw, packet1.servo10_raw, packet1.servo11_raw, packet1.servo12_raw, packet1.servo13_raw, packet1.servo14_raw, packet1.servo15_raw, packet1.servo16_raw );
    mavlink_msg_servo_output_raw_decode(&msg, &packet2);
    MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

    memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_servo_output_raw_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg, packet1.time_usec, packet1.port, packet1.servo1_raw, packet1.servo2_raw, packet1.servo3_raw, packet1.servo4_raw, packet1.servo5_raw, packet1.servo6_raw, packet1.servo7_raw, packet1.servo8_raw, packet1.servo9_raw, packet1.servo10_raw, packet1.servo11_raw, packet1.servo12_raw, packet1.servo13_raw, packet1.servo14_raw, packet1.servo15_raw, packet1.servo16_raw );
    mavlink_msg_servo_output_raw_decode(&msg, &packet2);
    MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

    memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_to_send_buffer(buffer, &msg);
    for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++)
    {
        comm_send_ch(MAVLINK_COMM_0, buffer[i]);
    }
    mavlink_msg_servo_output_raw_decode(last_msg, &packet2);
    MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

    memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_servo_output_raw_send(MAVLINK_COMM_1, packet1.time_usec, packet1.port, packet1.servo1_raw, packet1.servo2_raw, packet1.servo3_raw, packet1.servo4_raw, packet1.servo5_raw, packet1.servo6_raw, packet1.servo7_raw, packet1.servo8_raw, packet1.servo9_raw, packet1.servo10_raw, packet1.servo11_raw, packet1.servo12_raw, packet1.servo13_raw, packet1.servo14_raw, packet1.servo15_raw, packet1.servo16_raw );
    mavlink_msg_servo_output_raw_decode(last_msg, &packet2);
    MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}


//static void mavlink_test_minimal(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_heartbeat(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_message_t msg;
    uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
    uint16_t i;

    mavlink_heartbeat_t packet_in =
    {
        128,//963497464,
        17,
        84,
        151,
        218,
        2
    };
    mavlink_heartbeat_t packet1, packet2;
//Start G201712181289 ChenYang  $  初始化 和填充packet1
    memset(&packet1, 0, sizeof(packet1));
    packet1.custom_mode = packet_in.custom_mode;
    packet1.type = packet_in.type;
    packet1.autopilot = packet_in.autopilot;
    packet1.base_mode = packet_in.base_mode;
    packet1.system_status = packet_in.system_status;
    packet1.mavlink_version = packet_in.mavlink_version;
//End G201712181289 ChenYang

//    memset(&packet2, 0, sizeof(packet2));  									 //初始化packet2
//    mavlink_msg_heartbeat_encode(system_id, component_id, &msg, &packet1);   //将packet1 信息填充到msg中
//    mavlink_msg_heartbeat_decode(&msg, &packet2);                            //msg中 信息填充到packet2
//    MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);        //？？空函数，方便平台移植和扩展

//    memset(&packet2, 0, sizeof(packet2));
//    mavlink_msg_heartbeat_pack(system_id, component_id, &msg, packet1.type, packet1.autopilot, packet1.base_mode, packet1.custom_mode, packet1.system_status );
//    mavlink_msg_heartbeat_decode(&msg, &packet2);
//    MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

    memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_heartbeat_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg, packet1.type, packet1.autopilot, packet1.base_mode, packet1.custom_mode, packet1.system_status );

//    mavlink_msg_heartbeat_decode(&msg, &packet2);
//    MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS
    memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_to_send_buffer(buffer, &msg);
    for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++)
    {
        comm_send_ch(MAVLINK_COMM_0, buffer[i]);
    }
    mavlink_msg_heartbeat_decode(last_msg, &packet2);
    MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

    memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_heartbeat_send(MAVLINK_COMM_1, packet1.type, packet1.autopilot, packet1.base_mode, packet1.custom_mode, packet1.system_status );
    mavlink_msg_heartbeat_decode(last_msg, &packet2);
    MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
#endif
}

void mavlink_test_minimal(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_heartbeat(system_id, component_id, last_msg);
}





#endif // MINIMAL_TESTSUITE_H

