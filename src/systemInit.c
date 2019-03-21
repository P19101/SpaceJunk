/*
 * @file systemInit.c
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief File which utilizes the settings of pinUsage.h to initialize the system
 * 		after a standard reset event. 
 */
#include "systemInit.h"


void configure_sys(void){
	configure_GIPO();
	configure_ADC();
	configure_clock_sources();
}

void configure_GIPO(void){
	set_port_output_pins();
	enable_port_pull_resistors();
	set_pull_up_resistors();
	set_outputs_high();
	set_pin_functions();
	set_interrupts_edges();
	// unclock the pins allowing any settings to take effect.
	PM5CTL0 &= ~LOCKLPM5;
    clear_interrupt_flags();
	// per the manual ,enabling any interrupts should always be the last step.
	enable_pin_interrupts();
}

void configure_ADC(void){
    set_sample_hold_time_zero(ADC_MULTISAMPLE_HOLD_TIME);
    set_sample_hold_time_one(ADC_MULTISAMPLE_HOLD_TIME);
    set_conversion_sequence(ADC_SAMPLING_MODE);
    set_ADC_clock_source(ADC_CLOCK_SOURCE);
    set_ADC_clock_predivider(ADC_PRIMARY_DIVIDER);
    set_ADC_secondary_divider(ADC_SECONDARY_DIVIDER);
    set_ADC_sample_trigger_source(ADC_TRIGGER);
    set_ADC_resolution(ADC_RESOLUTION);
    select_ADC_mem_register(0x00);
}

void configure_clock_sources(void){
	// unlocking the CS registers must always be the first step. 
	unlock_CS_register_set();	
	diabled_conditional_request();
	diabled_clock_signals();
	high_low_freq_drive_strengths();
	default_clock_divisors();
	default_clock_sources();
	high_freq_clk_range(HIGH_FREQ_RANGE);
	set_digital_clock_frequency(DIGITAL_CLK_FREQ);
}
	
