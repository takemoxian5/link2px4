/** @file
 *	@brief MAVLink comm protocol testsuite generated from minimal.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#include "testsuite.h"
#include "minimal.h"
 void mavlink_test_servo_output_raw(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_SERVO_OUTPUT_RAW >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_servo_output_raw_t packet_in = {
        963497464,1743,1547,1651,1755,1859,1963,1067,1171,15
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
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_SERVO_OUTPUT_RAW_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_SERVO_OUTPUT_RAW_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_servo_output_raw_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_servo_output_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_servo_output_raw_pack(system_id, component_id, &msg , packet1.time_usec , packet1.port , packet1.servo1_raw , packet1.servo2_raw , packet1.servo3_raw , packet1.servo4_raw , packet1.servo5_raw , packet1.servo6_raw , packet1.servo7_raw , packet1.servo8_raw );
    mavlink_msg_servo_output_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_servo_output_raw_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.port , packet1.servo1_raw , packet1.servo2_raw , packet1.servo3_raw , packet1.servo4_raw , packet1.servo5_raw , packet1.servo6_raw , packet1.servo7_raw , packet1.servo8_raw );
    mavlink_msg_servo_output_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_servo_output_raw_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_servo_output_raw_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.port , packet1.servo1_raw , packet1.servo2_raw , packet1.servo3_raw , packet1.servo4_raw , packet1.servo5_raw , packet1.servo6_raw , packet1.servo7_raw , packet1.servo8_raw );
    mavlink_msg_servo_output_raw_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

//static void mavlink_test_minimal(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_heartbeat(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
  uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
  uint16_t i;
	
	mavlink_heartbeat_t packet_in = { 
		128,//963497464,
		17,
		84,
		151,
		218,
		2
  };	
	mavlink_heartbeat_t packet1, packet2;
	
  memset(&packet1, 0, sizeof(packet1));
  packet1.custom_mode = packet_in.custom_mode;
  packet1.type = packet_in.type;
  packet1.autopilot = packet_in.autopilot;
  packet1.base_mode = packet_in.base_mode;
  packet1.system_status = packet_in.system_status;
  packet1.mavlink_version = packet_in.mavlink_version;

  memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_heartbeat_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_heartbeat_decode(&msg, &packet2);
  MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

  memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_heartbeat_pack(system_id, component_id, &msg , packet1.type , packet1.autopilot , packet1.base_mode , packet1.custom_mode , packet1.system_status );
	mavlink_msg_heartbeat_decode(&msg, &packet2);
  MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

  memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_heartbeat_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.type , packet1.autopilot , packet1.base_mode , packet1.custom_mode , packet1.system_status );
	mavlink_msg_heartbeat_decode(&msg, &packet2);
  MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

  #ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS	
  memset(&packet2, 0, sizeof(packet2));
  mavlink_msg_to_send_buffer(buffer, &msg);
  for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
   	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
  } 
	mavlink_msg_heartbeat_decode(last_msg, &packet2);
  MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
  			
  memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_heartbeat_send(MAVLINK_COMM_1 , packet1.type , packet1.autopilot , packet1.base_mode , packet1.custom_mode , packet1.system_status );
	mavlink_msg_heartbeat_decode(last_msg, &packet2);
  MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
  #endif				
}

 void mavlink_test_minimal(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_heartbeat(system_id, component_id, last_msg);
}




