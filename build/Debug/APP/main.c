#include <stdio.h>
#include "../MCAL/ADC/ADC_Header.h"
#include "../MCAL/DIO/DIO_Header.h"
#include "../HAL/LCD/LCD_Header.h"

#define VCC 5

void setup(){
    ADC_Init(LEFT_ADJUST,DISABLE,AVCC);
    LCD_init_8bit();
}

void loop(){
    char Light_sensor[16];
    u16 Light_adc = ADC_AnalogRead(0);
    float Light_voltage = (Light_adc / 1023.0) * VCC;
    int Light_volts = (int)Light_voltage;
    int Light_millivolts = (int)((Light_voltage - Light_volts) * 1000);  // up to 3 decimal places
    sprintf(Light_sensor, "%d.%02d V", Light_volts, Light_millivolts);  // E.g., "2.345 V"


    char Temp_sensor[16];
    u16 Temp_adc=ADC_AnalogRead(1);
    float Temp_analog=(Temp_adc*5000UL)/1024;
    int Temp=(int)Temp_analog/10;

    
    
    sprintf(Temp_sensor, "%d.%02d C", Temp,00 );  // E.g., "2.345 V"


    LCD_WriteString("Light: ");
    LCD_WriteString(Light_sensor);
    LCD_SetCursor(2,0);
    LCD_WriteString("Temp:");
    LCD_WriteString(Temp_sensor);
    _delay_ms(100);
    LCD_Clear();

}


int main(){

    setup();
    while (1)
    {
        loop();
    }
    return 0;
}