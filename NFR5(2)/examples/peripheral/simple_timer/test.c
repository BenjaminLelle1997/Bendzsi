#include "main.h"
#include "bsp_evt_led_handler.h"

#include "unity.h"
#include <setjmp.h>
#include <stdio.h>
#include "unity_fixture.h"
#include "unity_memory.h"
/*
#include <stdbool.h>
#include <stdint.h>
#include "boards.h"
#include "bsp.h"
#include "app_timer.h"
#include "nordic_common.h"
#include "nrf_error.h"


#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"*/


static char buffer[100];
static uint8_t pos=0;

static void flush_log()
{


   
   {
      NRF_LOG_RAW_INFO("%s",buffer);

      pos = 0;
   }
}


void test_putchar(int c)
{

  //NRF_LOG_INFO("%c",c );
  //NRF_LOG_INFO_NONEWLINE(".");
  //NRF_LOG_INSTANCE_PTR_DECLARE(c);
  //NRF_LOG_FINAL_FLUSH();
  //NRF_LOG_RAW_INFO(c);
   
   //printf("c");
    /* Print your info messages */

  buffer[pos++] = c;

  if(pos == 100)
  { 
   flush_log(); 
  } 
 
}

bsp_event_t push_event;
bsp_event_t evt;

uint32_t led_idx;

TEST_GROUP(something);

//sometimes you may want to get at local data in a module.
//for example: If you plan to pass by reference, this could be useful
//however, it should often be avoided


TEST_SETUP(something)
{
  led_idx=1;

}

TEST_TEAR_DOWN(something)
{
}

 

TEST(something, bsp_board_led_state_get)
{
 
  bsp_evt_handler(BSP_EVENT_KEY_1);
   //All of these should pass
  TEST_ASSERT(bsp_board_led_state_get(led_idx));
   //TEST_ASSERT(bsp_evt_handler(BSP_EVENT_KEY_1));
}


TEST_GROUP_RUNNER(something)
{
    RUN_TEST_CASE(something,bsp_board_led_state_get);
}


/* -------------------------------------- */

/*
void setUp(void) {
   //push_event= evt;
	led_idx=1;
}

void tearDown(void) {
    // clean stuff up here
}

void Testing_Led1Event(void) {
    
     bsp_evt_handler(BSP_EVENT_KEY_1);
        
    //TEST_ASSERT_EQUAL(push_event, bsp_evt_handler(BSP_EVENT_KEY_1));
     TEST_ASSERT(bsp_board_led_state_get(led_idx));
     printf("Your event is the same, than expected.");
 	 
}*/
/*
void Test_LED1_IsOn(void)
{
	bool led_is_on;
	TEST_ASSERT(bsp_board_led_off(BSP_BOARD_LED_1)==led_is_on)
		return true;
	else
		return false;
}*/



static void RunAllTests(void)
{
    RUN_TEST_GROUP(something);
    //RUN_TEST();
}

int main(int argc, const char * argv[] )
{
	APP_ERROR_CHECK(NRF_LOG_INIT(NULL));
    NRF_LOG_DEFAULT_BACKENDS_INIT();
    NRF_LOG_INFO("testing");
    UnityMain(argc, argv, RunAllTests);
    flush_log();
   for (;;)
    {
        //power_manage();
        // Use directly __WFE and __SEV macros since the SoftDevice is not available.
        NRF_LOG_FLUSH();
        __SEV();
        __WFE();
        __WFE();

    }
	//return UnityMain(argc, argv, RunAllTests); 
  return 0;
       
}



    //return 0;

