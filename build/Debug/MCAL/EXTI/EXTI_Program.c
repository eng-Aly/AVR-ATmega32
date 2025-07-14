#include "EXTI_Header.h"



void (*INT0_Callback)(void) = 0;
void (*INT1_Callback)(void) = 0;
void (*INT2_Callback)(void) = 0;

void EXTI_EnableGlobalINT(){
    set_bit(Status_REG,ENABLE_INT_BIT);
}
void EXTI_DisableGlobalINT(){
    clear_bit(Status_REG,ENABLE_INT_BIT);
}
void EXTI_DisableINT(u8 INT_PIN){
    set_bit(GENRAL_INT_CONTROL_REG,INT_PIN);
}

void EXTI_SetINTMode(u8 INT_PIN,u8 mode){
        switch (mode) {
            case LOW_LEVEL_INT:
                if (INT_PIN == INT0) {
                    clear_bit(INT_0_1_CONTROL_REG, INT0_ISC0);
                    clear_bit(INT_0_1_CONTROL_REG, INT0_ISC1);
                } else if (INT_PIN == INT1) {
                    clear_bit(INT_0_1_CONTROL_REG, INT1_ISC0);
                    clear_bit(INT_0_1_CONTROL_REG, INT1_ISC1);
                }
                // INT2 doesn't support low-level mode
                break;
            
            case FALLING_EDGE_INT:
                if (INT_PIN == INT0) {
                    clear_bit(INT_0_1_CONTROL_REG, INT0_ISC0);
                    set_bit(INT_0_1_CONTROL_REG, INT0_ISC1);
                } else if (INT_PIN == INT1) {
                    clear_bit(INT_0_1_CONTROL_REG, INT1_ISC0);
                    set_bit(INT_0_1_CONTROL_REG, INT1_ISC1);
                } else if (INT_PIN == INT2) {
                    clear_bit(INT_2_CONTROL_REG, INT2_ISC2);  // falling edge for INT2
                }
                break;
            
            case RISING_EDGE_INT:
                if (INT_PIN == INT0) {
                    set_bit(INT_0_1_CONTROL_REG, INT0_ISC0);
                    set_bit(INT_0_1_CONTROL_REG, INT0_ISC1);
                } else if (INT_PIN == INT1) {
                    set_bit(INT_0_1_CONTROL_REG, INT1_ISC0);
                    set_bit(INT_0_1_CONTROL_REG, INT1_ISC1);
                } else if (INT_PIN == INT2) {
                    set_bit(INT_2_CONTROL_REG, INT2_ISC2);  // rising edge for INT2
                }
                break;
            
            case FAILING_RISING_EDGE_INT:  // only valid for INT0, INT1
                if (INT_PIN == INT0) {
                    set_bit(INT_0_1_CONTROL_REG, INT0_ISC0);
                    clear_bit(INT_0_1_CONTROL_REG, INT0_ISC1);
                } else if (INT_PIN == INT1) {
                    set_bit(INT_0_1_CONTROL_REG, INT1_ISC0);
                    clear_bit(INT_0_1_CONTROL_REG, INT1_ISC1);
                }
                break;
            
            default:
                // Invalid mode
                break;
        }
}

void EXTI_ClearFlag(u8 INT_PIN){
    set_bit(GENRAL_INT_FLAG_REG,INT_PIN);
}


void EXTI_Init(u8 INT_PIN,u8 mode){
    EXTI_EnableGlobalINT();  //sets enable interrupt flag by one
    EXTI_ClearFlag(INT_PIN);
    set_bit(GENRAL_INT_CONTROL_REG,INT_PIN); //enables the interrupt on the choosen pin
    EXTI_SetINTMode(INT_PIN,mode);
}

