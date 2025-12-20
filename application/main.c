/*****************************************************************************
 ******************************* SUNNY MATATO ********************************
 ****************************************************************************/

#include "snmtt_port.h"

#include "bsp.h"

#include "application.h"

/**
 * main
 */

void main(void) {

	/**
	 * AO constructor
	 */

	AO_ctor();

	/**
	 * initialize the Board Support Package
	 */

    BSP_init();

	SNMTT_INT_ENABLE();
	for (;;) {

		BSP_breathe(&AO_BSP_DBG);

		SNMTT_Printer_run(&SNMTT_PrtDbg);

	}

	return;

}
