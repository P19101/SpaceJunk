/**
 * @file commandHandeler.c
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief file which has functions to handle the command read from the ground control. The handler simply uses the opcode given from ground
 * to correctly call the functions needed for the commands execution.
 */


#include "commandHandler.h"
#include "ADC12Bit.h"
#include "gpio.h"
#include "pinUsage.h"

int8_t handle_command(inputMsg* msg, outputMsg* rsp){
    switch(msg->opcode){
        case TEST_COMM_OP:
            // making a generic response for comm test
            rsp->messageLength = 3;
            rsp->opcode = TEST_COMM_OP;
            break;
        case STATUS_OP:
            break;
        case READ_SENS_OP:
            rsp->messageLength = 4;
            rsp->opcode = READ_SENS_OP;
            rsp->payload.readSensorRsp.sensorVal = read_GPIO_input_pin(DEPLOY_SENSOR_PORT, DEPLOY_SENSOR_4);
            break;
        default:
            break;
    }
    return DEFAULT_SELECTION;
}
