#include "ADC_Header.h"

void ADC_Init(u8 adjust, u8 enableAutoTrigger, u8 referenceVoltage) {
    set_bit(ADCS_AREG, ADEN); // Enable ADC
    if (enableAutoTrigger == ENABLE)
    {
        set_bit(ADCS_AREG, ADATE); // Enable Auto Triggering
    }
    else if (enableAutoTrigger == DISABLE)
    {
        clear_bit(ADCS_AREG, ADATE); // Disable Auto Triggering
    }
    // set the reference voltage
    if (referenceVoltage == AVCC)
    {
        set_bit(ADMUX_REG, REFS0); // Set reference voltage to AVCC
        clear_bit(ADMUX_REG, REFS1); // Set reference voltage to AVCC
    }
    else if (referenceVoltage == AREF)
    {
        clear_bit(ADMUX_REG, REFS0);
        clear_bit(ADMUX_REG, REFS1);
    }
    else if (referenceVoltage == INTERNAL)
    {
        set_bit(ADMUX_REG, REFS0);
        set_bit(ADMUX_REG, REFS1);
    }
    // choose adjust mode
    if (adjust == LEFT_ADJUST) {
        set_bit(ADMUX_REG, ADLRA); // Set left adjust
    } else if (adjust == RIGHT_ADJUST) {
        clear_bit(ADMUX_REG, ADLRA); // Set right adjust
    }
    //ENABLE FREE RUNNING MODE
    clear_bit(SFIO_REG, ADTS0);
    clear_bit(SFIO_REG, ADTS1);
    clear_bit(SFIO_REG, ADTS2);   
    // Set ADC prescaler to 64 (for 16MHz clock, gives 250KHz ADC clock)
    clear_bit(ADCS_AREG, ADPS0);
    set_bit(ADCS_AREG, ADPS1);
    set_bit(ADCS_AREG, ADPS2);
}


u16 ADC_AnalogRead(u8 channel) {
    // clear the previous ADC channel
    clear_bit(ADMUX_REG, 0);
    clear_bit(ADMUX_REG, 1);
    clear_bit(ADMUX_REG, 2);
    clear_bit(ADMUX_REG, 3);
    clear_bit(ADMUX_REG, 4);


    *ADMUX_REG = (*ADMUX_REG & 0b11100000) | (channel & 0b00011111);

    if (get_bit(ADCS_AREG,ADATE)==DISABLE)
    {
        // Start conversion
        set_bit(ADCS_AREG, ADSC);
        // Wait for conversion to complete
        while (get_bit(ADCS_AREG, ADIF) == 0);
        // Clear the interrupt flag by writing a logic one to it
        set_bit(ADCS_AREG, ADIF);        
    }
    else if (get_bit(ADCS_AREG,ADATE)==ENABLE)
    {
        /* code */
    }
    
    


    u8 adjust = get_bit(ADMUX_REG, ADLRA);
    if (adjust == LEFT_ADJUST) {
        return (*ADC_REG >> 6); // Read the 10-bit value from ADCH and ADCL, left adjusted
    }
    else if (adjust == RIGHT_ADJUST)
    {
       return *ADC_REG;        
    }    
}
