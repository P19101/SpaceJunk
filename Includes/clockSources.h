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


