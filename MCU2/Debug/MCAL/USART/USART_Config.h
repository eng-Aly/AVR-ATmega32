#ifndef USART_CONFIG_H
#define USART_CONFIG_H

#define CPU_CLK                                    8000000UL // 8 MHz

#define BUAD_RATE_9600                             9600
#define BUAD_RATE_115200                           115200
#define BUAD_RATE_19200                            19200

#define BAUD_RATE                                  BUAD_RATE_9600 

#define DOUBLE_SPEED_MODE                          1  
#define NORMAL_SPEED_MODE                          0

#define SPEED_MODE                                 DOUBLE_SPEED_MODE

#define disable_parity                             0
#define even_parity                                1
#define odd_parity                                 2

#define PARITY                                     disable_parity


#define one_stop_bit                               1
#define two_stop_bits                              2

#define stop_bits                                   one_stop_bit




#endif 