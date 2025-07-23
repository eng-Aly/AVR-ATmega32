#include "USART_Header.h"

void USART_Init(u8 Baud_rate,u8 parity,u8 speed,u8 stop_bit){
    clear_bit(UBR_REGH,UCSRC_URSEL);   //choose the UBR_REGH to set the BAUDRATE
    u16 UBRR=0;                       //getting the ubrr ready
    switch (speed)
    {
    case DOUBLE_SPEED_MODE:
        UBRR=CPU_CLK/(8*Baud_rate)-1;
        
        break;
    case NORMAL_SPEED_MODE:
        UBRR=CPU_CLK/(16*Baud_rate)-1;
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