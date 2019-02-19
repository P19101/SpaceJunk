/*
 * @file ADC12Bit.c
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief File containing functions for the 12 bit ADC
 */

#include "ADC12Bit.h"
#include "commonHeader.h"
/********************************************************* ADC CONTROL REGISTER 0 ****************************************************************/
void start_adc_conversion(void){
    ADC12CTL0 |= ADC12SC; // toggle the conversion bit to begin conversion with the 12 bit ADC
}

void power_on_adc_12bit(void){
    ADC12CTL0 |= ADC12ON; // power on the ADC
}

void power_off_adc_12bit(void){
    ADC12CTL0 &= (~ADC12ON); // power off the ADC
}

void enable_adc_12bit(void){
    ADC12CTL0 |= ADC12ENC; // enable the chip. NOTE : this should only be done after all other ADC setup is complete.
}

void disable_adc_12bit(void){
    ADC12CTL0 &= (~ADC12ENC); // disable the chip and allow settings to be changed.
}

void set_multi_sampling_mode_adc_12bit(uint8_t multisample){
    if(multisample){
        ADC12CTL0 |= ADC12MSC; // enable multisamples from the ADC. After one sample is finished the ADC will immediately begin the next.
    }
    else{
        ADC12CTL0 &= (~ADC12MSC);
    }
}



void set_sample_hold_time_zero(uint8_t holdTime){
    uint16_t holdTimeSet;

    // clear the bits
    ADC12CTL0 &= ~(ADC12SHT00 | ADC12SHT01 | ADC12SHT02 | ADC12SHT03);

    // select which bits to set
    switch(holdTime){
        case HOLD_FOUR:
            holdTimeSet = DEFAULT_SELECTION;
            break;
        case HOLD_EIGHT:
            holdTimeSet = ADC12SHT00;
            break;
        case HOLD_SIXTEEN:
            holdTimeSet = ADC12SHT01;
            break;
        case HOLD_THIRTYTWO:
            holdTimeSet = ADC12SHT01 | ADC12SHT00;
            break;
        case HOLD_SIXTYFOUR:
            holdTimeSet = ADC12SHT02;
            break;
        case HOLD_NINTYSIX:
            holdTimeSet = ADC12SHT02 | ADC12SHT00;
            break;
        case HOLD_ONETWENTYEIGHT:
            holdTimeSet = ADC12SHT02 | ADC12SHT01;
            break;
        case HOLD_ONENINTYTWO:
            holdTimeSet = ADC12SHT02 | ADC12SHT01 | ADC12SHT00;
            break;
        case HOLD_TWOFIFTYSIX:
            holdTimeSet = ADC12SHT03;
            break;
        case HOLD_THREEEIGHTYFOUR:
            holdTimeSet = ADC12SHT03 | ADC12SHT00;
            break;
        case HOLD_FIVETWELVE:
            holdTimeSet = ADC12SHT03 | ADC12SHT01;
            break;
        default:
            holdTimeSet = DEFAULT_SELECTION;
            break;
    }
    ADC12CTL0 |= holdTimeSet;
}

void set_sample_hold_time_one(uint8_t holdTime){
    uint16_t holdTimeSet;

    // clear the bits
    ADC12CTL0 &= ~(ADC12SHT10 | ADC12SHT11 | ADC12SHT12 | ADC12SHT13);

    // select which bits to set
    switch(holdTime){
        case HOLD_FOUR:
            holdTimeSet = DEFAULT_SELECTION;
            break;
        case HOLD_EIGHT:
            holdTimeSet = ADC12SHT10;
            break;
        case HOLD_SIXTEEN:
            holdTimeSet = ADC12SHT11;
            break;
        case HOLD_THIRTYTWO:
            holdTimeSet = ADC12SHT11 | ADC12SHT10;
            break;
        case HOLD_SIXTYFOUR:
            holdTimeSet = ADC12SHT12;
            break;
        case HOLD_NINTYSIX:
            holdTimeSet = ADC12SHT12 | ADC12SHT10;
            break;
        case HOLD_ONETWENTYEIGHT:
            holdTimeSet = ADC12SHT12 | ADC12SHT11;
            break;
        case HOLD_ONENINTYTWO:
            holdTimeSet = ADC12SHT12 | ADC12SHT11 | ADC12SHT10;
            break;
        case HOLD_TWOFIFTYSIX:
            holdTimeSet = ADC12SHT13;
            break;
        case HOLD_THREEEIGHTYFOUR:
            holdTimeSet = ADC12SHT13 | ADC12SHT10;
            break;
        case HOLD_FIVETWELVE:
            holdTimeSet = ADC12SHT13 | ADC12SHT11;
            break;
        default:
            holdTimeSet = DEFAULT_SELECTION;
            break;
    }
    ADC12CTL0 |= holdTimeSet;
}

