#ifndef KEYPAD_HEADER_H
#define KEYPAD_HEADER_H

#include "KEYPAD_Config.h"
#include <util/delay.h>

void KEYPAD_INIT();
u8 KEYPAD_GetPressedKey();

#endif