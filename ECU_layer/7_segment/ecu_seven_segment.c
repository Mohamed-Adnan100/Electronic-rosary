

#include "ecu_seven_segment.h"






Std_ReturnType seven_segment_intailize(const segment_t *segment){
   
     Std_ReturnType ret = E_OK;
     
    if( NULL == segment ){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_intailize(&(segment->segment_pins[SEGMENT_PIN0]));
        ret = gpio_pin_intailize(&(segment->segment_pins[SEGMENT_PIN1]));
        ret = gpio_pin_intailize(&(segment->segment_pins[SEGMENT_PIN2]));
        ret = gpio_pin_intailize(&(segment->segment_pins[SEGMENT_PIN3]));
    }
    
    return ret;
     
    
}



Std_ReturnType seven_segment_write_number(const segment_t *segment , uint8 number){
         Std_ReturnType ret = E_OK;
     
    if( (NULL == segment) && (number > 9) ){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(segment->segment_pins[SEGMENT_PIN0]) , number & 0x01 );
        ret = gpio_pin_write_logic(&(segment->segment_pins[SEGMENT_PIN1]) , (number>>1) & 0x01 );
        ret = gpio_pin_write_logic(&(segment->segment_pins[SEGMENT_PIN2]) , (number>>2) & 0x01 );
        ret = gpio_pin_write_logic(&(segment->segment_pins[SEGMENT_PIN3]) , (number>>3) & 0x01 );
        
        
    }
    
    return ret;
     
    
}
    
    
    