/*
 * @file ClockSource.h
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief File containing function definitions for adjusting the clocks of the System.
 *		adjusting these values can have a large inpact on the performance of all subsystems.
 */
 
#ifndef CLOCK_SOURCES_H
#define CLOCK_SOURCES_H 
 
#include "commonHeader.h"

// idk why its called password if its preset and in a manual, i guess just so 
// you dont accidentally change all the clock sources?

typedef enum { 
	MHZ_1,
	MHZ_2_67,
	MHZ_3_5,
	MHZ_4,
	MHZ_5_33,
	MHZ_7,
	MHZ_8,
	MHZ_16,
	MHZ_21,
	MHZ_24
	
}digitalClockRangesHZ;

typedef enum {
	LFXTCLK,
	VLOCLK,
	LFMODCLK, // this is just the MODCLK divided by 128
	DCOCLK,
	MODCLK,
	HFXTCLK,
}clockSourcesINTXT;

typedef enum {
	FACTOR_1,
	FACTOR_2,
	FACTOR_4,
	FACTOR_8,
	FACTOR_16,
	FACTOR_32,
}clockSourceDivMain;

typedef enum { // drive level 1 is the lowest drive strenght
	HF_DRIVE_LV_1,
	HF_DRIVE_LV_2,
	HF_DRIVE_LV_3,
	HF_DRIVE_LV_4
}clockSourcesHighFreqClkDriveStrength;

typedef enum { // lower bounds are exclusive, upper bounds are inclusive.
	HF_0_TO_4_MHZ,
	HF_4_TO_8_MHZ,
	HF_8_TO_16_MHZ,
	HF_16_TO_24_MHZ
}clockSourceHighFreqClkRanges;

typedef enum { // lower bounds are exclusive, upper bounds are inclusive
	LF_DRIVE_LV_1,	
	LF_DRIVE_LV_2,	
	LF_DRIVE_LV_3,	
	LF_DRIVE_LV_4	
}

/**
 * Unlocks the CS registers so that the clock source settings can be modified upon
 * startup. This must be done before any changes can be made. 
 * @param: None
 * @return: None
 */
void unlock_CS_register_set(void);

/**
 * set the frequency for the digital clock source. 
 * @param - uint8_t frequency: the digitalClockRanges enum used to select the]
 * 		frequency for the digital clock.
 * @return: None
 */
void set_digital_clock_frequency(uint8_t frequency);

/**
 * select the source for the auxilary clock. the choices are either:
 * 		LFXTCLK
 * 		VLOCLK
 *		LFMODCLK
 * @param - uint8_t source: the source selection from the clockSources enum selected
 * 		from the three choices above. 
 * @return: None
 */
void select_ACLK_source(uint8_t source);

/**
 * select the source for the master clock.
 * @param - uint8_t source: the source selection from the clockSources enum.
 * @return: None
 */
void select_MCLK_source(uint8_t source);

/**
 * select the source for the subsytem master clock.
 * @param - uint8_t source: the source selection from the clockSources enum.
 * @return: None
 */
void select_SMCLK_source(uint8_t source);

/**
 * select the division factor for the auxilary clock
 * @param - uint8_t div: the clock divider enum for the division factor
 * @return: None
 */
void auxilary_clock_division_factor(uint8_t div);

/**
 * select the division factor for the master clock
 * @param - uint8_t div: the clock divider enum for the division factor
 * @return: None
 */
void master_clock_division_factor(uint8_t div);

/**
 * select the division factor for the subsystem clock
 * @param - uint8_t div: the clock divider enum for the division factor
 * @return: None
 */
void subsystem_clock_division_factor(uint8_t div);

/**
 * Determine the drive current for the high frequency oscillator crystal. 
 * This can be adjusted along with the HFFREQ to optimize the performance of the
 * attached crystal according to its specification. 
 * @param uint8_t drive: the enum characterizing the drive strength of the HF crystal
 * @return: None
 */
void high_freq_clk_drive_strength(uint8_t drive);

/**
 * Used when the high frequency source is a seperate clock signal, and NOT a crystal
 * bypassing the drive for the pins. 
 * @param: None
 * @return: None
 */
void high_freq_clk_bypass_enable(void);

/**
 * Used when the high frequency source is a crystal.
 * NOTE: this is the default option
 * @param: None
 * @return: None
 */
void high_freq_clk_bypass_diable(void);

/**
 * Used with the HFXTDRIVE to determine the optimal operation settings for the
 * high frequency crystal. Selects the general range of operational frequencies
 * that the attached crystal will have. 
 * @param - uint8_t freq: the frequency range enum that the attached crystal operates
 * 		in
 * @return: None
 */
