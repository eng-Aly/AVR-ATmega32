#ifndef USART_HEADER_H
#define USART_HEADER_H

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "USART_Config.h"
#include "USART_Private.h"

void USART_Init(u8 Baud_rate,u8 parity, u8 speed,u8 stop_bit);


#endif