#ifndef ADC_HEADER_H
#define ADC_HEADER_H
#include "ADC_Private.h"
#include "ADC_Config.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

void ADC_Init(u8 adjust, u8 enableAutoTrigger, u8 referenceVoltage);
u16 ADC_AnalogRead(u8 channel);
#endif