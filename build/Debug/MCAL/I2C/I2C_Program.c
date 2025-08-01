#include "I2C_Header.h"


void I2C_Master_Init(u8 Master_Address){
    set_bit(TWCR_CONTROL_REG,TWCR_ENABLE_ACK_BIT); //ENABLE ACKNOWLEDGE

    *TWBR_BIT_RATE_REG =2;     //400khz


    switch (PRESCALAR)
    {
    case PRESCALAR_1:
        clear_bit(TWSR_STATUS_REG,TWSR_PRESCALAR_1_BIT);
        clear_bit(TWSR_STATUS_REG,TWSR_PRESCALAR_2_BIT);
        break;
    case PRESCALAR_4:
        set_bit(TWSR_STATUS_REG,TWSR_PRESCALAR_1_BIT);
        clear_bit(TWSR_STATUS_REG,TWSR_PRESCALAR_2_BIT);
        break;
    case PRESCALAR_16:
        clear_bit(TWSR_STATUS_REG,TWSR_PRESCALAR_1_BIT);
        set_bit(TWSR_STATUS_REG,TWSR_PRESCALAR_2_BIT);    
        break;
    case PRESCALAR_64:
        set_bit(TWSR_STATUS_REG,TWSR_PRESCALAR_1_BIT);
        set_bit(TWSR_STATUS_REG,TWSR_PRESCALAR_2_BIT);
        break;                    
    default:
        break;
    }

    //SET TO 0 WHEN NO NEED TO THE MASTER TO BE ADDRESSED
    if (Master_Address != 0x00){
        *TWAR_SLAVE_ADDRESS_REG  = (Master_Address>>1);   //SET MASTER ADDRESS
    }
    
    set_bit(TWCR_CONTROL_REG,TWCR_ENABLE_BIT);  //ENABLE I2C
}


void I2C_MASTER_StopCondition(){
    set_bit(TWCR_CONTROL_REG,TWCR_STOP_BIT);
    set_bit(TWCR_CONTROL_REG,TWCR_INT_FLAG_BIT);    
}

void I2C_SLAVE_Init(u8 SLAVE_ADDRESS){
    set_bit(TWCR_CONTROL_REG,TWCR_ENABLE_ACK_BIT); //ENABLE ACKNOWLEDGE

    *TWAR_SLAVE_ADDRESS_REG  = (SLAVE_ADDRESS>>1); //SET SLAVE ADDRESS

    set_bit(TWCR_CONTROL_REG,TWCR_ENABLE_BIT);    //ENABLE I2C

}