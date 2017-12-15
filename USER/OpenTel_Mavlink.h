
#ifndef __OPENTEL_MAVLINK_H
#define __OPENTEL_MAVLINK_H


#include "../minimal/minimal/minimal.h"
#include "define.h"

//#include <mavlink.h>

//#define MAVLINK_PRIMARY_XML_IDX 0

//#ifndef MAVLINK_STX
//#define MAVLINK_STX 254
//#endif

//#ifndef MAVLINK_ENDIAN
//#define MAVLINK_ENDIAN MAVLINK_LITTLE_ENDIAN
//#endif

//#ifndef MAVLINK_ALIGNED_FIELDS
//#define MAVLINK_ALIGNED_FIELDS 1
//#endif

//#ifndef MAVLINK_CRC_EXTRA
//#define MAVLINK_CRC_EXTRA 1
//#endif

//#ifndef MAVLINK_COMMAND_24BIT
//#define MAVLINK_COMMAND_24BIT 0
//#endif













void mavlink_send_message(mavlink_channel_t chan, enum ap_message id, uint16_t packet_drops);
void update(void);

#endif /*__OPENTEL_MAVLINK_H*/   


