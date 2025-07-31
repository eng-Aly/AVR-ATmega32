#ifndef EXIT_HEADER_H
#define EXIT_HEADER_H

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "EXTI_CONFIG.h"
#include "EXTI_Private.h"



void EXTI_EnableGlobalINT();
void EXTI_DisableGlobalINT();
void EXTI_DisableINT(u8 INT_PIN);
void EXTI_SetINTMode(u8 INT_PIN,u8 mode);
void EXTI_ClearFlag(u8 INT_PIN);
void EXTI_Init(u8 INT_PIN,u8 mode);
void EXTI_SetCallBack(u8 INT_PIN,void (*local_FunctionPointer) (void));


#endif