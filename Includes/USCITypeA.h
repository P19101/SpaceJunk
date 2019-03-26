/**
 * @file uart.h
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief header file containing hardware specific functions for configuring Type A USCIA_H
 *      which can be used as either a UART of SPI device. 
 * NOTE: this header is rather large because of all the repeat options for UART and SPI.
 *      In the future should probably consider reformatting. 
 */

#ifndef USCIA_H
#define USCIA_H

#include "commonHeader.h"

typedef enum{
    UART_MODE,
    SPI_MODE
}operatingModesUSCIABase;
/**
 * Set or clear the Sync bit which will determine if the module operates in UART mode (UCSYNC = 0)
 * or in SPI mode (UCSYNC = 1)
 * @param uint8_t mode: the mode between UART and SPI which the module should operate in.
 * @return: None
 */
void choose_USCIA_operation_mode(uint8_t mode);
/**********************************UART MODE FUNCTION**************************************************/
/** 
 * This section is only for when the UCA0CTL0 SYNC bit is CLEAR indicating that the USCIA is in asychronous UART mode.
 */
typedef enum{
    UCLKI, // this is the external clock provided by the other device in SPI mode
    ACLK,
    SMCLK
}clockSourcesUSCIAUARTMode;

typedef enum{
    UART_STANDARD,
    IDLE_LINE_MULT_PROC,
    ADDRESS_BIT_MULT_PROC,
    UART_WITH_AUTO_BAUD_DET
}asychronousModeUSCIAUARTMode;

typedef enum{
    ONE_BIT_TIME,
    TWO_BIT_TIME,
    THREE_BIT_TIME,
    FOUR_BIT_TIME
}autoBaudTimeoutUSCIAUARTMode;
//*************************
// UCA0CTLW0 register
//*************************
/**
 *  Holds the UART in a reset state so that the control registers can be safely modified
 *  NOTE: always call this function before modifying any UART registers. 
 *  @param: None
 *  @return: None
 */
void hold_USCIA_UART_reset(void);

/**
 *  Release the UART from reset state to begin operation.
 *  NOTE: this should only be done after all configuration settings for the UART are complete
 *  @param: None
 *  @return: None
 */
void release_USCIA_UART_reset(void);

/**
 *  Transmit a break signal with the next transmited byte
 *  @param: None
 *  @return: None
 */
void transmit_break_bit_USCIA_UART(void);

/**
 *  clear the break bit after it is sent, so that the next byte signals the start
 *  of a new transmission sequence. 
 * @param: None
 * @return: None
 */
void clear_break_bit_USCIA_UART(void);

/**
 * Declares the next byte to be transmitted as an address byte, depending on the operation mode
 * @param: None
 * @return: None
 */
void set_next_byte_address_USCIA_UART(void);

/**
 * clear the address identifier bit after an address has already been set
 * @param: None
 * @return: None
 */
void clear_next_byte_address_USCIA_UART(void);

/**
 * set the dormant bit for the controller such that only certain sequences will
 * awaken the UART and set the RX interrupt flag. In UART mode with auto buad rate detection
 * only a break and sync combination will set the RX interrupt flag. 
 * @param: None
 * @return: None
 */
void set_dormant_mode_USCIA_UART(void);

/**
 * clear teh dormant mode bit so that any byte coming on the RX line will set the
 * RX interrupt flag
 * @param: None
 * @return: None
 */
void clear_dormant_mode_USCIA_UART(void);

/** 
 * allows break sequence bytes to set the RX interrupt flag
 * @param: None
 * @return: None
 */
void break_interrupt_enabled_USCIA_UART(void);

/**
 * disable break sequence bytes from setting the RX interrupt flag
 * @param: None
 * @return: None
 */
void break_interrupt_diabled_USCIA_UART(void);

/**
 * Allow erronious character recieved to be stored and set the RX interrupt flag
 * @param: None
 * @return: None
 */
void error_byte_interrupt_enabled_USCIA_UART(void);

/**
 * Diable erronious characters from setting the RX interrupt flag, and discard them
 * @param: None
 * @return: None
 */
void error_byte_interrupt_disabled_USCIA_UART(void);

