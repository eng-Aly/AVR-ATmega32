#ifndef DIO_HEADER_H
#define DIO_HEADER_H

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_Private.h"


void DIO_PINMode(u8 reg,int number,int SIGNAL);
void DIO_DigitalWrite(u8 reg,int number,int SIGNAL);
void DIO_PORTMode(u8 reg,int SIGNAL);
int DIO_DigitalRead(u8 reg,int number);




#endif