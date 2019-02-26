/**
 * @file gpio_init.h
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief file with container functions to consolidate the initilization of the
 * 		gpio pins on the board. All of the settings for these functions are in
 * 		pinUsage.h
 */

#ifndef GPIO_INIT_H
#define GPIO_INIT_H

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
 * NOTE: ALL UNUSED PINS SHOULD BE SET AS OUTPUT PINS PER THE MANUAL.
 * @param: None
 * @return: None
 */
void enable_port_pull_resistors(void);

/**
 * Of the ports enabled to have a pull network resistor, choose which should have a pull up
 * resistor. Pull down is the default resistor for all enabled pull networks.
 * @param: None
 * @return: None
 */
void set_pull_up_resistors(void);
 
/**
 * Set all outputs which should be high from the start of code execution. This often includes certain comm
 * enabling pins or pins which are active low and should be disabled by default. To toggle the state of output
 * pins during executable code use the GPIO functions: set_GPIO_pin and clear_GPIO_pin. The list of pins which
 * will have their reset state as high is determined by the four corresponding macros in the pinUsage.h header file.
 * @param: None
 * @return: None
 */
void set_outputs_high(void);

/**
 * Set all GPIO pins to their desired reset functionality. All pins which are not selected will be set as GPIO outputs by
 * default. The pins operating under their primary, secondary or tertiary functionality should be listed in their corrisponding
 * macro in the pinUsage.h header file.
 * @param: None
 * @return: None
 */
void set_pin_functions(void);

/** 
 * Set all pins which should have their interrupts enabled. All pins not set will
 * have their interrupts disabled by default.
 * @param: None
 * @return: None
 */
void enable_pin_interrupts(void);

/**
 * For any pins which have their interrupts enabled, select which should have a
 * high-to-low transition as their interrupt condition. By default interrupts are
 * caused by low-to-high transitions.
 * @param: None
 * @return: None
 */
void set_interrupts_edges(void);

#end if