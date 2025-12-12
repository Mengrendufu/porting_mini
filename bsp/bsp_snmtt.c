/*****************************************************************************
 ******************************* SUNNY MATATO ********************************
 ****************************************************************************/

#include "snmtt_port.h"

#include "bsp.h"

#include "application.h"

void SNMTT_PrtDbg_bspInit(void) {

	/**
	 * uart1 configurations
	 */

	/**
	 * uart1 mode configuration
	 */

	/**
	 * uart1 mode: mode1
	 */

	BITS_RESET_U8(SCON, 7);

	BITS_SET_U8(SCON, 6);

	/**
	 * uart clock configuration
	 *
	 * baudrate generator: timer 1
	 *
	 * default:
	 *
	 * 		timer clock prescale : 12
	 *
	 * 		timer mode 0         : 16-bit autoreload
	 */

	/**
	 * baudrate generator: timer 1
     *
     * default: timer 2
	 *
	 * baudrate: 115200
	 */

	BITS_RESET_U8(AUXR, 0);

	TH1 = (65536UL - SYSTEM_CLOCK_FREQUENCY / 12UL / 4UL / 115200UL)

				/ 256U;

	TL1 = (65536UL - SYSTEM_CLOCK_FREQUENCY / 12UL / 4UL / 115200UL)

				% 256U;

	/**
	 * trigger timer 1
	 */

	BITS_SET_U8(TCON, 6);

	/**
	 * GPIO config
	 */

	/**
	 * rx: P3_0
	 * tx: P3_1
	 */

	BITS_RESET_U8(P_SW1, 7);

	BITS_RESET_U8(P_SW1, 6);

	/* PIN_TX: pull-up output */

	BITS_RESET_U8(P3M1, 1);

	BITS_SET_U8(P3M0, 1);

	/**
	 * uart1 interrupt configuration
	 *
	 * uart1_isr enable
	 */

	BITS_SET_U8(IE, 4);

    return;

}
