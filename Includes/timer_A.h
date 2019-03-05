/**
 * @file timer_A.h
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief header file containing hardware specific functions for the type A timer
 * 		modules.
 */
 
#ifndef TIMER_A_H
#define TIMER_A_H



#endif

#include "commonHeader.h"

typedef enum timerAlist{
	TIM_A_0,
	TIM_A_1,
	TIM_A_2,
	TIM_A_3
}timerAList;

typedef enum timerASource{
	TAxCLK,
	TMRA_ACLK,
	TMRA_SMCLK,
	TMRA_INCLK
}timerAClockSource;

typedef enum timerAinDivider{
	TA_DIV_1,
	TA_DIV_2,
	TA_DIV_4,
	TA_DIV_8
}timerAInputDivider;

typedef enum timerAcountDir{
	STOP_MODE,
	UP_MODE,
	CONTINUOUS_MODE,
	UP_DOWN_MODE
}timerACountDirection;

typedef enum timerAcaptureMode{
	NO_CAPTURE,
	RISING_EDGE,
	FALLING_EDGE,
	DOUBLE_EDGE
}timerACaptureMode;

typedef enum timerACCinputSel{
	INPUT_A,
	INPUT_B,
	INPUT_GND,
	INPUT_VCC
}timerACaptureCompareInputSelect;

typedef enum timerAOutmode{
	OUT_BIT,
	SET,
	TOGGLE_RESET,
	SET_RESET,
	TOGGLE,
	RESET,
	TOGGLE_SET,
	RESET_SET
}timerAOutputModeSelect;

typedef enum timerAExpasionDiv{
	TA_EXDIV_1,
	TA_EXDIV_2,
	TA_EXDIV_3,
	TA_EXDIV_4,
	TA_EXDIV_5,
	TA_EXDIV_6,
	TA_EXDIV_7,
	TA_EXDIV_8,
}TimerAExpansionDivider;
/**
 * Select the clock source for the specific timer A type
 * @param - uint8_t timerNum: the specific type A timer reference
 * @param - uint8_t clockSource: the source for the selected timer. 
 * @return: None
 */
void select_timer_Ax_clock_source(uint8_t timerNum, uint8_t clockSource);

/** 
 * Select the initial input divider for the specified timer. 
 * @param - uint8_t timerNum: the specific type A timer reference
 * @param - uint8_t div: the amount to divide the timers clock by.  
 * @return: None
 */
void input_divider_timer_Ax(uint8_t timerNum, uint8_t div);

/** 
 * Select the operating mode for the timer. The options are either a count up mode
 * where the timer will reset and stop after reaching the specified value in the
 * TaxCCR0 register. continuous mode where the timer will count to 0xFFFF repeatedly.
 * And up/down mode where the timer will count up to the value specified in TaxCCR0,
 * and then back down to zero. 
 * @param - uint8_t timerNum: the specific type A timer reference
 * @param - uint8_t opMode: the operational mode for the timer to count in.
 * @return: None
 */
void mode_select_timer_Ax(uint8_t timerNum, uint8_t opMode);

/**
 * Clears the timer count value and resets the timer. This will also reset the 
 * operational mode to Stop. 
 * @param - uint8_t timerNum: the specific type A timer reference.
 * @return: None
 */
void clear_timer_Ax(uint8_t timerNum);

/**
 * Enable interrupts for the specified timer
 * @param - uint8_t timerNum: the specific type A timer reference.
 * @return: None
 */
void interrupt_enable_timer_Ax(uint8_t timerNum);

/**
 * Diable interrupts for the specified timer
 * @param - uint8_t timerNum: the specific type A timer reference.
 * @return: None
 */
void interupt_disable_timer_Ax(uint8_t timerNum);

/**
 * read the interrupt flag which is set whenver the timers count reaches the value
 * specified in TAxCCR0
 * @param - uint8_t timerNum: the specific type A timer reference.
 * @return - uint8_t flagStatus: the bit representing the interrupt flag. 
 */
uint8_t read_interrupt_flag_timer_Ax(uint8_t timerNum);

/**
 * read the regsiter which holds the specific number of clock counts for the selected
 * timer.
 * @param - uint8_t timerNum: the specific type A timer reference.
 * @return - uint16_t: the count value for the specified timer. 
 */
uint16_t read_timer_count_value_timer_Ax(uint8_t timerNum);

/**
 * set the capture mode for the selected timer
 * @param - uint8_t timerNum: the specific type A timer reference.
 * @param - uint8_t captureEdge: the edge enum used for capturing the input signal
 * @return: None
 */
void set_capture_mode_timer_Ax(uint8_t timerNum, uint8_t captureEdge);

/**
 * select the input source for the capture and compare register CCR0
 * @param - uint8_t timerNum: the specific type A timer reference
 * @param - uint8_t inputSource: the input source for the capture compare register
 * @return: None
 */
void set_capture_compare_input_source_timer_Ax(uint8_t timerNum, uint8_t captureEdge);

/**
 * Select if the input source should be synchronized
 * @param - uint8_t timerNum: the specific type A timer reference
 * @param - uint8_t synchronize: input determining if the input should be synched
 * 		with the timer input clock. 
 * @return: None
 */
void select_input_source_sychronisity_timer_Ax(uint8_t timerNum, uint8_t synchronize);

/** 
 * Read the synchronized signal bit, if sychronized is selected. 
 * @param - uint8_t timerNum: the specific type A timer reference
 * @return - uint8_t synchBit: the polarity of the synchronized bit. 
 */
void read_synchronized_bit(uint8_t timerNum);

