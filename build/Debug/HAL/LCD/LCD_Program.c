#include "LCD_Header.h"

 

void LCD_init_8bit(){
    DIO_PINMode(CONTROL_DDR,E,OUTPUT);
    DIO_PINMode(CONTROL_DDR,RS,OUTPUT);
    DIO_PINMode(CONTROL_DDR,RW,OUTPUT);

    DIO_PORTMode(DATA_DDR,OUTPUT);

    _delay_ms(35);

    LCD_WriteCommand(FUNCTION_SET_8BIT_2LS_5X10);
    _delay_ms(1);
    LCD_WriteCommand(ON_OFF_CONTROL_DISPLAY_CURSORS_OFF);
    _delay_ms(1);
    LCD_WriteCommand(DISPLAY_CLEAR);
    _delay_ms(2);
    LCD_WriteCommand(ENTRY_MODE_INCREASE_NO_SHIFT);
    _delay_ms(1);

}
void LCD_WriteCommand(u8 command){
    DIO_DigitalWrite(CONTROL_PORT,RS,LOW);
    DIO_DigitalWrite(CONTROL_PORT,RW,LOW);

    DIO_PortDigitalWrite(DATA_PORT,command);
    

    DIO_DigitalWrite(CONTROL_PORT,E,HIGH);
    _delay_ms(2);
    DIO_DigitalWrite(CONTROL_PORT,E,LOW);
}


void LCD_WriteChar(u8 character) {
    DIO_DigitalWrite(CONTROL_PORT, RS, HIGH);  // RS = 1 for data
    DIO_DigitalWrite(CONTROL_PORT, RW, LOW);   // RW = 0 for write

    DIO_PortDigitalWrite(DATA_PORT, character);
    _delay_ms(1);

    DIO_DigitalWrite(CONTROL_PORT, E, HIGH);
    _delay_ms(1);
    DIO_DigitalWrite(CONTROL_PORT, E, LOW);
}


void LCD_CreateCustomChar(u8 location, u8 pattern[8]) {
    location &= 0x07; 
    LCD_WriteCommand(0x40 + (location * 8)); 

    for (u8 i = 0; i < 8; i++) {
        LCD_WriteChar(pattern[i]); 
    }

    // Return to DDRAM
    LCD_WriteCommand(DDRAM_ADDRESS);
}

void LCD_SetCursor(u8 row, u8 col) {
    u8 address = (row == 0) ? col : (0x40 + col);
    LCD_WriteCommand(DDRAM_ADDRESS | address);
}