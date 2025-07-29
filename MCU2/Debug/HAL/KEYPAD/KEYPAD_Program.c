#include "KEYPAD_Header.h"


u8 KEYPAD_COLUMNS[KEYPAD_COLUMNS_NUMBER]={KPAD_COLUMN0,KPAD_COLUMN1,KPAD_COLUMN2,KPAD_COLUMN3};
u8 KEYPAD_ROWS[KEYPAD_ROWS_NUMBER]={KPAD_ROW0,KPAD_ROW1,KPAD_ROW2,KPAD_ROW3};
u8 KEYPAD_CHARS[KEYPAD_ROWS_NUMBER][KEYPAD_COLUMNS_NUMBER]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'c','0','=','+'}};

void KEYPAD_INIT(){
    DIO_PINMode(KEYPAD_DDR,KPAD_ROW0,INPUT);
    DIO_PINMode(KEYPAD_DDR,KPAD_ROW1,INPUT);
    DIO_PINMode(KEYPAD_DDR,KPAD_ROW2,INPUT);
    DIO_PINMode(KEYPAD_DDR,KPAD_ROW3,INPUT);

    DIO_PINMode(KEYPAD_DDR,KPAD_COLUMN0,OUTPUT);
    DIO_PINMode(KEYPAD_DDR,KPAD_COLUMN1,OUTPUT);
    DIO_PINMode(KEYPAD_DDR,KPAD_COLUMN2,OUTPUT);
    DIO_PINMode(KEYPAD_DDR,KPAD_COLUMN3,OUTPUT);
    
    DIO_DigitalWrite(KEYPAD_PORT,KPAD_ROW0,HIGH);
    DIO_DigitalWrite(KEYPAD_PORT,KPAD_ROW1,HIGH);    
    DIO_DigitalWrite(KEYPAD_PORT,KPAD_ROW2,HIGH);    
    DIO_DigitalWrite(KEYPAD_PORT,KPAD_ROW3,HIGH);


}
u8 KEYPAD_GetPressedKey() {
    for (u8 col = 0; col < KEYPAD_COLUMNS_NUMBER; col++) {
        // Set all columns HIGH first
        for (u8 i = 0; i < KEYPAD_COLUMNS_NUMBER; i++) {
            DIO_DigitalWrite(KEYPAD_PORT, KEYPAD_COLUMNS[i], HIGH);
        }

        // Drive current column LOW
        DIO_DigitalWrite(KEYPAD_PORT, KEYPAD_COLUMNS[col], LOW);

        // Check each row
        for (u8 row = 0; row < KEYPAD_ROWS_NUMBER; row++) {
            if (DIO_DigitalRead(KEYPAD_PIN, KEYPAD_ROWS[row]) == 0) {
                // Wait for release (debounce)
                while (DIO_DigitalRead(KEYPAD_PIN, KEYPAD_ROWS[row]) == 0);

                return KEYPAD_CHARS[row][col]; // Return the pressed key
            }
        }
    }

    return 0xFF; // No key pressed
}

