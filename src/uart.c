/**
 * @file uart.c
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief source file for configuring Type A USCI which can be used as either a UART
 *      or SPI device. 
 */
 
#include "uart.h"
#include "USCITypeA.h"

uint8_t read_byte_UART(void){
    return read_RX_buffer_USCIA_UART();
}

void send_string_UART(uint8_t dataPtr[], uint16_t size){
	uint16_t counter = 0;
	while(counter < size){
	    while(read_busy_flag_USCIA_UART());
		send_byte_UART(dataPtr[counter]);
		counter++;
	}
}

int8_t read_string_UART(uint8_t dataPtr[], uint16_t size){
	uint16_t counter = 0;
	while(counter < size){
		while(read_RX_interrupt_flag() == OFF); // wait until a byte is read
		//TODO: add timeout for reading data or this is very very bad.
		dataPtr[counter] = read_byte_UART();
		counter++;
		if(read_error_flag_USCIA_UART()){
			if(read_overrun_flag_USCIA_UART()){
				return UART_OVERRUN_ERR;
			}
			else if(read_framming_flag_USCIA_UART()){
				return UART_FRAMMING_ERR;
			}
			else if(read_parity_err_flag_USCIA_UART()){
				return UART_PARITY_ERR;
			}
		}
	}
	return UART_NO_ERR;
}

void select_baud_rate_UART(uint8_t baud){
    // one variable for each of the four registers which controls the baud rate.
    // as of now this function only handles the 32.768kHz clock.
    uint16_t baudInt;
    uint8_t oversample;
    uint8_t modFactorOne;
    uint8_t modFactorTwo;
    switch(baud){
        case BAUD_9600:
            baudInt = 3;
            oversample = ENABLE;
            modFactorOne = 3;
            modFactorTwo = 0x2;
            break;
        // all numbers are taken from the family manual talbe 30-5 and pg 779
        /*
        case BAUD_1200:
            baudInt = 1;
            oversample = ENABLE;
            modFactorOne = 11;
            modFactorTwo = 0x25;
            break;
        case BAUD_2400:
            baudInt = 13;
            oversample = DISABLE;
            modFactorOne = DEFAULT_SELECTION;
            modFactorTwo = 0xB6;
            break;
        case BAUD_4800:
            baudInt = 6;
            oversample = DISABLE;
            modFactorOne = DEFAULT_SELECTION;
            modFactorTwo = 0xEE;
            break;
        case BAUD_9600:
            baudInt = 3;
            oversample = DISABLE;
            modFactorOne = DEFAULT_SELECTION;
            modFactorTwo = 0x92;
            break;
        default:
            baudInt = 0;
            oversample = 0;
            modFactorOne = 0;
            modFactorTwo = 0;
            break;
            */
    }
    set_BR_Int_USCIA_UART(baudInt);
    choose_oversampling_mode_USCIA_UART(oversample);
    choose_mod_factor_one_USCIA_UART(modFactorOne);
    choose_mod_factor_two_USCIA_UART(modFactorTwo);
}

void send_byte_UART(uint8_t data){
    //TODO: add some timeout mechanics with the timers.
    write_TX_buffer_USCIA_UART(data);
}
