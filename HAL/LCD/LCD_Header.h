#ifndef LCD_HEADER_H
#define LCD_HEADER_H


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "LCD_Private.h"
#include "LCD_Config.h"


void LCD_init_8bit();
void LCD_WriteCommand(u8 command);

#endif