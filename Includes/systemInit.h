/*
 * @file systemInit.h
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief File containing function definitions to initialize the system to a default
 * 		operational state after a reset event. 
 */
 
#ifndef SYSTEM_INIT_H
#define SYSTEM_INIT_H

#include "gpioInit.h"
#include "pinUsage.h"
#include "adc12Bit.h"
#include "clockSourcesInit.h"
#include "USCITypeA.H"

/**
 * Master function which will call all corrisponding configuration functions.
 * Ideally this is the only function which should be directly called in the
 * executable code after a reset event. 
 * @param: None
 * @return: None
 */
void configure_sys(void);

/**
 * Function to call all setup functions for the GPIO pins.
 * @param: None
 * @return: None
 */
void configure_GIPO(void);

/**
 * Function to setup all defaults for the ADC
 * NOTE: Does not enable or power the ADC by default to save power until it is needed.
 * @param: None
 * @return: None
 */
void configure_ADC(void);

/** 
 * Calls all default configuration functions for the system clock sources. 
 * @param: None
 * @return: None
 */
void configure_clock_sources(void);

/**
 * Call all setup for the default UART comms. Configues UART 1 for 19200 baud for main comms
 * @param: None
 * @return: None
 */
void configure_UART(void);
#endif





