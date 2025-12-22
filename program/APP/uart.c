#include <avr/io.h>
/*initializes the UART module*/
void uart_initialize()
{
    unsigned int baudrate_value = 51;
    UBRRL = baudrate_value;
    UBRRH = (1 << URSEL) | (baudrate_value >> 8); // URSEL must be 1 to access UBRRH

    UCSRB = (1 << TXEN) | (1 << RXEN);           // Enable TX and RX

    UCSRC = (1 << URSEL) | (3 << UCSZ0);         // 8-bit data, URSEL=1
}

void write_uart(unsigned char data)
{
    while (!(UCSRA & (1 << UDRE)));  // Wait until data register empty
    UDR = data;
    while (!(UCSRA & (1 << TXC)));   // Wait until transmission complete
    UCSRA |= (1 << TXC);             // Clear TXC flag
}

/*receive a character through UART*/
unsigned char read_uart()
{
	unsigned char data;
	while(!(UCSRA&(1<<RXC)));
	data=UDR;
	return data;
}

/*function transmit a string through UART*/
void write_uart_strg(char *ptr)
{
	while(*ptr)
	{
		write_uart(*ptr);
		ptr++;
	}
}
