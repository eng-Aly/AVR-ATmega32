#include "SSEG_Header.h"


void SSEG_Init(volatile u8* reg){
    set_byte(reg);
}

void SSEG_PrintNumber(volatile u8* reg,int number,int type){
    switch (type)
    {
    case COMMON_CATHODE:
        DIO_PortDigitalWrite(reg,COMMON_CATHODE_ARRAY[number]);
        break;
    case COMMON_ANODE:
        DIO_PortDigitalWrite(reg,~COMMON_CATHODE_ARRAY[number]);
         break;
    default:
        break;
    }
}

void SSEG_PrintNumber_Dot(volatile u8* reg,int number,int type){
    switch (type)
    {
    case COMMON_CATHODE:
        DIO_PortDigitalWrite(reg,COMMON_CATHODE_ARRAY[number]+1);
        break;
    case COMMON_ANODE:
        DIO_PortDigitalWrite(reg,~(COMMON_CATHODE_ARRAY[number]+1));
         break;
    default:
        break;
    }
}