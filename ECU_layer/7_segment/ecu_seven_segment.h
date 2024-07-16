/* 
 * File:   ecu_seven_segment.h
 * Author: Global
 *
 * Created on July 14, 2024, 1:38 PM
 */

#ifndef ECU_SEVEN_SEGMENT_H
#define	ECU_SEVEN_SEGMENT_H

/****** Includes section                     ******/
#include "../../MCAL_Layer/GPIO/HAL_gpio.h"
#include "ecu_seven_segment_cfg.h"

/****** Macro declarations section           ******/
#define SEGMENT_PIN0   0
#define SEGMENT_PIN1   1
#define SEGMENT_PIN2   2
#define SEGMENT_PIN3   3

/****** Macro functions declarations section ******/
/****** Data types section                   ******/

typedef enum{
    SEGMENT_COMMON_ANODE,
    SEGMENT_COMMON_CATHODE   
}segment_type_t;

typedef struct{
    pin_config_t segment_pins[4] ;
    segment_type_t segment_type  ;
}segment_t;


/****** functions section                    ******/

Std_ReturnType seven_segment_intailize(const segment_t *segment);
Std_ReturnType seven_segment_write_number(const segment_t *segment , uint8 number);



#endif	/* ECU_SEVEN_SEGMENT_H */

