/*
 * @file ADC12Bit.h
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief File containing function definitions and enums for the 12 bit ADC
 */

#ifndef ADC12BIT_H_
#define ADC12BIT_H_

#include "commonHeader.h"

/* 
 * Used to define the number of ADC12CLK cycles in the sampling period. 
 * This is used when the ADC is in pulse sampling mode, and defines the lenght of
 * each sample in multiples of 4 * ADC12CLK.
 */
typedef enum {
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

/*
 * Used to define the four conversion modes which are possible.
 * 		In single channel single conversion mode, a single possible ADC channel
 * is converted one time and stored in the memory position indicated by 
 * the four bits of ADC12CSTARTADD in the ADC12CLT3 register.
 * 		In Multi channel single conversion mode, (also called auto sample)
 * a set of defined registers is sampled and converted together one time.
 * 		In single channel repeat sample, a signel channel is converted continuously,
 * until stopped by a trigger, If the conversion results are not read before the
 * next sample is complete, the previous results are overwritten. 
 * 		In Multi channel repeat conversion mode, a series of channels is converted and
 * stored to their respective memory registers. Once again, these results are overwritten
 * if they are not read before the next conversion is complete. 
 */
typedef enum {
    SINGLE_CHANNEL_SINGLE_CONVERSION,
    MULTI_CHANNEL_SINGLE_CONVERSION,
    SINGLE_CHANNEL_REPEAT_CONVERSION,
    MULTI_CHANNEL_REPEAT_CONVERSION
}ADCConversionSequences;

/*
 * Used to select the clock source for the ADC, with ADC_OSCILLATOR and the other
 * options being other clock sources which are available on the chip. Be aware of
 * the maximum clock frequency of the ADC before selecting a clock. 
 */
typedef enum {
    ADC_OSCILLATOR,
    ACLOCK,
    MCLOCK,
    SMCLOCK
}ADCClockSources;

/*
 * The secondary divider provides an additional way to divide down the clock input to
 * reduce the ADCCLK frequency and potentially save power.
 */
typedef enum {
    ADC_DIV_1,
    ADC_DIV_2,
    ADC_DIV_3,
    ADC_DIV_4,
    ADC_DIV_5,
    ADC_DIV_6,
    ADC_DIV_7,
    ADC_DIV_8
}ADCSecondaryDivider;

/* 
 * Selects the source of the sample start trigger. The default trigger is the 
 * ADC12SC bit in the ADC12CTL0 register, which can be set in software. 
 * Other triggers are connected to external pins.
 */
typedef enum {
    SOFTWARE_SOURCE,
    TA0_CCR1,
    TB0_CCR0,
    TB0_CCR1,
    TA1_CCR1,
    TA2_CCR1,
    TA3_CCR1,
}ADCSampleStartSource;

/*
 * The initial divider used to scale down the ADC clock frequency, primarily used
 * to save power, or if the clock source selected is above the maximum for the device.
 */
typedef enum {
    ADC_PRE_DIV_1,
    ADC_PRE_DIV_4,
    ADC_PRE_DIV_32,
    ADC_PRE_DIV_64
}ADCpredivider;

/*
 * select the number of bits used for the sampling of the signal. A higher number of bits
 * means a more accurate sample, but also will take longer to convert.
 */
typedef enum {
    ADC_8BIT_RES,
    ADC_10BIT_RES,
    ADC_12BIT_RES
}ADCResolution;

/**
 * Start the ADC conversion of the selected input signal. This is only valid when
 * the trigger source is set to be the default software trigger
 * @param: None
 * @return: None
 */
void start_adc_conversion(void);

/**
 * Power on the ADC by providing a clock source to it. Turning off the ADC
 * will save on power consumption by the whole system. 
 * @param: None
 * @return: None
 */
void power_on_adc_12bit(void);

/**
 * Power off the ADC by cutting the clock source to the device.
 * @param: None
 * @return: None
 */
void power_off_adc_12bit(void);

/** 
 * Enable the ADC with all of its current settings. All desired settings, especially
 * in the four main control registers, should be set before enabling the device. 
 * @param: None
 * @return: None
 */
void enable_adc_12bit(void);

/**
 * Disable the ADC. This is not the same as turning the device off, and will not
 * entirely cut the power consumption of the device. 
 * @param: None
 * @return: None
 */
void disable_adc_12bit(void);

/**
 * Enable the mult sampling mode on the ADC. After the current sample is complete,
 * the next sample will begin, until all selected samples are complete or the sampling
 * is interrupted.
 * @param - uint8_t multisample: boolean used to select multisampling
 * 		'0': Disable multisampling mode
 *		'1': Enable multisampling mode
 * @return: None
 */
void set_multi_sampling_mode_adc_12bit(uint8_t multisample);

/**
 * Used in multisample mode to select the sampling period for each individual sample.
 * the enum values for ADCHoldTimes provided should be used for selection.
 * This function will set the value for memory registers 0-7 and 24-31.
 * @param - uint8_t holdTime: one of the ADCHoldTimes enum values to select the
 *		number of clock cycles for each sample. 
 * @return: None
 */
void set_sample_hold_time_zero(uint8_t holdTime);

/**
 * Used in multisample mode to select the sampling period for each individual sample.
 * the enum values for ADCHoldTimes provided should be used for selection.
 * This function will set the value for memory registers 8-23.
 * @param - uint8_t holdTime: one of the ADCHoldTimes enum values to select the
 *		number of clock cycles for each sample. 
 * @return: None
 */
void set_sample_hold_time_one(uint8_t holdTime);

/** 
 * read the value of the ADC busy flag, which is used to indicate if the current conversion
 * has been completed. If no conversion was started this flag will also read as '0'.
 * @param: None
 * @return - uint8_t flagValue: the value of the busy flag.
 *		'0': no conversion was started, or the current conversion has finished. 
 * 		'1': the current conversion is in progress. 
 */
uint8_t read_ADC_busy_flag(void);

/**
 * Set the conversion sequence type as defined by the enum ADCConversionSequences
 * @param - uint8_t sequenceType: the enum to define the desired conversion sequence
 * @return: None
 */
void set_conversion_sequence(uint8_t sequenceType);

/**
 * Set the clock source for the ADC as defined by the enum ADCClockSources.
 * @param - uint8_t clockSource: ADCClockSources enum of the desired clock source
 *		to provide to the ADC.
 * @return: None
 */
void set_ADC_clock_source(uint8_t clockSource);

/**
 * Set the secondary clock source divider which provides the ability to divide
 * the clock source by up to an additional 8 times beyond the pre-divider. 
 * Defined by the ADCSecondaryDivider enum
 * @param - uint8_t divisor: ADCSecondaryDivider enum used to select the amount
 * 		to divide the source clock by.
 * @return: None
 */
void set_ADC_secondary_divider(uint8_t divisor);

/** 
 * Select if the sampled value should be inverted before the conversion.
 * @param - uint8_t invert: selects if the value should be inverted or not.
 * 		'0': the sampled value will not be inverted
 * 		'1': the sampled value will be inverted
 * @return: None
 */
void set_ADC_sample_inversion(uint8_t invert);

/**
 * Selects if the Pulse Sample mode should be used or not. 
 * @param - uint8_t pulse: boolean to determine if the pulse mode should be used.
 * 		'0': pulse mode will not be used.
 * 		'1': pulse mode will be used, and additional settings are configured.
 * @return: None
 */
void set_ADC_sample_pulse_mode(uint8_t pulse);

/**
 * Indicates what the trigger source for the start of ADC conversion should be.
 * Defined by the ADCSampleStartSource enum provided. The software source is the
 * ADC12SC bit in control register 0.
 * @param - uint8_t source: The source which should be used to trigger the ADC.
 * @return: None
 */
void set_ADC_sample_trigger_source(uint8_t source);

/**
 * Selects the value of the ADC clock predivider, which can be used to slow down the
 * clock source to meet maximum requirements, or to save power. 
 * @param - uint8_t divisor: ADCpredivider enum used to select the value of the predivider.
 * @return: None
 */
void set_ADC_clock_predivider(uint8_t divisor);

/**
 * Sets the low power mode for the ADC. The ADC clock source must be 1/4 or less the maximum
 * value to successfully set this bit. 
 * @param: None
 * @return: None
 */
void set_ADC_low_power_mode(void);

/**
 * Clear the bit indicating the use of the ADC low power mode. 
 * @param: None
 * @return: None
 */
void clear_ADC_low_power_mode(void);

/**
 * Set the conversion output of the ADC to be in a signed two's complement notation
 * @param: None
 * @return: None
 */
void set_ADC_signed_twos_complement_output(void);

/**
 * Set the conversion output of the ADC to unsigned notation. This is the default state.
 * @param: None
 * @return: None
 */
void clear_ADC_signed_twos_complement_output(void);

/**
 * Set the ADC resolution as defined by the ADCResolution enum. A higher resolution will
 * result in better accuracy, but will take longer to sample and convert. 
 * @param - uint8_t resolution: The desired resolution of the ADC for sampling and conversion.
 * @return: None
 */
void set_ADC_resolution(uint8_t resolution);

/**
 * Select the starting register to store the converted ADC value. In any single sample
 * mode this register will hold the result. In any multisample mode, this will hold the 
 * first result, and other results will be held in the N + 1 memory register for the ADC,
 * until all requested samples are aquired. 
 * @param - uint8_t memRegister: the number of the register which should be stored
 * 		ranging between 0x00 for register 0, and 0x1F for register 31
 * @return: None
 */
void select_ADC_mem_register(uint8_t memRegister);

/**
 * Determines if the 31st input source for the ADC should be set as the external pin, or
 * 1/2 AVCC internal signal.
 * @param - uint8_t source: selects the source of the 31st input signal.
 * 		'0': the signal will come from the corrisponding external pin.
 *		'1': the signal will be 1/2 of the internal AVCC signal. 
 * @return: None
 */
void set_or_clear_BAT_input_source(uint8_t source);

/**
 * Determines if the 30th inpuyt source should be set as an external pin, or the output
 * from the internal temperature sensor.
 * @param - uint8_t source: selects the source of the 30th input signal.
 * 		'0': the signal will come from the corrisponding external pin.
 *		'1': the signal will be the output from the internal temperature sensor. 
 * @return: None
 */
void set_or_clear_temp_sensor_input_source(uint8_t source);

/**
 * Determines if the 29th input source for the ADC should be set as the external pin,
 * or the 0th internal input channel.
 * @param - uint8_t source: selects the source of the 29th input signal.
 * 		'0': the signal will come from the corrisponding external pin.
 *		'1': the signal will be the output from the 0th internal source. 
 * @return: None
 */
void set_or_clear_internal_source_0(uint8_t source);

/**
 * Determines if the 28th input source for the ADC should be set as the external pin,
 * or the 1st internal input channel.
 * @param - uint8_t source: selects the source of the 28th input signal.
 * 		'0': the signal will come from the corrisponding external pin.
 *		'1': the signal will be the output from the 1st internal source. 
 * @return: None
 */
void set_or_clear_internal_source_1(uint8_t source);
 
/**
 * Determines if the 27th input source for the ADC should be set as the external pin,
 * or the 2nd internal input channel.
 * @param - uint8_t source: selects the source of the 27th input signal.
 * 		'0': the signal will come from the corrisponding external pin.
 *		'1': the signal will be the output from the 2nd internal source. 
 * @return: None
 */
void set_or_clear_internal_source_2(uint8_t source);

/**
 * Determines if the 26th input source for the ADC should be set as the external pin,
 * or the 3rd internal input channel.
 * @param - uint8_t source: selects the source of the 26th input signal.
 * 		'0': the signal will come from the corrisponding external pin.
 *		'1': the signal will be the output from the 3rd internal source.  
 * @return: None
 */
void set_or_clear_internal_source_3(uint8_t source);
#endif /* ADC12BIT_H_ */





