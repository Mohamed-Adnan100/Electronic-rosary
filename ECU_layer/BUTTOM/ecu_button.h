/* 
 * File:   ecu_buttom_.h
 * Author: Global
 *
 * Created on July 9, 2024, 10:36 PM
 */

#ifndef ECU_BUTTON__H
#define	ECU_BUTTON__H

/****** Includes section                     ******/
#include "../../MCAL_Layer/GPIO/HAL_gpio.h"
#include "ecu_buttom_cfg.h"

/****** Macro declarations section           ******/
/****** Macro functions declarations section ******/
/****** Data types section                   ******/

typedef enum{
    BUTTON_PRESSED = 0,
    BUTTON_RELEASED   
}BUTTON_STATUS_T;


typedef enum{
    BUTTON_ACTIVE_HIGH,
    BUTTON_ACTIVE_LOW   
}BUTTON_ACTIVE_T;

typedef struct{
    pin_config_t BUTTON_PIN        ;
    BUTTON_STATUS_T BUTTON_STATUS  ;
    BUTTON_ACTIVE_T BUTTON_ACTIVE  ; 
}BUTTON_T;





/****** functions section                    ******/

Std_ReturnType button_initialize(const BUTTON_T *btn);
Std_ReturnType button_read(const BUTTON_T *btn ,BUTTON_STATUS_T *btn_st);



#endif	/* ECU_BUTTOM__H */

