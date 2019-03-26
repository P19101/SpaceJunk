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
 * @param - uint8_t firstMode: the firt modulation factor for baud rate
 *      calculated with UCBRFx = INT([(N/16) – INT(N/16)] × 16)
 * NOTE: ignored when not in oversampling mode
 * @return: None
 */
void choose_mod_factor_one_USCIA_UART(uint8_t factor);

/***********************************************************************************************************************/


#endif
