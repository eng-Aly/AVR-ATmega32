#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef  unsigned char       u8;
typedef unsigned short int   u16;
typedef unsigned long int    u32;
typedef signed char          s8;
typedef signed short int     s16;
typedef signed long int      s32;
typedef float                f32 ;       // 4 Byte
typedef double               f64 ;       // 8 Byte


typedef struct bits
{   
    unsigned char bit0 :1 ;
    unsigned char bit1 :1 ;
    unsigned char bit2 :1 ;
    unsigned char bit3 :1 ;
    unsigned char bit4 :1 ;
    unsigned char bit5 :1 ;
    unsigned char bit6 :1 ;
    unsigned char bit7 :1 ;
                            
}bits;

#endif 