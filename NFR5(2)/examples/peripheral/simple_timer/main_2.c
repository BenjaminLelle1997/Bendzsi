/**
 * Copyright (c) 2014 - 2019, Nordic Semiconductor ASA
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
 *
 * @defgroup bsp_example_main main.c
 * @{
 * @ingroup bsp_example
 * @brief BSP Example Application main file.
 *
 */

#include "main_2.h"

#define BUTTON_PREV_ID           0                           /**< Button used to switch the state. */
#define BUTTON_NEXT_ID           1                           /**< Button used to switch the state. */
                                          
#define TOGGLE_LED_COUNTER               (500 / (TIMEOUT_VALUE / 1000)) /**< Interval for toggling a LED. Yields to 500 mseconds. */
#define STATE_TRANSIT_COUNTER_INIT_VALUE (4 * TOGGLE_LED_COUNTER)       /**< Initial value for the state transition counter.  */
#define GENERIC_DELAY_TIME               5000                           /**< Generic delay time used by application. */

APP_TIMER_DEF(m_single_shot_timer_1);                      /**< Handler for single shot timer used to light LED 1. */
APP_TIMER_DEF(m_single_shot_timer_2); 
APP_TIMER_DEF(m_single_shot_timer_3); 
APP_TIMER_DEF(m_single_shot_timer_4); 


/**
*@brief 
*Simple-Timer. This is my first paragraph.
*/

/**
 * @brief Application states. */
typedef enum
{
    APP_STATE_SINGLE_SHOT,                                              /**< Application state where single shot timer mode is tested. */
} state_t;

/**@brief  These are static variables for led's state.
*/
static volatile uint32_t m_state_transit_counter = 0;                            /**< State transition counter variable. */
static volatile uint32_t m_toggle_led_counter    = 0;                            /**< Led toggling counter variable. */
static volatile state_t  m_state;                                                /**< Current application state. */


/**
 * @brief Do something.
 */
void timeout_handler(void * p_context);


/**
  * @brief The led will off.
  * @param 
  */
void single_shot_timer_handler(void * p_context)
{
  
   /* if(BSP_EVENT_KEY_0) 

        bsp_board_led_off(BSP_BOARD_LED_0);

    if(BSP_EVENT_KEY_1) 
    
        bsp_board_led_off(BSP_BOARD_LED_1);
        
    if(BSP_EVENT_KEY_2) 

        bsp_board_led_off(BSP_BOARD_LED_2);

    if(BSP_EVENT_KEY_3)

        bsp_board_led_off(BSP_BOARD_LED_3);*/

   
    bsp_board_leds_off();   

}


/**
 * @brief Create timer for a short time
 */

ret_code_t create_timer_1()  
{

    ret_code_t err_code;
    
    // Create timer
    err_code = app_timer_create(&m_single_shot_timer_1,
                            APP_TIMER_MODE_SINGLE_SHOT,
                            single_shot_timer_handler);

    APP_ERROR_CHECK(err_code);

    return err_code;
}

ret_code_t create_timer_2()  
{
    ret_code_t err_code;
    

    // Create timer
    err_code = app_timer_create(&m_single_shot_timer_2,
                            APP_TIMER_MODE_SINGLE_SHOT,
                            single_shot_timer_handler);

    APP_ERROR_CHECK(err_code);

    return err_code;
}

ret_code_t create_timer_3()  
{
    ret_code_t err_code;
    

    // Create timer
    err_code = app_timer_create(&m_single_shot_timer_3,
                            APP_TIMER_MODE_SINGLE_SHOT,
                            single_shot_timer_handler);

    APP_ERROR_CHECK(err_code);

    return err_code;
}

ret_code_t create_timer_4()  
{
    ret_code_t err_code;
    

    // Create timer
    err_code = app_timer_create(&m_single_shot_timer_4,
                            APP_TIMER_MODE_SINGLE_SHOT,
                            single_shot_timer_handler);

    APP_ERROR_CHECK(err_code);

    return err_code;
}

/**
 * @brief Function for the Power Management.
 */


/**
 * @brief Functions for led. LED_1 does else.
 * @param evt This is the button event
 */
