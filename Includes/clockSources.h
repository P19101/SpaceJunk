/*
 * @file ClockSource.h
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief File containing function definitions for adjusting the clocks of the System.
 *		adjusting these values can have a large inpact on the performance of all subsystems.
 */
 
#ifndef CLOCK_SOURCES_H
#define CLOCK_SOURCES_H 
 
#include <stdint.h>
#include <msp430fr5969.h>

// idk why its called password if its preset and in a manual, i guess just so 
// you dont accidentally change all the clock sources?

typedef enum digitalClockRanges{
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

typedef enum clockSources{
	LFXTCLK,
	VLOCLK,
	LFMODCLK, // this is just the MODCLK divided by 128
	DCOCLK,
	MODCLK,
	HFXTCLK,
}clockSourcesINTXT;

typedef enum clockSourceDivider{
	FACTOR_1,
	FACTOR_2,
	FACTOR_4,
	FACTOR_8,
	FACTOR_16,
	FACTOR_32,
}clockSourceDivMain;

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
 * @param uint8_t source: the source selection from the clockSources enum selected
 * 		from the three choices above. 
 * @return: None
 */
void select_ACLK_source(uint8_t source);

/**
 * select the source for the master clock.
 * @param uint8_t source: the source selection from the clockSources enum.
 * @return: None
 */
void select_MCLK_source(uint8_t source);

/**
 * select the source for the subsytem master clock.
 * @param uint8_t source: the source selection from the clockSources enum.
 * @return: None
 */
void select_SMCLK_source(uint8_t source);

/**
 * select the division factor for the auxilary clock
 * @param uint8_t div: the clock divider enum for the division factor
 * @return: None
 */
void auxilary_clock_division_factor(uint8_t div);

/**
 * select the division factor for the master clock
 * @param uint8_t div: the clock divider enum for the division factor
 * @return: None
 */
void master_clock_division_factor(uint8_t div);

/**
 * select the division factor for the subsystem clock
 * @param uint8_t div: the clock divider enum for the division factor
 * @return: None
 */
void subsystem_clock_division_factor(uint8_t div);



#endif




