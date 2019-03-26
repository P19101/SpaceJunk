/*
 * @file commonHeader.h
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief file for defines and includes which are universally helpful.
 */

#ifndef COMMON_HEADER_H
#define COMMON_HEADER_H

#include <stdint.h>
#include <msp430fr5969.h>

#define DEFAULT_SELECTION   0x0000 // use when setting any module to its default reset value. better than just having 0x0000 in the code randomly.
#define ON					0x0001 // use to turn pins on and stuff
#define ENABLE				0x0001 // use to enable pins and stuff
#define OFF					0x0000 // use to turn pins off and stuff
#define DISABLE				0x0000 // use to disable pins and stuff
#define LOW_BYTE            0x00FF // use when needing the low byte from a 16 bit number
#define HIGH_BYTE           0xFF00 // use when needing the high byte from a 16 bit number
#define HIGH_BYTE_SHIFT     8      // use to shift a high byte into the lower part of a variable for reading. 

// commond bit positions
#define BIT_0               0x0001
#define BIT_1               0x0002
#define BIT_2               0x0004
#define BIT_3               0x0008
#define BIT_4               0x0010
#define BIT_5               0x0020
#define BIT_6               0x0040
#define BIT_7               0x0080
#define BIT_8               0x0100
#define BIT_9               0x0200
#define BIT_10              0x0400
#define BIT_11              0x0800
#define BIT_12              0x1000
#define BIT_13              0x2000
#define BIT_14              0x4000
#define BIT_15              0x8000


#endif
