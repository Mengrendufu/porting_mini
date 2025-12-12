/*****************************************************************************
 ******************************* SUNNY MATATO ********************************
 ****************************************************************************/

#include "snmtt_port.h"

#include "bsp.h"

#include "application.h"

/**
 * system clock tick ISR
 */

void Timer0_ISR_Handler (void) interrupt TMR0_VECTOR {

    BSP_heartBeats(&AO_BSP_DBG);

    Printer_tick(&SNMTT_PrtDbg);

	return;

}
