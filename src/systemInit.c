/*
 * @file systemInit.c
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief File which utilizes the settings of pinUsage.h to initialize the system
 * 		after a standard reset event. 
 */
 
#include "pinUsage.h"
#include "systemInit.h"

void configure_sys(void){
	configure_GIPO();
}

void configure_GIPO(void){
	set_port_output_pins();
	enable_port_pull_resistors();
	set_pull_up_resistors();
	set_outputs_high();
	set_pin_functions();
	enable_pin_interrupts();
	set_interrupts_edges();
}
	
