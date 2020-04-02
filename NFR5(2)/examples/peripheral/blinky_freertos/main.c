/**
 * Copyright (c) 2015 - 2019, Nordic Semiconductor ASA
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 *
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
/** @file
 * @defgroup blinky_example_main main.c
 * @{
 * @ingroup blinky_example_freertos
 *
 * @brief Blinky FreeRTOS Example Application main file.
 *
 * This file contains the source code for a sample application using FreeRTOS to blink LEDs.
 *
 */
/*
#include <stdbool.h>
#include <stdint.h>

#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "bsp.h"
#include "nordic_common.h"
#include "nrf_drv_clock.h"
#include "sdk_errors.h"
#include "app_error.h"


#include <stdio.h>

#include "app_simple_timer.h"
#include "app_timer.h"
#include "boards.h"
#include "bsp.h"
#include "led_softblink.h"
#include "nrf.h"
#include "nrf_error.h"
#include "nrf_gpio.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

#include "sdk_common.h"
#include "app_util_platform.h"
#include "nrf_timer.h"
#include "nrf_drv_timer.h"



#if LEDS_NUMBER <= 2
#error "Board is not equipped with enough amount of LEDs"
#endif*/

//#define TASK_DELAY        400           /**< Task delay. Delays a LED0 task for 200 ms */
//#define TIMER_PERIOD      2000          /**< Timer period. LED1 timer will expire after 1000 ms */

//TaskHandle_t  led_toggle_task_handle;   /**< Reference to LED0 toggling FreeRTOS task. */
//TimerHandle_t led_toggle_timer_handle;  /**< Reference to LED1 toggling FreeRTOS timer. */

/**@brief LED0 task entry function.
 *
 * @param[in] pvParameter   Pointer that will be used as the parameter for the task.
*/
/*
static void led_toggle_task_functions (void * pvParameter)
{
    
    UNUSED_PARAMETER(pvParameter);
    while (true)
    {
        bsp_board_led_invert(BSP_BOARD_LED_0);

        // Delay a task for a given number of ticks 
        vTaskDelay(TASK_DELAY);

        // Tasks must be implemented to never return... 
    }

}
*/
/**@brief The function to call when the LED1 FreeRTOS timer expires.
 *
 * @param[in] pvParameter   Pointer that will be used as the parameter for the timer.
 */
/*
static void led_toggle_timer_callback (void * pvParameter)
{
    
    UNUSED_PARAMETER(pvParameter);
    bsp_board_led_invert(BSP_BOARD_LED_1);
}


int main(void)
{
    ret_code_t err_code;

    // Initialize clock driver for better time accuracy in FREERTOS 
    err_code = nrf_drv_clock_init();
    APP_ERROR_CHECK(err_code);

    // Configure LED-pins as outputs 
    bsp_board_init(BSP_INIT_LEDS);

    // Create task for LED0 blinking with priority set to 2 
    UNUSED_VARIABLE(xTaskCreate(led_toggle_task_functions, "LED0", configMINIMAL_STACK_SIZE + 200, NULL, 2, &led_toggle_task_handle));

    // Start timer for LED1 blinking 
    led_toggle_timer_handle = xTimerCreate( "LED1", TIMER_PERIOD, pdTRUE, NULL, led_toggle_timer_callback);
    UNUSED_VARIABLE(xTimerStart(led_toggle_timer_handle, 0));


    // Activate deep sleep mode 
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;

    // Start FreeRTOS scheduler. 
    vTaskStartScheduler();

    while (true)
    {
        // FreeRTOS should not be here... FreeRTOS goes back to the start of stack
        // in vTaskStartScheduler function. 
    }
}
*/
/**
 *@}
 **/








#include <stdbool.h>
#include <stdint.h>

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"
#include "bsp.h"
#include "nordic_common.h"
#include "nrf_drv_clock.h"
#include "sdk_errors.h"
#include "app_error.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_drv_gpiote.h"
#include "nrf_log_default_backends.h"
//#include "SEGGER_RTT.h"
#include "app_timer.h"

#define LED_BLINKING_DELAY_MS   1000

#define TASK_DBG_LED_PRIORITY 2
#define TASK_BSP_PRIORITY     2

static TaskHandle_t  g_dbg_led_task_handle;


//#define BUTTON_PREV_ID           0                           /**< Button used to switch the state. */
//#define BUTTON_NEXT_ID           1                           /**< Button used to switch the state. */
                                          
