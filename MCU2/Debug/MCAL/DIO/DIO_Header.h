#ifndef DIO_HEADER_H
#define DIO_HEADER_H

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_Private.h"


void DIO_PINMode(volatile u8 *reg,int number,int SIGNAL);
void DIO_DigitalWrite(volatile u8 *reg,int number,int SIGNAL);
u8 DIO_DigitalRead(volatile u8 *reg,int number);

void DIO_PORTMode(volatile u8 *reg,int SIGNAL);
void DIO_PortDigitalWrite(volatile u8 *reg,u8 SIGNAL);




#endif