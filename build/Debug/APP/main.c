#include "../MCAL/USART/USART_Header.h"
#include  "../HAL/LCD/LCD_Header.h"
#include "../MCAL/DIO/DIO_Header.h"
#include <stdio.h>
#include <avr/interrupt.h>  // Needed for sei()

u8 recieved_char=0;

void SETUP(){
    LCD_init_8bit();
    USART_Init(BUAD_RATE_9600,PARITY,SPEED_MODE,stop_bits);
    USART_Async_Read_Data(&recieved_char);
    sei();
}


/*
void Loop1(){
    u8 test_send = 7;
    u8 *test_recieve=0;
    USART_Write_Data(test_send);
    LCD_WriteString("SENT DATA");
    _delay_ms(200);
    LCD_Clear();
    USART_Read_Data(test_recieve);
    char string_recieved[10];
    sprintf(string_recieved, "recievied %d", *test_recieve);
    LCD_WriteString(string_recieved);
    _delay_ms(200);
    LCD_Clear();
}

void Loop2(){
    u8 test_send = 10;
    u8 *test_recieve=0;
    USART_Read_Data(test_recieve);
    char string_recieved[10];
    sprintf(string_recieved, "recievied %d", *test_recieve);
    LCD_WriteString(string_recieved);
    _delay_ms(200);
    LCD_Clear();
    USART_Write_Data(test_send);
    LCD_WriteString("SENT DATA");
    _delay_ms(200);
    LCD_Clear();
        
}
*/
/*
void Loop1(){
    char test_recieve[15];
    char test='a';
    char test_send[15]="Hello from mcu1";
    for (int i=0 ;i<15;i++){
        USART_Write_Data(test_send[i]);
    }
    LCD_WriteString("Data Sent");
    _delay_ms(200);
    LCD_Clear();
    for (int i=0;i<15;i++){
        LCD_WriteChar('a');
        USART_Read_Data(&test);
    }
    LCD_Clear();
    LCD_WriteString(test_recieve);


}
void Loop2(){
    char test_recieve[15];
    char test='a';
    char test_send[15]="Hello from mcu2";
    for (int i=0;i<15;i++){
        LCD_WriteChar('b');
        USART_Read_Data(&test);
    }
    LCD_WriteString(test_recieve);
    _delay_ms(200);
    LCD_Clear();
    for (int i=0;i<15;i++){

        USART_Write_Data(test_send[i]);
    }
    LCD_Clear();
    LCD_WriteString("Data sent");
    LCD_Clear();    


}
*/
void Loop1(){
    /*
    if (recieved_char != 0) {
    LCD_WriteChar(recieved_char);  // Display it or use it
    recieved_char = 0;             // Reset after processing
    USART_Async_Read_Data(&recieved_char);  // Set up next read
    _delay_ms(200);
    LCD_Clear();
    }
    */
    char test_send[15]="Hello from mcu1";
    for (int i=0 ;i<15;i++){
        USART_Write_Data(test_send[i]);
    }
    LCD_WriteString("Data sent");
    _delay_ms(200);
    LCD_Clear();    
}
void Loop2(){
    if (recieved_char != 0) {
    LCD_WriteChar(recieved_char);  // Display it or use it
    recieved_char = 0;             // Reset after processing
    USART_Async_Read_Data(&recieved_char);  // Set up next read
    _delay_ms(200);
    LCD_Clear();
    }    
    //char test_send[15]="Hello from mcu2";
    //for (int i=0 ;i<15;i++){
    //    USART_Write_Data(test_send[i]);
    //}
    //LCD_WriteString("Data sent");
    //_delay_ms(200);
    //LCD_Clear(); 

}    
int main(){
    SETUP();
    while (1){
        Loop1();
    }
    return 0;
}

