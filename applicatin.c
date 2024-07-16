/* 
 * File:   application.c
 * Author: mohamed_adnan
 *
 * Created on July 21, 2023, 8:28 AM
 */
#include "application.h"

pin_config_t seg_en_1 = {
  .port = PORTD_INDEX,
  .pin = PIN3,
  .direction = OUTPUT,
  .logic = LOW
};
pin_config_t seg_en_2 = {
  .port = PORTD_INDEX,
  .pin = PIN2,
  .direction = OUTPUT,
  .logic = LOW
};
pin_config_t seg_en_3 = {
  .port = PORTD_INDEX,
  .pin = PIN1,
  .direction = OUTPUT,
  .logic = LOW
};
pin_config_t seg_en_4 = {
  .port = PORTD_INDEX,
  .pin = PIN0,
  .direction = OUTPUT,
  .logic = LOW
};

segment_t segment_1 = {
    .segment_pins[0].port = PORTC_INDEX,
    .segment_pins[0].pin = PIN0,
    .segment_pins[0].direction = OUTPUT,
    .segment_pins[0].logic = LOW,
    .segment_pins[1].port = PORTC_INDEX,
    .segment_pins[1].pin = PIN1,
    .segment_pins[1].direction = OUTPUT,
    .segment_pins[1].logic = LOW,
    .segment_pins[2].port = PORTC_INDEX,
    .segment_pins[2].pin = PIN2,
    .segment_pins[2].direction = OUTPUT,
    .segment_pins[2].logic = LOW,
    .segment_pins[3].port = PORTC_INDEX,
    .segment_pins[3].pin = PIN3,
    .segment_pins[3].direction = OUTPUT,
    .segment_pins[3].logic = LOW,
    .segment_type = SEGMENT_COMMON_ANODE
};

BUTTON_T btn_count = {
    .BUTTON_PIN.port =PORTC_INDEX,
    .BUTTON_PIN.pin = PIN4,
    .BUTTON_PIN.direction = INPUT,
    .BUTTON_PIN.logic = LOW,
    .BUTTON_STATUS = BUTTON_RELEASED,
    .BUTTON_ACTIVE = BUTTON_ACTIVE_HIGH
};
    
BUTTON_T btn_reset = {
    .BUTTON_PIN.port =PORTC_INDEX,
    .BUTTON_PIN.pin = PIN5,
    .BUTTON_PIN.direction = INPUT,
    .BUTTON_PIN.logic = LOW,
    .BUTTON_STATUS = BUTTON_RELEASED,
    .BUTTON_ACTIVE = BUTTON_ACTIVE_HIGH
};

BUTTON_T btn_led = {
    .BUTTON_PIN.port =PORTC_INDEX,
    .BUTTON_PIN.pin = PIN7,
    .BUTTON_PIN.direction = INPUT,
    .BUTTON_PIN.logic = LOW,
    .BUTTON_STATUS = BUTTON_RELEASED,
    .BUTTON_ACTIVE = BUTTON_ACTIVE_HIGH
};

LED_T led ={
  .PORT_NAME =PORTD_INDEX,
  .PIN = PIN4,
  .LED_ST = LED_OFF  
};


uint8 counter = 0;
uint16 number = 0;
uint8 VAR = 0;
uint16 c = 0;


BUTTON_STATUS_T btn_count_st = BUTTON_RELEASED;
BUTTON_STATUS_T btn_reset_st = BUTTON_RELEASED;
BUTTON_STATUS_T btn_led_st = BUTTON_RELEASED;

int main() {
    application_intailize();
    Std_ReturnType ret = E_NOT_OK;
    
    

    while(1){     

 
    ret = seven_segment_write_number(&segment_1 , ((uint8)(number%10)) );
    ret = gpio_pin_write_logic(&seg_en_1 , HIGH);
    __delay_ms(5);
    ret = gpio_pin_write_logic(&seg_en_1 , LOW);
    
    ret = seven_segment_write_number(&segment_1 ,((uint8)((number/10)%10)) );
    ret = gpio_pin_write_logic(&seg_en_2 , HIGH);
    __delay_ms(5);
    ret = gpio_pin_write_logic(&seg_en_2 , LOW);
        
    ret = seven_segment_write_number(&segment_1 ,((uint8)((number/100)%10)) );
    ret = gpio_pin_write_logic(&seg_en_3 , HIGH);
    __delay_ms(5);
    ret = gpio_pin_write_logic(&seg_en_3 , LOW);
        
    ret = seven_segment_write_number(&segment_1 ,((uint8)((number/1000)%10)) );
    ret = gpio_pin_write_logic(&seg_en_4 , HIGH);
    __delay_ms(5);
    ret = gpio_pin_write_logic(&seg_en_4 , LOW);
    
    
    
    
    

    ret = button_read(&(btn_reset),&(btn_reset_st));
    
    if (btn_reset_st == BUTTON_PRESSED){
            number = 0;
     }
    
    
    ret = button_read(&(btn_count),&(btn_count_st));
    
    if ( (btn_count_st == BUTTON_PRESSED) && (VAR ==0)){
            VAR = 1;
            number++;
     }
    
    if((btn_count_st ==BUTTON_RELEASED)&& (VAR ==1) ){
        VAR = 0;
    }
    
    
    ret = button_read(&(btn_led),&(btn_led_st));
    
    if (btn_led_st == BUTTON_PRESSED){
            ret = LED_TURN_ON(&led);
            
    }
   else{
           ret = LED_TURN_OFF(&led);
   }

    
    }
    
    return (EXIT_SUCCESS);

}

void application_intailize(void){
    Std_ReturnType ret = E_NOT_OK;
    ret = seven_segment_intailize(&segment_1);
    ret = gpio_pin_intailize(&seg_en_1);
    ret = gpio_pin_intailize(&seg_en_2);
    ret = gpio_pin_intailize(&seg_en_3);
    ret = gpio_pin_intailize(&seg_en_4);
    
    ret = button_initialize(&btn_count);
    ret = button_initialize(&btn_reset);
    ret = button_initialize(&btn_led);
    
    ret = LED_intailize(&led);
    
    
    

}

