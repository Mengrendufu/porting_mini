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

void TimerInit_timer0(void);

/*..........................................................................*/

void BSP_init(void) {

    /**
     * system initialization
     */

    SystemClock_init();

    TimerInit_timer0();

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

void TimerInit_timer0(void) {

	/**
	 * default:
	 *
	 * 		timer clock prescale : 12
	 *
	 * 		timer mode 0         : 16-bit autoreload
	 */

	/**
	 * cnt_load
	 */

	TH0 = (65536UL - SYSTEM_CLOCK_FREQUENCY / 12UL / BSP_TICKS_PER_SEC)

				/ 256U;

	TL0 = (65536UL - SYSTEM_CLOCK_FREQUENCY / 12UL / BSP_TICKS_PER_SEC)

				% 256U;

	/**
	 * enable timer0 ISR
	 */

	BITS_SET_U8(IE, 1);

	/**
	 * trigger timer 0
	 */

	BITS_SET_U8(TCON, 4);

	return;

}
