/**
 * @file timer_A.c
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief source file containing hardware specific functions for the type A timer
 * 		modules.
 */
#include "timer_A.h"

void select_timer_Ax_clock_source(uint8_t timerNum, uint8_t clockSource){
	switch(timerNum){
		case TIM_A_0:
			// clear the bits first.
			TA0CTL &= ~(TASSEL1 | TASSEL0);
			switch(clockSource){
				case TAxCLK:
					// bits are already cleared, no operation requried. 
					break;
				case TMRA_ACLK:
					TA0CTL |= TASSEL__TACLK;
					break;
				case TMRA_SMCLK:
					TA0CTL |= TASSEL__SMCLK;
					break;
				case TMRA_INCLK:
					TA0CTL |= TASSEL__INCLK;
					break;
				default:
					TA0CTL |= (DEFAULT_SELECTION);
					break;
			}
			break;
		
		case TIM_A_1:
			TA1CTL &= ~(TASSEL1 | TASSEL0);
			switch(clockSource){
				case TAxCLK:
					// bits are already cleared, no operation requried. 
					break;
				case TMRA_ACLK:
					TA1CTL |= TASSEL__TACLK;
					break;
				case TMRA_SMCLK:
					TA1CTL |= TASSEL__SMCLK;
					break;
				case TMRA_INCLK:
					TA1CTL |= TASSEL__INCLK;
					break;
				default:
					TA1CTL |= (DEFAULT_SELECTION);
					break;
			}
			break;
		
		case TIM_A_2:
			TA2CTL &= ~(TASSEL1 | TASSEL0);
			switch(clockSource){
				case TAxCLK:
					// bits are already cleared, no operation requried. 
					break;
				case TMRA_ACLK:
					TA2CTL |= TASSEL__TACLK;
					break;
				case TMRA_SMCLK:
					TA2CTL |= TASSEL__SMCLK;
					break;
				case TMRA_INCLK:
					TA2CTL |= TASSEL__INCLK;
					break;
				default:
					TA2CTL |= (DEFAULT_SELECTION);
					break;
			}
			break;
			
		case TIM_A_3:
			TA3CTL &= ~(TASSEL1 | TASSEL0);
			switch(clockSource){
				case TAxCLK:
					// bits are already cleared, no operation requried. 
					break;
				case TMRA_ACLK:
					TA3CTL |= TASSEL__TACLK;
					break;
				case TMRA_SMCLK:
					TA3CTL |= TASSEL__SMCLK;
					break;
				case TMRA_INCLK:
					TA3CTL |= TASSEL__INCLK;
					break;
				default:
					TA3CTL |= (DEFAULT_SELECTION);
					break;
			}
			break;
	}
}

void input_divider_timer_Ax(uint8_t timerNum, uint8_t div){
	switch(timerNum){
		case TIM_A_0:
			// clear the bits first.
			TA0CTL &= ~(ID1 | ID0);
			switch(clockSource){
				case TA_DIV_1:
					// bits are already cleared, no operation requried. 
					break;
				case TA_DIV_2:
					TA0CTL |= ID__2;
					break;
				case TA_DIV_4:
					TA0CTL |= ID__4;
					break;
				case TA_DIV_8:
					TA0CTL |= ID__8;
					break;
				default:
					TA0CTL |= (DEFAULT_SELECTION);
					break;
			}
			break;
		
		case TIM_A_1:
			TA1CTL &= ~(ID1 | ID0);
			switch(clockSource){
				case TA_DIV_1:
					// bits are already cleared, no operation requried. 
					break;
				case TA_DIV_2:
					TA1CTL |= ID__2;
					break;
				case TA_DIV_4:
					TA1CTL |= ID__4;
					break;
				case TA_DIV_8:
					TA1CTL |= ID__8;
					break;
				default:
					TA1CTL |= (DEFAULT_SELECTION);
					break;
			}
			break;
		
		case TIM_A_2:
			TA2CTL &= ~(ID1 | ID0);
			switch(clockSource){
				case TA_DIV_1:
					// bits are already cleared, no operation requried. 
					break;
				case TA_DIV_2:
					TA2CTL |= ID__2;
					break;
				case TA_DIV_4:
					TA2CTL |= ID__4;
					break;
				case TA_DIV_8:
					TA2CTL |= ID__8;
					break;
				default:
					TA2CTL |= (DEFAULT_SELECTION);
					break;
			}
			break;
			
		case TIM_A_3:
			TA3CTL &= ~(ID1 | ID0);
			switch(clockSource){
				case TA_DIV_1:
					// bits are already cleared, no operation requried. 
					break;
				case TA_DIV_2:
					TA3CTL |= ID__2;
					break;
				case TA_DIV_4:
					TA3CTL |= ID__4;
					break;
				case TA_DIV_8:
					TA3CTL |= ID__8;
					break;
				default:
					TA3CTL |= (DEFAULT_SELECTION);
					break;
			}
			break;
	}
}

