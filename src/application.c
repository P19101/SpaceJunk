/** 
 * @file application.c
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief File which utilizes the settings of pinUsage.h to initialize the system
 * 		after a standard reset event. 
 */
#include "application.h"
#include "messageHandler.h"

uint8_t application(void){
	/* stop watchdog timer TODO: this should not be done
	 * and instead the watch dog should be looked at and actually used properly for system
	 * safety
	 */
	WDTCTL = WDTPW | WDTHOLD;
	
	//configure the system will all the default settings defined in pinUsage.h
	configure_sys();
	
	// TODO: put this in a function with timeout protection.
	while(read_TX_interrupt_flag() == 0);
	send_byte_UART('>'); // send a command promter to show that the system is online.
	
	uint8_t cmdError = 0;
	inputMsg command;
	outputMsg response;
	
	// start main control loop.
	while(true){
	    
		// slow the clock while the system is idle by setting master clk to be sourced by the 32kHz crystal
		select_MCLK_source(LFXTCLK);
		while(read_RX_interrupt_flag() == 0);		// this is where the watchdog timer should be reset when online
	    
		// speed the clock back up to receive the message. Done by reseting the MCLK source to the high freq crystal.
		select_MCLK_source(HFXTCLK);
		// receive the message from ground. 
		cmdError = recieve_msg(&command);
		
		// if the message was correctly received, then complete the command. 
		if(!cmdError){
			// command handler. 
		}
		
		// send back the response from the command. 
		cmdError = send_rsp(&response);
	}
	
}
