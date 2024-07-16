/* 
 * File:   ecu_led.c
 * Author: mohamed_adnan
 *
 * Created on July 21, 2023, 11:14 AM
 */

#include "ecu_button.h"


/**
 * 
 * @param btn
 * @return 
 */
Std_ReturnType button_initialize(const BUTTON_T *btn){
    Std_ReturnType ret = E_OK;
    if( NULL == btn ){
        ret = E_NOT_OK;
    }
    else{
        gpio_pin_direction_intailize(&(btn->BUTTON_PIN));
        ret = E_OK;
    }
    
    return ret;
    
}

/**
 * 
 * @param btn
 * @param btn_st
 * @return 
 */
Std_ReturnType button_read(const BUTTON_T *btn ,BUTTON_STATUS_T *btn_st){
     Std_ReturnType ret = E_NOT_OK;
     logic_t pin_logic_status = LOW;
    if( (NULL == btn) || (NULL == btn_st)){
        ret = E_NOT_OK;
    }
    else{
        gpio_pin_read_logic(&(btn->BUTTON_PIN), &pin_logic_status);
        if(BUTTON_ACTIVE_HIGH == (btn->BUTTON_ACTIVE)){
            if(HIGH == pin_logic_status){
                *btn_st = BUTTON_PRESSED;
            }
            else{
                *btn_st = BUTTON_RELEASED;
            }
        }
        else if(BUTTON_ACTIVE_LOW == (btn->BUTTON_ACTIVE)){
            if(HIGH == pin_logic_status){
                *btn_st = BUTTON_RELEASED;
            }
            else{
                *btn_st = BUTTON_PRESSED;
            }
        }
        else{/*nothing*/}
        
        ret = E_OK;
    }
    
    return ret;

}
