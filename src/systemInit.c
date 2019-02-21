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
    int port_2_outs[] = PORT_2_OUTPUTS;
    int port_3_outs[] = PORT_3_OUTPUTS;
    int port_3_outs[] = PORT_4_OUTPUTS;

    // First set pins for PORT1
    uint8_t i = 0;
    int current_pin;
    current_pin = port_1_outs[i];
    while(current_pin != DEFAULT_SELECTION){
        set_GPIO_pin_output(PORT_1, current_pin);
        current_pin = port_1_outs[++i];
    }

    // PORT2
    i = 0;
    current_pin = port_2_outs[0];
    while(current_pin != DEFAULT_SELECTION){
        set_GPIO_pin_output(PORT_2, current_pin);
        current_pin = port_2_outs[++i];
    }

    // PORT3
    i = 0;
    current_pin = port_3_outs[0];
    while(current_pin != DEFAULT_SELECTION){
        set_GPIO_pin_output(PORT_3, current_pin);
        current_pin = port_3_outs[++i];
    }

    // PORT4
    i = 0;
    current_pin = port_4_outs[0];
    while(current_pin != DEFAULT_SELECTION){
        set_GPIO_pin_output(PORT_4, current_pin);
        current_pin = port_4_outs[++i];
    }
}

void enable_port_pull_resistors(void){
    int port_1_pulled[] = PORT_1_PULLED_PINS;
    int port_2_pulled[] = PORT_2_PULLED_PINS;
    int port_3_pulled[] = PORT_3_PULLED_PINS;
    int port_4_pulled[] = PORT_4_PULLED_PINS;

    // First set pins for PORT1
    uint8_t i = 0;
    int current_pin;
    current_pin = port_1_pulled[i];
    while(current_pin != DEFAULT_SELECTION){
        enable_GPIO_pin_pull_resistor(PORT_1, current_pin);
        current_pin = port_1_pulled[++i];
    }

    // PORT2
    i = 0;
    current_pin = port_2_pulled[0];
    while(current_pin != DEFAULT_SELECTION){
        enable_GPIO_pin_pull_resistor(PORT_2, current_pin);
        current_pin = port_2_pulled[++i];
    }

    // PORT3
    i = 0;
    current_pin = port_3_pulled[0];
    while(current_pin != DEFAULT_SELECTION){
        enable_GPIO_pin_pull_resistor(PORT_3, current_pin);
        current_pin = port_3_pulled[++i];
    }

    // PORT4
    i = 0;
    current_pin = port_4_pulled[0];
    while(current_pin != DEFAULT_SELECTION){
        enable_GPIO_pin_pull_resistor(PORT_4, current_pin);
        current_pin = port_4_pulled[++i];
    }
}

void set_outputs_high(void){
    int port_1_out_high[] = PORT_1_HIGHS;
    int port_2_out_high[] = PORT_2_HIGHS;
    int port_3_out_high[] = PORT_3_HIGHS;
    int port_4_out_high[] = PORT_4_HIGHS;

    // First set pins for PORT1
    uint8_t i = 0;
    int current_pin;
    current_pin = port_1_out_high[i];
    while(current_pin != DEFAULT_SELECTION){
        set_GPIO_pin(PORT_1, current_pin);
        current_pin = port_1_out_high[++i];
    }

    // PORT2
    i = 0;
    current_pin = port_2_out_high[0];
    while(current_pin != DEFAULT_SELECTION){
        set_GPIO_pin(PORT_2, current_pin);
        current_pin = port_2_out_high[++i];
    }

    // PORT3
    i = 0;
    current_pin = port_3_out_high[0];
    while(current_pin != DEFAULT_SELECTION){
        set_GPIO_pin(PORT_3, current_pin);
        current_pin = port_3_out_high[++i];
    }

    // PORT4
    i = 0;
    current_pin = port_4_out_high[0];
    while(current_pin != DEFAULT_SELECTION){
        set_GPIO_pin(PORT_4, current_pin);
        current_pin = port_4_out_high[++i];
    }
}