/**
 * Select the clock source for the USCIA_H
 * @param - uint8_t source: the clock source enum selecting the clock for the USCI type Allow
 * @return: None
 */
void set_clock_source_USCIA_UART(uint8_t source);

/**
 * select the asychronous operation mode
 * @param - uint8_t mode: the asychronous operation mode chosen when the UCSYNC bit is cleared
 * @return: None
 */
void set_mode_USCIA_UART(uint8_t mode);

/**
 * select the number of stop bits by setting or clearing the selection flag
 * @param - uint8_t stopBits: select the number of stop bits for each byte transmitted
 *      0 - 1 stop bit per transmitted byte
 *      1 - 2 stop bits per transmitted byte
 * @return: None
 */
void select_number_stop_bits_USCIA_UART(uint8_t stopBits);

/**
 * select the size of the data as either 8 or 7 bits
 * @param - uint8_t dataBits: the number of data bits per transmitted and recieved byte
 *      0 - standard 8 data bits
 *      1 - 7 data bits
 * @return: None
 */
void select_number_data_bits_USCIA_UART(uint8_t dataBits);

/**
 * select the endianness of the data
 * @param - uint8_t endianness: the direction of the transmitted data
 *      0 - LSB first little endian mode
 *      1 - MSB first bit endian mode
 * @return: None
 */
void select_endianness_USCIA_UART(uint8_t endian);

/**
 * select between even and odd parity selection for the parity bit. 
 * @param - uint8_t parity: selects either even or odd parity.
 *      0 - odd parity
 *      1 - even parity
 * @return: None
 */
void select_parity_USCIA_UART(uint8_t parity);

/**
 * enable the addition of a parity bit in the transmitted data and the expectation
 * of a parity bit in the received data
 * @param: None
 * @return: None
 */
void enable_parity_check_USCIA_UART(void);

/**
 * disable the addition of the parity bit in the transmitted data and the expectation
 * of a parity bit in the received data
 * @param: None
 * @return: None
 */
void disable_parity_check_USCIA_UART(void);

/**
 * NOTE: this is the only bit feild in the UCA0CTLW1 register which doesnt seem to exist in the
 * msp430 header file, so im just gunna leave this template here, but i dont think
 * this option actually exist (dont let interns write the manuals people)
 * Set the deglitch time for the UART which ensures that the UART is not started
 * by any random glitches on the RX line. 
 * @param - uint8_t glitchTime: enum selection for how long the glitch detection should
 *      hold before a signal is accepted
 * @return: None
 */
//void select_deglitch_time_USCIA_UART(uint8_t glitchTime);

//*******************
//UCA0BRW register
//*******************

/**
 * Write the integer part of the baud rate N value. This value is determined by N = clkfreq/baudRate
 * @param - uint16_t baudFactorInt: the integer part of the baud rate factor.
 *      NOTE: if oversampling is DISABLED then UCBRx = INT(N);
 *      otherwise when oversampling is ENABLED then UCBRx = INT(N/16)
 * @return: None
 */
void set_BR_Int_USCIA_UART(uint16_t baudFactorInt);

//*******************
//UCA0MCTLW register
//*******************

/** 
 * Set or clear oversampling mode. Over sampling mode should be used when the N factor of the baud rate
 * has been determined and is greater than or equal to 16. This enables a second stage of modulation for
 * reduced error
 * @param - uint8_t oversample: boolean value of whether oversampling should be set or not.
 * @return: None
 */
void choose_oversampling_mode_USCIA_UART(uint8_t oversample);

/**
 * Choose the first modulation level factor
 * @param - uint8_t factor: the first modulation factor for baud rate
 *      calculated with UCBRFx = INT([(N/16) – INT(N/16)] × 16)
 *      NOTE: ignored when not in oversampling mode
 * @return: None
 */
void choose_mod_factor_one_USCIA_UART(uint8_t factor);

/** choose the second modulation level factor
 * @param - uint8_t factor: the second modulation factor for baud rate
 *      NOTE: when oversampling is DISABLED then a error calculation is recommened by using
 *      the formulas starting on page 777 of the family manuals
 *      However when oversampling ENABLED or for faster calculation, a set of sample factors
 *      is given on page 776 in table 30-4
 * @return: None
 */
