/* 
 * File:   ecu_led.c
 * Author: mohamed_adnan
 *
 * Created on July 21, 2023, 11:14 AM
 */

#include "ecu_led.h"

/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType LED_intailize(const LED_T *led){
    Std_ReturnType ret = E_OK;
    
    if( NULL == led ){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_obj =
        {.port = led->PORT_NAME,
         .pin = led->PIN,
         .logic = led->LED_ST,
         .direction = OUTPUT};
        gpio_pin_intailize(&pin_obj);
    }
    
    return ret;
    
}



/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType LED_TURN_ON(const LED_T *led){
    Std_ReturnType ret = E_OK;
    
    if( NULL == led ){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_obj =
        {.port = led->PORT_NAME,
         .pin = led->PIN,
         .logic = led->LED_ST,
         .direction = OUTPUT};
        gpio_pin_write_logic(&pin_obj, HIGH);
    }
    
    return ret;  
}



/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType LED_TURN_OFF(const LED_T *led){
    Std_ReturnType ret = E_OK;
    
    if( NULL == led ){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_obj =
        {.port = led->PORT_NAME,
         .pin = led->PIN,
         .logic = led->LED_ST,
         .direction = OUTPUT};
        gpio_pin_write_logic(&pin_obj, LOW);
    }
    
    return ret;   
}



/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType LED_TURN_TOGGEL(const LED_T *led){
    Std_ReturnType ret = E_OK;
    
    if( NULL == led ){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_obj =
        {.port = led->PORT_NAME,
         .pin = led->PIN,
         .logic = led->LED_ST,
         .direction = OUTPUT};
        gpio_pin_toggle_logic(&pin_obj);
    }
    
    return ret;      
}