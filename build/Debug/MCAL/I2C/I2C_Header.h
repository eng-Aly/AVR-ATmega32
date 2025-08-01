#ifndef I2C_HEADER_H
#define I2C_HEADER_H

#include "I2C_Private.h"
#include "I2C_Config.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Header.h"
#include "../../MCAL/EXTI/EXTI_Header.h"


typedef enum{
    I2C_OK,
}I2C_ERROR_TABLE;

void I2C_Master_Init(u8 Master_Address);
void I2C_MASTER_StopCondition();
void I2C_SLAVE_Init(u8 SLAVE_ADDRESS);


#endif