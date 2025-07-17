#include "ADC_Header.h"

void ADC_Init(){
    set_bit(ADCS_AREG, ADEN); // Enable ADC

    set_bit(ADCS_AREG, ADATE); // Enable Auto Triggering
    //ENABLE FREE RUNNING MODE
    clear_bit(SFIO_REG, ADTS0);
    clear_bit(SFIO_REG, ADTS1);
    clear_bit(SFIO_REG, ADTS2);

    set_bit(ADMUX_REG, REFS0); // Set reference voltage to AVCC
    set_bit(ADMUX_REG, REFS1); // Set reference voltage to AVCC
    set_bit(ADMUX_REG, ADLRA); // Left adjust ADC result
    
    // Set ADC prescaler to 64 (for 16MHz clock, gives 250KHz ADC clock)
    clear_bit(ADCS_AREG, ADPS0);
    set_bit(ADCS_AREG, ADPS1);
    set_bit(ADCS_AREG, ADPS2);

    

}

u16 ADC_AnalogRead(u8 channel) {
    u16 adcValue = 0;
    u8 adjust = get_bit(ADMUX_REG, ADLRA); // Check if
    // Select ADC channel with safety check
    if (channel > 7) {
        return 0; // Invalid channel, return 0
    }
    
    // Set the channel in ADMUX
    *ADMUX_REG &= 0xF8; // Clear the previous channel selection
    *ADMUX_REG |= channel; // Set the new channel

    // Start the conversion
    set_bit(ADCS_AREG, ADSC);

    // Wait for conversion to complete
    while (get_bit(ADCS_AREG, ADIF) == 0);

    // Clear the ADIF flag by writing a one to it
    set_bit(ADCS_AREG, ADIF);

    // Read the ADC value
    if (adjust==RIGHT_ADJUST){
         adcValue = *ADC_REG<<6;                     //it may be reading only 8 bits i dont know 
    }
    else if (adjust==LEFT_ADJUST)
    {
         adcValue = *ADC_REG>>6;                       
    }
    

    return adcValue;
}
