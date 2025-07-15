#include "KEYPAD_Header.h"


u8 KEYPAD_COLUMNS[KEYPAD_COLUMNS_NUMBER]={KPAD_COLUMN0,KPAD_COLUMN1,KPAD_COLUMN2,KPAD_COLUMN3};
u8 KEYPAD_ROWS[KEYPAD_ROWS_NUMBER]={KPAD_ROW0,KPAD_ROW1,KPAD_ROW2,KPAD_ROW3};
u8 KEYPAD_CHARS[KEYPAD_COLUMNS_NUMBER][KEYPAD_ROWS_NUMBER]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'c','0','=','+'}};

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

u8 KEYPAD_GetPressedKey(){
    u8 PressedKeyFlag;
    u8 PressedKeyChar;
    u8 ReturnFlag=0;
    for (u8 COLUMN_ITR = 0; COLUMN_ITR < KEYPAD_COLUMNS_NUMBER; COLUMN_ITR++)
    {
        DIO_DigitalWrite(KEYPAD_PORT,KEYPAD_COLUMNS[COLUMN_ITR],LOW);
        for (u8 ROWS_ITR = 0; ROWS_ITR < KEYPAD_ROWS_NUMBER; ROWS_ITR++)
        {
            PressedKeyFlag=DIO_DigitalRead(KEYPAD_PORT,KEYPAD_ROWS[ROWS_ITR]);
            if (PressedKeyFlag==0)
            {
                while (PressedKeyFlag==0)
                {
                    PressedKeyChar=KEYPAD_CHARS[COLUMN_ITR][ROWS_ITR];

                    ReturnFlag=1;
                    PressedKeyFlag=DIO_DigitalRead(KEYPAD_PORT,KEYPAD_ROWS[ROWS_ITR]);

                }
                break;
                
            }
            DIO_DigitalWrite(KEYPAD_PORT,KEYPAD_COLUMNS[COLUMN_ITR],HIGH);
            if (ReturnFlag==1)
            {
                break;
            }
            
            

        }
        return PressedKeyChar;
        
    }
    


}