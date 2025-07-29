#ifndef USART_HEADER_H
#define USART_HEADER_H

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "USART_Config.h"
#include "USART_Private.h"
#include <stddef.h>

void USART_Init(u32 Baud_rate,u8 parity, u8 speed,u8 stop_bit);
void USART_Read_Data(u8 *Data);
void USART_Write_Data(u8 Data);
void USART_Async_Read_Data(u8 *Data);
void USART_Async_Write_Data(u8 *Data,void (*call_back)(void));

#endif