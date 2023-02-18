/**
 * ==============================================
 *  @file       main.c
 *
 *  @brief      Source code for msp401p423 firmware for the
 *              monitoring app project
 *
 *  @author     Christian
 *  @date       07/12/2020
 *==============================================*/

#include "main.h"

/** us delay macro  */
#define __delay_us(t_us) __delay_cycles( ( ((uint64_t)t_us)*3000000 ) / 1000000 )


/** Macros for specific GPIO functions */
#define SWITCH_PORT     GPIO_PORT_P1
#define SWITCH_1        GPIO_PIN1
#define SWITCH_2        GPIO_PIN4

#define LED_1_PORT      GPIO_PORT_P2
#define LED_1           GPIO_PIN0
#define LED_2_PORT      GPIO_PORT_P1
#define LED_2            GPIO_PIN0

switch_evt_type switch_evt;
dev_state_type dev_state;

bool l_sw_active = false;
bool r_sw_active = false;


void main(void)
{

    WDT_A_hold(WDT_A_BASE);

    /* Init led */
    GPIO_setAsOutputPin(LED_1_PORT, LED_1 );
    GPIO_setAsOutputPin(LED_2_PORT, LED_2);

    /* init switches */
    GPIO_setAsInputPinWithPullUpResistor(SWITCH_PORT, SWITCH_1 | SWITCH_2);
    GPIO_clearInterruptFlag(SWITCH_PORT, SWITCH_1 | SWITCH_2);
    GPIO_enableInterrupt(SWITCH_PORT, SWITCH_1 | SWITCH_2);
    Interrupt_enableInterrupt(INT_PORT1);

    MAP_SysCtl_enableSRAMBankRetention(SYSCTL_SRAM_BANK1);
    /* Enabling MASTER interrupts */
    MAP_Interrupt_enableMaster();

    /* Initialize serial communication */
    initialize_uart();

    while(1){
        if (l_sw_active){
            l_sw_active = false;

            //wait for a few millisecs and check if switch
            //is still active
            __delay_us(20);
            if (!GPIO_getInputPinValue(SWITCH_PORT, SWITCH_1)){
                state_pattern_fn(l_SW);
            }
        }
        else if(r_sw_active){
            r_sw_active = false;

            __delay_us(20);
            if (!GPIO_getInputPinValue(SWITCH_PORT, SWITCH_2)){
                state_pattern_fn(R_SW);
            }
        }
    }
}


/**
 * l and r switch  ISR
 * */
void PORT1_IRQHandler(void)
{
    uint32_t ret;

    ret = GPIO_getEnabledInterruptStatus(SWITCH_PORT);

    GPIO_clearInterruptFlag(SWITCH_PORT, ret);

    if(ret & SWITCH_1)
        l_sw_active = true;
    else if(ret & SWITCH_2)
        r_sw_active = true;
}

/**
 *  handling switch events
 *  */
void state_pattern_fn(uint8_t event)
{
    switch(dev_state){
    case DEV_STATE_ONE:
        if (event == l_SW) dev_state = DEV_STATE_FOUR;
        else if (event == R_SW) dev_state = DEV_STATE_TWO;
        break;
    case DEV_STATE_TWO:
        if (event == l_SW) dev_state = DEV_STATE_ONE;
        else if (event == R_SW) dev_state = DEV_STATE_THREE;
        break;
    case DEV_STATE_THREE:
        if (event == l_SW) dev_state = DEV_STATE_TWO;
        else if (event == R_SW) dev_state = DEV_STATE_FOUR;
        break;
    case DEV_STATE_FOUR:
        if (event == l_SW) dev_state = DEV_STATE_THREE;
        else if (event == R_SW) dev_state = DEV_STATE_ONE;
        break;
    default:
        return;
    }

    /* turn on LEDs accordingly */
    if (dev_state & 0x02)
        GPIO_setOutputHighOnPin(LED_1_PORT, LED_1);
    else
        GPIO_setOutputLowOnPin(LED_1_PORT, LED_1);

    if (dev_state & 0x01)
        GPIO_setOutputHighOnPin(LED_2_PORT, LED_2);
    else
        GPIO_setOutputLowOnPin(LED_2_PORT, LED_2);

    /* communication state with PC */
    switch (dev_state){
    case DEV_STATE_ONE:
        uart_print_str("Device state: 1\n ");
        break;
    case DEV_STATE_TWO:
        uart_print_str("Device state: 2\n ");
        break;
    case DEV_STATE_THREE:
        uart_print_str("Device state: 3\n ");
        break;
    case DEV_STATE_FOUR:
        uart_print_str("Device state: 4\n ");
        break;
    default:
        break;
    }

    return;
}



/**  ISR for serial messages */
void EUSCIA0_IRQHandler(void)
{
    uint16_t st = MAP_UART_getEnabledInterruptStatus(EUSCI_A0_BASE);

    if(st & EUSCI_A_UART_RECEIVE_INTERRUPT_FLAG)
    {
        uint8_t recv_byte = MAP_UART_receiveData(EUSCI_A0_BASE);
        if (recv_byte == l_SW) state_pattern_fn(l_SW);
        else if (recv_byte == R_SW) state_pattern_fn(R_SW);
        else uart_print_str("COMMAND is INVALID \r\n");
    }

}


/* Serial communication params
 * baud rate: 115200
 * parity : none
 * stop bit : 1
 * data bits : 8*/
const eUSCI_UART_Config uartConfig =
{
        EUSCI_A_UART_CLOCKSOURCE_SMCLK,
        1,
        10,
        0,
        EUSCI_A_UART_NO_PARITY,
        EUSCI_A_UART_LSB_FIRST,
        EUSCI_A_UART_ONE_STOP_BIT,
        EUSCI_A_UART_MODE,
        EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION,
};

void initialize_uart()
{
    /* Initialize rx and tx pins  */
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1,
            GPIO_PIN2 | GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);

    CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_3);

    /* passing config for initializing serial module */
    MAP_UART_initModule(EUSCI_A0_BASE, &uartConfig);
    MAP_UART_enableModule(EUSCI_A0_BASE);

    /* Enable interrupts */
    MAP_UART_enableInterrupt(
            EUSCI_A0_BASE,
            EUSCI_A_UART_RECEIVE_INTERRUPT);
    MAP_Interrupt_enableInterrupt(INT_EUSCIA0);
    MAP_Interrupt_enableMaster();
}

void uart_w_char(uint8_t b)
{
    /* wait for uart */
    while (!(UART_getInterruptStatus(
            EUSCI_A0_BASE,
            EUSCI_A_UART_TRANSMIT_INTERRUPT)));
    MAP_UART_transmitData(EUSCI_A0_BASE, b);
}

void uart_print_str(uint8_t* str)
{
    int16_t i = 0;

    do{ uart_w_char(str[i]);
    }while(str[i++]!=0 && i < 512);
}

