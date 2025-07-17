#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define ADMUX_REG                                                   ((volatile unsigned char*)(0x27))
#define REFS0                                                       6
#define REFS1                                                       7
#define ADLRA                                                       5



#define ADCH_REG                                                    ((volatile unsigned char*)(0x25))
#define ADCL_REG                                                    ((volatile unsigned char*)(0x24))
#define ADC_REG                                                     ((volatile unsigned short int*)(0x24))  // Pointer to 16 bit ADCH and ADCL to read Data From 10 BIT of ADC Data.



#define ADCS_AREG                                                   ((volatile unsigned char*)(0x26))
#define ADEN                                                        7
#define ADATE                                                       5
#define ADIF                                                        4
#define ADIE                                                        3
#define ADSC                                                        6

#define ADPS0                                                       0
#define ADPS1                                                       1
#define ADPS2                                                       2



#define SFIO_REG                                                    ((volatile unsigned char*)(0x50))
#define ADTS0                                                       5
#define ADTS1                                                       6
#define ADTS2                                                       7


#endif