/*
 * @file systemInit.c
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief File which utilizes the settings of pinUsage.h to initialize the system
 * 		after a standard reset event. 
 */
 
#include "pinUsage.h"
#include "systemInit.h"

void set_port_output_pins(void){
    int port_1_outs[] = PORT_1_OUTPUTS;
    int i = 0;
    int current_pin;
    current_pin = port_1_outs[i];
    while(current_pin != DEFAULT_SELECTION){
        set_GPIO_pin_output(PORT_1, current_pin);
        i++;
        current_pin = port_1_outs[i];
    }
}