/********************************************************* ADC CONTROL REGISTER 1 ****************************************************************/
uint8_t read_ADC_busy_flag(void){
    return (ADC12CTL0 & ADC12BUSY);
}

void set_conversion_sequence(uint8_t sequenceType){
    uint16_t sequenceTypeSet;

    // clear the bits
    ADC12CTL1 &= ~(ADC12CONSEQ0 | ADC12CONSEQ1);

    // select which bits to set
    switch(sequenceType){
        case SINGLE_CHANNEL_SINGLE_CONVERSION:
            sequenceTypeSet = DEFAULT_SELECTION;
            break;
        case MULTI_CHANNEL_SINGLE_CONVERSION:
            sequenceTypeSet = ADC12CONSEQ0;
            break;
        case SINGLE_CHANNEL_REPEAT_CONVERSION:
            sequenceTypeSet = ADC12CONSEQ1;
            break;
        case MULTI_CHANNEL_REPEAT_CONVERSION:
            sequenceTypeSet = ADC12CONSEQ1 | ADC12CONSEQ0;
        default:
            sequenceTypeSet = DEFAULT_SELECTION;
            break;
    }
    ADC12CTL1 |= sequenceTypeSet;
}

void set_ADC_clock_source(uint8_t clockSource){
    uint16_t clockSourceSet;

    // clear the bits
    ADC12CTL1 &= ~(ADC12SSEL0 | ADC12SSEL1);

    // select which bits to set
    switch(clockSource){
        case ADC_OSCILLATOR:
            clockSourceSet = DEFAULT_SELECTION;
            break;
        case ACLOCK:
            clockSourceSet = ADC12SSEL0;
            break;
        case MCLOCK:
            clockSourceSet = ADC12SSEL1;
            break;
        case SMCLOCK:
            clockSourceSet = ADC12SSEL1 | ADC12SSEL0;
            break;
        default:
            clockSourceSet = DEFAULT_SELECTION;
            break;
    }
    ADC12CTL1 |= clockSourceSet;
}

void set_ADC_secondary_divider(uint8_t divisor){
    uint16_t divisorSet;

    // clear the bits
    ADC12CTL1 &= ~(ADC12DIV0 | ADC12DIV1 | ADC12DIV2);

    // select which bits to set
    switch(divisor){
        case ADC_DIV_1:
            divisorSet = DEFAULT_SELECTION;
            break;
        case ADC_DIV_2:
            divisorSet = ADC12DIV0;
            break;
        case ADC_DIV_3:
            divisorSet = ADC12DIV1;
            break;
        case ADC_DIV_4:
            divisorSet = ADC12DIV1 | ADC12DIV0;
            break;
        case ADC_DIV_5:
            divisorSet = ADC12DIV2;
            break;
        case ADC_DIV_6:
            divisorSet = ADC12DIV2 | ADC12DIV0;
            break;
        case ADC_DIV_7:
            divisorSet = ADC12DIV2 | ADC12DIV1;
            break;
        case ADC_DIV_8:
            divisorSet = ADC12DIV2 | ADC12DIV1 | ADC12DIV0;
            break;
        default:
            divisorSet = DEFAULT_SELECTION;
    }
    ADC12CTL1 |= divisorSet;
}

void set_ADC_sample_inversion(uint8_t invert){
    if(invert){
        ADC12CTL1 |= ADC12ISSH;
    }
    else{
        ADC12CTL1 &= (~ADC12ISSH);
    }
}

void set_ADC_sample_pulse_mode(uint8_t pulse){
    if(pulse){
       ADC12CTL1 |= ADC12SHP;
    }
    else{
        ADC12CTL1 &= (~ADC12SHP);
    }
}

