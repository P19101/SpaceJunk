/*
 * @file ClockSource.c
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief File containing functions for adjusting the clocks of the System.
 *		adjusting these values can have a large inpact on the performance of all subsystems.
 */

#include "clockSources.h"
#include "commonHeader.h"
 
void unlock_CS_register_set(void){
	CSCTL0 |= CSKEY;
}

void set_digital_clock_frequency(uint8_t frequency){
	uint16_t frequencySet;
	CSCTL1 &= ~(DCOFSEL0 | DCOFSEL1 | DCOFSEL2 | DCORSEL);
	switch(frequency){
		case MHZ_1:
			frequencySet = DEFAULT_SELECTION;
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
			frequencySet = DCORSEL | DCOFSEL2;
			break;
		case MHZ_21:
			frequencySet = DCORSEL | DCOFSEL0 | DCOFSEL2;
			break;
		case MHZ_24:
			frequencySet = DCORSEL | DCOFSEL1 | DCOFSEL2;
			break;
		default:
			// by default select lowest frequency
			frequencySet = DEFAULT_SELECTION;
			break;
	}
	CSCTL1 = frequencySet;
}

void select_ACLK_source(uint8_t source){
	uint16_t sourceSet;
	CSCTL2 &= ~(SELA0 | SELA1 | SELA2);
	switch(source){
		case LFXTCLK:
			sourceSet = DEFAULT_SELECTION;
			break;
		case VLOCLK:
			sourceSet = SELA0;
			break;
		case LFMODCLK:
			sourceSet = SELA1;
			break;
		default:
			sourceSet = DEFAULT_SELECTION;
			break;
	}
	CSCTL2 |= sourceSet;
}

void select_MCLK_source(uint8_t source){
	uint16_t sourceSet;
	CSCTL2 &= ~(SELS0 | SELS1 | SELS2);
	switch(source){
		case LFXTCLK:
			sourceSet = DEFAULT_SELECTION;
			break;
		case VLOCLK:
			sourceSet = SELS0;
			break;
		case LFMODCLK:
			sourceSet = SELS1;
			break;
		case DCOCLK:
			sourceSet = SELS0 | SELS1;
			break;
		case MODCLK:
			sourceSet = SELS2;
			break;
		case HFXTCLK:
			sourceSet = SELS0 | SELS2;
			break;
		default:
			sourceSet = DEFAULT_SELECTION;
			break;
	}
	CSCTL2 |= sourceSet;
}

void select_SMCLK_source(uint8_t source){
	uint16_t sourceSet;
	CSCTL2 &= ~(SELM0 | SELM1 | SELM2);
	switch(source){
		case LFXTCLK:
			sourceSet = DEFAULT_SELECTION;
			break;
		case VLOCLK:
			sourceSet = SELM0;
			break;
		case LFMODCLK:
			sourceSet = SELM1;
			break;
		case DCOCLK:
			sourceSet = SELM0 | SELM1;
			break;
		case MODCLK:
			sourceSet = SELM2;
			break;
		case HFXTCLK:
			sourceSet = SELM0 | SELM2;
			break;
		default:
			sourceSet = DEFAULT_SELECTION;
			break;
	}
	CSCTL2 |= sourceSet;
}

void auxilary_clock_division_factor(uint8_t div){
	uint16_t divSet;
	CSCTL2 &= ~(DIVA0 | DIVA1 | DIVA2);
	switch(div){
		case FACTOR_1:
			divSet = DEFAULT_SELECTION;
			break;
		case FACTOR_2:
			divSet = DIVA0;
			break;
		case FACTOR_4:
			divSet = DIVA1;
			break;
		case FACTOR_8:
			divSet = DIVA1 | DIVA0;
			break;
		case FACTOR_16:
			divSet = DIVA2;
			break;
		case FACTOR_32:
			divSet = DIVA2 | DIVA0;
			break;
		default:
			divSet = DEFAULT_SELECTION;
			break;
	}
	CSCTL2 |= divSet;
}

void master_clock_division_factor(uint8_t div){
	uint16_t divSet;
	CSCTL2 &= ~(DIVM0 | DIVM1 | DIVM2);
	switch(div){
		case FACTOR_1:
			divSet = DEFAULT_SELECTION;
			break;
		case FACTOR_2:
			divSet = DIVM0;
			break;
		case FACTOR_4:
			divSet = DIVM1;
			break;
		case FACTOR_8:
			divSet = DIVM1 | DIVM0;
			break;
		case FACTOR_16:
			divSet = DIVM2;
			break;
		case FACTOR_32:
			divSet = DIVM2 | DIVM0;
			break;
		default:
			divSet = DEFAULT_SELECTION;
			break;
	}
	CSCTL2 |= divSet;
}

void subsystem_clock_division_factor(uint8_t div){
	uint16_t divSet;
	CSCTL2 &= ~(DIVS0 | DIVS1 | DIVS2);
	switch(div){
		case FACTOR_1:
			divSet = DEFAULT_SELECTION;
			break;
		case FACTOR_2:
			divSet = DIVS0;
			break;
		case FACTOR_4:
			divSet = DIVS1;
			break;
		case FACTOR_8:
			divSet = DIVS1 | DIVS0;
			break;
		case FACTOR_16:
			divSet = DIVS2;
			break;
		case FACTOR_32:
			divSet = DIVS2 | DIVS0;
			break;
		default:
			divSet = DEFAULT_SELECTION;
			break;
	}
	CSCTL2 |= divSet;
}

