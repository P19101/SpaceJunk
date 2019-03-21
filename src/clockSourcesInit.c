/*
 * @file clockSourcesInit.c
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief File containing functions for default clock settings
 */
 
#include "clockSourcesInit.h"
#include "pinUsage.h"
#include "commonHeader.h"
#include "clockSources.h"

void default_clock_sources(void){
	select_MCLK_source(MASTER_CLK_SOURCE);
	select_SMCLK_source(SUB_SYS_CLK_SOURCE);
	select_ACLK_source(AUX_CLOCK_SOURCE);
}

void default_clock_divisors(void){
	auxilary_clock_division_factor(AUX_CLK_DIV_FACTOR);
	master_clock_division_factor(MASTER_CLK_DIV_FACTOR);
	subsystem_clock_division_factor(SUB_SYS_CLK_DIV_FACTOR);
}

void high_low_freq_drive_strengths(void){
	high_freq_clk_drive_strength(HIGH_FREQ_DRIVE);
	low_frequency_clk_drive_strength(LOW_FREQ_DRIVE);
}

void diabled_clock_signals(void){
	high_freq_clk_on_off(HIGH_FREQ_ON_OFF_DEFAULT);
	low_frequency_clk_on_off(LOW_FREQ_ON_OFF_DEFAULT);
	very_low_clk_on_off(VL_FREQ_ON_OFF_DEFAULT);
	subsystem_master_clk_on_off(SMCLK_ON_OFF_DEFAULT);
}

void diabled_conditional_request(void){
	mod_clk_conditional_req_on_off(MOD_CLK_COND_REQ);
	sub_sys_clk_conditional_req_on_off(SMCLK_COND_REQ);
	master_clk_conditional_req_on_off(MCLK_COND_REQ);
	auxilary_clk_conditional_req_on_off(ACLK_COND_REQ);
}