void set_ADC_sample_trigger_source(uint8_t source){
    uint16_t sourceSet;

    // clear the bits
    ADC12CTL1 &= ~(ADC12SHS0 | ADC12SHS1 | ADC12SHS2);

    // select which bits to set
    switch(source){
        case SOFTWARE_SOURCE:
            sourceSet = DEFAULT_SELECTION;
            break;
        case TA0_CCR1:
            sourceSet = ADC12SHS0;
            break;
        case TB0_CCR0:
            sourceSet = ADC12SHS1;
            break;
        case TB0_CCR1:
            sourceSet = ADC12SHS1 | ADC12SHS0;
            break;
        case TA1_CCR1:
            sourceSet = ADC12SHS2;
            break;
        case TA2_CCR1:
            sourceSet = ADC12SHS2 | ADC12SHS0;
            break;
        case TA3_CCR1:
            sourceSet = ADC12SHS2 | ADC12SHS1;
            break;
        // the case for ADC12SHS2 | ADC12SHS1 | ADC12SHS0 is reserved
        default:
            sourceSet = DEFAULT_SELECTION;
            break;
    }
    ADC12CTL1 |= sourceSet;
}

void set_ADC_clock_predivider(uint8_t divisor){
    uint16_t divisorSet;

    // clear the bits
    ADC12CTL1 &= ~(ADC12PDIV0 | ADC12PDIV1);

    // select which bits to set
    switch(divisor){
        case ADC_PRE_DIV_1:
            divisorSet = DEFAULT_SELECTION;
            break;
        case ADC_PRE_DIV_4:
            divisorSet = ADC12PDIV0;
            break;
        case ADC_PRE_DIV_32:
            divisorSet = ADC12PDIV1;
            break;
        case ADC_PRE_DIV_64:
            divisorSet = ADC12PDIV0 | ADC12PDIV1;
            break;
    }
    ADC12CTL1 |= divisorSet;
}

/********************************************************* ADC CONTROL REGISTER 2 ****************************************************************/

void set_ADC_low_power_mode(void){
    ADC12CTL2 |= ADC12PWRMD;
}

void clear_ADC_low_power_mode(void){
    ADC12CTL2 &= ~(ADC12PWRMD);
}

void set_ADC_signed_twos_complement_output(void){
    ADC12CTL2 |= ADC12DF;
}

void clear_ADC_signed_twos_complement_output(void){
    ADC12CTL2 &= ~(ADC12DF);
}

void set_ADC_resolution(uint8_t resolution){
    uint16_t resolutionSet;

    // clear the bits
    ADC12CTL2 &= ~(ADC12RES0 | ADC12RES1);

    // select which bits to set
    switch(resolution){
        case ADC_8BIT_RES:
            resolutionSet = DEFAULT_SELECTION;
            break;
        case ADC_10BIT_RES:
            resolutionSet = ADC12RES0;
            break;
        case ADC_12BIT_RES:
            resolutionSet = ADC12RES1;
            break;
    }
    ADC12CTL2 |= resolutionSet;
}

/********************************************************* ADC CONTROL REGISTER 3 ****************************************************************/

void select_ADC_mem_register(uint8_t memRegister){

    // clear the bits
    ADC12CTL3 |= ADC12CSTARTADD0 | ADC12CSTARTADD1 | ADC12CSTARTADD2 | ADC12CSTARTADD3 | ADC12CSTARTADD4;

    // ensure the user selection is in the bounds
    if(memRegister > 0x1F){
        memRegister = 0x00;
    }

    // set the bits
    ADC12CTL3 |= memRegister;
}

void set_or_clear_BAT_input_source(uint8_t source){
    if(source){
        ADC12CTL3 |= ADC12BATMAP;
    }
    else{
        ADC12CTL3 &= ~(ADC12BATMAP);
    }
}

void set_or_clear_temp_sensor_input_source(uint8_t source){
    if(source){
        ADC12CTL3 |= ADC12TCMAP;
    }
    else{
        ADC12CTL3 &= ~(ADC12TCMAP);
    }
}

void set_or_clear_internal_source_0(uint8_t source){
    if(source){
        ADC12CTL3 |= ADC12ICH0MAP;
    }
    else{
        ADC12CTL3 &= ~(ADC12ICH0MAP);
    }
}

void set_or_clear_internal_source_1(uint8_t source){
    if(source){
        ADC12CTL3 |= ADC12ICH1MAP;
    }
    else{
        ADC12CTL3 &= ~(ADC12ICH1MAP);
    }
}

void set_or_clear_internal_source_2(uint8_t source){
    if(source){
        ADC12CTL3 |= ADC12ICH2MAP;
    }
    else{
        ADC12CTL3 &= ~(ADC12ICH2MAP);
    }
}

void set_or_clear_internal_source_3(uint8_t source){
    if(source){
        ADC12CTL3 |= ADC12ICH3MAP;
    }
    else{
        ADC12CTL3 &= ~(ADC12ICH3MAP);
    }
}
