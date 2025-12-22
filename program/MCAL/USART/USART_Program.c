#include "USART_Header.h"


void (*ISR_FUNC_POINTER)(void) = NULL;
u8  data_TX =0  ;
u8 *data_Rx =0  ; 
/*
void USART_Init(u32 Baud_rate,u8 parity,u8 speed,u8 stop_bit){
    clear_bit(UBR_REGH,UCSRC_URSEL);   //choose the UBR_REGH to set the BAUDRATE
    u16 UBRR=0;                       //getting the ubrr ready
    switch (speed)
    {
    case DOUBLE_SPEED_MODE:
        UBRR=CPU_CLK/(8UL*Baud_rate)-1;
        
        break;
    case NORMAL_SPEED_MODE:
        UBRR=CPU_CLK/(16UL*Baud_rate)-1;
        break;    
    
    default:
        break;
    }
    *UBR_REGL=(u8)(UBRR);
    *UBR_REGH=(u8)(UBRR>>8);

    set_bit(UCS_REGC,UCSRC_URSEL);   //choose back the UCS_REGC to configure
    clear_bit(UCS_REGC,UCSRC_UMSE1);
    
    switch (parity)
    {
    case disable_parity:
        clear_bit(UCS_REGC,UCSRC_UPM0);
        clear_bit(UCS_REGC,UCSRC_UPM1);
        break;
    case even_parity:
        clear_bit(UCS_REGC,UCSRC_UPM0);
        set_bit(UCS_REGC,UCSRC_UPM1);
        break;
    case odd_parity:
        set_bit(UCS_REGC,UCSRC_UPM0);
        set_bit(UCS_REGC,UCSRC_UPM1);
        break;    
    default:
        break;
    }

    switch (stop_bit)
    {
    case two_stop_bits:
        set_bit(UCS_REGC,UCSRC_USBS);
        break;
    case one_stop_bit:
        clear_bit(UCS_REGC,UCSRC_USBS);
        break;
    default:
        break;
    }


    set_bit(UCS_REGC,UCSRC_UCSZ0);
    set_bit(UCS_REGC,UCSRC_UCSZ1);
    clear_bit(UCS_REGB,UCSRB_UCSZ2);

    set_bit(UCS_REGB,UCSRB_TXEN);               
    set_bit(UCS_REGB,UCSRB_RXEN);  

}
*/
void USART_Init(void) {
    u16 ubrr = MYUBRR;
    *UBR_REGH = (u8)(ubrr >> 8);
    *UBR_REGH = (u8)ubrr;
    *UCS_REGB = (1 << UCSRB_RXEN) | (1 << UCSRB_TXEN);       // Enable TX and RX
    *UCS_REGC = (1 << UCSRC_URSEL) | (1 << UCSRC_UCSZ1) | (1 << UCSRC_UCSZ0); // 8-bit, no parity, 1 stop
}

//pooling 
void USART_Read_Data(u8 *Data){
    while (get_bit(UCS_REGA,UCSRA_RXC)==0); 
    *Data=*UD_REG; //you are passing an addresss in the arguments so you use dereference  && UD_REG is an address so you use dereference       
}
void USART_Write_Data(u8 Data){
    while (get_bit(UCS_REGA,UCSRA_UDRE)==0);
    *UD_REG=Data;
    //set_bit(UCS_REGA,UCSRA_TXC);  //commented to test
}
void UART_SendChar(char data) {
	*UD_REG =data;
	while(!(*UCS_REGA& (1<<UCSRA_TXC)));;
}

//INTERRUPT
void USART_Async_Read_Data(u8 *Data){
    set_bit(UCS_REGB,UCSRB_RXCIE);
    data_Rx=Data;
}

void USART_Async_Write_Data(u8 *Data,void (*call_back)(void)){
    set_bit(UCS_REGB,UCSRB_TXCIE);
    set_bit(UCS_REGB,UCSRB_UDRIE);
    data_TX=*Data;
    ISR_FUNC_POINTER=call_back;    
}


//ISR no13 -in the interrupt vector table-  Of the interrupt signal of pin RXCIE which indicates recieving data 
void __vector_13 (void)              __attribute__((signal)); 
void __vector_13 (void){
        *data_Rx=*UD_REG;   
}

//ISR no14 of the interrupt signal of pin TXCIE which indicates that the mp has data to be sent 
void __vector_14 (void)             __attribute__((signal));
void __vector_14 (void){
    *UD_REG=data_TX;
}

void __vector_15 (void)             __attribute__((signal));
void __vector_15 (void){
    ISR_FUNC_POINTER();  //the  transmission complete flag raise func in the app 
}