void bsp_evt_handler(bsp_event_t evt)   // Tesztet írni
{
        static uint32_t timeout_1 = 0;
        /*static uint32_t timeout_2 = 2000;
        static uint32_t timeout_3 = 4000;
        static uint32_t timeout_4 = 8000;*/

        uint32_t err_code_1;
        uint32_t err_code_2; 
        uint32_t err_code_3; 
        uint32_t err_code_4;       

        switch (evt)
        {
            /*bsp_board_led_invert(BSP_BOARD_LED_0);
            bsp_board_led_invert(BSP_BOARD_LED_1);
            bsp_board_led_invert(BSP_BOARD_LED_2);
            bsp_board_led_invert(BSP_BOARD_LED_3);*/




            case BSP_EVENT_KEY_0:            // On Button 1 press. 
          
               
                //bsp_board_leds_off(); 
                //bsp_board_led_off(BSP_BOARD_LED_2);
                //bsp_board_led_off(BSP_BOARD_LED_3);
                
                
                
                bsp_board_led_on(BSP_BOARD_LED_0);
                timeout_1=1000;
                err_code_1 = app_timer_start(m_single_shot_timer_1, APP_TIMER_TICKS(timeout_1), NULL);
                APP_ERROR_CHECK(err_code_1);

            
                break;



            case BSP_EVENT_KEY_1:            // On Button 2 press. 
            
                //bsp_board_leds_off(); 
                //bsp_board_led_off(BSP_BOARD_LED_2);
                //bsp_board_led_off(BSP_BOARD_LED_3);
               

                bsp_board_led_on(BSP_BOARD_LED_1);
                timeout_1=2000;
                err_code_2 = app_timer_start(m_single_shot_timer_2, APP_TIMER_TICKS(timeout_1), NULL);
                APP_ERROR_CHECK(err_code_2);

                break;

               

            case BSP_EVENT_KEY_2:            // On Button 3 press. 

               
                //bsp_board_leds_off(); 
                //bsp_board_led_off(BSP_BOARD_LED_1);
                //bsp_board_led_off(BSP_BOARD_LED_3);
                
                
                bsp_board_led_on(BSP_BOARD_LED_2);
                timeout_1=4000;
                err_code_3 = app_timer_start(m_single_shot_timer_3, APP_TIMER_TICKS(timeout_1), NULL);
                APP_ERROR_CHECK(err_code_3);

                break;


                

            case BSP_EVENT_KEY_3:            // On Button 4 press. 

                //bsp_board_leds_off(); 
                //bsp_board_led_off(BSP_BOARD_LED_1);
                //bsp_board_led_off(BSP_BOARD_LED_2);
                
                
                

                bsp_board_led_on(BSP_BOARD_LED_3);
                timeout_1=8000;
                err_code_4 = app_timer_start(m_single_shot_timer_4, APP_TIMER_TICKS(timeout_1), NULL);
                APP_ERROR_CHECK(err_code_4);

                break;

               


            default:
                return; // no implementation needed

        }

        err_code_1 = NRF_SUCCESS;
        APP_ERROR_CHECK(err_code_1);

        err_code_2 = NRF_SUCCESS;
        APP_ERROR_CHECK(err_code_2);

        err_code_3 = NRF_SUCCESS;
        APP_ERROR_CHECK(err_code_3);

        err_code_4 = NRF_SUCCESS;
        APP_ERROR_CHECK(err_code_4);

}

/**@brief Function for initializing low frequency clock.
 */
void clock_initialization()
{
    NRF_CLOCK->LFCLKSRC            = (CLOCK_LFCLKSRC_SRC_Xtal << CLOCK_LFCLKSRC_SRC_Pos);
    NRF_CLOCK->EVENTS_LFCLKSTARTED = 0;
    NRF_CLOCK->TASKS_LFCLKSTART    = 1;

    while (NRF_CLOCK->EVENTS_LFCLKSTARTED == 0)
    {
        // Do nothing.
    }
}

/**@brief Function for initializing bsp module.
 * @param BSP_INIT_LEDS Initalizating the leds.
 * @param BSP_INIT_BUTTONS Initalizing the buttonds.
 * @param bsp_evt_handler Inviting the own function.
 */
void bsp_configuration()
{
    uint32_t err_code;

    err_code = bsp_init(BSP_INIT_LEDS | BSP_INIT_BUTTONS, bsp_evt_handler);
    bsp_board_init(BSP_INIT_LEDS);
    APP_ERROR_CHECK(err_code);
}


/**
 * @brief Function for application main entry.
 */
int main(void)
{
    clock_initialization();
   
    uint32_t err_code = app_timer_init();
    APP_ERROR_CHECK(err_code);

    err_code = app_simple_timer_init();
    APP_ERROR_CHECK(err_code);
    
    APP_ERROR_CHECK(NRF_LOG_INIT(NULL));
    NRF_LOG_DEFAULT_BACKENDS_INIT();

    NRF_LOG_INFO("BSP example started.");
    bsp_configuration();

    create_timer_1();
    create_timer_2();
    create_timer_3();
    create_timer_4();
    
   
    for (;;)
    {
        NRF_LOG_FLUSH();
        __SEV();
        __WFE();
        __WFE();
        // no implementation needed
    }

    return 0;
}


/** @} */