void high_freq_crystal_drive_strength(uint8_t drive){
	CSCTL4 &= ~(HFXTDRIVE1 | HFXTDRIVE0);
	switch(drive){
		case HF_DRIVE_LV_1:
			CSCTL4 |= HFXTDRIVE_0;
			break;
		case HF_DRIVE_LV_2:
			CSCTL4 |= HFXTDRIVE_1;
			break;
		case HF_DRIVE_LV_3:
			CSCTL4 |= HFXTDRIVE_2;
			break;
		case HF_DRIVE_LV_4:
			CSCTL4 |= HFXTDRIVE_3;
			break;
	}
}

void high_freq_clk_bypass_enable(void){
	CSCTL4 |= HFXTBYPASS;
}

void high_freq_clk_bypass_diable(void){
	CSCTL4 &= ~(HFXTBYPASS);
}

void high_freq_clk_range(uint8_t freq){
	CSCTL4 &= ~(HFFREQ1 | HFFREQ0);
	swtich(freq){
		case HF_0_TO_4_MHZ:
			CSCTL4 |= HFFREQ_0;
			break;
		case HF_4_TO_8_MHZ:
			CSCTL4 |= HFFREQ_1;
			break;
		case HF_8_TO_16_MHZ:
			CSCTL4 |= HFFREQ_2;
			break;
		case HF_16_TO_24_MHZ:
			CSCTL4 |= HFFREQ_3;
			break;
	}
}

void high_freq_clk_on_off(uint8_t enable){
	if(enable){
		CSCTL4 |= HFXTOFF;
	}
	else{
		CSCTL4 &= ~(HFXTOFF);
	}
}

void low_frequency_clk_drive_strength(uint8_t drive){
	CSCTL4 &= ~(LFXTDRIVE1 | LFXTDRIVE0);
	switch(drive){
		case LF_DRIVE_LV_1:
			CSCTL4 |= LFXTDRIVE_0;
			break;
		case LF_DRIVE_LV_2:
			CSCTL4 |= LFXTDRIVE_1;
			break;
		case LF_DRIVE_LV_3:
			CSCTL4 |= LFXTDRIVE_2;
			break;
		case LF_DRIVE_LV_4:
			CSCTL4 |= LFXTDRIVE_3;
			break;
	}
}

void low_frequency_clk_bypass_enable(void){
	CSCTL4 |= LFXTBYPASS;
}

void low_frequency_clk_bypass_disable(void){
	CSCTL4 &= ~(LFXTBYPASS);
}

void low_frequency_clk_on_off(uint8_t enable){
	if(enable){
		CSCTL4 |= LFXTOFF;
	}
	else{
		CSCTL4 &= ~(LFXTOFF);
	}
}

void very_low_clk_on_off(uint8_t enable){
	if(enable){
		CSCTL4 |= VLOOFF;
	}
	else{
		CSCTL4 &= ~(VLOOFF);
	}
}

void subsystem_master_clk_on_off(uint8_t enable){
	if(enable){
		CSCTL4 |= SMCLKOFF;
	}
	else{
		CSCTL4 &= ~(SMCLKOFF);
	}
}

void high_frequency_clock_start_counter(uint8_t enable){
	if(enable){
		CSCTL5 |= ENSTFCNT2;
	}
	else{
		CSCTL5 &= ~(ENSTFCNT2);
	}
}

void low_frequency_clock_start_counter(uint8_t enable){
	if(enable){
		CSCTL5 |= ENSTFCNT1;
	}
	else{
		CSCTL5 &= ~(ENSTFCNT1);
	}
}

uint8_t read_high_frequency_fault_flag(void){
	uint8_t flag;
	flag = CSCTL5 & HFXTOFFG;
	CSCTL5 &= ~(HFXTOFFG);
	return flag;
}

uint8_t read_low_frequency_fault_flag(void){
	uint8_t flag;
	flag = CSCTL5 & LFXTOFFG;
	CSCTL5 &= ~(LFXTOFFG);
	return flag;
}

void mod_clk_conditional_req_on_off(uint8_t enable){
	if(enable){
		CSCTL6 |= MODCLKREQEN;
	}
	else{
		CSCTL6 &= ~(MODCLKREQEN);
	}
}

void sub_sys_clk_conditional_req_on_off(uint8_t enable){
	if(enable){
		CSCTL6 |= MODCLKREQEN;
	}
	else{
		CSCTL6 &= ~(MODCLKREQEN);
	}
}

void master_clk_conditional_req_on_off(uint8_t enable){
	if(enable){
		CSCTL6 |= MODCLKREQEN;
	}
	else{
		CSCTL6 &= ~(MODCLKREQEN);
	}
}

void auxilary_clk_conditional_req_on_off(uint8_t enable){
	if(enable){
		CSCTL6 |= MODCLKREQEN;
	}
	else{
		CSCTL6 &= ~(MODCLKREQEN);
	}
}




















