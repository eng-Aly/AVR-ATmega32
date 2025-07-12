#ifndef LCD_HEADER_H
#define LCD_HEADER_H


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Header.h"
#include "LCD_Private.h"
#include "LCD_Config.h"
#include <util/delay.h>


void LCD_init_8bit();
void LCD_WriteCommand(u8 command);
void LCD_WriteChar(u8 character);
void LCD_CreateCustomChar(u8 location, u8 pattern[8]);
void LCD_SetCursor(u8 row, u8 col);

#endif