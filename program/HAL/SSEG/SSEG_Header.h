#ifndef SSEG_HEADER_H
#define SSEG_HEADER_H

#include "SSEG_CONFIG.h"
#include "SSEG_Private.h"

void SSEG_Init(volatile u8* reg);
void SSEG_PrintNumber(volatile u8* reg,int number,int type);
void SSEG_PrintNumber_Dot(volatile u8* reg,int number,int type);


#endif