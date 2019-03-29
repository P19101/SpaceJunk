/** 
 * @file messageHandeler.c
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief file which has functions to handle the messaging with the main comm system. 
 * Currently this message system assume the comms are done with UART.
 */
 
#include "messageHandler.h"

uint8_t recieve_msg(inputMsg* msg){
	// TODO: as with all the message stuff, i need to add timeout checks to this;

	// first get the message lenght of the incomming message.
	read_string_UART(&(msg->messageLength), 2);
	
	// subtract 2 for the 2 bytes already gathered which make up the length.
	uint16_t messageLength = (msg->messageLength - 2);
	
	// second get the opcode for the message.
	read_string_UART(&(msg->opcode), 1);
	
	// subtract 1 from the total message lenght for the opcode which was just gathred.
	messageLength = messageLength - 1;
	
	// read the payload for the message and store it in the payload part of the struct.
	read_string_UART(&(msg->payload), messageLength);
}


uint8_t send_rsp(outputMsg* rsp){
	// send the entire message back including the length and opcode.
	send_string_UART(rsp, (rsp->messageLength));
}