//#define TOGGLE_LED_COUNTER               (500 / (TIMEOUT_VALUE / 1000)) /**< Interval for toggling a LED. Yields to 500 mseconds. */
//#define STATE_TRANSIT_COUNTER_INIT_VALUE (4 * TOGGLE_LED_COUNTER)       /**< Initial value for the state transition counter.  */
//#define GENERIC_DELAY_TIME               5000                           /**< Generic delay time used by application. */

//APP_TIMER_DEF(m_single_shot_timer_1);                      /**< Handler for single shot timer used to light LED 1. */
//APP_TIMER_DEF(m_single_shot_timer_2); 
//APP_TIMER_DEF(m_single_shot_timer_3); 


//typedef enum
//{
//    APP_STATE_SINGLE_SHOT,                                              /**< Application state where single shot timer mode is tested. */
//} state_t;

/**@brief  These are static variables for led's state.
*/
//static volatile uint32_t m_state_transit_counter = 0;                            /**< State transition counter variable. */
//static volatile uint32_t m_toggle_led_counter    = 0;                            /**< Led toggling counter variable. */
//static volatile state_t  m_state;                                                /**< Current application state. */


/**
 * @brief Do something.
 */
//void timeout_handler(void * p_context);







static void log_init(void)
{
    ret_code_t err_code = NRF_LOG_INIT(NULL);
    APP_ERROR_CHECK(err_code);

    NRF_LOG_DEFAULT_BACKENDS_INIT();
}


void task_dbg_led(void * pvParameter)
{
    UNUSED_PARAMETER(pvParameter);
    

    while (true) {
    //SEGGER_RTT_printf(0,"+ task_dbg_led()\n");
        bsp_board_led_invert(BSP_BOARD_LED_0);
        vTaskDelay(LED_BLINKING_DELAY_MS);
    
    }

}


static void bsp_evt_handler(bsp_event_t evt)
{
          //static uint32_t timeout_1 = 0;
        /*static uint32_t timeout_2 = 2000;
        static uint32_t timeout_3 = 4000;
        static uint32_t timeout_4 = 8000;*/

        //uint32_t err_code_1;
        //uint32_t err_code_2; 
        //uint32_t err_code_3; 
        //uint32_t err_code_4;       

        //switch (evt)
        //{
            /*bsp_board_led_invert(BSP_BOARD_LED_0);
            bsp_board_led_invert(BSP_BOARD_LED_1);
            bsp_board_led_invert(BSP_BOARD_LED_2);
            bsp_board_led_invert(BSP_BOARD_LED_3);*/




           // case BSP_EVENT_KEY_0:            // On Button 1 press. 
          
               
                //bsp_board_leds_off(); 
                //bsp_board_led_off(BSP_BOARD_LED_2);
                //bsp_board_led_off(BSP_BOARD_LED_3);
                
                
                
                /*bsp_board_led_on(BSP_BOARD_LED_0);
                timeout_1=1000;
                err_code_1 = app_timer_start(m_single_shot_timer_1, APP_TIMER_TICKS(timeout_1), NULL);
                APP_ERROR_CHECK(err_code_1);*/

            //  task_dbg_led(void * pvParameter);


            //    break;


}



int main(void)
{
    ret_code_t err_code;

    /* Initialize clock driver for better time accuracy in FREERTOS */
    err_code = nrf_drv_clock_init();
    APP_ERROR_CHECK(err_code);

    log_init();
    uint32_t res = bsp_init(BSP_INIT_LEDS | BSP_INIT_BUTTONS, bsp_evt_handler);
    if (res != NRF_SUCCESS) {
     //SEGGER_RTT_printf(0,"+ bsp_init() ERROR %d\n", res);
    } else {
     //SEGGER_RTT_printf(0,"+ bsp_init() OK %d\n", res);
    }

    /* Create and Initialize all the tasks. */
    //SEGGER_RTT_printf(0,"Creating tasks...");
    UNUSED_VARIABLE(xTaskCreate(task_dbg_led, "LED0",
                    configMINIMAL_STACK_SIZE + 1024,
                    NULL, TASK_DBG_LED_PRIORITY,
                    &g_dbg_led_task_handle));


    
   // SEGGER_RTT_printf(0,"OK.\n");

    /* Activate deep sleep mode */
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;

    /* Start FreeRTOS scheduler. */
    vTaskStartScheduler();

    while (true)
    {
        /* FreeRTOS should not be here... FreeRTOS goes back to the start of stack
         * in vTaskStartScheduler function. */
    }
}