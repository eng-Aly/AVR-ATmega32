#ifndef BIT_MATH_H
#define BIT_MATH_H

#define set_bit(register,number)   register|=(1<<number)
#define clear_bit(register,number)   register&=~(1<<number)
#define get_bit(register, number)    (((register) >> (number)) & 1)
#define toggle_bit(register,number)  register^=(1<<number) 


#endif