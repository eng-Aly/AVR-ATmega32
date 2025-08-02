#include <stdio.h>
#include "../MCAL/ADC/ADC_Header.h"
#include "../MCAL/DIO/DIO_Header.h"
#include "../HAL/LCD/LCD_Header.h"
#include "MCU2_CONFIG.h"



void setup(){
    ADC_Init(LEFT_ADJUST,DISABLE,AVCC);
    LCD_init_8bit();
    DIO_PINMode(LED_DDR,LED,OUTPUT);
    DIO_PINMode(BUZ_DDR,BUZ,OUTPUT);
    DIO_PINMode(FAN_DDR,FAN,OUTPUT); 
    DIO_PINMode(PUMP_DDR,PUMP,OUTPUT);        
}

void loop(){
    char Light_sensor[16];
    u16 Light_adc = ADC_AnalogRead(0);
    float Light_analog = (Light_adc*VCC)/1024.0;
    int Light = 5-(int)Light_analog;  
    sprintf(Light_sensor, "%d.%02d V", Light, 00);  


    char Temp_sensor[16];
    u16 Temp_adc=ADC_AnalogRead(1);
    float Temp_analog=(Temp_adc*5000UL)/1024;
    int Temp=(int)Temp_analog/10;   
    sprintf(Temp_sensor, "%d.%02d C", Temp,00 );  // E.g., "2.345 V"

    char Smoke_sensor[16];
    u16 Smoke_adc=ADC_AnalogRead(2);
    float Smoke_analog=(Smoke_adc*5000UL)/1024;
    int Smoke=(int)((Smoke_analog/10)*(120.0/482));   
    sprintf(Smoke_sensor, "%d.%02d P", Smoke,00 );  // E.g., "2.345 V"

    //Light Control
    if(Light<1.5){
        DIO_DigitalWrite(LED_PORT,LED,HIGH);
    }
    else{
        DIO_DigitalWrite(LED_PORT,LED,LOW);
    }

    // BUZZER control
    if (Temp > 50 || Smoke > 70) {
        DIO_DigitalWrite(BUZ_PORT, BUZ, HIGH);
    } else {
        DIO_DigitalWrite(BUZ_PORT, BUZ, LOW);
    }

    // FAN control
    if (Temp > 30) {
        DIO_DigitalWrite(FAN_PORT, FAN, HIGH);
    } else {
        DIO_DigitalWrite(FAN_PORT, FAN, LOW);
    }

    // PUMP control
    if (Smoke > 70) {
        DIO_DigitalWrite(PUMP_PORT, PUMP, HIGH);
    } else {
        DIO_DigitalWrite(PUMP_PORT, PUMP, LOW);
    }
    

    
    LCD_WriteString("Light: ");
    LCD_WriteString(Light_sensor);
    LCD_SetCursor(2,0);
    LCD_WriteString("Temp:");
    LCD_WriteString(Temp_sensor);
    LCD_SetCursor(1,8);
    LCD_WriteString("Smoke:");
    LCD_WriteString(Smoke_sensor);
    _delay_ms(10);
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