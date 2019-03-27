/**
 * @file USCITypeA.c
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief source file for configuring Type A USCI which can be used as either a UART
 *      or SPI device. 
 */

#include "USCITypeA.h"

void choose_USCIA_operation_mode(uint8_t mode){
    if(mode){
        UCA0CTL0 |= UCSYNC; // set SPI MODE
    }
    else{
        UCA0CTL0 &= ~UCSYNC; // set UART MODE 
    }
}

/********************UART SPECIFIC FUNCTIONS************************/
void hold_USCIA_reset(void){
    UCA0CTL1 |= UCSWRST;
}

void release_USCIA_reset(void){
    UCA0CTL1 &= ~UCSWRST;
}

void transmit_break_bit_USCIA(void){
    UCA0CTL1 |= UCTXBRK;
}

void clear_break_bit_USCIA(void){
    UCA0CTL1 &= ~UCTXBRK;
}

void set_next_byte_address_USCIA(void){
    UCA0CTL1 |= UCTXADDR;
}

void clear_next_byte_address_USCIA(void){
    UCA0CTL1 &= ~UCTXADDR;
}

void set_dormant_mode_USCIA(void){
    UCA0CTL1 |= UCDORM;
}

void clear_dormant_mode_USCIA(void){
    UCA0CTL1 &= ~UCDORM;
}

void break_interrupt_enabled_USCIA(void){
    UCA0CTL1 |= UCBRKIE;
}

void break_interrupt_diabled_USCIA(void){
    UCA0CTL1 &= ~UCBRKIE;
}

void error_byte_interrupt_enabled_USCIA(void){
    UCA0CTL1 |= UCRXEIE;
}

void error_byte_interrupt_disabled_USCIA(void){
    UCA0CTL1 &= ~UCRXEIE;
}

void set_clock_source_USCIA(uint8_t source){
    UCA0CTL1 &= ~(UCSSEL1 | UCSSEL0);
    switch(source){
        case UCLKI:
            UCA0CTL1 |= DEFAULT_SELECTION;
            break;
        case ACLK:
            UCA0CTL1 |= UCSSEL0;
            break;
        case SMCLK:
            UCA0CTL1 |= UCSSEL1;
            break;
        default:
            UCA0CTL1 |= DEFAULT_SELECTION;
            break;
    }
}

void set_mode_USCIA_UART(uint8_t mode){
    UCA0CTL0 &= ~(UCMODE0 | UCMODE1);
    switch(mode){
        case UART_STANDARD:
            UCA0CTL0 |= DEFAULT_SELECTION;
            break;
        case IDLE_LINE_MULT_PROC:
            UCA0CTL0 |= UCMODE0;
            break;
        case ADDRESS_BIT_MULT_PROC:
            UCA0CTL0 |= UCMODE1;
            break;
        case UART_WITH_AUTO_BAUD_DET:
            UCA0CTL0 |= (UCMODE1 | UCMODE0);
            break;
    }
}

void select_number_stop_bits_USCIA_UART(uint8_t stopBits){
    if(stopBits){
        UCA0CTL0 |= UCSPB;
    }
    else{
        UCA0CTL0 &= ~UCSPB;
    }
}

void select_number_data_bits_USCIA_UART(uint8_t dataBits){
    if(dataBits){
        UCA0CTL0 |= UC7BIT;
    }
    else{
        UCA0CTL0 &= ~UC7BIT; 
    }
}

void select_endianness_USCIA_UART(uint8_t endian){
    if(endian){
        UCA0CTL0 |= UCMSB;
    }
    else{
        UCA0CTL0 &= ~UCMSB;
    }
}

void select_parity_USCIA_UART(uint8_t parity){
    if(parity){
        UCA0CTL0 |= UCPAR;
    }
    else{
        UCA0CTL0 &= ~UCPAR;
    }
}

void enable_parity_check_USCIA_UART(void){
    UCA0CTL0 |= UCPEN;
}

