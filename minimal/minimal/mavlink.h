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
#define MAVLINK_MESSAGE_CRCS {50, 124, 137, 0, 237, 217, 104, 119, 0, 0, 0, 89, 0, 0, 0, 0, 0, 0, 0, 0, 214, 159, 220, 168, 24, 23, 170, 144, 67, 115, 39, 246, 185, 104, 237, 244, 222, 212, 9, 254, 230, 28, 28, 132, 221, 232, 11, 153, 41, 39, 78, 196, 0, 0, 15, 3, 0, 0, 0, 0, 0, 153, 183, 51, 59, 118, 148, 21, 0, 243, 124, 0, 0, 38, 20, 158, 152, 143, 0, 0, 0, 106, 49, 22, 143, 140, 5, 150, 0, 231, 183, 63, 54, 47, 0, 0, 0, 0, 0, 0, 175, 102, 158, 208, 56, 93, 138, 108, 32, 185, 84, 34, 174, 124, 237, 4, 76, 128, 56, 116, 134, 237, 203, 250, 87, 203, 220, 25, 226, 46, 29, 223, 85, 6, 229, 203, 1, 195, 109, 168, 181, 47, 72, 131, 127, 0, 103, 154, 178, 200, 134, 219, 208, 188, 84, 22, 19, 21, 134, 0, 78, 68, 189, 127, 154, 21, 21, 144, 1, 234, 73, 181, 22, 83, 167, 138, 234, 240, 47, 189, 52, 174, 229, 85, 159, 186, 72, 0, 0, 0, 0, 92, 36, 71, 98, 0, 0, 0, 0, 0, 134, 205, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 69, 101, 50, 202, 17, 162, 0, 0, 0, 0, 0, 0, 207, 0, 0, 0, 163, 105, 151, 35, 179, 0, 0, 0, 0, 0, 0, 90, 104, 85, 95, 130, 184, 81, 8, 204, 49, 170, 44, 83, 46, 0}
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
