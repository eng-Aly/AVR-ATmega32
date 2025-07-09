#include "DIO_Header.h"

void DIO_PINMode(volatile u8 *reg,int number,int SIGNAL){
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

void DIO_PORTMode(volatile u8 *reg,int SIGNAL){
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

void DIO_DigitalWrite(volatile u8 *reg,int number,int SIGNAL){
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



int DIO_DigitalRead(volatile u8 *reg,int number){
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

void DIO_PortDigitalWrite(volatile u8 *reg,u8 SIGNAL){
    *reg=SIGNAL;
}