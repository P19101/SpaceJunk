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
#include "ADC12Bit.h"
#include "clockSources.h"

/**
 * Define the specific ports which different system use.
 */
#define DEPLOY_SENSOR_PORT		PORT_1
#define MOTOR_CONTROL_PORT 		PORT_1
#define	NICHROME_CONTROL_PORT	PORT_2

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
#define MOTOR_PWM_1			PIN_6		// 31	- P1.6
#define MOTOR_PWM_2         PIN_7	    // 32 	- P1.7
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

/*******************************GPIO SETTINGS************************************/

// ALL PINS WHICH SHOULD BE SET TO OUTPUTS FOR EACH PORT.
// any unused pins should also be set as an output and left unconnected, the drive
// direction is not important. 
#define PORT_1_OUTPUTS {PIN_4, PIN_5, PIN_6, PIN_7, DEFAULT_SELECTION}
#define PORT_2_OUTPUTS {PIN_0, PIN_2, PIN_3, PIN_4, PIN_5, PIN_6, PIN_7, DEFAULT_SELECTION}
#define PORT_3_OUTPUTS {PIN_0, PIN_1, PIN_2, PIN_3, PIN_4, PIN_5, PIN_6, PIN_7, DEFAULT_SELECTION}
#define PORT_4_OUTPUTS {PIN_0, PIN_1, PIN_2, PIN_3, PIN_4, PIN_5, PIN_6, PIN_7, DEFAULT_SELECTION}
#define PORT_J_OUTPUTS {PIN_6, PIN_7, DEFAULT_SELECTION}

// ALL INPUT PIN WHICH SHOULD HAVE A PULL RESISTOR.
#define PORT_1_PULLED_PINS {DEFAULT_SELECTION}
#define PORT_2_PULLED_PINS {DEFAULT_SELECTION}
#define PORT_3_PULLED_PINS {DEFAULT_SELECTION}
#define PORT_4_PULLED_PINS {DEFAULT_SELECTION}
#define PORT_J_PULLED_PINS {DEFAULT_SELECTION}

// FOR ANY PINS WITH PULL ENABLED ABOVE, SELECT ANY WHICH SHOULD HAVE PULL UP
#define PORT_1_PULL_UP {DEFAULT_SELECTION}
#define PORT_2_PULL_UP {DEFAULT_SELECTION}
#define PORT_3_PULL_UP {DEFAULT_SELECTION}
#define PORT_4_PULL_UP {DEFAULT_SELECTION}
#define PORT_J_PULL_UP {DEFAULT_SELECTION}

// ALL PINS WHICH ARE OUTPUTS AND SHOULD HAVE THEIR DEFAULT STATE AS LOGIC '1'
#define PORT_1_HIGHS {DEFAULT_SELECTION}
#define PORT_2_HIGHS {DEFAULT_SELECTION}
#define PORT_3_HIGHS {DEFAULT_SELECTION}
#define PORT_4_HIGHS {DEFAULT_SELECTION}
#define PORT_J_HIGHS {DEFAULT_SELECTION}

// THE DESIRED RESET STATE FUNCTION FOR EACH GPIO PIN
// no marcos are defined for pins which are set to the default GPIO settings as
// this is the default state
#define PORT_1_PRIMARIES    {DEFAULT_SELECTION}
#define PORT_2_PRIMARIES    {DEFAULT_SELECTION}
#define PORT_3_PRIMARIES    {DEFAULT_SELECTION}
#define PORT_4_PRIMARIES    {DEFAULT_SELECTION}
#define PORT_J_PRIMARIES    {PIN_4, PIN_5, DEFAULT_SELECTION}

#define PORT_1_SECONDARIES  {DEFAULT_SELECTION}
#define PORT_2_SECONDARIES  {PIN_0, PIN_1, DEFAULT_SELECTION}
#define PORT_3_SECONDARIES  {DEFAULT_SELECTION}
#define PORT_4_SECONDARIES  {DEFAULT_SELECTION}
#define PORT_J_SECONDARIES  {DEFAULT_SELECTION}

#define PORT_1_TERTIARIES   {PIN_0, PIN_1, PIN_2, PIN_3, PIN_6, PIN_7, DEFAULT_SELECTION}
#define PORT_2_TERTIARIES   {DEFAULT_SELECTION}
#define PORT_3_TERTIARIES   {DEFAULT_SELECTION}
#define PORT_4_TERTIARIES   {DEFAULT_SELECTION}
#define PORT_J_TERTIARIES   {DEFAULT_SELECTION}

