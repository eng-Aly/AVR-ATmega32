/*
 * UART.c
 *
 * Created: 3/29/2016 9:46:10 AM
 * Author : user
 */ 
#define F_CPU 8000000UL


#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"  
#include "stdio.h"

#include "../HAL/LCD/LCD_Header.h"
#include "../MCAL/DIO/DIO_Header.h"
#include "../MCAL/ADC/ADC_Header.h"


#define F_CPUj 8000000UL
#define VCC           5.0


#define MUX_PORT  PORTB_REG
#define MUX_DDR   DDRB_REG


#define MUX_1     2
#define MUX_2     3
#define MUX_3     4

#define GND_PORT PORTD_REG
#define GND_DDR  DDRD_REG

#define GND_1    2
#define GND_2    3
#define GND_3    4


//  #define MUX_1     0
//  #define MUX_2     1
//  #define MUX_3     3
#define START_INPUT 0


void Setup() {
    // Set PORTC pins 3, 4, 5 as output
    DIO_PINMode(MUX_DDR, MUX_1, OUTPUT);
    DIO_PINMode(MUX_DDR, MUX_2, OUTPUT);
    DIO_PINMode(MUX_DDR, MUX_3, OUTPUT);
    DIO_PINMode(MUX_DDR, START_INPUT,INPUT);

    DIO_PINMode(GND_DDR,GND_1,OUTPUT);
    DIO_PINMode(GND_DDR,GND_2,OUTPUT);
    DIO_PINMode(GND_DDR,GND_3,OUTPUT);


    DIO_DigitalWrite(GND_PORT, GND_1, HIGH);
    DIO_DigitalWrite(GND_PORT, GND_2, 0);
    DIO_DigitalWrite(GND_PORT, GND_3, HIGH);

    //UART Init
    uart_initialize();

    //ADC Init
    ADC_Init(RIGHT_ADJUST,DISABLE,AVCC);
}

void loop() {
    write_uart_strg("Started reading IC values\r\n");

    int i;
    for (i = 0; i < 8; i++) {

        // ----- MUX CONTROL -----
        if (i & 1) DIO_DigitalWrite(MUX_PORT, MUX_1, 1);
        else       DIO_DigitalWrite(MUX_PORT, MUX_1, 0);

        if (i & 2) DIO_DigitalWrite(MUX_PORT, MUX_2, 1);
        else       DIO_DigitalWrite(MUX_PORT, MUX_2, 0);

        if (i & 4) DIO_DigitalWrite(MUX_PORT, MUX_3, 1);
        else       DIO_DigitalWrite(MUX_PORT, MUX_3, 0);

        _delay_ms(250);

        // ----- READ ADC -----
        u16 adc_raw = ADC_AnalogRead(0);  // or whichever channel you want
        float adc_volt = (adc_raw * VCC) / 1024.0;

        // ----- CONVERT FLOAT (your working method) -----
        float frac_f = adc_volt - (int)adc_volt;
        int frac_i = (int)(frac_f * 100);

        char buffer[32];
        sprintf(buffer, "Iter %d: %d.%02d V\r\n", i, (int)adc_volt, frac_i);

        write_uart_strg(buffer);
    }
}


int main(void)
{
    Setup();
    while (1)
    {    
      if (DIO_DigitalRead(PINB_REG,START_INPUT)==1)
      {
          // 
          loop();
      }
      else 
      {
        write_uart_strg("Press the button to start\n\r");

        DIO_DigitalWrite(PORTB_REG, MUX_3, HIGH);
        DIO_DigitalWrite(PORTB_REG, MUX_2, 0);
        DIO_DigitalWrite(PORTB_REG, MUX_1, 0);





      }
    }
}
/*
void loop2(){
    char IC_diode[16];
    u16 diode_adc = ADC_AnalogRead(1);
    float diode_analog = (diode_adc*VCC)/1024.0; 


    float diode_carry_f =diode_analog - (int)diode_analog;
    int diode_carry_i=(int)(diode_carry_f*100);

    sprintf(IC_diode, "%d.%02d V", (int)diode_analog, diode_carry_i); 


    write_uart_strg(IC_diode);
    _delay_ms(1000);
}
int main(void){
  Setup();
  while (1)
  {
    loop2();
  }
  
}
*/