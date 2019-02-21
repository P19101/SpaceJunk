/*
 * @file systemInit.h
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief File containing function definitions to initialize the system to a default operational state after a reset event. 
 */
 
#ifndef SYSTEM_INIT_H
#define SYSTEM_INIT_H

#include "commonHeader.h"
#include "gpio.h"

/**
 * set all of the pins which should be configured as outputs after a reset event. There is
 * no similar function to set all pins as inputs, because input is the default state. If a specific
 * pin must change from output to input during the executable code stage, use the corresponding
 * GPIO function: set_GPIO_pin_input. The list of pins to set as inputs is determined by the four
 * corresponding macros in the pinUsage.h header file.
 * @param: None
 * @return: None
 */
void set_port_output_pins(void);

/**
 * enable pull resistor for all required input pins on all four GPIO ports. There is no similar
 * function to disable pull resistors on all pins selected, because disabled pull resistors
 * is the default state. If a specific pin should change from pull enabled to pull disabled
 * during executable code stage, use the corresponding GPIO function: disable_GPIO_pin_pull_resistor.
 * The list of pins which will have pull resistors enabled is determined by the four corresponding
 * macros in the pinUsage.h header file
 * @param: None
 * @return: None
 */
void enable_port_pull_resistors(void);

#endif
