#include "DIO_Header.h"

void DIO_PINMode(u8 reg,int SIGNAL, int number ){
    switch (SIGNAL)
    {
    case LOW:
        clear_bit(reg,number);
        break;
    case HIGH:
        set_bit(reg,number);     
        break;

    default:
        break;
    }
}