void high_freq_clk_range(uint8_t freq);

/** Use to turn the high frequency clock on or off to conserve power. 
 * @param - uint8_t enable: SET to turn the clock OFF,
 * 						  CLEAR to turn the crystal ON,
 * @return: None
 */
void high_freq_clk_on_off(uint8_t enable);

/**
 * Determine the drive current for the low frequency oscillator crystal.
 * This can be adjusted to optimize the performance of the attached crystal
 * according to its specification
 * @param - uint8_t drive: the enum to chose the drive strenght going to the crystal
 * @return: None
 */
void low_frequency_clk_drive_strength(uint8_t drive);

/** 
 * Used when the low frequency source is a seperate clock signal, and NOT a crystal
 * bypassing the drive for the pins. 
 * @param: None
 * @return: None
 */
void low_frequency_clk_bypass_enable(void);

/** 
 * Used when the low frequency source is a cystal.
 * NOTE: this is the default option.
 * @param: None
 * @return: None
 */
void low_frequency_clk_bypass_disable(void);

/**
 * Use to turn the low frequency clock on or off to conserve power.
 * @param - uint8_t enable: SET to turn the clock OFF,
 * 						  CLEAR to turn the crystal ON,
 * @return: None
 */
void low_frequency_clk_on_off(uint8_t enable);

/**
 * Use to turn the very low interal oscillator on or off to conserve power.
 * @param - uint8_t enable: SET to turn the clock OFF,
 * 						  CLEAR to turn the crystal ON,
 * @return: None
 */
void very_low_clk_on_off(uint8_t enable);

/**
 * Use to turn the subsystem master clock on or off to conserve power. 
 * @param - uint8_t enable: SET to turn the clock OFF,
 * 						  CLEAR to turn the crystal ON,
 * @return: None
 */
void subsystem_master_clk_on_off(uint8_t enable);

/** 
 * Used to count the number of successful cycles that have taken place since a reset for
 * the high frequency clock. 1024 cycles must be counted before the system will enable the 
 * high frequency clock as stable if this bit is enabled. 
 * NOTE: this bit is enabled by default and HIGHLY RECOMMENED to keep high.
 * @param - uint8_t enable: determines if the fault counter should be enabled or disabled
 * @return: None
 */
void high_frequency_clock_start_counter(uint8_t enable);

/** 
 * Used to count the number of successful cycles that have taken place since a reset for
 * the low frequency clock. 1024 cycles must be counted before the system will enable the 
 * low frequency clock as stable if this bit is enabled. 
 * NOTE: this bit is enabled by default and HIGHLY RECOMMENED to keep high.
 * @param - uint8_t enable: determines if the fault counter should be enabled or disabled
 * @return: None
 */
void low_frequency_clock_start_counter(uint8_t enable);

/**
 * Read the flag indicating if the high frequency fault flag has been set upon startup.
 * After reading the value, the function will also automatically clear the bit. 
 * @param: None
 * @return - uint8_t fault: indicates the value of the high frequency fault flag. 
 */
uint8_t read_high_frequency_fault_flag(void);

/**
 * Read the flag indicating if the low frequencies fault flag has been set upon startup.
 * After reading the vaule, the function will also automatically clear the bit.
 * @param: None
 * @return - uint8_t fault: indicates the vaule of the low frequency fault flag.
 */
uint8_t read_low_frequency_fault_flag(void);

/**
 * determines if the MODCLK can be requested by subsystems directly even when it is normally
 * off. This will enable the clock with any user settings which were previously in place.
 * @param - uint8_t enable: enable the clock for conditional request or not.
 * @return: None
 */
void mod_clk_conditional_req_on_off(uint8_t enable);

/**
 * determines if the SMCLK can be requested by subsystems directly even when it is normally
 * off. This will enable the clock with any user settings which were previously in place.
 * @param - uint8_t enable: enable the clock for conditional request or not.
 * @return: None
 */
void sub_sys_clk_conditional_req_on_off(uint8_t enable);

/**
 * determines if the MCLK can be requested by subsystems directly even when it is normally
 * off. This will enable the clock with any user settings which were previously in place.
 * @param - uint8_t enable: enable the clock for conditional request or not.
 * @return: None
 */
void master_clk_conditional_req_on_off(uint8_t enable);

/**
 * determines if the ACLK can be requested by subsystems directly even when it is normally
 * off. This will enable the clock with any user settings which were previously in place.
 * @param - uint8_t enable: enable the clock for conditional request or not.
 * @return: None
 */
void auxilary_clk_conditional_req_on_off(uint8_t enable);


#endif









