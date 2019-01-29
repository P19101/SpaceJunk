/*
 * @file PreAssemblyTestSuite.c
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief File containing some simple function definitions which are used to test connections with peripheral devices and set pin assignments.
 */

#include <msp430fr5969.h>
#include <stdint.h>
#include <stdbool.h>
#include "ADC12bit.h"

void init_pins(){
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Unlock the GPIOs from the power manager after a complete reset.

    // ADC Setup
    // ADC12ON - Register used to power on the ADC chip. This can be turned off the disable clocking to the chip to save power.

}













