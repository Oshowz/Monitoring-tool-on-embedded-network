/**
 * ==============================================
 *  @file       main.h
 *
 *  @brief      Header file for main source code
 *
 *  @author     Christian
 *  @date       07/12/2020
 *==============================================*/

#ifndef MAIN_H_
#define MAIN_H_

/* Include standard libraries */
#include <stdint.h>
#include <stdbool.h>

/* Include msp official driver libraries */
#include "driverlib.h"
#include "msp.h"

/* DEVICE state function */
void state_pattern_fn(uint8_t evnt);

/* Serial com functions */
void initialize_uart();
void uart_w_char(uint8_t b);
void uart_print_str(uint8_t* str);


typedef enum{
    l_SW = 'l',
    R_SW = 'r',
}switch_evt_type;

typedef enum{
    DEV_STATE_ONE = 0x00,
    DEV_STATE_TWO = 0x01,
    DEV_STATE_THREE = 0x02,
    DEV_STATE_FOUR = 0x03,
}dev_state_type;


#endif /* MAIN_H_ */

/* END OF FILE */
