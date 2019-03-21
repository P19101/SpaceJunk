/**
 * @file timer_A.c
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief source file containing hardware specific functions for the type A timer
 * 		modules.
 */
#include "timerA.h"

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

		case TIM_A_1:
			return (TA1CTL & TAIFG);

		case TIM_A_2:
			return (TA2CTL & TAIFG);

		case TIM_A_3:
			return (TA3CTL & TAIFG);

		default:// may want to return some sort of timer error code. 
			return DEFAULT_SELECTION;

	}
}

uint16_t read_timer_count_value_timer_Ax(uint8_t timerNum){
	switch(timerNum){
		case TIM_A_0:
			return (TA0R);

		case TIM_A_1:
			return (TA1R);

		case TIM_A_2:
			return (TA2R);

		case TIM_A_3:
			return (TA3R);

		default:// may want to return some sort of timer error code. 
			return DEFAULT_SELECTION;

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
                 }
            
            break;
    }
}

void set_capture_compare_input_source_timer_Ax(uint8_t timerNum, uint8_t captureSource, uint8_t captureChannel){
    switch(timerNum){
        case TIM_A_0:
            switch(captureChannel){
                // CCTL0
                case CHANNEL_0:
                    // Clear the bits first
                    TA0CCTL0 &= ~(CCIS1 | CCIS0);
                    switch(captureSource){
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
                    switch(captureSource){
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
                    switch(captureSource){
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

            }
            
            break;
        case TIM_A_1:
            switch(captureChannel){
                // CCTL0
                case CHANNEL_0:
                    // Clear the bits first
                    TA1CCTL0 &= ~(CCIS1 | CCIS0);
                    switch(captureSource){
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
                    switch(captureSource){
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
                    switch(captureSource){
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

            }
            
            break;
        case TIM_A_2:
            switch(captureChannel){
                // CCTL0
                case CHANNEL_0:
                    // Clear the bits first
                    TA2CCTL0 &= ~(CCIS1 | CCIS0);
                    switch(captureSource){
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
                    switch(captureSource){
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
                }
            
            break;
        case TIM_A_3:
            switch(captureChannel){
                // CCTL0
                case CHANNEL_0:
                    // Clear the bits first
                    TA3CCTL0 &= ~(CCIS1 | CCIS0);
                    switch(captureSource){
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
                    switch(captureSource){
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
                }
            
            break;
    }
}

void select_input_source_sychronisity_timer_Ax(uint8_t timerNum, uint8_t synchronize, uint8_t captureChannel){
    switch(timerNum){
        case TIM_A_0:
            switch(captureChannel){
                // CCTL0
                case CHANNEL_0:
                    if(synchronize){
                        TA0CCTL0 |= SCS;
                    }
                    else{
                        TA0CCTL0 &= ~SCS;
                    }
                    break;
                //CCTL1
                case CHANNEL_1:
                    if(synchronize){
                        TA0CCTL1 |= SCS;
                    }
                    else{
                        TA0CCTL1 &= ~SCS;
                    }
                    break;
                //CCTL2
                case CHANNEL_2:
                    if(synchronize){
                        TA0CCTL2 |= SCS;
                    }
                    else{
                        TA0CCTL2 &= ~SCS;
                    }
                    break;

            }
            
            break;
        case TIM_A_1:
            switch(captureChannel){
                // CCTL0
                case CHANNEL_0:
                    if(synchronize){
                        TA1CCTL0 |= SCS;
                    }
                    else{
                        TA1CCTL0 &= ~SCS;
                    }
                    break;
                //CCTL1
                case CHANNEL_1:
                    if(synchronize){
                        TA1CCTL1 |= SCS;
                    }
                    else{
                        TA1CCTL1 &= ~SCS;
                    }
                    break;
                //CCTL2
                case CHANNEL_2:
                    if(synchronize){
                        TA1CCTL2 |= SCS;
                    }
                    else{
                        TA1CCTL2 &= ~SCS;
                    }
                    break;

            }
            
            break;
        case TIM_A_2:
            switch(captureChannel){
                // CCTL0
                case CHANNEL_0:
                    if(synchronize){
                        TA2CCTL0 |= SCS;
                    }
                    else{
                        TA2CCTL0 &= ~SCS;
                    }
                    break;
                //CCTL1
                case CHANNEL_1:
                    if(synchronize){
                        TA2CCTL1 |= SCS;
                    }
                    else{
                        TA2CCTL1 &= ~SCS;
                    }
                    break;

            }
            
            break;
        case TIM_A_3:
            switch(captureChannel){
                // CCTL0
                case CHANNEL_0:
                    if(synchronize){
                        TA3CCTL0 |= SCS;
                    }
                    else{
                        TA3CCTL0 &= ~SCS;
                    }
                    break;
                //CCTL1
                case CHANNEL_1:
                    if(synchronize){
                        TA3CCTL1 |= SCS;
                    }
                    else{
                        TA3CCTL1 &= ~SCS;
                    }
                    break;

            }
            
            break;
    }
}

uint8_t read_synchronized_bit_timer_Ax(uint8_t timerNum, uint8_t captureChannel){
    switch(timerNum){
        case TIM_A_0:
            switch(captureChannel){
                // CCTL0
                case CHANNEL_0:
                    return (TA0CCTL0 & SCCI);
                //CCTL1
                case CHANNEL_1:
                    return (TA0CCTL1 & SCCI);
                //CCTL2
                case CHANNEL_2:
                    return (TA0CCTL2 & SCCI);

            }
            break;
        case TIM_A_1:
            switch(captureChannel){
                // CCTL0
                case CHANNEL_0:
                    return (TA1CCTL0 & SCCI);
                //CCTL1
                case CHANNEL_1:
                    return (TA1CCTL1 & SCCI);
                //CCTL2
                case CHANNEL_2:
                    return (TA1CCTL2 & SCCI);

            }
            break;
        case TIM_A_2:
            switch(captureChannel){
                // CCTL0
                case CHANNEL_0:
                    return (TA2CCTL0 & SCCI);
                //CCTL1
                case CHANNEL_1:
                    return (TA2CCTL1 & SCCI);

            }
            break;
        case TIM_A_3:
            switch(captureChannel){
                // CCTL0
                case CHANNEL_0:
                    return (TA3CCTL0 & SCCI);
                //CCTL1
                case CHANNEL_1:
                    return (TA3CCTL1 & SCCI);

            }
            break;
        default:
             return DEFAULT_SELECTION;
    }
    return DEFAULT_SELECTION;
}














