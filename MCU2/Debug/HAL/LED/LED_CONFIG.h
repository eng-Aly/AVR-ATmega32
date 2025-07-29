//This file is modified by the config of each different app
#ifndef LED_CONFIG_H
#define LED_CONFIG_H

#include "../../MCAL/DIO/DIO_Header.h"

#define REDLED_DDR     DDRA_REG
#define REDLED_PORT    PORTA_REG
#define REDLED_PIN     PA0

#define BLUELED_DDR    DDRA_REG
#define BLUELED_PORT   PORTA_REG
#define BLUELED_PIN    PA1

#define GREENLED_DDR   DDRA_REG
#define GREENLED_PORT  PORTA_REG
#define GREENLED_PIN   PA2

#endif