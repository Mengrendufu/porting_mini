/*****************************************************************************
 ******************************* SUNNY MATATO ********************************
 ****************************************************************************/

#include "snmtt_port.h"

#include "bsp.h"

#include "application.h"

void AO_ctor(void) {

	SNMTT_PrtDbg_ctor(&SNMTT_PrtDbg);

	return;

}

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
