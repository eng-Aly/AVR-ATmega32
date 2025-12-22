#ifndef UART_H
#define UART_H


void uart_initialize();


void write_uart(unsigned char data);


unsigned char read_uart();


void write_uart_strg(char *ptr);


#endif