void disable_parity_check_USCIA_UART(void){
    UCA0CTL0 &= ~UCPEN;
}

//void select_deglitch_time_USCIA_UART(uint8_t glitchTime){
    //UCA0CTL0 &= ~();
//}

void set_BR_Int_USCIA_UART(uint16_t baudFactorInt){
    UCA0BRW = baudFactorInt;
}

void choose_oversampling_mode_USCIA_UART(uint8_t oversample){
    if(oversample){
        UCA0MCTLW |= UCOS16;
    }
    else{
        UCA0MCTLW &= ~(UCOS16);
    }
}

void choose_mod_factor_one_USCIA_UART(uint8_t factor){
    uint8_t factorSet;
    UCA0MCTLW &= ~(UCBRF0 | UCBRF1 | UCBRF2 | UCBRF3); // clear the four bits which make up the first mod factor.
    if(factor > (BIT_0 | BIT_1 | BIT_2 | BIT_3)){ //max is 0x0F or 00001111
        factorSet = DEFAULT_SELECTION;
    }
    else{
        factorSet = factor;
    }
    UCA0MCTLW |= factorSet;
    
}

void choose_mod_factor_two_USCIA_UART(uint8_t factor){
    uint16_t factorSet;
    UCA0MCTLW &= ~(BIT_8 | BIT_9 | BIT_10 | BIT_11 | BIT_12 | BIT_13 | BIT_14 | BIT_15); // clear the eight bits for the second mod factor.
    factorSet = factor;
    factorSet = factorSet << HIGH_BYTE_SHIFT; //esure the factor is in the higher byte
    UCA0MCTLW |= (factorSet & HIGH_BYTE);// clear the lower byte while setting to not disrupt other settings.
}

uint8_t read_busy_flag_USCIA_UART(void){
    return (UCA0STATW & UCBUSY);
}

uint8_t read_address_flag_USCIA_UART(void){
    return (UCA0STATW & UCADDR);
}

uint8_t read_idle_line_flag_USCIA_UART(void){
    return (UCA0STATW & UCIDLE);
}

uint8_t read_error_flag_USCIA_UART(void){
    return (UCA0STATW & UCRXERR);
}

uint8_t read_break_condition_USCIA_UART(void){
    return (UCA0STATW & UCBRK);
}

uint8_t read_parity_err_flag_USCIA_UART(void){
    return (UCA0STATW & UCPE);
}

uint8_t read_overrun_flag_USCIA_UART(void){
    return (UCA0STATW & UCOE);
}

uint8_t read_framming_flag_USCIA_UART(void){
    return (UCA0STATW & UCFE);
}

void loopback_mode_USCIA_UART(uint8_t loopback){
    if(loopback){
        UCA0STATW |= UCLISTEN;
    } 
    else{
        UCA0STATW &= ~(UCLISTEN);
    }
}

uint8_t read_RX_buffer(void){
    return UCA0RXBUF;
}

void write_TX_buffer_USCIA_UART(uint8_t data){
	UCA0TXBUF = data;
}

void choose_auto_baud_USCIA_UART(uint8_t autoBaud){
    if(autoBaud){
        UCA0ACBTL |= UCABDEN;
    }
    else{
        UCA0ACBTL &= ~(UCABDEN);
    }
}

uint8_t read_break_err_flag_USCIA_UART(void){
    return (UCA0ACBTL & UCBTOE);
}

uint8_t read_sync_err_flag_USCIA_UART(void){
    return (UCA0ACBTL & UCSTOE);
}

void set_auto_baud_timeout_USCIA_UART(uint8_t timeout){
    UCA0ACBTL &= ~(UCDELIM0 | UCDELIM1); 
    switch(timeout){
        case ONE_BIT_TIME:
            UCA0ACBTL |= DEFAULT_SELECTION;
            break;
        case TWO_BIT_TIME:
            UCA0ACBTL |= UCDELIM0;
            break;
        case THREE_BIT_TIME:
            UCA0ACBTL |= UCDELIM1;
            break;
        case FOUR_BIT_TIME:
            UCA0ACBTL |= (UCDELIM0 | UCDELIM1);
            break;
    }
}

