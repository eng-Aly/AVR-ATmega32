//THIS FILE IS CHANGED WITH DIFFERNT PINOUTS

#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Header.h"


#define KEYPAD_DDR                DDRB_REG
#define KEYPAD_PORT               PORTB_REG
#define KEYPAD_PIN                PINB_REG

#define KEYPAD_COLUMNS_NUMBER     4
#define KEYPAD_ROWS_NUMBER        4


#define KPAD_ROW0         PB0      
#define KPAD_ROW1         PB1
#define KPAD_ROW2         PB2
#define KPAD_ROW3         PB3
#define KPAD_COLUMN0      PB4      
#define KPAD_COLUMN1      PB5
#define KPAD_COLUMN2      PB6
#define KPAD_COLUMN3      PB7




#endif