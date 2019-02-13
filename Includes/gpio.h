/*
 * @file gpio.h
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief File containing function definitions for programming the GPIO ports
 */

#ifndef GPIO_H
#define GPIO_H

typedef enum pinNumbers{
    PIN_1 = 0x01,
    PIN_2 = 0x02,
    PIN_3 = 0x04,
    PIN_4 = 0x08,
    PIN_5 = 0x10,
    PIN_6 = 0x20,
    PIN_7 = 0x40,
    PIN_8 = 0x80
}GPIOPins;

typedef enum portSelection{
    PORT_1,
    PORT_2,
    PORT_3,
    PORT_4
}GPIOPorts;

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




#endif /* GPIO_H */
