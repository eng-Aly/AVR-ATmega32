#ifndef BIT_MATH_H
#define BIT_MATH_H

#define set_bit(reg,number)   reg|=(1<<number)
#define clear_bit(reg,number)   reg&=~(1<<number)
#define get_bit(reg, number)    (((reg) >> (number)) & 1)
#define toggle_bit(reg,number)  reg^=(1<<number)

#define set_byte(reg)           reg=0xFF
#define clear_byte(reg)         reg=0x00



#define INPUT  0
#define OUTPUT 1

#define LOW 0
#define HIGH 1


#endif