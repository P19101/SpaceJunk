/**
 * @file uart.h
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief header file containing higher level UART functionality to read and write bytes/strings
 * 		as well as a few minor configurations 
 */
 
#ifndef UART_H
#define UART_H

#include "commonHeader.h"

#define UART_NO_ERR			0
#define UART_OVERRUN_ERR 	-1
#define UART_PARITY_ERR 	-2
#define UART_FRAMMING_ERR 	-3

typedef enum{
	BAUD_1200,
	BAUD_2400,
	BAUD_4800,
	BAUD_9600
}UART_baud_rates_32_768_kHz_clk;

/**
 * Set the baud rate assuming that the clock being used is the 32.768kHz clock
 * NOTE: This should really be more generic to other clocks and stuff, but its a very complex
 * formula to make generic and I'm kinda just working for this one project application. 
 * @param - uint8_t baud: the desired baud rate selected from the enum. 
 * @return: None
 */
void select_baud_rate_UART(uint8_t baud);

/**
 * Write a single byte to the TX register for transmission.
 * @param - uint8_t data: the data byte to send.
 * @return: None
 * NOTE: maybe should check for errors here.
 */
void send_byte_UART(uint8_t data);

/**
 * Read a byte form the receive buffer
 * @param: None
 * @return - uint8_t data: the data read from the RX buffer.
 */
uint8_t read_byte_UART(void);

/**
 * Send a sting of data
 * @param - uint8_t* dataPtr: pointer/string of data to send
 * @param - uint16_t size: the length of the data in bytes to send
 * @return: None
 */
void send_string_UART(uint8_t dataPtr[], uint16_t size);

/**
 * Read a string of data and return it.
 * @param - uint8_t* dataPtr: pointer to where the data will be returned after reading
 * @param - uint16_t size: the size of the data in bytes to read
 * @return - uint8_t error: any errors that may occur while reading the data.
 */
int8_t read_string_UART(uint8_t dataPtr[], uint16_t size);


#endif