void choose_IrDA_enabled_USCIA_UART(uint8_t enable){
    if(enable){
        UCA0IRCTL |= UCIREN;
    }
    else{
        UCA0IRCTL &= ~(UCIREN);
    }
}

void choose_IrDA_clk_source_USCIA_UART(uint8_t clockSrc){
    if(clockSrc){
        UCA0IRCTL |= UCIRTXCLK;
    }
    else{
        UCA0IRCTL &= ~(UCIRTXCLK);
    }
}

void set_TX_pulse_length_USCIA_UART(uint8_t pulseTime){
	uint16_t pulseSet;
	UCA0IRCTL &= ~ (UCIRTXPL0 | UCIRTXPL1 | UCIRTXPL2 | UCIRTXPL3 | UCIRTXPL4 | UCIRTXPL5);// clear the bits
	if(pulseTime > (BIT_0 | BIT_1 | BIT_2 | BIT_3 | BIT_4 | BIT_5)){
		pulseSet = DEFAULT_SELECTION;
	}
	else{
		pulseSet = (pulseTime << BIT_1); //Shift over by two to fill the bits 7-2
	}
	UCA0IRCTL |= pulseSet;
}

void enable_IrDA_filter_USCIA_UART(uint8_t enabled){
	if(enabled){
		UCA0IRCTL |= UCIRRXFE;
	}
	else{
		UCA0IRCTL &= ~(UCIRRXFE);
	}
}

void set_RX_pulse_polarity_USCIA_UART(uint8_t polarity){
	if(polarity){
		UCA0IRCTL |= UCIRRXPL;
	}
	else{
		UCA0IRCTL &= ~(UCIRRXPL);
	}
}

void set_RX_filter_length_USCIA_UART(uint8_t filtLength){
	uint16_t filtSet;
	UCA0IRCTL &= ~(UCIRRXFL0 | UCIRRXFL1 | UCIRRXFL2 | UCIRRXFL3 | UCIRRXFL4 | UCIRRXFL5);// clear the bits
	if(filtLenght > (BIT_0 | BIT_1 | BIT_2 | BIT_3 | BIT_4 | BIT_5)){
		filtSet = DEFAULT_SELECTION;
	}
	else{
		filtSet = (filtLength << (BIT_3 | BIT_2)); //Shift over by 10 to fill the bits 15-10
	}
	UCA0IRCTL |= filtSet;
}

void set_RX_interrupts_enabled_USCIA_UART(uint8_t enable){
	if(enable){
		UCA0IE |= UCRXIE;
	}
	else{
		UCA0IE &= ~(UCRXIE);
	}
}

void set_TX_interrupts_enabled_USCIA_UART(uint8_t enable){
	if(enable){
		UCA0IE |= UCTXIE;
	}
	else{
		UCA0IE &= ~(UCTXIE);
	}
}

void set_start_bit_itnerrupts_enabled_USCIA_UART(uint8_t enable){
	if(enable){
		UCA0IE |= UCSTTIE;
	}
	else{
		UCA0IE &= ~(UCSTTIE);
	}
}

void set_TX_complete_interrupts_enabled_USCIA_UART(uint8_t enable){
	if(enable){
		UCA0IE |= UCTXCPTIE;
	}
	else{
		UCA0IE &= ~(UCTXCPTIE);
	}
}

uint8_t read_RX_interrupt_flag(void){
	return (UCA0IFG & UCRXIFG);
}

uint8_t read_TX_interrupt_flag(void){
	return (UCA0IFG & UCTXIFG);
}

uint8_t read_start_bit_interrupt_flag(void){
	return (UCA0IFG & UCSTTIFG);
}

uint8_t read_TX_complete_interrupt_flag(void){
	return (UCA0IFG & UCTXCPTIFG);
}


	




/*******************************************************************************/
