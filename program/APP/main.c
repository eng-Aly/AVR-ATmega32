#include <stdio.h>
#include "../MCAL/ADC/ADC_Header.h"
#include "../MCAL/DIO/DIO_Header.h"
#include "../HAL/LCD/LCD_Header.h"

#define VCC           5
#define LED           PB0
#define BUZ           PB1
#define LED_PORT      PORTB_REG
#define BUZ_PORT      PORTB_REG
#define LED_DDR       DDRB_REG
#define BUZ_DDR       DDRB_REG

void setup(){
    ADC_Init(LEFT_ADJUST,DISABLE,AVCC);
    LCD_init_8bit();
    DIO_PINMode(LED_DDR,LED,OUTPUT);
    DIO_PINMode(BUZ_DDR,BUZ,OUTPUT);    
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

    if(Light<1.5){
        DIO_DigitalWrite(LED_PORT,LED,HIGH);
    }
    else{
        DIO_DigitalWrite(LED_PORT,LED,LOW);
    }

    if (Temp>50)
    {
        DIO_DigitalWrite(BUZ_PORT,BUZ,HIGH);
    }
    else{
        DIO_DigitalWrite(BUZ_PORT,BUZ,LOW);
    }
    


    LCD_WriteString("Light: ");
    LCD_WriteString(Light_sensor);
    LCD_SetCursor(2,0);
    LCD_WriteString("Temp:");
    LCD_WriteString(Temp_sensor);
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