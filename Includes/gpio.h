/*
 * @file gpio.h
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief File containing function definitions for programming the GPIO ports
 */

#ifndef GPIO_H
#define GPIO_H

#include "commonHeader.h"

typedef enum pinNumbers{
    PIN_0 = 0x01,
    PIN_1 = 0x02,
    PIN_2 = 0x04,
    PIN_3 = 0x08,
    PIN_4 = 0x10,
    PIN_5 = 0x20,
    PIN_6 = 0x40,
    PIN_7 = 0x80
}GPIOPins;

typedef enum portSelection{
    PORT_1,
    PORT_2,
    PORT_3,
    PORT_4,
	PORT_J
}GPIOPorts;

typedef enum function{
	DEFAULT_GPIO,
	PRIMARY_MOD,
	SECONDARY_MOD,
	TERTIARY_MOD
}GPIOfunctionSelect;

typedef enum interruptEdge{
	LOW_TO_HIGH,
	HIGH_TO_LOW
}GPIOInterruptEdge;

typedef enum pullResistorDirection{
    PULL_DOWN = 0x00,
    PULL_UP = 0x01
}GPIOPullResistoredDirection;

/**
 * Read a digital pin for a selected port which is set as an input and return its value.
 * @param - uint8_t port: the port number for which the pin should be read.
 * @param - uint8_t pin: the pin number to read in the chosen port.
 * @return - uint8_t pinValue: the input value of the selected pin.
 */
uint8_t read_GPIO_input_pin(uint8_t port, uint8_t pin);

/**
 * Read a digital pin for a selected port which is set as an output and return its value.
 * @param - uint8_t port: the port number for which the pin should be read.
 * @param - uint8_t pin: the pin number to read in the chosen port.
 * @return - uint8_t pinValue: the output value of the selected pin.
 */
uint8_t read_GPIO_output_pin(uint8_t port, uint8_t pin);

/**
 * Read the direction of the resistor if the pin is configured as an input.
 * @param - uint8_t port: the port number for which the pin should be read.
 * @param - uint8_t pin: the pin number to read in the chosen port.
 * @return - uint8_t resistorDirection: the direction of the pull resistor for the input pin
 *      0 - the resistor is configured as a pull down connection
 *      1 - the resistor is configured as a pull up connection
 */
uint8_t read_GPIO_resistor_pull_direction(uint8_t port, uint8_t pin);

/**
 * Set the direction of the pull resistor as either a pull up or pull down resistor
 * The use of this function is determined by if the pull resistor is enabled or not.
 * Enable with the enable_GPIO_pin_pull_resistor function.
 * @param - uint8_t port: the port number for which the pin should be set.
 * @param - uint8_t pin: the pin number to set in the chosen port.
 * @param - uint8_t pullDirection: the pull direction of the resistor.
 *      0 - PULL DOWN
 *      1 - PULL UP
 * @return: None
 */
void set_GPIO_resistor_pull_direction(uint8_t port, uint8_t pin, uint8_t pullDirection);

/**
 * Set a pin on the selected port.
 * @param - uint8_t port: the port number for which the pin should be set.
 * @param - uint8_t pin: the pin number to set in the chosen port.
 * @return: None
 */
void set_GPIO_pin(uint8_t port, uint8_t pin);

/**
 * Clear a pin on the selected port.
 * @param - uint8_t port: the port number for which the pin should be clear.
 * @param - uint8_t pin: the pin number to clear in the chosen port.
 * @return: None
 */
void clear_GPIO_pin(uint8_t port, uint8_t pin);

/**
 * Set the direction of the pin for the selected port as an output
 * @param - uint8_t port: the port number for which pin should have its direction set.
 * @param - uint8_t pin: the pin number to set the direction of in the chosen port.
 * @return: None
 */
void set_GPIO_pin_output(uint8_t port, uint8_t pin);

/** 
 * Set the direction of the pin for the selected port as an input
 * @param - uint8_t port: the port number for which pin should have its direction set.
 * @param - uint8_t pin: the pin number to set the direction of in the chosen port.
 * @return: None
 */
void set_GPIO_pin_input(uint8_t port, uint8_t pin);

/**
 * Enable pull resistors for the selected GPIO pin. The direction is set by the
 * set_GPIO_resistor_pull_direction function.
 * @param - uint8_t port: the port number for which pin should have its direction set.
 * @param - uint8_t pin: the pin number to set the direction of in the chosen port.
 * @return: None
 */
void enable_GPIO_pin_pull_resistor(uint8_t port , uint8_t pin);

/**
 * Disable the pull resistor for the selected GPIO pin.
 * @param - uint8_t port: the port number for which pin should have its direction set.
 * @param - uint8_t pin: the pin number to set the direction of in the chosen port.
 * @return: None
 */
void disable_GPIO_pin_pull_resistor(uint8_t port , uint8_t pin);

/**
 * Chose the function mode for the selected pin on the selected port.
 * @param - uint8_t port: the port number for which pin should have its direction set.
 * @param - uint8_t pin: the pin number to set the direction of in the chosen port.
 * @param - uint8_t function: the function to select for the pin. 
 * @return: None
 */
void choose_GPIO_function(uint8_t port, uint8_t pin, uint8_t function);

/**
 * Chose the edge for an interrupt on the selected pin for the chosen port
 * @param - uint8_t port: the port number for which pin should have its direction set.
 * @param - uint8_t pin: the pin number to set the direction of in the chosen port.
 * @param - uint8_t edge: the function to select for the pin. 
 * @return: None
 */
void choose_interrupt_edge(uint8_t port, uint8_t pin, uint8_t edge);

/**
 * Enable interrupts for the chosen pin 
 * @param - uint8_t port: the port number for which pin should have its direction set.
 * @param - uint8_t pin: the pin number to set the direction of in the chosen port.
 * @return: None
 */
void enable_GPIO_interrupt(uint8_t port, uint8_t pin);

/**
 * Disable interrupts for the chosen pin
 * @param - uint8_t port: the port number for which pin should have its direction set.
 * @param - uint8_t pin: the pin number to set the direction of in the chosen port.
 * @return: None
 */
void disable_GPIO_interrupt(uint8_t port, uint8_t pin);

/**
 * Read the interrupt flag for the selected pin. 
 * @param - uint8_t port: the port number for which pin should have its direction set.
 * @param - uint8_t pin: the pin number to set the direction of in the chosen port.
 * @return - uint8_t flag: the setting of the flag for the selected pin. 
 */
uint8_t read_GPIO_interrupt_flag(uint8_t port, uint8_t pin);

#endif /* GPIO_H */
