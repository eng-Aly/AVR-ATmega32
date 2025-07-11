#include "LED_Header.h"


void LED_Init(volatile u8 *reg,int number){
    set_bit(reg,number);
}

void LED_PortInit(volatile u8 *reg,int number){
    set_byte(reg);
}


void LED_Status(volatile u8 *reg,int number,int signal){
    switch (signal)
    {
    case HIGH:
        set_bit(reg,number);
        break;
    case LOW:
         clear_bit(reg,number);
         break;   
    default:
        break;
    }

}

void LED_PortStatus(volatile u8 *reg,int signal){
    switch (signal)
    {
    case HIGH:
        set_byte(reg);
        break;
    case LOW:
         clear_byte(reg);    
    default:
        break;
    }

}