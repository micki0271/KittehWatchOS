#include <stdbool.h>
#include <stdint.h>

#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#ifndef __linux__
#include "app_error.h"
#include "bsp.h"
#include "nordic_common.h"
#include "nrf_drv_clock.h"
#include "sdk_errors.h"
#include <nrf_log_backend_serial.h>
#include <nrf_log_ctrl_internal.h>
#include <nrfx_log.h>
#endif

#include <stdbool.h>

void vApplicationIdleHook(void) {}

uint8_t pinLcdBacklight1 = 14;
uint8_t pinLcdBacklight2 = 22;
uint8_t pinLcdBacklight3 = 23;

#define TASK_DELAY 1000 /**< Task delay. Delays a LED0 task for 200 ms */
#define TIMER_PERIOD                                                           \
  3000 /**< Timer period. LED1 timer will expire after 1000 ms */

TaskHandle_t
    led_toggle_task_handle; /**< Reference to LED0 toggling FreeRTOS task. */
TimerHandle_t
    led_toggle_timer_handle; /**< Reference to LED1 toggling FreeRTOS timer. */


void toggleLED(bool x) {
#ifndef __linux__
    if (x) {
      nrf_gpio_pin_clear(pinLcdBacklight1);
      nrf_gpio_pin_clear(pinLcdBacklight2);
      nrf_gpio_pin_clear(pinLcdBacklight3);
    } else {
      nrf_gpio_pin_set(pinLcdBacklight1);
      nrf_gpio_pin_set(pinLcdBacklight2);
      nrf_gpio_pin_set(pinLcdBacklight3);
    }
#else
printf(x ? "true\n" : "false\n");
#endif
    return !x;
}


static void led_toggle_task_function(void *pvParameter) {
  bool x = true;
  while (true) {
    x = toggleLED;
    vTaskDelay(TASK_DELAY);
  }
}






int main(void) {
#ifndef __linux__
  ret_code_t err_code;

  nrf_gpio_cfg_output(pinLcdBacklight1);
  nrf_gpio_cfg_output(pinLcdBacklight2);
  nrf_gpio_cfg_output(pinLcdBacklight3);

  /* Initialize clock driver for better time accuracy in FREERTOS */
  err_code = nrf_drv_clock_init();
  APP_ERROR_CHECK(err_code);

  /* Configure LED-pins as outputs */
  bsp_board_init(BSP_INIT_LEDS);

#endif

  /* Create task for LED0 blinking with priority set to 2 */
  xTaskCreate(led_toggle_task_function, "LED0",
                              configMINIMAL_STACK_SIZE + 200, NULL, 2,
                              &led_toggle_task_handle);

  xTimerStart(led_toggle_timer_handle, 0);

#ifndef __linux__
  /* Activate deep sleep mode */
  SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
#endif

  /* Start FreeRTOS scheduler. */
  vTaskStartScheduler();

  while (true) {
    /* FreeRTOS should not be here... FreeRTOS goes back to the start of stack
     * in vTaskStartScheduler function. */
  }
}
