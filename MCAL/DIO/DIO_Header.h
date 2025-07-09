#ifndef DIO_HEADER_H
#define DIO_HEADER_H

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_Interface.h"


void DIO_PINMode(u8 reg,int SIGNAL, int number );
void DIO_DigitalWrite(u8 reg,int SIGNAL,int number);


#endif