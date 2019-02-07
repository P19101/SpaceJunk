/*
 * @file ClockSource.c
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief File containing functions for adjusting the clocks of the System.
 *		adjusting these values can have a large inpact on the performance of all subsystems.
 */

#include "clockSources.h"
 
void unlock_CS_register_set(void){
	CSCTL0 |= CSKEY;
}

void set_digital_clock_frequency(uint8_t frequency){
	uint16_t frequencySet;
	CSCTL1 &= ~(DCOFSEL0 | DCOFSEL1 | DCOFSEL2 | DCOFSEL);
	switch(frequency){
		case MHZ_1:
			frequencySet = 0x0000;
			break;
		case MHZ_2_67:
			frequencySet = DCOFSEL0;
			break;
		case MHZ_3_5:
			frequencySet = DCOFSEL1;
			break;
		case MHZ_4:
			frequencySet = DCOFSEL0 | DCOFSEL1;
			break;
		case MHZ_5_33:
			frequencySet = DCOFSEL2;
			break;
		case MHZ_7:
			frequencySet = DCOFSEL0 | DCOFSEL2;
			break;
		case MHZ_8:
			frequencySet = DCOFSEL1 | DCOFSEL2;
			break;
		case MHZ_16:
			frequencySet = DCOFSEL | DCOFSEL2;
			break;
		case MHZ_21:
			frequencySet = DCOFSEL | DCOFSEL0 | DCOFSEL2;
			break;
		case MHZ_24:
			frequencySet = DCOFSEL | DCOFSEL1 | DCOFSEL2;
			break;
		default:
			// by default select lowest frequency
			frequencySet = 0x0000;
			break;
	}
	CSCTL1 = frequencySet;
}