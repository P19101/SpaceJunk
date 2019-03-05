/**
 * @file timer_A.c
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief source file containing hardware specific functions for the type A timer
 * 		modules.
 */
#include "timer_A.h"

void select_clock_source_timer_Ax(uint8_t timerNum, uint8_t clockSource){
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
			switch(div){
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
			switch(div){
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
			switch(div){
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
			switch(div){
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
			switch(opMode){
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
			switch(opMode){
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
			switch(opMode){
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
			switch(opMode){
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
}

void set_capture_mode_timer_Ax(uint8_t timerNum, uint8_t captureEdge, uint8_t captureChannel){
    switch(timerNum){
        case TIM_A_0:
            switch(captureChannel){
                // CCTL0
                case CHANNEL_0:
                    // Clear the bits first
                    TA0CCTL0 &= ~(CM1 | CM0);
                    switch(captureEdge){
                        case NO_CAPTURE:
                            TA0CCTL0 |= CM_0;
                            break;
                        case RISING_EDGE:
                            TA0CCTL0 |= CM_1;
                            break;
                        case FALLING_EDGE:
                            TA0CCTL0 |= CM_2;
                            break;
                        case DOUBLE_EDGE:
                            TA0CCTL0 |= CM_3;
                            break;
                    }
                    break;
                //CCTL1
                case CHANNEL_1:
                    // Clear the bits first
                    TA0CCTL1 &= ~(CM1 | CM0);
                    switch(captureEdge){
                        case NO_CAPTURE:
                            TA0CCTL1 |= CM_0;
                            break;
                        case RISING_EDGE:
                            TA0CCTL1 |= CM_1;
                            break;
                        case FALLING_EDGE:
                            TA0CCTL1 |= CM_2;
                            break;
                        case DOUBLE_EDGE:
                            TA0CCTL1 |= CM_3;
                            break;
                    }
                    break;
                //CCTL2
                case CHANNEL_2:
                    // Clear the bits first
                    TA0CCTL2 &= ~(CM1 | CM0);
                    switch(captureEdge){
                        case NO_CAPTURE:
                            TA0CCTL2 |= CM_0;
                            break;
                        case RISING_EDGE:
                            TA0CCTL2 |= CM_1;
                            break;
                        case FALLING_EDGE:
                            TA0CCTL2 |= CM_2;
                            break;
                        case DOUBLE_EDGE:
                            TA0CCTL2 |= CM_3;
                            break;
                    }
                    break;
                //CCTL3
                case CHANNEL_3:
                    // Clear the bits first
                    TA0CCTL3 &= ~(CM1 | CM0);
                    switch(captureEdge){
                        case NO_CAPTURE:
                            TA0CCTL3 |= CM_0;
                            break;
                        case RISING_EDGE:
                            TA0CCTL3 |= CM_1;
                            break;
                        case FALLING_EDGE:
                            TA0CCTL3 |= CM_2;
                            break;
                        case DOUBLE_EDGE:
                            TA0CCTL3 |= CM_3;
                            break;
                    }
                    break;
                //CCTL4
                case CHANNEL_4:
                    // Clear the bits first
                    TA0CCTL4 &= ~(CM1 | CM0);
                    switch(captureEdge){
                        case NO_CAPTURE:
                            TA0CCTL4 |= CM_0;
                            break;
                        case RISING_EDGE:
                            TA0CCTL4 |= CM_1;
                            break;
                        case FALLING_EDGE:
                            TA0CCTL4 |= CM_2;
                            break;
                        case DOUBLE_EDGE:
                            TA0CCTL4 |= CM_3;
                            break;
                    }
                    break;
                //CCTL5
                case CHANNEL_5:
                    // Clear the bits first
                    TA0CCTL5 &= ~(CM1 | CM0);
                    switch(captureEdge){
                        case NO_CAPTURE:
                            TA0CCTL5 |= CM_0;
                            break;
                        case RISING_EDGE:
                            TA0CCTL5 |= CM_1;
                            break;
                        case FALLING_EDGE:
                            TA0CCTL5 |= CM_2;
                            break;
                        case DOUBLE_EDGE:
                            TA0CCTL5 |= CM_3;
                            break;
                    }
                    break;
                //CCTL6
                case CHANNEL_6:
                    // Clear the bits first
                    TA0CCTL6 &= ~(CM1 | CM0);
                    switch(captureEdge){
                        case NO_CAPTURE:
                            TA0CCTL6 |= CM_0;
                            break;
                        case RISING_EDGE:
                            TA0CCTL6 |= CM_1;
                            break;
                        case FALLING_EDGE:
                            TA0CCTL6 |= CM_2;
                            break;
                        case DOUBLE_EDGE:
                            TA0CCTL6 |= CM_3;
                            break;
                    }
                    break;
            }
            
            break;
        case TIM_A_1:
            switch(captureChannel){
                // CCTL0
                case CHANNEL_0:
                    // Clear the bits first
                    TA1CCTL0 &= ~(CM1 | CM0);
                    switch(captureEdge){
                        case NO_CAPTURE:
                            TA1CCTL0 |= CM_0;
                            break;
                        case RISING_EDGE:
                            TA1CCTL0 |= CM_1;
                            break;
                        case FALLING_EDGE:
                            TA1CCTL0 |= CM_2;
                            break;
                        case DOUBLE_EDGE:
                            TA1CCTL0 |= CM_3;
                            break;
                    }
                    break;
                //CCTL1
                case CHANNEL_1:
                    // Clear the bits first
                    TA1CCTL1 &= ~(CM1 | CM0);
                    switch(captureEdge){
                        case NO_CAPTURE:
                            TA1CCTL1 |= CM_0;
                            break;
                        case RISING_EDGE:
                            TA1CCTL1 |= CM_1;
                            break;
                        case FALLING_EDGE:
                            TA1CCTL1 |= CM_2;
                            break;
                        case DOUBLE_EDGE:
                            TA1CCTL1 |= CM_3;
                            break;
                    }
                    break;
                //CCTL2
                case CHANNEL_2:
                    // Clear the bits first
                    TA1CCTL2 &= ~(CM1 | CM0);
                    switch(captureEdge){
                        case NO_CAPTURE:
                            TA1CCTL2 |= CM_0;
                            break;
                        case RISING_EDGE:
                            TA1CCTL2 |= CM_1;
                            break;
                        case FALLING_EDGE:
                            TA1CCTL2 |= CM_2;
                            break;
                        case DOUBLE_EDGE:
                            TA1CCTL2 |= CM_3;
                            break;
                    }
                    break;
                //CCTL3
                case CHANNEL_3:
                    // Clear the bits first
                    TA1CCTL3 &= ~(CM1 | CM0);
                    switch(captureEdge){
                        case NO_CAPTURE:
                            TA1CCTL3 |= CM_0;
                            break;
                        case RISING_EDGE:
                            TA1CCTL3 |= CM_1;
                            break;
                        case FALLING_EDGE:
                            TA1CCTL3 |= CM_2;
                            break;
                        case DOUBLE_EDGE:
                            TA1CCTL3 |= CM_3;
                            break;
                    }
                    break;
                //CCTL4
                case CHANNEL_4:
                    // Clear the bits first
                    TA1CCTL4 &= ~(CM1 | CM0);
                    switch(captureEdge){
                        case NO_CAPTURE:
                            TA1CCTL4 |= CM_0;
                            break;
                        case RISING_EDGE:
                            TA1CCTL4 |= CM_1;
                            break;
                        case FALLING_EDGE:
                            TA1CCTL4 |= CM_2;
                            break;
                        case DOUBLE_EDGE:
                            TA1CCTL4 |= CM_3;
                            break;
                    }
                    break;
                //CCTL5
                case CHANNEL_5:
                    // Clear the bits first
                    TA1CCTL5 &= ~(CM1 | CM0);
                    switch(captureEdge){
                        case NO_CAPTURE:
                            TA1CCTL5 |= CM_0;
                            break;
                        case RISING_EDGE:
                            TA1CCTL5 |= CM_1;
                            break;
                        case FALLING_EDGE:
                            TA1CCTL5 |= CM_2;
                            break;
                        case DOUBLE_EDGE:
                            TA1CCTL5 |= CM_3;
                            break;
                    }
                    break;
                //CCTL6
                case CHANNEL_6:
                    // Clear the bits first
                    TA1CCTL6 &= ~(CM1 | CM0);
                    switch(captureEdge){
                        case NO_CAPTURE:
                            TA1CCTL6 |= CM_0;
                            break;
                        case RISING_EDGE:
                            TA1CCTL6 |= CM_1;
                            break;
                        case FALLING_EDGE:
                            TA1CCTL6 |= CM_2;
                            break;
                        case DOUBLE_EDGE:
                            TA1CCTL6 |= CM_3;
                            break;
                    }
                    break;
            }
            
            break;
        case TIM_A_2:
            switch(captureChannel){
                // CCTL0
                case CHANNEL_0:
                    // Clear the bits first
                    TA2CCTL0 &= ~(CM1 | CM0);
                    switch(captureEdge){
                        case NO_CAPTURE:
                            TA2CCTL0 |= CM_0;
                            break;
                        case RISING_EDGE:
                            TA2CCTL0 |= CM_1;
                            break;
                        case FALLING_EDGE:
                            TA2CCTL0 |= CM_2;
                            break;
                        case DOUBLE_EDGE:
                            TA2CCTL0 |= CM_3;
                            break;
                    }
                    break;
                //CCTL1
                case CHANNEL_1:
                    // Clear the bits first
                    TA2CCTL1 &= ~(CM1 | CM0);
                    switch(captureEdge){
                        case NO_CAPTURE:
                            TA2CCTL1 |= CM_0;
                            break;
                        case RISING_EDGE:
                            TA2CCTL1 |= CM_1;
                            break;
                        case FALLING_EDGE:
                            TA2CCTL1 |= CM_2;
                            break;
                        case DOUBLE_EDGE:
                            TA2CCTL1 |= CM_3;
                            break;
                    }
                    break;
                //CCTL2
                case CHANNEL_2:
                    // Clear the bits first
                    TA2CCTL2 &= ~(CM1 | CM0);
                    switch(captureEdge){
                        case NO_CAPTURE:
                            TA2CCTL2 |= CM_0;
                            break;
                        case RISING_EDGE:
                            TA2CCTL2 |= CM_1;
                            break;
                        case FALLING_EDGE:
                            TA2CCTL2 |= CM_2;
                            break;
                        case DOUBLE_EDGE:
                            TA2CCTL2 |= CM_3;
                            break;
                    }
                    break;
                //CCTL3
                case CHANNEL_3:
                    // Clear the bits first
                    TA2CCTL3 &= ~(CM1 | CM0);
                    switch(captureEdge){
                        case NO_CAPTURE:
                            TA2CCTL3 |= CM_0;
                            break;
                        case RISING_EDGE:
                            TA2CCTL3 |= CM_1;
                            break;
                        case FALLING_EDGE:
                            TA2CCTL3 |= CM_2;
                            break;
                        case DOUBLE_EDGE:
                            TA2CCTL3 |= CM_3;
                            break;
                    }
                    break;
                //CCTL4
                case CHANNEL_4:
                    // Clear the bits first
                    TA2CCTL4 &= ~(CM1 | CM0);
                    switch(captureEdge){
                        case NO_CAPTURE:
                            TA2CCTL4 |= CM_0;
                            break;
                        case RISING_EDGE:
                            TA2CCTL4 |= CM_1;
                            break;
                        case FALLING_EDGE:
                            TA2CCTL4 |= CM_2;
                            break;
                        case DOUBLE_EDGE:
                            TA2CCTL4 |= CM_3;
                            break;
                    }
                    break;
                //CCTL5
                case CHANNEL_5:
                    // Clear the bits first
                    TA2CCTL5 &= ~(CM1 | CM0);
                    switch(captureEdge){
                        case NO_CAPTURE:
                            TA2CCTL5 |= CM_0;
                            break;
                        case RISING_EDGE:
                            TA2CCTL5 |= CM_1;
                            break;
                        case FALLING_EDGE:
                            TA2CCTL5 |= CM_2;
                            break;
                        case DOUBLE_EDGE:
                            TA2CCTL5 |= CM_3;
                            break;
                    }
                    break;
                //CCTL6
                case CHANNEL_6:
                    // Clear the bits first
                    TA2CCTL6 &= ~(CM1 | CM0);
                    switch(captureEdge){
                        case NO_CAPTURE:
                            TA2CCTL6 |= CM_0;
                            break;
                        case RISING_EDGE:
                            TA2CCTL6 |= CM_1;
                            break;
                        case FALLING_EDGE:
                            TA2CCTL6 |= CM_2;
                            break;
                        case DOUBLE_EDGE:
                            TA2CCTL6 |= CM_3;
                            break;
                    }
                    break;
            }
            
            break;
        case TIM_A_3:
            switch(captureChannel){
                // CCTL0
                case CHANNEL_0:
                    // Clear the bits first
                    TA3CCTL0 &= ~(CM1 | CM0);
                    switch(captureEdge){
                        case NO_CAPTURE:
                            TA3CCTL0 |= CM_0;
                            break;
                        case RISING_EDGE:
                            TA3CCTL0 |= CM_1;
                            break;
                        case FALLING_EDGE:
                            TA3CCTL0 |= CM_2;
                            break;
                        case DOUBLE_EDGE:
                            TA3CCTL0 |= CM_3;
                            break;
                    }
                    break;
                //CCTL1
                case CHANNEL_1:
                    // Clear the bits first
                    TA3CCTL1 &= ~(CM1 | CM0);
                    switch(captureEdge){
                        case NO_CAPTURE:
                            TA3CCTL1 |= CM_0;
                            break;
                        case RISING_EDGE:
                            TA3CCTL1 |= CM_1;
                            break;
                        case FALLING_EDGE:
                            TA3CCTL1 |= CM_2;
                            break;
                        case DOUBLE_EDGE:
                            TA3CCTL1 |= CM_3;
                            break;
                    }
                    break;
                //CCTL2
                case CHANNEL_2:
                    // Clear the bits first
                    TA3CCTL2 &= ~(CM1 | CM0);
                    switch(captureEdge){
                        case NO_CAPTURE:
                            TA3CCTL2 |= CM_0;
                            break;
                        case RISING_EDGE:
                            TA3CCTL2 |= CM_1;
                            break;
                        case FALLING_EDGE:
                            TA3CCTL2 |= CM_2;
                            break;
                        case DOUBLE_EDGE:
                            TA3CCTL2 |= CM_3;
                            break;
                    }
                    break;
                //CCTL3
                case CHANNEL_3:
                    // Clear the bits first
                    TA3CCTL3 &= ~(CM1 | CM0);
                    switch(captureEdge){
                        case NO_CAPTURE:
                            TA3CCTL3 |= CM_0;
                            break;
                        case RISING_EDGE:
                            TA3CCTL3 |= CM_1;
                            break;
                        case FALLING_EDGE:
                            TA3CCTL3 |= CM_2;
                            break;
                        case DOUBLE_EDGE:
                            TA3CCTL3 |= CM_3;
                            break;
                    }
                    break;
                //CCTL4
                case CHANNEL_4:
                    // Clear the bits first
                    TA3CCTL4 &= ~(CM1 | CM0);
                    switch(captureEdge){
                        case NO_CAPTURE:
                            TA3CCTL4 |= CM_0;
                            break;
                        case RISING_EDGE:
                            TA3CCTL4 |= CM_1;
                            break;
                        case FALLING_EDGE:
                            TA3CCTL4 |= CM_2;
                            break;
                        case DOUBLE_EDGE:
                            TA3CCTL4 |= CM_3;
                            break;
                    }
                    break;
                //CCTL5
                case CHANNEL_5:
                    // Clear the bits first
                    TA3CCTL5 &= ~(CM1 | CM0);
                    switch(captureEdge){
                        case NO_CAPTURE:
                            TA3CCTL5 |= CM_0;
                            break;
                        case RISING_EDGE:
                            TA3CCTL5 |= CM_1;
                            break;
                        case FALLING_EDGE:
                            TA3CCTL5 |= CM_2;
                            break;
                        case DOUBLE_EDGE:
                            TA3CCTL5 |= CM_3;
                            break;
                    }
                    break;
                //CCTL6
                case CHANNEL_6:
                    // Clear the bits first
                    TA3CCTL6 &= ~(CM1 | CM0);
                    switch(captureEdge){
                        case NO_CAPTURE:
                            TA3CCTL6 |= CM_0;
                            break;
                        case RISING_EDGE:
                            TA3CCTL6 |= CM_1;
                            break;
                        case FALLING_EDGE:
                            TA3CCTL6 |= CM_2;
                            break;
                        case DOUBLE_EDGE:
                            TA3CCTL6 |= CM_3;
                            break;
                    }
                    break;
            }
            
            break;
    }
}

void set_capture_compare_input_source_timer_Ax(uint8_t timerNum, uint8_t captureEdge, uint8_t captureChannel){
    switch(timerNum){
        case TIM_A_0:
            switch(captureChannel){
                // CCTL0
                case CHANNEL_0:
                    // Clear the bits first
                    TA0CCTL0 &= ~(CCIS1 | CCIS0);
                    switch(captureEdge){
                        case INPUT_A:
                            TA0CCTL0 |= CCIS_0;
                            break;
                        case INPUT_B:
                            TA0CCTL0 |= CCIS_1;
                            break;
                        case INPUT_GND:
                            TA0CCTL0 |= CCIS_2;
                            break;
                        case INPUT_VCC:
                            TA0CCTL0 |= CCIS_3;
                            break;
                    }
                    break;
                //CCTL1
                case CHANNEL_1:
                    // Clear the bits first
                    TA0CCTL1 &= ~(CCIS1 | CCIS0);
                    switch(captureEdge){
                        case INPUT_A:
                            TA0CCTL1 |= CCIS_0;
                            break;
                        case INPUT_B:
                            TA0CCTL1 |= CCIS_1;
                            break;
                        case INPUT_GND:
                            TA0CCTL1 |= CCIS_2;
                            break;
                        case INPUT_VCC:
                            TA0CCTL1 |= CCIS_3;
                            break;
                    }
                    break;
                //CCTL2
                case CHANNEL_2:
                    // Clear the bits first
                    TA0CCTL2 &= ~(CCIS1 | CCIS0);
                    switch(captureEdge){
                        case INPUT_A:
                            TA0CCTL2 |= CCIS_0;
                            break;
                        case INPUT_B:
                            TA0CCTL2 |= CCIS_1;
                            break;
                        case INPUT_GND:
                            TA0CCTL2 |= CCIS_2;
                            break;
                        case INPUT_VCC:
                            TA0CCTL2 |= CCIS_3;
                            break;
                    }
                    break;
                //CCTL3
                case CHANNEL_3:
                    // Clear the bits first
                    TA0CCTL3 &= ~(CCIS1 | CCIS0);
                    switch(captureEdge){
                        case INPUT_A:
                            TA0CCTL3 |= CCIS_0;
                            break;
                        case INPUT_B:
                            TA0CCTL3 |= CCIS_1;
                            break;
                        case INPUT_GND:
                            TA0CCTL3 |= CCIS_2;
                            break;
                        case INPUT_VCC:
                            TA0CCTL3 |= CCIS_3;
                            break;
                    }
                    break;
                //CCTL4
                case CHANNEL_4:
                    // Clear the bits first
                    TA0CCTL4 &= ~(CCIS1 | CCIS0);
                    switch(captureEdge){
                        case INPUT_A:
                            TA0CCTL4 |= CCIS_0;
                            break;
                        case INPUT_B:
                            TA0CCTL4 |= CCIS_1;
                            break;
                        case INPUT_GND:
                            TA0CCTL4 |= CCIS_2;
                            break;
                        case INPUT_VCC:
                            TA0CCTL4 |= CCIS_3;
                            break;
                    }
                    break;
                //CCTL5
                case CHANNEL_5:
                    // Clear the bits first
                    TA0CCTL5 &= ~(CCIS1 | CCIS0);
                    switch(captureEdge){
                        case INPUT_A:
                            TA0CCTL5 |= CCIS_0;
                            break;
                        case INPUT_B:
                            TA0CCTL5 |= CCIS_1;
                            break;
                        case INPUT_GND:
                            TA0CCTL5 |= CCIS_2;
                            break;
                        case INPUT_VCC:
                            TA0CCTL5 |= CCIS_3;
                            break;
                    }
                    break;
                //CCTL6
                case CHANNEL_6:
                    // Clear the bits first
                    TA0CCTL6 &= ~(CCIS1 | CCIS0);
                    switch(captureEdge){
                        case INPUT_A:
                            TA0CCTL6 |= CCIS_0;
                            break;
                        case INPUT_B:
                            TA0CCTL6 |= CCIS_1;
                            break;
                        case INPUT_GND:
                            TA0CCTL6 |= CCIS_2;
                            break;
                        case INPUT_VCC:
                            TA0CCTL6 |= CCIS_3;
                            break;
                    }
                    break;
            }
            
            break;
        case TIM_A_1:
            switch(captureChannel){
                // CCTL0
                case CHANNEL_0:
                    // Clear the bits first
                    TA1CCTL0 &= ~(CCIS1 | CCIS0);
                    switch(captureEdge){
                        case INPUT_A:
                            TA1CCTL0 |= CCIS_0;
                            break;
                        case INPUT_B:
                            TA1CCTL0 |= CCIS_1;
                            break;
                        case INPUT_GND:
                            TA1CCTL0 |= CCIS_2;
                            break;
                        case INPUT_VCC:
                            TA1CCTL0 |= CCIS_3;
                            break;
                    }
                    break;
                //CCTL1
                case CHANNEL_1:
                    // Clear the bits first
                    TA1CCTL1 &= ~(CCIS1 | CCIS0);
                    switch(captureEdge){
                        case INPUT_A:
                            TA1CCTL1 |= CCIS_0;
                            break;
                        case INPUT_B:
                            TA1CCTL1 |= CCIS_1;
                            break;
                        case INPUT_GND:
                            TA1CCTL1 |= CCIS_2;
                            break;
                        case INPUT_VCC:
                            TA1CCTL1 |= CCIS_3;
                            break;
                    }
                    break;
                //CCTL2
                case CHANNEL_2:
                    // Clear the bits first
                    TA1CCTL2 &= ~(CCIS1 | CCIS0);
                    switch(captureEdge){
                        case INPUT_A:
                            TA1CCTL2 |= CCIS_0;
                            break;
                        case INPUT_B:
                            TA1CCTL2 |= CCIS_1;
                            break;
                        case INPUT_GND:
                            TA1CCTL2 |= CCIS_2;
                            break;
                        case INPUT_VCC:
                            TA1CCTL2 |= CCIS_3;
                            break;
                    }
                    break;
                //CCTL3
                case CHANNEL_3:
                    // Clear the bits first
                    TA1CCTL3 &= ~(CCIS1 | CCIS0);
                    switch(captureEdge){
                        case INPUT_A:
                            TA1CCTL3 |= CCIS_0;
                            break;
                        case INPUT_B:
                            TA1CCTL3 |= CCIS_1;
                            break;
                        case INPUT_GND:
                            TA1CCTL3 |= CCIS_2;
                            break;
                        case INPUT_VCC:
                            TA1CCTL3 |= CCIS_3;
                            break;
                    }
                    break;
                //CCTL4
                case CHANNEL_4:
                    // Clear the bits first
                    TA1CCTL4 &= ~(CCIS1 | CCIS0);
                    switch(captureEdge){
                        case INPUT_A:
                            TA1CCTL4 |= CCIS_0;
                            break;
                        case INPUT_B:
                            TA1CCTL4 |= CCIS_1;
                            break;
                        case INPUT_GND:
                            TA1CCTL4 |= CCIS_2;
                            break;
                        case INPUT_VCC:
                            TA1CCTL4 |= CCIS_3;
                            break;
                    }
                    break;
                //CCTL5
                case CHANNEL_5:
                    // Clear the bits first
                    TA1CCTL5 &= ~(CCIS1 | CCIS0);
                    switch(captureEdge){
                        case INPUT_A:
                            TA1CCTL5 |= CCIS_0;
                            break;
                        case INPUT_B:
                            TA1CCTL5 |= CCIS_1;
                            break;
                        case INPUT_GND:
                            TA1CCTL5 |= CCIS_2;
                            break;
                        case INPUT_VCC:
                            TA1CCTL5 |= CCIS_3;
                            break;
                    }
                    break;
                //CCTL6
                case CHANNEL_6:
                    // Clear the bits first
                    TA1CCTL6 &= ~(CCIS1 | CCIS0);
                    switch(captureEdge){
                        case INPUT_A:
                            TA1CCTL6 |= CCIS_0;
                            break;
                        case INPUT_B:
                            TA1CCTL6 |= CCIS_1;
                            break;
                        case INPUT_GND:
                            TA1CCTL6 |= CCIS_2;
                            break;
                        case INPUT_VCC:
                            TA1CCTL6 |= CCIS_3;
                            break;
                    }
                    break;
            }
            
            break;
        case TIM_A_2:
            switch(captureChannel){
                // CCTL0
                case CHANNEL_0:
                    // Clear the bits first
                    TA2CCTL0 &= ~(CCIS1 | CCIS0);
                    switch(captureEdge){
                        case INPUT_A:
                            TA2CCTL0 |= CCIS_0;
                            break;
                        case INPUT_B:
                            TA2CCTL0 |= CCIS_1;
                            break;
                        case INPUT_GND:
                            TA2CCTL0 |= CCIS_2;
                            break;
                        case INPUT_VCC:
                            TA2CCTL0 |= CCIS_3;
                            break;
                    }
                    break;
                //CCTL1
                case CHANNEL_1:
                    // Clear the bits first
                    TA2CCTL1 &= ~(CCIS1 | CCIS0);
                    switch(captureEdge){
                        case INPUT_A:
                            TA2CCTL1 |= CCIS_0;
                            break;
                        case INPUT_B:
                            TA2CCTL1 |= CCIS_1;
                            break;
                        case INPUT_GND:
                            TA2CCTL1 |= CCIS_2;
                            break;
                        case INPUT_VCC:
                            TA2CCTL1 |= CCIS_3;
                            break;
                    }
                    break;
                //CCTL2
                case CHANNEL_2:
                    // Clear the bits first
                    TA2CCTL2 &= ~(CCIS1 | CCIS0);
                    switch(captureEdge){
                        case INPUT_A:
                            TA2CCTL2 |= CCIS_0;
                            break;
                        case INPUT_B:
                            TA2CCTL2 |= CCIS_1;
                            break;
                        case INPUT_GND:
                            TA2CCTL2 |= CCIS_2;
                            break;
                        case INPUT_VCC:
                            TA2CCTL2 |= CCIS_3;
                            break;
                    }
                    break;
                //CCTL3
                case CHANNEL_3:
                    // Clear the bits first
                    TA2CCTL3 &= ~(CCIS1 | CCIS0);
                    switch(captureEdge){
                        case INPUT_A:
                            TA2CCTL3 |= CCIS_0;
                            break;
                        case INPUT_B:
                            TA2CCTL3 |= CCIS_1;
                            break;
                        case INPUT_GND:
                            TA2CCTL3 |= CCIS_2;
                            break;
                        case INPUT_VCC:
                            TA2CCTL3 |= CCIS_3;
                            break;
                    }
                    break;
                //CCTL4
                case CHANNEL_4:
                    // Clear the bits first
                    TA2CCTL4 &= ~(CCIS1 | CCIS0);
                    switch(captureEdge){
                        case INPUT_A:
                            TA2CCTL4 |= CCIS_0;
                            break;
                        case INPUT_B:
                            TA2CCTL4 |= CCIS_1;
                            break;
                        case INPUT_GND:
                            TA2CCTL4 |= CCIS_2;
                            break;
                        case INPUT_VCC:
                            TA2CCTL4 |= CCIS_3;
                            break;
                    }
                    break;
                //CCTL5
                case CHANNEL_5:
                    // Clear the bits first
                    TA2CCTL5 &= ~(CCIS1 | CCIS0);
                    switch(captureEdge){
                        case INPUT_A:
                            TA2CCTL5 |= CCIS_0;
                            break;
                        case INPUT_B:
                            TA2CCTL5 |= CCIS_1;
                            break;
                        case INPUT_GND:
                            TA2CCTL5 |= CCIS_2;
                            break;
                        case INPUT_VCC:
                            TA2CCTL5 |= CCIS_3;
                            break;
                    }
                    break;
                //CCTL6
                case CHANNEL_6:
                    // Clear the bits first
                    TA2CCTL6 &= ~(CCIS1 | CCIS0);
                    switch(captureEdge){
                        case INPUT_A:
                            TA2CCTL6 |= CCIS_0;
                            break;
                        case INPUT_B:
                            TA2CCTL6 |= CCIS_1;
                            break;
                        case INPUT_GND:
                            TA2CCTL6 |= CCIS_2;
                            break;
                        case INPUT_VCC:
                            TA2CCTL6 |= CCIS_3;
                            break;
                    }
                    break;
            }
            
            break;
        case TIM_A_3:
            switch(captureChannel){
                // CCTL0
                case CHANNEL_0:
                    // Clear the bits first
                    TA3CCTL0 &= ~(CCIS1 | CCIS0);
                    switch(captureEdge){
                        case INPUT_A:
                            TA3CCTL0 |= CCIS_0;
                            break;
                        case INPUT_B:
                            TA3CCTL0 |= CCIS_1;
                            break;
                        case INPUT_GND:
                            TA3CCTL0 |= CCIS_2;
                            break;
                        case INPUT_VCC:
                            TA3CCTL0 |= CCIS_3;
                            break;
                    }
                    break;
                //CCTL1
                case CHANNEL_1:
                    // Clear the bits first
                    TA3CCTL1 &= ~(CCIS1 | CCIS0);
                    switch(captureEdge){
                        case INPUT_A:
                            TA3CCTL1 |= CCIS_0;
                            break;
                        case INPUT_B:
                            TA3CCTL1 |= CCIS_1;
                            break;
                        case INPUT_GND:
                            TA3CCTL1 |= CCIS_2;
                            break;
                        case INPUT_VCC:
                            TA3CCTL1 |= CCIS_3;
                            break;
                    }
                    break;
                //CCTL2
                case CHANNEL_2:
                    // Clear the bits first
                    TA3CCTL2 &= ~(CCIS1 | CCIS0);
                    switch(captureEdge){
                        case INPUT_A:
                            TA3CCTL2 |= CCIS_0;
                            break;
                        case INPUT_B:
                            TA3CCTL2 |= CCIS_1;
                            break;
                        case INPUT_GND:
                            TA3CCTL2 |= CCIS_2;
                            break;
                        case INPUT_VCC:
                            TA3CCTL2 |= CCIS_3;
                            break;
                    }
                    break;
                //CCTL3
                case CHANNEL_3:
                    // Clear the bits first
                    TA3CCTL3 &= ~(CCIS1 | CCIS0);
                    switch(captureEdge){
                        case INPUT_A:
                            TA3CCTL3 |= CCIS_0;
                            break;
                        case INPUT_B:
                            TA3CCTL3 |= CCIS_1;
                            break;
                        case INPUT_GND:
                            TA3CCTL3 |= CCIS_2;
                            break;
                        case INPUT_VCC:
                            TA3CCTL3 |= CCIS_3;
                            break;
                    }
                    break;
                //CCTL4
                case CHANNEL_4:
                    // Clear the bits first
                    TA3CCTL4 &= ~(CCIS1 | CCIS0);
                    switch(captureEdge){
                        case INPUT_A:
                            TA3CCTL4 |= CCIS_0;
                            break;
                        case INPUT_B:
                            TA3CCTL4 |= CCIS_1;
                            break;
                        case INPUT_GND:
                            TA3CCTL4 |= CCIS_2;
                            break;
                        case INPUT_VCC:
                            TA3CCTL4 |= CCIS_3;
                            break;
                    }
                    break;
                //CCTL5
                case CHANNEL_5:
                    // Clear the bits first
                    TA3CCTL5 &= ~(CCIS1 | CCIS0);
                    switch(captureEdge){
                        case INPUT_A:
                            TA3CCTL5 |= CCIS_0;
                            break;
                        case INPUT_B:
                            TA3CCTL5 |= CCIS_1;
                            break;
                        case INPUT_GND:
                            TA3CCTL5 |= CCIS_2;
                            break;
                        case INPUT_VCC:
                            TA3CCTL5 |= CCIS_3;
                            break;
                    }
                    break;
                //CCTL6
                case CHANNEL_6:
                    // Clear the bits first
                    TA3CCTL6 &= ~(CCIS1 | CCIS0);
                    switch(captureEdge){
                        case INPUT_A:
                            TA3CCTL6 |= CCIS_0;
                            break;
                        case INPUT_B:
                            TA3CCTL6 |= CCIS_1;
                            break;
                        case INPUT_GND:
                            TA3CCTL6 |= CCIS_2;
                            break;
                        case INPUT_VCC:
                            TA3CCTL6 |= CCIS_3;
                            break;
                    }
                    break;
            }
            
            break;
    }
}


