void mode_select_timer_Ax(uint8_t timerNum, uint8_t opMode){
	switch(timerNum){
		case TIM_A_0:
			// clear the bits first.
			TA0CTL &= ~(MC1 | MC0);
			switch(clockSource){
				case STOP_MODE:
					// bits are already cleared, no operation requried. 
					break;
				case UP_MODE:
					TA0CTL |= MC__UP;
					break;
				case CONTINUOUS_MODE:
					TA0CTL |= MC__CONTINUOUS;
					break;
				case UP_DOWN_MODE:
					TA0CTL |= MC__UPDOWN;
					break;
				default:
					TA0CTL |= (DEFAULT_SELECTION);
					break;
			}
			break;
		
		case TIM_A_1:
			TA1CTL &= ~(MC1 | MC0);
			switch(clockSource){
				case STOP_MODE:
					// bits are already cleared, no operation requried. 
					break;
				case UP_MODE:
					TA1CTL |= MC__UP;
					break;
				case CONTINUOUS_MODE:
					TA1CTL |= MC__CONTINUOUS;
					break;
				case UP_DOWN_MODE:
					TA1CTL |= MC__UPDOWN;
					break;
				default:
					TA1CTL |= (DEFAULT_SELECTION);
					break;
			}
			break;
		
		case TIM_A_2:
			TA2CTL &= ~(MC1 | MC0);
			switch(clockSource){
				case STOP_MODE:
					// bits are already cleared, no operation requried. 
					break;
				case UP_MODE:
					TA2CTL |= MC__UP;
					break;
				case CONTINUOUS_MODE:
					TA2CTL |= MC__CONTINUOUS;
					break;
				case UP_DOWN_MODE:
					TA2CTL |= MC__UPDOWN;
					break;
				default:
					TA2CTL |= (DEFAULT_SELECTION);
					break;
			}
			break;
			
		case TIM_A_3:
			TA3CTL &= ~(MC1 | MC0);
			switch(clockSource){
				case STOP_MODE:
					// bits are already cleared, no operation requried. 
					break;
				case UP_MODE:
					TA3CTL |= MC__UP;
					break;
				case CONTINUOUS_MODE:
					TA3CTL |= MC__CONTINUOUS;
					break;
				case UP_DOWN_MODE:
					TA3CTL |= MC__UPDOWN;
					break;
				default:
					TA3CTL |= (DEFAULT_SELECTION);
					break;
			}
			break;
	}
}

void clear_timer_Ax(uint8_t timerNum){
	switch(timerNum){
		case TIM_A_0:
			TA0CTL |= TACLR;
			break;
		case TIM_A_1:
			TA1CTL |= TACLR;
			break;
		case TIM_A_2:
			TA2CTL |= TACLR;
			break;
		case TIM_A_3:
			TA3CTL |= TACLR;
			break;
		default:
			TA3CTL |= DEFAULT_SELECTION;
			break;
}

void interrupt_enable_timer_Ax(uint8_t timerNum){
	switch(timerNum){
		case TIM_A_0:
			TA0CTL |= TAIE;
			break;
		case TIM_A_1:
			TA1CTL |= TAIE;
			break;
		case TIM_A_2:
			TA2CTL |= TAIE;
			break;
		case TIM_A_3:
			TA3CTL |= TAIE;
			break;
		default:
			TA3CTL |= DEFAULT_SELECTION;
			break;
}

void interupt_disable_timer_Ax(uint8_t timerNum){
	switch(timerNum){
		case TIM_A_0:
			TA0CTL &= ~TAIE;
			break;
		case TIM_A_1:
			TA1CTL &= ~TAIE;
			break;
		case TIM_A_2:
			TA2CTL &= ~TAIE;
			break;
		case TIM_A_3:
			TA3CTL &= ~TAIE;
			break;
		default:
			TA3CTL |= DEFAULT_SELECTION;
			break;
}

uint8_t read_interrupt_flag_timer_Ax(uint8_t timerNum){
	switch(timerNum){
		case TIM_A_0:
			return (TA0CTL & TAIFG);
			break;
		case TIM_A_1:
			return (TA1CTL & TAIFG);
			break;
		case TIM_A_2:
			return (TA2CTL & TAIFG);
			break;
		case TIM_A_3:
			return (TA3CTL & TAIFG);
			break;
		default:// may want to return some sort of timer error code. 
			return DEFAULT_SELECTION;
			break;
}

uint16_t read_timer_count_value_timer_Ax(uint8_t timerNum){
	switch(timerNum){
		case TIM_A_0:
			return (TA0R);
			break;
		case TIM_A_1:
			return (TA1R);
			break;
		case TIM_A_2:
			return (TA2R);
			break;
		case TIM_A_3:
			return (TA3R);
			break;
		default:// may want to return some sort of timer error code. 
			return DEFAULT_SELECTION;
			break;
}






















