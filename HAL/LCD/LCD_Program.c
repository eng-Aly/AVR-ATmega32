#include "LCD_Header.h"

void LCD_init_8bit(){
    DIO_PINMode(CONTROL_DDR,E,OUTPUT);
    DIO_PINMode(CONTROL_DDR,RS,OUTPUT);
    DIO_PINMode(CONTROL_DDR,RW,OUTPUT);

    DIO_PORTMode(DATA_DDR,OUTPUT);



}

void LCD_WriteCommand(u8 command){
    DIO_DigitalWrite(CONTROL_PORT,RS,LOW);
    DIO_DigitalWrite(CONTROL_PORT,RW,LOW);

    DIO_PortDigitalWrite(DATA_PORT,command);
    _delay_ms(3);

    DIO_DigitalWrite(CONTROL_PORT,E,HIGH);
    _delay_ms(2);
    DIO_DigitalWrite(CONTROL_PORT,E,LOW);
}