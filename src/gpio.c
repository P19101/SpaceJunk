/*
 * @file gpio.c
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief File containing function for programming the GPIO ports
 */

#include "gpio.h"
#include "commonHeader.h"


uint8_t read_GPIO_input_pin(uint8_t port, uint8_t pin){
    switch(port){
        case PORT_1:
            return (P1IN & pin);
        case PORT_2:
            return (P2IN & pin);
        case PORT_3:
            return (P3IN & pin);
        case PORT_4:
            return (P4IN & pin);
        case PORT_J:
            return (PJIN & pin);
        default:
            return DEFAULT_SELECTION;
    }
}

uint8_t read_GPIO_output_pin(uint8_t port, uint8_t pin){
    switch(port){
        case PORT_1:
            return (P1OUT & pin);
        case PORT_2:
            return (P2OUT & pin);
        case PORT_3:
            return (P3OUT & pin);
        case PORT_4:
            return (P4OUT & pin);
        case PORT_J:
            return (PJOUT & pin);
        default:
            return DEFAULT_SELECTION;
    }
}

uint8_t read_GPIO_resistor_pull_direction(uint8_t port, uint8_t pin){
    switch(port){
        case PORT_1:
            return (P1OUT & pin);
        case PORT_2:
            return (P2OUT & pin);
        case PORT_3:
            return (P3OUT & pin);
        case PORT_4:
            return (P4OUT & pin);
        case PORT_J:
            return (PJOUT & pin);
        default:
            return DEFAULT_SELECTION;
    }
}

void set_GPIO_resistor_pull_direction(uint8_t port, uint8_t pin, uint8_t pullDirection){
    switch(port){
        case PORT_1:
            if(pullDirection){
                P1OUT |= pin;
            }
            else{
                P1OUT &= ~pin;
            }
            break;
        case PORT_2:
            if(pullDirection){
                P2OUT |= pin;
            }
            else{
                P2OUT &= ~pin;
            }
            break;
        case PORT_3:
            if(pullDirection){
                P3OUT |= pin;
            }
            else{
                P3OUT &= ~pin;
            }
            break;
        case PORT_4:
            if(pullDirection){
                P4OUT |= pin;
            }
            else{
                P4OUT &= ~pin;
            }
            break;
        case PORT_J:
            if(pullDirection){
                PJOUT |= pin;
            }
            else{
                PJOUT &= ~pin;
            }
            break;
        default:
            break;
    }
}

void set_GPIO_pin(uint8_t port, uint8_t pin){
	switch(port){
		case PORT_1:
            P1OUT |= pin;
			break;
        case PORT_2:
            P2OUT |= pin;
			break;
        case PORT_3:
            P3OUT |= pin;
			break;
        case PORT_4:
            P4OUT |= pin;
			break;
        case PORT_J:
            PJOUT |= pin;
            break;
        default:
            break;
	}
}

void clear_GPIO_pin(uint8_t port, uint8_t pin){
	switch(port){
		case PORT_1:
            P1OUT &= ~(pin);
			break;
        case PORT_2:
            P2OUT &= ~(pin);
			break;
        case PORT_3:
            P3OUT &= ~(pin);
			break;
        case PORT_4:
            P4OUT &= ~(pin);
			break;
        case PORT_J:
            PJOUT &= ~(pin);
            break;
        default:
			break;
	}
}

void set_GPIO_pin_output(uint8_t port, uint8_t pin){
	switch(port){
		case PORT_1:
            P1DIR |= pin;
			break;
        case PORT_2:
            P2DIR |= pin;
			break;
        case PORT_3:
            P3DIR |= pin;
			break;
        case PORT_4:
            P4DIR |= pin;
			break;
        case PORT_J:
            PJDIR |= pin;
            break;
        default:
			break;
	}
}

void set_GPIO_pin_input(uint8_t port, uint8_t pin){
	switch(port){
		case PORT_1:
            P1DIR &= ~(pin);
			break;
        case PORT_2:
            P2DIR &= ~(pin);
			break;
        case PORT_3:
            P3DIR &= ~(pin);
			break;
        case PORT_4:
            P4DIR &= ~(pin);
			break;
        case PORT_J:
            PJDIR &= ~(pin);
            break;
        default:
			break;
	}
}
void enable_GPIO_pin_pull_resistor(uint8_t port, uint8_t pin){
    switch(port){
        case PORT_1:
            P1REN |= pin;
            break;
        case PORT_2:
            P2REN |= pin;
            break;
        case PORT_3:
            P3REN |= pin;
            break;
        case PORT_4:
            P4REN |= pin;
            break;
        case PORT_J:
            PJREN |= pin;
            break;
        default:
            break;
    }
}

void disable_GPIO_pin_pull_resistor(uint8_t port , uint8_t pin){
    switch(port){
        case PORT_1:
            P1REN &= ~(pin);
            break;
        case PORT_2:
            P2REN &= ~(pin);
            break;
        case PORT_3:
            P3REN &= ~(pin);
            break;
        case PORT_4:
            P4REN &= ~(pin);
            break;
        case PORT_J:
            PJREN &= ~(pin);
            break;
        default:
            break;
    }
}

