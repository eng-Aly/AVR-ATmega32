#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H


//I2C Register Addresses
#define TWAR_SLAVE_ADDRESS_REG       ((volatile unsigned char*)0x22)
#define TWBR_BIT_RATE_REG            ((volatile unsigned char*)0x20)
#define TWSR_STATUS_REG              ((volatile unsigned char*)0x21)
#define TWCR_CONTROL_REG             ((volatile unsigned char*)0x56)
#define TWDR_DATA_REG                ((volatile unsigned char*)0x23)

//I2C Control Register Bits
#define TWCR_INTERRUPT_ENABLE_BIT          0
#define TWCR_ENABLE_BIT                    2
#define TWCR_START_BIT                     5
#define TWCR_STOP_BIT                      4
#define TWCR_WRITE_COLLISION_BIT           3
#define TWCR_ENABLE_ACK_BIT                6
#define TWCR_INT_FLAG_BIT                  7

//I2C Status Register Bits
#define TWSR_PRESCALAR_1_BIT               0
#define TWSR_PRESCALAR_2_BIT               1
#define TWSR_STATUS_0                      3
#define TWSR_STATUS_1                      4
#define TWSR_STATUS_2                      5
#define TWSR_STATUS_3                      6
#define TWSR_STATUS_4                      7

//I2C Address Register Bits
#define TWAR_GENERAL_CALL_ENABLE_BIT      0
#define TWAR_ADDRESS_0_BIT                1
#define TWAR_ADDRESS_1_BIT                2
#define TWAR_ADDRESS_2_BIT                3
#define TWAR_ADDRESS_3_BIT                4
#define TWAR_ADDRESS_4_BIT                5
#define TWAR_ADDRESS_5_BIT                6
#define TWAR_ADDRESS_6_BIT                7


#define TWDR_DATA_0_BIT                   0        //for writing conditions




#define NULL                           (void*)(0)

#endif