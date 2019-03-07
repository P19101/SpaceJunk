/**
 * @file gpio_init.c
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief file with container functions to consolidate the initilization of the
 * 		gpio pins on the board. All of the settings for these functions are in
 * 		pinUsage.h
 */
 
#include "gpio_init.h"

void set_port_output_pins(void){
    int port_1_outs[] = PORT_1_OUTPUTS;
    int port_2_outs[] = PORT_2_OUTPUTS;
    int port_3_outs[] = PORT_3_OUTPUTS;
    int port_4_outs[] = PORT_4_OUTPUTS;

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

void set_pull_up_resistors(void){
	int port_1_pulls[] = PORT_1_PULL_UP;
	int port_2_pulls[] = PORT_2_PULL_UP;
	int port_3_pulls[] = PORT_3_PULL_UP;
	int port_4_pulls[] = PORT_4_PULL_UP;
	
	uint8_t i = 0;
	int current_pin;
	//PORT1
	current_pin = port_1_pulls[i];
    while(current_pin != DEFAULT_SELECTION){
        set_GPIO_resistor_pull_direction(PORT_1, current_pin, PULL_UP);
        current_pin = port_1_pulls[++i];
    }

    // PORT2
    i = 0;
    current_pin = port_2_pulls[0];
    while(current_pin != DEFAULT_SELECTION){
        set_GPIO_resistor_pull_direction(PORT_2, current_pin, PULL_UP);
        current_pin = port_2_pulls[++i];
    }

    // PORT3
    i = 0;
    current_pin = port_3_pulls[0];
    while(current_pin != DEFAULT_SELECTION){
        set_GPIO_resistor_pull_direction(PORT_3, current_pin, PULL_UP);
        current_pin = port_3_pulls[++i];
    }

    // PORT4
    i = 0;
    current_pin = port_4_pulls[0];
    while(current_pin != DEFAULT_SELECTION){
        set_GPIO_resistor_pull_direction(PORT_4, current_pin, PULL_UP);
        current_pin = port_4_pulls[++i];
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

void set_pin_functions(void){
    int port_1_pri[] = PORT_1_PRIMARIES;
    int port_2_pri[] = PORT_2_PRIMARIES;
    int port_3_pri[] = PORT_3_PRIMARIES;
    int port_4_pri[] = PORT_4_PRIMARIES;

    int port_1_sec[] = PORT_1_SECONDARIES;
    int port_2_sec[] = PORT_2_SECONDARIES;
    int port_3_sec[] = PORT_3_SECONDARIES;
    int port_4_sec[] = PORT_4_SECONDARIES;

    int port_1_tri[] = PORT_1_TERTIARIES;
    int port_2_tri[] = PORT_2_TERTIARIES;
    int port_3_tri[] = PORT_3_TERTIARIES;
    int port_4_tri[] = PORT_4_TERTIARIES;

    /*** PRIMARY SET PINS ***/
    // First set pins for PORT1
    uint8_t i = 0;
    int current_pin;
    current_pin = port_1_pri[i];
    while(current_pin != DEFAULT_SELECTION){
        choose_GPIO_function(PORT_1, current_pin, PRIMARY_MOD);
        current_pin = port_1_pri[++i];
    }

    // PORT2
    i = 0;
    current_pin = port_2_pri[0];
    while(current_pin != DEFAULT_SELECTION){
        choose_GPIO_function(PORT_2, current_pin, PRIMARY_MOD);
        current_pin = port_2_pri[++i];
    }

    // PORT3
    i = 0;
    current_pin = port_3_pri[0];
    while(current_pin != DEFAULT_SELECTION){
        choose_GPIO_function(PORT_3, current_pin, PRIMARY_MOD);
        current_pin = port_3_pri[++i];
    }

    // PORT4
    i = 0;
    current_pin = port_4_pri[0];
    while(current_pin != DEFAULT_SELECTION){
        choose_GPIO_function(PORT_4, current_pin, PRIMARY_MOD);
        current_pin = port_4_pri[++i];
    }
    /*********************************************************/

    /*** SECONDARY SET PINS ***/
    // First set pins for PORT1
    current_pin = port_1_sec[i];
    while(current_pin != DEFAULT_SELECTION){
        choose_GPIO_function(PORT_1, current_pin, SECONDARY_MOD);
        current_pin = port_1_sec[++i];
    }

    // PORT2
    i = 0;
    current_pin = port_2_sec[0];
    while(current_pin != DEFAULT_SELECTION){
        choose_GPIO_function(PORT_2, current_pin, SECONDARY_MOD);
        current_pin = port_2_sec[++i];
    }

    // PORT3
    i = 0;
    current_pin = port_3_sec[0];
    while(current_pin != DEFAULT_SELECTION){
        choose_GPIO_function(PORT_3, current_pin, SECONDARY_MOD);
        current_pin = port_3_sec[++i];
    }

    // PORT4
    i = 0;
    current_pin = port_4_sec[0];
    while(current_pin != DEFAULT_SELECTION){
        choose_GPIO_function(PORT_4, current_pin, SECONDARY_MOD);
        current_pin = port_4_sec[++i];
    }
    /*******************************************************/

    /*** TERTIARY SET PINS ***/
    // First set pins for PORT1
    current_pin = port_1_tri[i];
    while(current_pin != DEFAULT_SELECTION){
        choose_GPIO_function(PORT_1, current_pin, TERTIARY_MOD);
        current_pin = port_1_tri[++i];
    }

    // PORT2
    i = 0;
    current_pin = port_2_tri[0];
    while(current_pin != DEFAULT_SELECTION){
        choose_GPIO_function(PORT_2, current_pin, TERTIARY_MOD);
        current_pin = port_2_tri[++i];
    }

    // PORT3
    i = 0;
    current_pin = port_3_tri[0];
    while(current_pin != DEFAULT_SELECTION){
        choose_GPIO_function(PORT_3, current_pin, TERTIARY_MOD);
        current_pin = port_3_tri[++i];
    }

    // PORT4
    i = 0;
    current_pin = port_4_tri[0];
    while(current_pin != DEFAULT_SELECTION){
        choose_GPIO_function(PORT_4, current_pin, TERTIARY_MOD);
        current_pin = port_4_tri[++i];
    }
    /******************************************************/
}

void enable_pin_interrupts(void){
	int port_1_ints[] = PORT_1_INTERRUPTS;
    int port_2_ints[] = PORT_2_INTERRUPTS;
    int port_3_ints[] = PORT_3_INTERRUPTS;
    int port_4_ints[] = PORT_4_INTERRUPTS;

    // First set pins for PORT1
    uint8_t i = 0;
    int current_pin;
    current_pin = port_1_ints[i];
    while(current_pin != DEFAULT_SELECTION){
        enable_GPIO_interrupt(PORT_1, current_pin);
        current_pin = port_1_ints[++i];
    }

    // PORT2
    i = 0;
    current_pin = port_2_ints[0];
    while(current_pin != DEFAULT_SELECTION){
        enable_GPIO_interrupt(PORT_2, current_pin);
        current_pin = port_2_ints[++i];
    }

    // PORT3
    i = 0;
    current_pin = port_3_ints[0];
    while(current_pin != DEFAULT_SELECTION){
        enable_GPIO_interrupt(PORT_3, current_pin);
        current_pin = port_3_ints[++i];
    }

    // PORT4
    i = 0;
    current_pin = port_4_ints[0];
    while(current_pin != DEFAULT_SELECTION){
        enable_GPIO_interrupt(PORT_4, current_pin);
        current_pin = port_4_ints[++i];
    }
}

void set_interrupts_edges(void){
	int port_1_edge[] = PORT_1_EDGES;
    int port_2_edge[] = PORT_2_EDGES;
    int port_3_edge[] = PORT_3_EDGES;
    int port_4_edge[] = PORT_4_EDGES;

    // First set pins for PORT1
    uint8_t i = 0;
    int current_pin;
    current_pin = port_1_edge[i];
    while(current_pin != DEFAULT_SELECTION){
        choose_interrupt_edge(PORT_1, current_pin, HIGH_TO_LOW);
        current_pin = port_1_edge[++i];
    }

    // PORT2
    i = 0;
    current_pin = port_2_edge[0];
    while(current_pin != DEFAULT_SELECTION){
        choose_interrupt_edge(PORT_2, current_pin, HIGH_TO_LOW);
        current_pin = port_2_edge[++i];
    }

    // PORT3
    i = 0;
    current_pin = port_3_edge[0];
    while(current_pin != DEFAULT_SELECTION){
        choose_interrupt_edge(PORT_3, current_pin, HIGH_TO_LOW);
        current_pin = port_3_edge[++i];
    }

    // PORT4
    i = 0;
    current_pin = port_4_edge[0];
    while(current_pin != DEFAULT_SELECTION){
        choose_interrupt_edge(PORT_4, current_pin, HIGH_TO_LOW);
        current_pin = port_4_edge[++i];
    }
}

void clear_interrupt_flags(void){
    // write all zeros to all flags to clear
    P1IFG = DEFAULT_SELECTION;
    P2IFG = DEFAULT_SELECTION;
    P3IFG = DEFAULT_SELECTION;
    P4IFG = DEFAULT_SELECTION;
}
