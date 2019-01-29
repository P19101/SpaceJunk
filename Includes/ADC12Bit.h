/*
 * @file ADC12Bit.h
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief File containing function definitions and enums for the 12 bit ADC
 */

#ifndef ADC12BIT_H_
#define ADC12BIT_H_

#include <stdint.h>
#include <msp430fr5969.h>

typedef enum adcHoldTimes{
    HOLD_FOUR,
    HOLD_EIGHT,
    HOLD_SIXTEEN,
    HOLD_THIRTYTWO,
    HOLD_SIXTYFOUR,
    HOLD_NINTYSIX,
    HOLD_ONETWENTYEIGHT,
    HOLD_ONENINTYTWO,
    HOLD_TWOFIFTYSIX,
    HOLD_THREEEIGHTYFOUR,
    HOLD_FIVETWELVE
}ADCHoldTimes;

typedef enum converstionSequences{
    SINGLE_CHANNEL_SINGLE_CONVERSION,
    MULTI_CHANNEL_SINGLE_CONVERSION,
    SINGLE_CHANNEL_REPEAT_CONVERSION,
    MULTI_CHANNEL_REPEAT_CONVERSION
}ADCConversionSequences;

typedef enum clockSources{
    ADC_OSCILLATOR,
    ACLOCK,
    MCLOCK,
    SMCLOCK
}ADCClockSources;

typedef enum secondaryDivider{
    ADC_DIV_1,
    ADC_DIV_2,
    ADC_DIV_3,
    ADC_DIV_4,
    ADC_DIV_5,
    ADC_DIV_6,
    ADC_DIV_7,
    ADC_DIV_8
}ADCSecondaryDivider;

typedef enum sampleStartSource{
    SOFTWARE_SOURCE,
    TA0_CCR1,
    TB0_CCR0,
    TB0_CCR1,
    TA1_CCR1,
    TA2_CCR1,
    TA3_CCR1,
}ADCSampleStartSource;

typedef enum predivider{
    ADC_PRE_DIV_1,
    ADC_PRE_DIV_4,
    ADC_PRE_DIV_32,
    ADC_PRE_DIV_64
}ADCpredivider;

typedef enum resolution{
    ADC_8BIT_RES,
    ADC_10BIT_RES,
    ADC_12BIT_RES
}ADCResolution;

#endif /* ADC12BIT_H_ */





