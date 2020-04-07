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

#include <stdbool.h>
#include <stdint.h>

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"
#include "bsp.h"
#include "boards.h"
#include "nordic_common.h"
#include "nrf_drv_clock.h"
#include "sdk_errors.h"
#include "app_error.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_drv_gpiote.h"
#include "nrf_log_default_backends.h"
#include "app_timer.h"


#if LEDS_NUMBER <= 2
#error "Board is not equipped with enough amount of LEDs"
#endif

#define TASK_1_PERIOD        1000
#define TASK_2_PERIOD        2000  
#define TASK_3_PERIOD        4000             
#define TASK_4_DELAY      200

//TaskHandle_t  led_1_toggle_task_handle; 
//TaskHandle_t  led_2_toggle_task_handle;
//TimerHandle_t led_2_timer_handle;   
//TaskHandle_t  led_3_toggle_task_handle; 
//TaskHandle_t  led_4_toggle_task_handle;  
TaskHandle_t  leds_toggle_task_handle;  


static void log_init(void)
{
    ret_code_t err_code = NRF_LOG_INIT(NULL);
    APP_ERROR_CHECK(err_code);

    NRF_LOG_DEFAULT_BACKENDS_INIT();
}


/**@brief LED0 task entry function.
 *
 * @param[in] pvParameter   Pointer that will be used as the parameter for the task.
 */



/*
static void led_2_timer_callback (void * pvParameter)
{
    UNUSED_PARAMETER(pvParameter);
    bsp_board_led_on(BSP_BOARD_LED_1);
    vTaskDelay(TASK_1_PERIOD);
    bsp_board_led_off(BSP_BOARD_LED_1);
   
}
*/





static void bsp_evt_handler(bsp_event_t evt)
{
    //SEGGER_RTT_printf(0,"+ bsp_evt_handler()\n");
    switch(evt)
    {

        case BSP_EVENT_KEY_0:

            
        //UNUSED_VARIABLE(xTaskCreate(led_1_task_function, "LED0", configMINIMAL_STACK_SIZE + 200, NULL, 2, &led_1_toggle_task_handle));


            static void led_1_task_function (void * pvParameter)
            {

                UNUSED_PARAMETER(pvParameter);
               
                bsp_board_led_on(BSP_BOARD_LED_0);

                vTaskDelay(TASK_1_PERIOD);

                bsp_board_led_off(BSP_BOARD_LED_0);

            }


        break;



        case BSP_EVENT_KEY_1:

        //UNUSED_VARIABLE(xTaskCreate(led_2_task_function, "LED1", configMINIMAL_STACK_SIZE + 200, NULL, 2, &led_2_toggle_task_handle));          

        /*led_2_timer_handle = xTimerCreate( "LED1", TASK_2_PERIOD, pdTRUE, NULL, led_2_timer_callback);
        UNUSED_VARIABLE(xTimerStart(led_2_timer_handle, 0));
        vTaskDelay(TASK_2_PERIOD);
        UNUSED_VARIABLE(xTimerStop(led_2_timer_handle, 0)); */  



            static void led_2_task_function (void * pvParameter)
            {
                
                UNUSED_PARAMETER(pvParameter);
               
                bsp_board_led_invert(BSP_BOARD_LED_1);

                vTaskDelay(TASK_2_PERIOD);

                bsp_board_led_off(BSP_BOARD_LED_1);

            } 

        break;

        case BSP_EVENT_KEY_2:

        //UNUSED_VARIABLE(xTaskCreate(led_3_task_function, "LED1", configMINIMAL_STACK_SIZE + 200, NULL, 2, &led_3_toggle_task_handle));          
 
            static void led_3_task_function (void * pvParameter)
            {
               
                UNUSED_PARAMETER(pvParameter);
               
                bsp_board_led_on(BSP_BOARD_LED_2);

                vTaskDelay(TASK_3_PERIOD);

                bsp_board_led_off(BSP_BOARD_LED_2);

            }


        break;

        case BSP_EVENT_KEY_3:

        //UNUSED_VARIABLE(xTaskCreate(led_4_task_function, "LED1", configMINIMAL_STACK_SIZE + 200, NULL, 2, &led_4_toggle_task_handle));          

            static void led_4_task_function (void * pvParameter)
            {
               
                UNUSED_PARAMETER(pvParameter);
                
                while(true)
                {

                    bsp_board_led_invert(BSP_BOARD_LED_3);

                    vTaskDelay(TASK_4_DELAY);

                }

            }

        break;


        default:

        break;


    }    
}


