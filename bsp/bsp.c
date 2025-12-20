/*****************************************************************************
 ******************************* SUNNY MATATO ********************************
 ****************************************************************************/

#include "snmtt_port.h"

#include "bsp.h"

#include "application.h"

/*..........................................................................*/

/**
 * system clock
 */

void SystemClock_init(void);

/**
 * timer0 initialization
 */

void TimerInit_systick(void);

/*..........................................................................*/

void BSP_init(void) {

    /**
     * system initialization
     */

    SystemClock_init();

    TimerInit_systick();

	SNMTT_PrtDbg_bspInit();

	return;

}

void SystemClock_init(void) {

	/**
	 * default configurations:
	 *
	 * 		resonator： internal high-speed resonator(IRC)
	 *
	 *      the frequency is slected when downloading the hex via the ISP prog
	 */

	return;

}

void TimerInit_systick(void) {

	return;

}
