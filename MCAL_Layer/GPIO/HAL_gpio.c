
/* 
 * File:   HAL_gpio.c
 * Author: mohamed_adnan
 *
 * Created on July 21, 2023, 8:28 AM
 */

#include "HAL_gpio.h"


volatile uint8 *tris_regesters[] = { &TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
volatile uint8 *lat_regesters[] = { &LATA, &LATB, &LATC, &LATD, &LATE};
volatile uint8 *port_regesters[] = { &PORTA, &PORTB, &PORTC, &PORTD, &PORTE};

/**
 * 
 * @param pin_config
 * @return 
 */
#if(GPIO_PORT_PIN_CONFIGURATION == CONFIG_ENABLE)
Std_ReturnType gpio_pin_direction_intailize(const pin_config_t *pin_config){
    Std_ReturnType ret = E_OK;
    if( NULL == pin_config || pin_config->pin > PIN_MAX_NUM-1){
        ret = E_NOT_OK;
    }
    else{
        switch(pin_config->direction){
        case (OUTPUT):
            CLEAR_bit(*tris_regesters[pin_config->port], pin_config->pin);
            break;
        case (INPUT):
            set_bit(*tris_regesters[pin_config->port] , pin_config->pin);
            break;
        default :
            ret = E_NOT_OK;
    }
    }
    
    return ret;
}
#endif
/**
 * 
 * @param pin_config
 * @param direction
 * @return 
 */
#if(GPIO_PORT_PIN_CONFIGURATION == CONFIG_ENABLE)
Std_ReturnType gpio_pin_git_direction_status(const pin_config_t *pin_config, direction_t *direction){
    Std_ReturnType ret = E_OK;
    if( NULL == pin_config || NULL == direction || pin_config->pin > PIN_MAX_NUM-1){
        ret = E_NOT_OK;
    }
    else{
        *direction = read_bit(*tris_regesters[pin_config->port] , pin_config->pin);
    } 
    return ret;
}
#endif

/**
 * 
 * @param pin_config
 * @param logic
 * @return 
 */
#if(GPIO_PORT_PIN_CONFIGURATION == CONFIG_ENABLE)
Std_ReturnType gpio_pin_write_logic(const pin_config_t *pin_config, logic_t logic){
    Std_ReturnType ret = E_OK;
    if( NULL == pin_config || pin_config->pin > PIN_MAX_NUM-1){
        ret = E_NOT_OK;
    }
    else{
        switch(logic){
        case (LOW):
            CLEAR_bit(*lat_regesters[pin_config->port], pin_config->pin);
            break;
        case (HIGH):
            set_bit(*lat_regesters[pin_config->port] , pin_config->pin);
            break;
        default :
            ret = E_NOT_OK;
    }
    }
    
    return ret;

}
#endif


/**
 * 
 * @param pin_config
 * @param logic
 * @return 
 */
#if(GPIO_PORT_PIN_CONFIGURATION == CONFIG_ENABLE)
Std_ReturnType gpio_pin_read_logic(const pin_config_t *pin_config, logic_t *logic){
    Std_ReturnType ret = E_OK;
    if( NULL == pin_config || NULL == logic || pin_config->pin > PIN_MAX_NUM-1){
        ret = E_NOT_OK;
    }
    else{
        *logic = read_bit(*port_regesters[pin_config->port] , pin_config->pin);
    } 
    return ret;
}
#endif


/**
 * 
 * @param pin_config
 * @return 
 */
#if(GPIO_PORT_PIN_CONFIGURATION == CONFIG_ENABLE)
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *pin_config){
    Std_ReturnType ret = E_OK;
    if( NULL == pin_config || pin_config->pin > PIN_MAX_NUM-1){
        ret = E_NOT_OK;
    }
    else{
         TOGGLE_bit(*port_regesters[pin_config->port] , pin_config->pin);
    } 
    return ret;
    
}
#endif

#if(GPIO_PORT_PIN_CONFIGURATION == CONFIG_ENABLE)
Std_ReturnType gpio_pin_intailize(const pin_config_t *pin_config){
    Std_ReturnType ret = E_OK;
    if( NULL == pin_config || pin_config->pin == PIN_MAX_NUM-1){
        ret = E_NOT_OK;
    }
    else{
        ret =gpio_pin_direction_intailize(pin_config);
        ret =gpio_pin_write_logic(pin_config,pin_config->logic);
    }   
}
#endif


/**
 * 
 * @param port_index
 * @param direction
 * @return 
 */
#if(GPIO_PORT_CONFIGURATION == CONFIG_ENABLE)
Std_ReturnType gpio_port_direction_intailize( port_index_t port_index, uint8 direction){
    Std_ReturnType ret = E_OK;
    if(port_index > PORT_MAX_NUM-1){
        ret = E_NOT_OK;
    }
    else{
        *tris_regesters[port_index] = direction;
    } 
    return ret;
}
#endif


/**
 * 
 * @param port_index
 * @param direction
 * @return 
 */
#if(GPIO_PORT_CONFIGURATION == CONFIG_ENABLE)
Std_ReturnType gpio_port_git_direction_status( port_index_t port_index, uint8 *direction){
    Std_ReturnType ret = E_OK;
    if( (NULL == direction) && (port_index > PIN_MAX_NUM-1)){
        ret = E_NOT_OK;
    }
    else{
        *direction = *tris_regesters[port_index];
    } 
    return ret;
    
}
#endif


/**
 * 
 * @param port_index
 * @param logic
 * @return 
 */
#if(GPIO_PORT_CONFIGURATION == CONFIG_ENABLE)
Std_ReturnType gpio_port_write_logic( port_index_t port_index, uint8 logic){
    Std_ReturnType ret = E_OK;
    if((port_index > PIN_MAX_NUM-1)){
        ret = E_NOT_OK;
    }
    else{
        *lat_regesters[port_index] = logic ;
    } 
    return ret;
    
}
#endif


/**
 * 
 * @param port_index
 * @param logic
 * @return 
 */
#if(GPIO_PORT_CONFIGURATION == CONFIG_ENABLE)
Std_ReturnType gpio_port_read_logic( port_index_t port_index, uint8 *logic){
    Std_ReturnType ret = E_OK;
    if(( NULL == logic) && (port_index > PIN_MAX_NUM-1)){
        ret = E_NOT_OK;
    }
    else{
         *logic = *lat_regesters[port_index] ;
    } 
    return ret;
    

}
#endif


/**
 * 
 * @param port_index
 * @return 
 */
#if(GPIO_PORT_CONFIGURATION == CONFIG_ENABLE)
Std_ReturnType gpio_port_toggle_logic( port_index_t port_index){
    Std_ReturnType ret = E_OK;
    if((port_index > PIN_MAX_NUM-1)){
        ret = E_NOT_OK;
    }
    else{
        *lat_regesters[port_index] ^=PORTC_MASK;
    } 
    return ret;

}
#endif