#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

#define PINA_REG   *(volatile unsigned char*(0x39))
#define DDRA_REG   *(volatile unsigned char*(0x3A))
#define PORTA_REG  *(volatile unsigned char*(0x3B))


#define PINB_REG   *(volatile unsigned char*(0x23))
#define DDRB_REG   *(volatile unsigned char*(0x24))
#define PORTB_REG  *(volatile unsigned char*(0x25))

#define PINC_REG   *(volatile unsigned char*(0x23))
#define DDRC_REG   *(volatile unsigned char*(0x24))
#define PORTC_REG  *(volatile unsigned char*(0x25))

#define PIND_REG   *(volatile unsigned char*(0x23))
#define DDRD_REG   *(volatile unsigned char*(0x24))
#define PORTD_REG  *(volatile unsigned char*(0x25))

#endif