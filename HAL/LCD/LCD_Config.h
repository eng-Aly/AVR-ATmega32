//This file is replaced with config for each different app

#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

#include "../../MCAL/DIO/DIO_Header.h"

#define RS               PB0
#define RW               PB1
#define E                PB2

#define CONTROL_DDR       DDRB_REG
#define CONTROL_PORT      PORTB_REG

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