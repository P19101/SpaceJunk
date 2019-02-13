/*
 * @file gpio.c
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief File containing function for programming the GPIO ports
 */

#include "includes/gpio.h"
#include "includes/commonHeader.h"


uint8_t read_GPIO_input_pin(uint8_t port, uint8_t pin){
    switch(port){
        case PORT_1:
            return (P1IN & pin);
        case PORT_2:
            return (P2IN & pin);
        case PORT_3:
            return (P3IN & pin);
        case PORT_4:
            return (P4IN & pin);
        default:
            return DEFAULT_SELECTION;
    }
}

uint8_t read_GPIO_output_pin(uint8_t port, uint8_t pin){
    switch(port){
        case PORT_1:
            return (P1OUT & pin);
        case PORT_2:
            return (P2OUT & pin);
        case PORT_3:
            return (P3OUT & pin);
        case PORT_4:
            return (P4OUT & pin);
        default:
            return DEFAULT_SELECTION;
    }
}

uint8_t read_GPIO_resistor_pull_direction(uint8_t port, uint8_t pin){
    switch(port){
        case PORT_1:
            return (P1OUT & pin);
        case PORT_2:
            return (P2OUT & pin);
        case PORT_3:
            return (P3OUT & pin);
        case PORT_4:
            return (P4OUT & pin);
        default:
            return DEFAULT_SELECTION;
    }
}






