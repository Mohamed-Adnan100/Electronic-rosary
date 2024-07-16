/* 
 * File:   ecu_led.h
 * Author: mohamed_adnan
 *
 * Created on July 21, 2023, 11:14 AM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H

/****** Includes section                     ******/
#include "../../MCAL_Layer/GPIO/HAL_gpio.h"
#include "ecu_led_cfg.h"


/****** Macro declarations section           ******/
/****** Macro functions declarations section ******/
/****** Data types section                   ******/

typedef enum{
    LED_OFF,
    LED_ON   
}LED_STATUS_T;

typedef struct{
    uint8 PORT_NAME     :4;
    uint8 PIN      :3;
    uint8 LED_ST   :1; 
}LED_T;


/****** functions section                    ******/

Std_ReturnType LED_intailize(const LED_T *led);
Std_ReturnType LED_TURN_ON(const LED_T *led);
Std_ReturnType LED_TURN_OFF(const LED_T *led);
Std_ReturnType LED_TURN_TOGGEL(const LED_T *led);



#endif	/* ECU_LED_H */

