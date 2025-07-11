#include <util/delay.h>
#include "../HAL/LED/LED_Header.h"

void setup(){
    LED_Init(REDLED_DDR,REDLED_PIN);
    LED_Init(YELLOWLED_DDR,YELLOWLED_PIN);
    LED_Init(GREENLED_DDR,GREENLED_PIN);
}

void loop(){
    LED_Status(REDLED_PORT,REDLED_PIN,HIGH);
    _delay_ms(3000);
    LED_Status(YELLOWLED_PORT,REDLED_PIN,HIGH);
    _delay_ms(3000);
    LED_Status(GREENLED_PORT,REDLED_PIN,HIGH);
    _delay_ms(3000);
    
}

int main(){
    setup();
    while (1)
    {
        loop();
    }
    
    return 0;
}