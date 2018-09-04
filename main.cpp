/*
 * main.cpp
 *
 * Created: 05.08.2018 15:14:57
 *  Author: Bogdan
 */ 

#include "ch.h"
#include "hal.h"
#include "cmsis_os.h"

main() {


	/*
	* System initializations.
	* - HAL initialization, this also initializes the configured device drivers
	*   and performs the board-specific initializations.
	* - Kernel initialization, the main() function becomes a thread and the
	*   RTOS is active.
	*/
	halInit();
	osKernelInitialize();
	
}