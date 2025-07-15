#include "../MCAL/DIO/DIO_Header.h"
#include "../MCAL/EXTI/EXTI_Header.h"
#include "../HAL/KEYPAD/KEYPAD_Header.h"
#include "../HAL/LCD/LCD_Header.h"



void setup() {
    LCD_init_8bit();       // Initialize LCD
    KEYPAD_INIT();         // Initialize Keypad
    //LCD_WriteString("Press Key:");
}
void loop() {
    u8 key = KEYPAD_GetPressedKey();
    if (key != 0xFF) {
        LCD_WriteChar(key);
        _delay_ms(30);  // Optional debounce
    }
}


int main() {
    setup();
    LCD_WriteChar('A');
    while (1) {
        loop();
    }
    return 0;
}

//LCD TEST --> WORKING
/*
int main(){
    LCD_init_8bit();
    LCD_WriteChar('H');
    return 0;   
}


//test interrupt --> working
void toggle_led() {
    static u8 state = 0;
    state = !state;
    DIO_DigitalWrite(PORTB_REG, PB0, state);
}

void setup() {
    // Initialize LED pin as output
    DIO_PINMode(DDRB_REG, PB0, OUTPUT);
    DIO_DigitalWrite(PORTB_REG, PB0, LOW);  // Start with LED off

    // Set INT0 pin as input
    DIO_PINMode(DDRD_REG, PD2, INPUT);
    DIO_DigitalWrite(PORTD_REG, PD2, HIGH);  // Enable internal pull-up

    // Initialize External Interrupt
    EXTI_Init(INT0, FALLING_EDGE_INT);         // Falling edge on INT0
    EXTI_SetCallBack(INT0, &toggle_led);       // Set ISR callback
}

int main() {
    setup();
    while (1) {
        // Do nothing, just wait for interrupt
    }
}*/