void choose_mod_factor_two_USCIA_UART(uint8_t factor);

//*******************
//UCA0STATW register
//*******************

/**
 * Read the busy flag indicating if the UART is receiving or transmitting
 * @param: None
 * @return - uint8_t busy: when set indicates that the UART is either transmitting
 *      or recieving data, otherwise the controller is idle.
 */
uint8_t read_busy_flag_USCIA_UART(void);

/**
 * Read address status flag bit
 * @param: None
 * @return - uint8_t address: when set the last byte stored in the recieve buffer is the address
 *      otherwise the byte stored is data.
 */
uint8_t read_address_flag_USCIA_UART(void);

/**
 * Read the idle line flag bit
 * @param: None
 * @return - uint8_t idle: when set, and idle line was detected, otherwise no idle line
 */
uint8_t read_idle_line_flag_USCIA_UART(void);

/**
 * Read General Error flag
 * @param: None
 * @return - uint8_t error: set when some error occurs. When this flag is set some other error
 *      flag is also set and should be checked
 */
uint8_t read_error_flag_USCIA_UART(void);

/**
 * Read the flag indicating a break condition has occured
 * @param: None
 * @return - uint8_t break: if set, then a break condition has occured
 */
uint8_t read_break_condition_USCIA_UART(void);

/**
 * Read the parity error flag
 * @param: None
 * @return - uint8_t parityErr: if set, then a parity error has occured indicating transmission error
 */
uint8_t read_parity_err_flag_USCIA_UART(void);

/**
 * Read the overrun error flag
 * @param: None
 * @return - uint8_t overrunErr: if set, an overrun error has occured and data has likely been lost
 */
uint8_t read_overrun_flag_USCIA_UART(void);

/**
 * Read the framing error flag
 * @param: None
 * @return - uint8_t framingErr: if set, a framming error has occured and a baud rate error is likely.
 */
uint8_t read_framming_flag_USCIA_UART(void);

/**
 * Set an internal loopback mode connecting the receiver to the transmitter
 * @param - uint8_t loopback: if set then loopback mode interally is enabled
 * @return: None
 */
void loopback_mode_USCIA_UART(uint8_t loopback);

//*******************
//UCA0RXBUF register
//*******************

/**
 * read the RX buffer data. Reading this flag clear the error bits and iterrupt flag
 * @param: None
 * @return - uint8_t data: the byte of data stored in the RX buffer. 
 */
uint8_t read_RX_buffer_USCIA_UART(void);

//********************
//UCA0TXBUF register
//********************

/**
 * write the TX buffer with data to be transmitted
 * @param - uint8_t data: the data byte to be transmitted.
 * @return: None
 */
uint8_t write_TX_buffer_USCIA_UART(void);

//********************
//UCA0ABCTLW register
//********************

/**
 * Choose to set or clear the automatic baud rate detection mode
 * @param - uint8_t autoBaud: setting this will enable auto baud rate detection
 * @return: None
 */
void choose_auto_baud_USCIA_UART(uint8_t autoBaud);

/**
 * read the break timeout flag
 * @param: None
 * @return - uint8_t breakErr: if set, indicates that a break timming error occured
 */
uint8_t read_break_err_flag_USCIA_UART(void);

/**
 * read the sync timeout flag
 * @param: None
 * @return - uint8_t sychErr: if set, a sync timeout error has occured
 */
uint8_t read_sync_err_flag_USCIA_UART(void);

/**
 * Set the bit timeout limit for the sync and break bits in auto baud detection mode
 * @param - uint8_t timeout: enum for the number of bit times for a timeout in auto baud mode
 * @return: None
 */
void set_auto_baud_timeout_USCIA_UART(uint8_t timeout);

//*********************
//UCA0IRCTL register
//*********************

/**
 * Enable or disable the IrDA encoder/decoder
 * @param - uint8_t enable: when set, enable the IrDA encoder/decoder, otherwise diabled
 * @return: None
 */
void choose_IrDA_enabled_USCIA_UART(uint8_t enable);
/***********************************************************************************************************************/


#endif