int main(void)
{

    ret_code_t err_code;

    /* Initialize clock driver for better time accuracy in FREERTOS */
    err_code = nrf_drv_clock_init();
    APP_ERROR_CHECK(err_code);

    log_init();

    /* Configure LED-pins as outputs */
    uint32_t res = bsp_init(BSP_INIT_LEDS | BSP_INIT_BUTTONS, bsp_evt_handler);
 
    //bsp_board_init(BSP_INIT_LEDS);
    
    if (res != NRF_SUCCESS) 
    {
        NRF_LOG_INFO("BSP example can't started.");
    } 

    else {
     
        NRF_LOG_INFO("BSP example started.");
       // bsp_configuration();
    }


    /* Create task for LED0 blinking with priority set to 2 */
    //UNUSED_VARIABLE(xTaskCreate(led_1_task_function, "LED0", configMINIMAL_STACK_SIZE + 200, NULL, 2, &led_1_toggle_task_handle));
    
    //UNUSED_VARIABLE(xTaskCreate(led_2_task_function, "LED1", configMINIMAL_STACK_SIZE + 200, NULL, 2, &led_2_toggle_task_handle));
    
    //UNUSED_VARIABLE(xTaskCreate(led_3_task_function, "LED2", configMINIMAL_STACK_SIZE + 200, NULL, 2, &led_3_toggle_task_handle));
    
    //UNUSED_VARIABLE(xTaskCreate(led_4_task_function, "LED3", configMINIMAL_STACK_SIZE + 200, NULL, 2, &led_4_toggle_task_handle));

    UNUSED_VARIABLE(xTaskCreate(bsp_evt_handler, "LEDS_NUMBER", configMINIMAL_STACK_SIZE + 200, NULL, 2, &leds_toggle_task_handle));


   /* led_2_timer_handle = xTimerCreate( "LED1", TASK_2_PERIOD, pdTRUE, NULL, led_2_timer_callback);
    UNUSED_VARIABLE(xTimerStart(led_2_timer_handle, 0));
    UNUSED_VARIABLE(xTimerStop(led_2_timer_handle, 0));*/



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

/**
 *@}
 **/







/*
#include <stdbool.h>
#include <stdint.h>

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"
#include "bsp.h"
#include "boards.h"
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



#if LEDS_NUMBER <= 2
#error "Board is not equipped with enough amount of LEDs"
#endif


#define LED_1_BLINKING_DELAY_MS   1000
#define LED2_BLINKING_MS   1000

#define TASK_DBG_LED_PRIORITY 2
#define TASK_BSP_PRIORITY     2

//static TaskHandle_t   g_dbg_led_task_handle_1;
static TimerHandle_t  g_dbg_led_timer_handle_1;
static TimerHandle_t  g_dbg_led_timer_handle_2;


static void log_init(void)
{
    ret_code_t err_code = NRF_LOG_INIT(NULL);
    APP_ERROR_CHECK(err_code);

    NRF_LOG_DEFAULT_BACKENDS_INIT();
}

*/
/*
void single_shot_timer_handler_2(void * p_context)
{
  
        bsp_board_led_off(BSP_BOARD_LED_1);
  
}*/

/*
static void task_dbg_led1(void * pvParameter)
{
    UNUSED_PARAMETER(pvParameter);

    while (true) {
    //SEGGER_RTT_printf(0,"+ task_dbg_led()\n");
        bsp_board_led_invert(BSP_BOARD_LED_0);
        vTaskDelay(LED_1_BLINKING_DELAY_MS);
    }
}

static void led2_dbg_timer_callback (void * pvParameter)
{
    
    UNUSED_PARAMETER(pvParameter);
    bsp_board_led_on(BSP_BOARD_LED_1);
    //vTaskDelay(LED2_BLINKING_MS);
    //bsp_board_led_off(BSP_BOARD_LED_1);
}

static void bsp_evt_handler(bsp_event_t evt)
{
    //SEGGER_RTT_printf(0,"+ bsp_evt_handler()\n");
    switch(evt)
    {

        case BSP_EVENT_KEY_0:

            

            

            break;



        case BSP_EVENT_KEY_1:

            g_dbg_led_timer_handle_2 = xTimerCreate( "LED1", LED2_BLINKING_MS, pdTRUE, NULL, led2_dbg_timer_callback);
            UNUSED_VARIABLE(xTimerStart(g_dbg_led_timer_handle_2, 0));
            
           

            break;


        default:

            break;


    }    
}

int main(void)
{
    ret_code_t err_code;

    // Initialize clock driver for better time accuracy in FREERTOS 
    err_code = nrf_drv_clock_init();
    APP_ERROR_CHECK(err_code);

    log_init();
    uint32_t res = bsp_init(BSP_INIT_LEDS | BSP_INIT_BUTTONS, bsp_evt_handler);
    if (res != NRF_SUCCESS) {
     //SEGGER_RTT_printf(0,"+ bsp_init() ERROR %d\n", res);
    } else {
     //SEGGER_RTT_printf(0,"+ bsp_init() OK %d\n", res);
    }

    // Create and Initialize all the tasks. //
    //SEGGER_RTT_printf(0,"Creating tasks...");
    //UNUSED_VARIABLE(xTaskCreate(task_dbg_led1, "LED0",
    //                configMINIMAL_STACK_SIZE + 1024,
    //                NULL, TASK_DBG_LED_PRIORITY,
    //                &g_dbg_led_task_handle));
    //SEGGER_RTT_printf(0,"OK.\n");
    //g_dbg_led_timer_handle = xTimerCreate( "LED1", LED_BLINKING_DELAY_MS, pdTRUE, NULL, led1_dbg_timer_callback);
    //UNUSED_VARIABLE(xTimerStart(g_dbg_led_timer_handle, 0));


   
    //UNUSED_VARIABLE(xTaskCreate(task_dbg_led1, "LED0",
    //                configMINIMAL_STACK_SIZE + 1024,
    //                NULL, TASK_DBG_LED_PRIORITY,
    //                &g_dbg_led_task_handle));

    g_dbg_led_timer_handle_1 = xTimerCreate( "LED0", LED2_BLINKING_MS, pdTRUE, NULL, task_dbg_led1);
            UNUSED_VARIABLE(xTimerStart(g_dbg_led_timer_handle_1, 0));

    g_dbg_led_timer_handle_2 = xTimerCreate( "LED1", LED2_BLINKING_MS, pdTRUE, NULL, task_dbg_led1);
    UNUSED_VARIABLE(xTimerStart(g_dbg_led_timer_handle_2, 0));
            
 */           
    

    /* Activate deep sleep mode */
    //SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;

    /* Start FreeRTOS scheduler. */
    //vTaskStartScheduler();

    //while (true)
    //{
        /* FreeRTOS should not be here... FreeRTOS goes back to the start of stack
         * in vTaskStartScheduler function. */
    //}
//}