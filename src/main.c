/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "ch.h"
#include "hal.h"
#include "rt_test_root.h"
#include "oslib_test_root.h"

#include "usbcfg.h"

/*
 * Green ACTIVITY_LED blinker thread, times are in milliseconds.
 */
static THD_WORKING_AREA(waBlinkerThread, 128);
static THD_FUNCTION(BlinkerThread, arg) {
  (void)arg;
  chRegSetThreadName("blinker");
  while (true) {
    systime_t time = serusbcfg1.usbp->state == USB_ACTIVE ? 250 : 500;
    palClearLine(ACTIVITY_LED);
    chThdSleepMilliseconds(time);
    palSetLine(ACTIVITY_LED);
    chThdSleepMilliseconds(time);
  }
}

extern void gdb_main(void);
static THD_WORKING_AREA(waGDBThread, 512);
static THD_FUNCTION(GDBThread, arg) {
  (void)arg;
  chRegSetThreadName("gdb");
  gdb_main();
}


/*
 * Application entry point.
 */
int main(void) {
  halInit();
  chSysInit();

  // Serial 1
  sdStart(&SD1, NULL);

  // USB serial driver
  sduObjectInit(&SDU1);
  sduStart(&SDU1, &serusbcfg1);
  sduObjectInit(&SDU2);
  sduStart(&SDU2, &serusbcfg2);
  // USB
  usbDisconnectBus(serusbcfg1.usbp);
  chThdSleepMilliseconds(15);
  usbStart(serusbcfg1.usbp, &usbcfg);
  usbConnectBus(serusbcfg1.usbp);


  // start blinker thread
  chThdCreateStatic(waBlinkerThread, sizeof(waBlinkerThread), NORMALPRIO, BlinkerThread, NULL);
  chThdCreateStatic(waGDBThread, sizeof(waGDBThread), NORMALPRIO, GDBThread, NULL);

  /*
   * Normal main() thread activity, in this demo it does nothing except
   * sleeping in a loop and check the button state.
   */
  while (true) {
    if (!palReadLine(BUTTON)) {
      test_execute((BaseSequentialStream *)&SD1, &rt_test_suite);
      test_execute((BaseSequentialStream *)&SD1, &oslib_test_suite);
    }
    chThdSleepMilliseconds(500);
  }
}
