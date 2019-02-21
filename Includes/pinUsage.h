/*
 * @file pinUsage.h
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief File containing macros which define the usage of each pin on the chip
 * 		and which also details the basic settings for each peripheral device. 
 */
 
#ifndef PIN_USAGE_H
#define PIN_USAGE_H

#include "commonHeader.h"
#include "gpio.h"

/**
 * Define the specific ports which different system use.
 */
#define DEPLOY_SENSOR_PORT		PORT_1
#define MOTOR_CONTROL_PORT 		PORT_1
#define	NICHROME_CONTROL_PORT	PORT_1

/**
 * Define all 48 pins and their usage. In order of pin number, not port numbers.
 * Inludes all power and single use pins. Alternate Pin usages are found in the 
 * GPIOalternateFunctionList sheet in the docs folder of the repository. 
 *		PIN FUNCTION |   PIN POSITION | PIN# |  PIN NAME
 */
#define DEPLOY_SENSOR_1 	PIN_1		// 1 	- P1.0
#define DEPLOY_SENSOR_2		PIN_2		// 2 	- P1.1
#define DEPLOY_SENSOR_3		PIN_3		// 3 	- P1.2
										// 4 	- P3.0
										// 5 	- P3.1
										// 6 	- P3.2
										// 7 	- P3.3
										// 8 	- P4.7
#define DEPLOY_SENSOR_4		PIN_4		// 9 	- P1.3
										// 10 	- P1.4
										// 11 	- P1.5
//JTAG TDO PIN							// 12 	- PJ.0
//JTAG TDI PIN							// 13 	- PJ.1
//JTAG TMS PIN							// 14 	- PJ.2
//JTAG TCLK PIN							// 15 	- PJ.3
										// 16	- P4.0
										// 17 	- P4.1
										// 18 	- P4.2
										// 19 	- P4.3
										// 20 	- P2.5
										// 21 	- P2.6
										// 22 	- TESTMODE/SBWCLK
										// 23 	- ~RST/NMI/SBWTDIO
										// 24 	- P2.0
										// 25	- P2.1
										// 26 	- P2.2
										// 27 	- P3.4
										// 28 	- P3.5
										// 29 	- P3.6
										// 30 	- P3.7
#define MOTOR_PWM			PIN_6		// 31	- P1.6
										// 32 	- P1.7
										// 33 	- P4.4
										// 34 	- P4.5
										// 35	- P4.6
//Digital Ground Supply					// 36	- DVSS
//Digital Power Supply					// 37 	- DVCC
#define NICHROME_ON_OFF		PIN_7		// 38 	- P2.7
										// 39 	- P2.3
										// 40	- P2.4
//Analog Ground Supply					// 41 	- AVSS
										// 42	- PJ.6
										// 43 	- PJ.7
//Analog Ground Supply					// 44	- AVSS
										// 45	- PJ.4
										// 46	- PJ.5
//Analog Ground Supply					// 47	- AVSS
//Analog Power Supply					// 48 	- AVCC

/*******************************GPIO SETTINGS**********************************/

// ALL PINS WHICH SHOULD BE SET TO OUTPUTS FOR EACH PORT.
// no input selection is required, as on reset all pins are configured to input by default.
#define PORT_1_OUTPUTS {PIN_6, DEFAULT_SELECTION}
#define PORT_2_OUTPUTS {PIN_7, DEFAULT_SELECTION}
#define PORT_3_OUTPUTS {DEFAULT_SELECTION}
#define PORT_4_OUTPUTS {DEFAULT_SELECTION}

// ALL INPUT PIN WHICH SHOULD HAVE A PULL RESISTOR.
#define PORT_1_PULLED_PINS {DEFAULT_SELECTION}
#define PORT_2_PULLED_PINS {DEFAULT_SELECTION}
#define PORT_3_PULLED_PINS {DEFAULT_SELECTION}
#define PORT_4_PULLED_PINS {DEFAULT_SELECTION}

// ALL PINS WHICH ARE OUTPUTS AND SHOULD HAVE THEIR DEFAULT STATE AS LOGIC '1'
#define PORT_1_HIGHS {DEFAULT_SELECTION}
#define PORT_2_HIGHS {DEFAULT_SELECTION}
#define PORT_3_HIGHS {DEFAULT_SELECTION}
#define PORT_4_HIGHS {DEFAULT_SELECTION}

// THE DESIRED RESET STATE FUNCTION FOR EACH GPIO PIN
// no marcos are defined for pins which are set to the default GPIO settings as
// this is the default state
#define PORT_1_PRIMARIES    {DEFAULT_SELECTION}
#define PORT_2_PRIMARIES    {DEFAULT_SELECTION}
#define PORT_3_PRIMARIES    {DEFAULT_SELECTION}
#define PORT_4_PRIMARIES    {DEFAULT_SELECTION}

#define PORT_1_SECONDARIES  {DEFAULT_SELECTION}
#define PORT_2_SECONDARIES  {DEFAULT_SELECTION}
#define PORT_3_SECONDARIES  {DEFAULT_SELECTION}
#define PORT_4_SECONDARIES  {DEFAULT_SELECTION}

#define PORT_1_TERTIARIES   {PIN_0, PIN_1, PIN_2, PIN_3, PIN_6, DEFAULT_SELECTION}
#define PORT_2_TERTIARIES   {DEFAULT_SELECTION}
#define PORT_3_TERTIARIES   {DEFAULT_SELECTION}
#define PORT_4_TERTIARIES   {DEFAULT_SELECTION}




/******************************************************************************/
#endif
