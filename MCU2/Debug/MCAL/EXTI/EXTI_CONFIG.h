// this should change from one mp to another
#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H

#include "../DIO/DIO_Header.h"


#define Status_REG                        ((volatile unsigned char*)(0x5F))
#define ENABLE_INT_BIT                    7 

#define GENRAL_INT_CONTROL_REG            ((volatile unsigned char*)(0x5B)) 
#define INT0                              6
#define INT1                              5
#define INT2                              7

#define INT_0_1_CONTROL_REG               ((volatile unsigned char*)(0x55))
#define INT0_ISC0                         0
#define INT0_ISC1                         1
#define INT1_ISC0                         2
#define INT1_ISC1                         3 


#define INT_2_CONTROL_REG                 ((volatile unsigned char*)(0x54))
#define INT2_ISC2                         6



#define GENRAL_INT_FLAG_REG              ((volatile unsigned char*)(0x5A))

#endif

