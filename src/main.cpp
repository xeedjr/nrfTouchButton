#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <util/delay.h>

#include "main.h"
#include <stdlib.h>
//#include <new>

#include "ch.h"
#include "hal.h"
#include "cmsis_os.h"

#include "SensorButton.h"
#include "LEDBlinker.h"
#include "Rf.h"
#include "BL_Main.h"
#include "SensorButton.h"
#include "power_management.h"

SensorButton* button = nullptr;
LEDBlinker led_blink;
Rf rf;

BL_Main bl;

static void ext_cb(EXTDriver *extp, expchannel_t channel){
//	chSysLockFromISR();
	if (button != nullptr) {
		button->event();
	}
//	chSysUnlockFromISR();
}

/**
 * @brief  EXT Driver configurations.
 */
static const EXTConfig extcfg = {
  {
    {EXT_CH_MODE_BOTH_EDGES , ext_cb},      /* INT0 Config. */
    {EXT_CH_MODE_DISABLED , NULL},      /* INT1 Config. */
    {EXT_CH_MODE_DISABLED , NULL},      /* INT2 Config. */
    {EXT_CH_MODE_DISABLED , NULL},      /* INT3 Config. */
    {EXT_CH_MODE_DISABLED , NULL},  /* INT4 Config. */
    {EXT_CH_MODE_DISABLED , NULL},      /* INT5 Config. */
  }
};


int main( void )
{
	_delay_ms(500);

	  /*
	   * System initializations.
	   * - HAL initialization, this also initializes the configured device drivers
	   *   and performs the board-specific initializations.
	   * - Kernel initialization, the main() function becomes a thread and the
	   *   RTOS is active.
	   */
	  halInit();
	  osKernelInitialize();

	/* LED timer initialization.*/
//	palSetPadMode(IOPORT2, 5, PAL_MODE_OUTPUT_PUSHPULL);
//	led_blink.init(IOPORT2, 5);

  extStart(&EXTD1, &extcfg);

	button = new SensorButton(IOPORT4,
								2,
								[](){bl.SwitchPress();},
								[](){bl.SwitchRelease();});
	
	//Rf
	rf.init();
	bl.init();

	//Ir
	extChannelEnable(&EXTD1, INT0);

	enter_sleep_set(true);

	while (1)
	{
		bl.iteration();
	}
}
