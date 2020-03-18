#include "unity.h"
#include <setjmp.h>
#include <stdio.h>
#include "unity_fixture.h"
#include "unity_memory.h"

#include <stdbool.h>
#include <stdint.h>
#include "boards.h"
#include "bsp.h"
#include "app_timer.h"
#include "nordic_common.h"
#include "nrf_error.h"

#include "nrf_delay.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

void bsp_evt_handler(bsp_event_t evt);