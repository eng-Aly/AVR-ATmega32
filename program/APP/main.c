#define F_CPU 8000000UL
#include <util/delay.h>
#include "../HAL/LED/LED_Header.h"

void setup(){
    LED_Init(REDLED_DDR,REDLED_PIN);
    LED_Init(YELLOWLED_DDR,YELLOWLED_PIN);
    LED_Init(GREENLED_DDR,GREENLED_PIN);
}

void loop(){
    LED_Status(GREENLED_PORT,GREENLED_PIN,LOW);
    LED_Status(REDLED_PORT,REDLED_PIN,HIGH);
    for (int i = 5; i >0; i--)
    {
       _delay_ms(100);
    }
    _delay_ms(100);
    LED_Status(REDLED_PORT,REDLED_PIN,LOW);
    LED_Status(YELLOWLED_PORT,YELLOWLED_PIN,HIGH);
    for (int i = 5; i >0; i--)
    {
       _delay_ms(100);
    }    
    LED_Status(YELLOWLED_PORT,YELLOWLED_PIN,LOW);    
    LED_Status(GREENLED_PORT,GREENLED_PIN,HIGH);
    for (int i = 5; i >0; i--)
    {
       _delay_ms(100);
    }
    
}

int main(){
    setup();
    while (1)
    {
        loop();
    }
    
    return 0;
}