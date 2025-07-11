#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Header.h"


#define KEYPAD_DDR                DDRA_REG
#define KEYPAD_PORT               PORTA_REG
#define KEYPAD_PIN                PINA_REG

#define KEYPAD_COLUMNS_NUMBER     4
#define KEYPAD_ROWS_NUMBER        4


#define KPAD_ROW0         PA0      
#define KPAD_ROW1         PA1
#define KPAD_ROW2         PA2
#define KPAD_ROW3         PA3

#define KPAD_COLUMN0      PA4      
#define KPAD_COLUMN1      PA5
#define KPAD_COLUMN2      PA6
#define KPAD_COLUMN3      PA7



#endif