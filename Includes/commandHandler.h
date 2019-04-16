/**
 * @file commandHandeler.h
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief file which has functions to handle the command read from the ground control. The handler simply uses the opcode given from ground
 * to correctly call the functions needed for the commands execution.
 */

#include "commonHeader.h"
#include "messageHandler.h"


typedef enum{
    TEST_COMM_OP = 0x00,
    STATUS_OP = 0x01,
    READ_SENS_OP = 0x02,
}OpCodes;


/**
 * Takes in an inputMsg strcture with the command which was sent from ground and
 * uses that to execute the command. will fill a corrisponding outputMsg with any
 * data returned from the command.
 * @param - inputMsg* cmd: pointer to the inputMsg structure which holds the data used to execute the command
 * @param - outputMsg* rsp: pointer to the outputMsg structure which will hold the returned data from the command
 * @return - int8_t error: any error command returned from teh attempted command, 0 if no error.
 */
int8_t handle_command(inputMsg* msg, outputMsg* rsp);
