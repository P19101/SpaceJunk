/** 
 * @file application.h
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief application header file. This is the sudo main loop for the launch application
 * which will run durring normal mission operation. This file is seperated from main, so
 * that other builds for testing or other reasons are usable with the usage of the
 * precompiler.
 */
 
#ifndef APP_H
#define APP_H

#include <msp430.h> 
#include "systemInit.h"
#include "gpio.h"
#include "msp430fr5969.h"
#include "uart.h"
#include "USCITypeA.h"
#include <stdio.h>
#include <stdbool.h>
/**
 * This is the function called by main when the default build is made. This function
 * seperates main so that other builds can be called through main without having to change
 * the build files, with the use of the precompiler
 * @param: None
 * @return - uint8_t error: standard exit signals for a program which is probalby useless
 */
uint8_t application(void);

















#endif
