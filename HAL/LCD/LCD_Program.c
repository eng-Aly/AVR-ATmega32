#include "LCD_Header.h"

void LCD_init_8bit(){
    DIO_PINMode(CONTROL_DDR,E,OUTPUT);
    DIO_PINMode(CONTROL_DDR,RS,OUTPUT);
    DIO_PINMode(CONTROL_DDR,RW,OUTPUT);

    DIO_PORTMode(DATA_DDR,OUTPUT);

    DIO_DigitalWrite(CONTROL_PORT,RS,LOW);
    DIO_DigitalWrite(CONTROL_PORT,RW,LOW);


}