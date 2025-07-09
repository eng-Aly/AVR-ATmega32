#include "DIO_Header.h"

void DIO_PINMode(u8 reg,int number,int SIGNAL){
    switch (SIGNAL)
    {
    case OUTPUT:
        clear_bit(reg,number);
        break;
    case INPUT:
        set_bit(reg,number);     
        break;

    default:
        break;
    }
}

void DIO_PORTMode(u8 reg,int SIGNAL){
    switch (SIGNAL)
    {
    case OUTPUT:
        set_byte(reg);
        break;
    case INPUT:
         clear_byte(reg);
         break;
    default:
        break;
    }
}

void DIO_DigitalWrite(u8 reg,int number,int SIGNAL){
    switch (SIGNAL)
    {
    case LOW:
        clear_bit(reg,number);
        break;
    case HIGH:
            set_bit(reg,number);    
    
    default:
        break;
    }
}



int DIO_DigitalRead(u8 reg,int number){
    switch (get_bit(reg,number))
    {
    case HIGH:
        return 1;
    case LOW:
        return 0;    
    
    default:
        break;
    }
}