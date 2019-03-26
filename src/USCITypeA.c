/**
 * @file uart.c
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


/*******************************************************************************/
