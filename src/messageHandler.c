/** 
 * @file messageHandeler.c
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief file which has functions to handle the messaging with the main comm system. 
 * Currently this message system assume the comms are done with UART.
 */
 
#include "messageHandler.h"
#include "uart.h"

int8_t recieve_msg(inputMsg* msg){
	// TODO: as with all the message stuff, i need to add timeout checks to this;
    uint8_t byte_data; // used for all single data bytes

	// first read the wake byte which should be 0xFF.
    byte_data = read_byte_UART();
    if(byte_data == COMM_ACK){
        send_byte_UART(COMM_ACK);
    }
    else{
        return ACK_ERROR;
    }

    // next read the two bytes for the message length
	read_string_UART((uint8_t*)&(msg->messageLength), 2);
	/*
	if(msg->messageLength < 2){
	    return MSG_LEN_ERROR;
	}
	else{
	    send_byte_UART(COMM_ACK);
	}
	*/
	// subtract 2 for the 2 bytes already gathered which make up the length.
	uint16_t messageLength = (msg->messageLength - 2);
	
	// second get the opcode for the message.
	read_string_UART((uint8_t*)&(msg->opcode), 1);
	
	// subtract 1 from the total message lenght for the opcode which was just gathred.
	messageLength = messageLength - 1;
	
	// read the payload for the message and store it in the payload part of the struct.
	read_string_UART((uint8_t*)(&(msg->payload)), messageLength);

	return DEFAULT_SELECTION;
}


int8_t send_rsp(outputMsg* rsp){
	// send the entire message back including the length and opcode.
    send_string_UART((uint8_t*)&(rsp->messageLength), 2);
	send_string_UART((uint8_t*)rsp, (rsp->messageLength));

	return DEFAULT_SELECTION;
}