// ALL PINS WHICH SHOULD HAVE THEIR INTERRUPTS ENABLED
// pin interrupts are disabled by default. 
#define PORT_1_INTERRUPTS	{DEFAULT_SELECTION}
#define PORT_2_INTERRUPTS	{DEFAULT_SELECTION}
#define PORT_3_INTERRUPTS	{DEFAULT_SELECTION}
#define PORT_4_INTERRUPTS	{DEFAULT_SELECTION}
#define PORT_J_INTERRUPTS   {DEFAULT_SELECTION}

// FOR ANY PINS WITH INTERRUPTS ENABLED, SELECT ANY WHICH SHOULD HAVE HIGH-TO-LOW EDGES
// by default the interrupt edge is low-to-high. 
#define PORT_1_EDGES {DEFAULT_SELECTION}
#define PORT_2_EDGES {DEFAULT_SELECTION}
#define PORT_3_EDGES {DEFAULT_SELECTION}
#define PORT_4_EDGES {DEFAULT_SELECTION}
#define PORT_J_EDGES {DEFAULT_SELECTION}

/********************************************************************************/

/********************************ADC SETTINGS************************************/
// DEFAULT MULTISAMPLING HOLD TIME FOR ALL ADC MEM REGISTERS
#define ADC_MULTISAMPLE_HOLD_TIME   HOLD_FOUR

// DEFAULT SAMPLING MODE FOR ADC CONVERSIONS
#define ADC_SAMPLING_MODE   SINGLE_CHANNEL_SINGLE_CONVERSION

// DEFAULT ADC CLOCK SOURCE
#define ADC_CLOCK_SOURCE    ADC_OSCILLATOR

// DEFAULT ADC CLOCK SOURCE DIVIDERS
#define ADC_PRIMARY_DIVIDER     ADC_PRE_DIV_1
#define ADC_SECONDARY_DIVIDER   ADC_DIV_1

// DEFAULT TRIGGER SOURCE
#define ADC_TRIGGER             SOFTWARE_SOURCE

// DEFAULT ADC RESOLUTION
#define ADC_RESOLUTION      ADC_12BIT_RES
/********************************************************************************/

/*******************************CLOCK SOURCE*************************************/
// DEFAULT DIGITAL CLOCK FREQUENCY
#define DIGITAL_CLK_FREQ        MHZ_1

// DEFAULT AUXILARY CLOCK SOURCE
#define AUX_CLOCK_SOURCE        LFXTCLK

// DEFAULT MASTER CLOCK SOURCE
#define MASTER_CLK_SOURCE       MODCLK

// DEFAULT SUBSYSTEM CLOCK SOURCE
#define SUB_SYS_CLK_SOURCE      DCOCLK

// DEFAULT AUX CLOCK DIVISION FACTOR
#define AUX_CLK_DIV_FACTOR      FACTOR_1

// DEFAULT MASTER CLOCK DIVISION FACTOR
#define MASTER_CLK_DIV_FACTOR   FACTOR_1

// DEFAULT SUBSYSTEM CLOCK DIVISION FACTOR
#define SUB_SYS_CLK_DIV_FACTOR  FACTOR_1

// DEFAULT DRIVE STRENGHTS FOR THE HIGH AND LOW FREQ EXT SOURCES
#define HIGH_FREQ_DRIVE		HF_DRIVE_LV_1
#define LOW_FREQ_DRIVE		LF_DRIVE_LV_1

// DEFAULT OPERATIONAL FREQUENCY RANGE OF HF CRYSTAL OR BYPASS SIGNAL.
#define HIGH_FREQ_RANGE		HF_0_TO_4_MHZ

// DEFAULT CLOCK SOURCES WHICH SHOULD BE TURNED OFF
// the auxilary and master clocks are always on. 
#define 	LOW_FREQ_ON_OFF_DEFAULT		ACTIVE_LOW
#define 	HIGH_FREQ_ON_OFF_DEFAULT	ACTIVE_HIGH
#define 	VL_FREQ_ON_OFF_DEFAULT		ACTIVE_HIGH
#define 	SMCLK_ON_OFF_DEFAULT		ACTIVE_HIGH

// DEFAULT STATE OF CONDITIONAL REQUEST FOR SYSTEM CLOCKS
#define		MOD_CLK_COND_REQ			ENABLE
#define		MCLK_COND_REQ				ENABLE
#define		SMCLK_COND_REQ				ENABLE
#define		ACLK_COND_REQ				ENABLE


/********************************************************************************/
#endif
