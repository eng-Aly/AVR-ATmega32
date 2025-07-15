//This file is replaced with config for each different app

#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

#include "../../MCAL/DIO/DIO_Header.h"

#define RS               PA0
#define RW               PA1
#define E                PA2

#define CONTROL_DDR       DDRA_REG
#define CONTROL_PORT      PORTA_REG

#define DATA_DDR         DDRC_REG
#define DATA_PORT        PORTC_REG


#define DB0  PC0
#define DB1  PC1
#define DB2  PC2
#define DB3  PC3
#define DB4  PC4
#define DB5  PC5
#define DB6  PC6
#define DB7  PC7


#endif 