void choose_GPIO_function(uint8_t port, uint8_t pin, uint8_t function){
	switch(port){
		case PORT_1:
            switch(function){
				case DEFAULT_GPIO:
					P1SEL0 &= ~(pin);
					P1SEL1 &= ~(pin);
					break;
				case PRIMARY_MOD:
					P1SEL0 |= pin;
					P1SEL1 &= ~(pin);
					break;
				case SECONDARY_MOD:
					P1SEL0 &= ~(pin);
					P1SEL1 |= pin;
					break;
				case TERTIARY_MOD:
					P1SEL0 |= pin;
					P1SEL1 |= pin;
					break;
				default:
					P1SEL0 &= ~(pin);
					P1SEL1 &= ~(pin);
					break;
			}
			break;
        case PORT_2:
            switch(function){
				case DEFAULT_GPIO:
					P2SEL0 &= ~(pin);
					P2SEL1 &= ~(pin);
					break;
				case PRIMARY_MOD:
					P2SEL0 |= pin;
					P2SEL1 &= ~(pin);
					break;
				case SECONDARY_MOD:
					P2SEL0 &= ~(pin);
					P2SEL1 |= pin;
					break;
				case TERTIARY_MOD:
					P2SEL0 |= pin;
					P2SEL1 |= pin;
					break;
				default:
					P2SEL0 &= ~(pin);
					P2SEL1 &= ~(pin);
					break;
			}
			break;
        case PORT_3:
            switch(function){
				case DEFAULT_GPIO:
					P3SEL0 &= ~(pin);
					P3SEL1 &= ~(pin);
					break;
				case PRIMARY_MOD:
					P3SEL0 |= pin;
					P3SEL1 &= ~(pin);
					break;
				case SECONDARY_MOD:
					P3SEL0 &= ~(pin);
					P3SEL1 |= pin;
					break;
				case TERTIARY_MOD:
					P3SEL0 |= pin;
					P3SEL1 |= pin;
					break;
				default:
					P3SEL0 &= ~(pin);
					P3SEL1 &= ~(pin);
					break;
			}
			break;
        case PORT_4:
            switch(function){
				case DEFAULT_GPIO:
					P4SEL0 &= ~(pin);
					P4SEL1 &= ~(pin);
					break;
				case PRIMARY_MOD:
					P4SEL0 |= pin;
					P4SEL1 &= ~(pin);
					break;
				case SECONDARY_MOD:
					P4SEL0 &= ~(pin);
					P4SEL1 |= pin;
					break;
				case TERTIARY_MOD:
					P4SEL0 |= pin;
					P4SEL1 |= pin;
					break;
				default:
					P4SEL0 &= ~(pin);
					P4SEL1 &= ~(pin);
					break;
			}
			break;
        case PORT_J:
            switch(function){
                case DEFAULT_GPIO:
                    PJSEL0 &= ~(pin);
                    PJSEL1 &= ~(pin);
                    break;
                case PRIMARY_MOD:
                    PJSEL0 |= pin;
                    PJSEL1 &= ~(pin);
                    break;
                case SECONDARY_MOD:
                    PJSEL0 &= ~(pin);
                    PJSEL1 |= pin;
                    break;
                case TERTIARY_MOD:
                    PJSEL0 |= pin;
                    PJSEL1 |= pin;
                    break;
                default:
                    PJSEL0 &= ~(pin);
                    PJSEL1 &= ~(pin);
                    break;
            }
            break;
        default:
			break;
	}
}

void choose_interrupt_edge(uint8_t port, uint8_t pin, uint8_t edge){
	switch(port){
		case PORT_1:
			if(edge){
				P1IES |= pin;
			}
			else{
				P1IES &= ~(pin);
			}
			break;
        case PORT_2:
            if(edge){
				P2IES |= pin;
			}
			else{
				P2IES &= ~(pin);
			}
			break;
        case PORT_3:
            if(edge){
				P3IES |= pin;
			}
			else{
				P3IES &= ~(pin);
			}
			break;
        case PORT_4:
            if(edge){
				P4IES |= pin;
			}
			else{
				P4IES &= ~(pin);
			}
			break;
        default:
			break;
	}
}

void enable_GPIO_interrupt(uint8_t port, uint8_t pin){
	switch(port){
		case PORT_1:
            P1IE |= pin;
			break;
        case PORT_2:
            P2IE |= pin;
			break;
        case PORT_3:
            P3IE |= pin;
			break;
        case PORT_4:
            P4IE |= pin;
			break;
        default:
            break;
	}
}

void disable_GPIO_interrupt(uint8_t port, uint8_t pin){
	switch(port){
		case PORT_1:
            P1IE &= ~(pin);
			break;
        case PORT_2:
            P2IE &= ~(pin);
			break;
        case PORT_3:
            P3IE &= ~(pin);
			break;
        case PORT_4:
            P4IE &= ~(pin);
			break;
        default:
			break;
	}
}

uint8_t read_GPIO_interrupt_flag(uint8_t port, uint8_t pin){
	switch(port){
        case PORT_1:
            return (P1IFG & pin);
        case PORT_2:
            return (P2IFG & pin);
        case PORT_3:
            return (P3IFG & pin);
        case PORT_4:
            return (P4IFG & pin);
        default:
            return DEFAULT_SELECTION;
    }
}
