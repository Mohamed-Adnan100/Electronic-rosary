/* 
 * File  :   HAL_gpio.h
 * Author:   mohame_dadnan
 *
 * Created on July 21, 2023, 10:53 AM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/****** Includes section                     ******/
#include "pic18f4620.h"
#include "../MCAL_std_types.h"
#include "../../device_config.h"
#include "hal_gpio_cfg.h"

/****** Macro declarations section           ******/
#define BIT_MASK      (uint8)1
#define PORTC_MASK    0XFF

#define PIN_MAX_NUM     8
#define PORT_MAX_NUM    5

#define GPIO_PORT_PIN_CONFIGURATION    CONFIG_ENABLE
#define GPIO_PORT_CONFIGURATION        CONFIG_ENABLE

/****** Macro functions declarations section ******/
#define HWREG8(_x)      (*((volatile uint8  *)(_x))

#define set_bit(_REG , _pos)     (_REG |= (BIT_MASK << _pos))
#define CLEAR_bit(_REG , _pos)   (_REG &= ~(BIT_MASK << _pos))
#define TOGGLE_bit(_REG , _pos)  (_REG ^= (BIT_MASK << _pos))
#define read_bit(_REG , _pos)    ((_REG >> _pos) & BIT_MASK )

/****** Data types section                   ******/
typedef enum{
    LOW  = 0,
    HIGH = 1         
}logic_t;

typedef enum{
    OUTPUT = 0,
    INPUT  = 1      
}direction_t;

typedef enum{
    PIN0 = 0,
    PIN1 ,
    PIN2 ,
    PIN3 ,
    PIN4 ,
    PIN5 ,
    PIN6 ,
    PIN7 
}pin_index_t;

typedef enum{
    PORTA_INDEX = 0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
}port_index_t;

typedef struct{
    uint8 port          :3 ; /* @ref port_index_t */
    uint8 pin           :3 ; /* @ref pin_index_t */
    uint8 direction     :1 ; /* @ref direction_t */
    uint8 logic         :1 ; /* @ref logic_t */
}pin_config_t;

/****** functions section                    ******/

Std_ReturnType gpio_pin_direction_intailize(const pin_config_t *pin_config);
Std_ReturnType gpio_pin_git_direction_status(const pin_config_t *pin_config, direction_t *direction);
Std_ReturnType gpio_pin_write_logic(const pin_config_t *pin_config, logic_t logic);
Std_ReturnType gpio_pin_read_logic(const pin_config_t *pin_config, logic_t *logic);
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *pin_config);
Std_ReturnType gpio_pin_intailize(const pin_config_t *pin_config);

Std_ReturnType gpio_port_direction_intailize( port_index_t port_index, uint8 direction);
Std_ReturnType gpio_port_git_direction_status( port_index_t port_index, uint8 *direction);
Std_ReturnType gpio_port_write_logic( port_index_t port_index, uint8 logic);
Std_ReturnType gpio_port_read_logic( port_index_t port_index, uint8 *logic);
Std_ReturnType gpio_port_toggle_logic( port_index_t port_index);









#endif	/* HAL_GPIO_H */

