#include <msp430.h> 
#include "systemInit.h"
#include "gpio.h"
#include "msp430fr5969.h"
#include "uart.h"
#include "USCITypeA.h"
#include <stdio.h>
/**
 * main.c
 */


int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	configure_sys();
	uint8_t character = 0x31;
	hold_USCIA_UART_reset();
	choose_USCIA_operation_mode(UART_MODE);
	set_clock_source_USCIA_UART(USCIA_SMCLK);
	select_baud_rate_UART(BAUD_9600);
	//UCA0CTL0 |= UCMSB;
	release_USCIA_UART_reset();
	while(1){
	    while(read_TX_interrupt_flag() == 0);
	    send_byte_UART(character);
	    while(read_RX_interrupt_flag() == 0);
	    character = read_byte_UART();
	}




	return 0;
}
