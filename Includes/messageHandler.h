/** 
 * @file messageHandeler.h
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief file which has functions to handle the messaging with the main comm system. 
 * Currently this message system assume the comms are done with UART.
 */
 
 
#ifndef MSG_HANDLER_H
#define MSG_HANDLER_H

#include "commonHeader.h"

#define COMM_ACK 0xAA
#define ACK_ERROR -1
#define MSG_LEN_ERROR -2
/*******************************MESSAGE STRUCTURES*****************************************/
// when a new command is created, then create a new message for its structure and add it here

/***********************************INPUTS*************************************************/
input{
	uint8_t 		confirmationCode;
}deployIn;

input{
    uint8_t         sensorNum;
}readSensorIn;

typedef union{
	// add all new messages here
	deployIn		deployCmd;
	readSensorIn    readSensorCmd;
}msgDataIn;

input{
	uint16_t 		messageLength;
	uint8_t			opcode;
	msgDataIn		payload;
}inputMsg;

/***********************************OUTPUTS************************************************/
output{
	uint8_t 		confirmationCode;
}deployOut;

output{
    uint8_t        sensorVal;
}readSensorOut;

typedef union{
	// add all new messages here
	deployOut		deployRsp;
	readSensorOut   readSensorRsp;
}msgDataOut;

output{
	uint16_t		messageLength;
	uint8_t			opcode;
	msgDataOut		payload;
}outputMsg;
/******************************************************************************************/

/**
 * gather a message from the main comm system. The expected format is given by the msg structure.
 * @param - inputMsg* msg: the structure where the input message will be returned upon reception. 
 * @return - int8_t error: any error signal which should be returned.
 */
int8_t recieve_msg(inputMsg* msg);

/**
 * send a message back to the main comm system. The expected format is given by the rsp structure.
 * @param - outputMsg* rsp: the structure where the output message is stored to be sent.
 * @return - int8_t error: any error singal which should be returned.
 */
int8_t send_rsp(outputMsg* rsp);






























#endif
