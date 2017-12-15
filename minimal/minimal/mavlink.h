#ifndef MAVLINK_H
#define MAVLINK_H

#include "../mavlink_types.h"

#ifndef MAVLINK_STX
#define MAVLINK_STX 254
#endif

#ifndef MAVLINK_ENDIAN
#define MAVLINK_ENDIAN MAVLINK_LITTLE_ENDIAN
#endif

#ifndef MAVLINK_ALIGNED_FIELDS
#define MAVLINK_ALIGNED_FIELDS 1
#endif

#ifndef MAVLINK_CRC_EXTRA
#define MAVLINK_CRC_EXTRA 1
#endif

#define MAVLINK_USE_CONVENIENCE_FUNCTIONS 1

#include "version.h"


//add by BigW
// MESSAGE LENGTHS AND CRCS
#ifndef MAVLINK_MESSAGE_LENGTHS

                                   //0~19
#define MAVLINK_MESSAGE_LENGTHS {  9,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
                                   0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 28,  0,  0, 28,  0,  0,  0,  0,  0,  0,\
                                   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
                                   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
                                   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
                                   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
                                   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
                                   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
                                   0,  0,  0, 28,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
                                   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
                                   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
                                   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
                                   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {    50,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
                                   0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 39,  0,  0,104,  0,  0,  0,  0,  0,  0,\
                                   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
                                   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
                                   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
                                   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
                                   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
                                   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
                                   0,  0,  0,127,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
                                   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
                                   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
                                   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
                                   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}
#endif

#ifndef MAVLINK_MESSAGE_INFO
#define MAVLINK_MESSAGE_INFO { \
    0, \
    "TEST_TYPES", \
    22, \
    {  { "u64", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_test_types_t, u64) }, \
         { "s64", NULL, MAVLINK_TYPE_INT64_T, 0, 8, offsetof(mavlink_test_types_t, s64) }, \
         { "d", NULL, MAVLINK_TYPE_DOUBLE, 0, 16, offsetof(mavlink_test_types_t, d) }, \
         { "u64_array", NULL, MAVLINK_TYPE_UINT64_T, 3, 24, offsetof(mavlink_test_types_t, u64_array) }, \
         { "s64_array", NULL, MAVLINK_TYPE_INT64_T, 3, 48, offsetof(mavlink_test_types_t, s64_array) }, \
         { "d_array", NULL, MAVLINK_TYPE_DOUBLE, 3, 72, offsetof(mavlink_test_types_t, d_array) }, \
         { "u32", "0x%08x", MAVLINK_TYPE_UINT32_T, 0, 96, offsetof(mavlink_test_types_t, u32) }, \
         { "s32", NULL, MAVLINK_TYPE_INT32_T, 0, 100, offsetof(mavlink_test_types_t, s32) }, \
         { "f", NULL, MAVLINK_TYPE_FLOAT, 0, 104, offsetof(mavlink_test_types_t, f) }, \
         { "u32_array", NULL, MAVLINK_TYPE_UINT32_T, 3, 108, offsetof(mavlink_test_types_t, u32_array) }, \
         { "s32_array", NULL, MAVLINK_TYPE_INT32_T, 3, 120, offsetof(mavlink_test_types_t, s32_array) }, \
         { "f_array", NULL, MAVLINK_TYPE_FLOAT, 3, 132, offsetof(mavlink_test_types_t, f_array) }, \
         { "u16", NULL, MAVLINK_TYPE_UINT16_T, 0, 144, offsetof(mavlink_test_types_t, u16) }, \
         { "s16", NULL, MAVLINK_TYPE_INT16_T, 0, 146, offsetof(mavlink_test_types_t, s16) }, \
         { "u16_array", NULL, MAVLINK_TYPE_UINT16_T, 3, 148, offsetof(mavlink_test_types_t, u16_array) }, \
         { "s16_array", NULL, MAVLINK_TYPE_INT16_T, 3, 154, offsetof(mavlink_test_types_t, s16_array) }, \
         { "c", NULL, MAVLINK_TYPE_CHAR, 0, 160, offsetof(mavlink_test_types_t, c) }, \
         { "s", NULL, MAVLINK_TYPE_CHAR, 10, 161, offsetof(mavlink_test_types_t, s) }, \
         { "u8", NULL, MAVLINK_TYPE_UINT8_T, 0, 171, offsetof(mavlink_test_types_t, u8) }, \
         { "s8", NULL, MAVLINK_TYPE_INT8_T, 0, 172, offsetof(mavlink_test_types_t, s8) }, \
         { "u8_array", NULL, MAVLINK_TYPE_UINT8_T, 3, 173, offsetof(mavlink_test_types_t, u8_array) }, \
         { "s8_array", NULL, MAVLINK_TYPE_INT8_T, 3, 176, offsetof(mavlink_test_types_t, s8_array) }, \
         } \
}
#endif
    
#endif // MAVLINK_H
