#include "bsp_evt_led_handler.h"

#define BUTTON_PREV_ID           0                           /**< Button used to switch the state. */
#define BUTTON_NEXT_ID           1                           /**< Button used to switch the state. */



/**@brief Function for handling bsp events.
 */
void bsp_evt_handler(bsp_event_t evt)   // Tesztet írni
{
        static uint32_t timeout = 0;

        uint32_t err_code;
        

        switch (evt)
        {

           
            case BSP_EVENT_KEY_1:            // On Button 2 press. 

                // ez-az==ison
                bsp_board_led_on(BSP_BOARD_LED_1);
                //timeout += 3000;
                // Teszt függvény a timeout-ra
                //Testing_Led1Event(evt);

                err_code = app_timer_start(m_single_shot_timer_id, APP_TIMER_TICKS(timeout), NULL);
                APP_ERROR_CHECK(err_code);
                break;

            default:
                return; // no implementation needed

        }

        err_code = NRF_SUCCESS;
        APP_ERROR_CHECK(err_code);
    
}