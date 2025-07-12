#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

#define PINA_REG   ((volatile unsigned char*)(0x39))
#define DDRA_REG   ((volatile unsigned char*)(0x3A))
#define PORTA_REG  ((volatile unsigned char*)(0x3B))


#define PINB_REG   ((volatile unsigned char*)(0x36))
#define DDRB_REG   ((volatile unsigned char*)(0x37))
#define PORTB_REG  ((volatile unsigned char*)(0x38))

#define PINC_REG   ((volatile unsigned char*)(0x33))
#define DDRC_REG   ((volatile unsigned char*)(0x34))
#define PORTC_REG  ((volatile unsigned char*)(0x35))

#define PIND_REG   ((volatile unsigned char*)(0x30))
#define DDRD_REG   ((volatile unsigned char*)(0x31))
#define PORTD_REG  ((volatile unsigned char*)(0x32))

#define PA0 0
#define PA1 1
#define PA2 2
#define PA3 3
#define PA4 4
#define PA5 5
#define PA6 6
#define PA7 7

#define PB0 0
#define PB1 1
#define PB2 2
#define PB3 3
#define PB4 4
#define PB5 5
#define PB6 6
#define PB7 7

#define PC0 0
#define PC1 1
#define PC2 2
#define PC3 3
#define PC4 4
#define PC5 5
#define PC6 6
#define PC7 7

#define PD0 0
#define PD1 1
#define PD2 2
#define PD3 3
#define PD4 4
#define PD5 5
#define PD6 6
#define PD7 7


#endif