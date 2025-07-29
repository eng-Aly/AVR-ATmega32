//This file is modified by the config of each different app
#ifndef SSEG_CONFIG_H
#define SSEG_CONFIG_H

#include "../../MCAL/DIO/DIO_Header.h"

#define SSEG1_DDR  DDRB_REG
#define SSEG2_DDR  DDRC_REG

#define SSEG1_PORT PORTB_REG
#define SSEG2_PORT PORTC_REG

#define SSEG1_PINS PINB_REG
#define SSEG2_PINS PINC_REG

#define SSEG1_ENB  PB0
#define SSEG2_ENB  PC0


#endif