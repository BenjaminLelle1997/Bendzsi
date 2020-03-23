//#include "bsp_evt_led_handler.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "app_error.h"
#include "app_simple_timer.h"
#include "app_timer.h"
#include "boards.h"
#include "bsp.h"
#include "led_softblink.h"
#include "nordic_common.h"
#include "nrf.h"
#include "nrf_delay.h"
#include "nrf_error.h"
#include "nrf_gpio.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

#include "sdk_common.h"
#include "app_util_platform.h"
#include "nrf_timer.h"
#include "nrf_drv_timer.h"


void timeout_handler(void * p_context);

void single_shot_timer_handler(void * p_context);

ret_code_t create_timer_1();

ret_code_t create_timer_2();

ret_code_t create_timer_3();

ret_code_t create_timer_4();

void bsp_evt_handler(bsp_event_t evt);

void clock_initialization();

void bsp_configuration();




