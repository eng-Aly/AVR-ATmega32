#ifndef LED_HEADER_H
#define LED_HEADER_H

#include "LED_CONFIG.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

void LED_Init(volatile u8 *reg,int number);
void LED_PortInit(volatile u8 *reg,int number);
void LED_Status(volatile u8 *reg,int number,int signal);
void LED_PortStatus(volatile u8 *reg,int signal);



#endif