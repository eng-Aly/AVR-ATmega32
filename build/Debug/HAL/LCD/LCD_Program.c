#include "LCD_Header.h"



void LCD_WriteCommand(u8 command){
    DIO_DigitalWrite(CONTROL_PORT,RS,LOW);
    DIO_DigitalWrite(CONTROL_PORT,RW,LOW);

    DIO_PortDigitalWrite(DATA_PORT,command);
    _delay_ms(3);

    DIO_DigitalWrite(CONTROL_PORT,E,HIGH);
    _delay_ms(2);
    DIO_DigitalWrite(CONTROL_PORT,E,LOW);
}
void LCD_init_8bit(){
    DIO_PINMode(CONTROL_DDR,E,OUTPUT);
    DIO_PINMode(CONTROL_DDR,RS,OUTPUT);
    DIO_PINMode(CONTROL_DDR,RW,OUTPUT);

    DIO_PORTMode(DATA_DDR,OUTPUT);

    LCD_WriteCommand(FUNCTION_SET_8BIT_2LS_5X10);
    _delay_ms(3);
    LCD_WriteCommand(ON_OFF_CONTROL_DISPLAY_CURSORS_BLINK);
    _delay_ms(3);
    LCD_WriteCommand(DISPLAY_CLEAR);



}


