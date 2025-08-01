#ifndef I2C_CONFIG_H
#define I2C_CONFIG_H

#define PRESCALAR            PRESCALAR_1

#define PRESCALAR_1          0
#define PRESCALAR_4          1
#define PRESCALAR_16         2
#define PRESCALAR_64         3


//STATUS MASK
#define STATUS_BITS_MASK                           0xF8

/*===================================================STATUS MESSAGES===============================================================*/

//Status Codes for Master Transmitter
#define I2C_MASTER_START_TRANSMITION               0x08
#define I2C_MASTER_REPEATED_START_TRANSMITION      0x10
#define I2C_SLAVE_ADDRESS_WRITE_ACK                0x18                    //Elslave bey2olk tmam astlmt
#define I2C_SLAVE_ADDRESS_WRITE_NACK               0x20
#define I2C_MASTER_DATA_TRANSMITTED_ACK            0x28
#define I2C_MASTER_DATA_TRANSMITTED_NACK           0x30
#define I2C_SLAVE_ADDRESS_READ_ACK                 0x40
#define I2C_SLAVE_ADDRESS_READ_NACK                0x48
#define I2C_MASTER_DATA_RECEIVED_ACK               0x50
#define I2C_MASTER_DATA_RECEIVED_NACK              0x58

#endif