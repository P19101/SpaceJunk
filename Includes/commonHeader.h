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


#endif
