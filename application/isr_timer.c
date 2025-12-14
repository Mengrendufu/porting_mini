/*****************************************************************************
 ******************************* SUNNY MATATO ********************************
 ****************************************************************************/

#include "snmtt_port.h"

#include "bsp.h"

#include "application.h"

/**
 * system tick container of
 *
 * 		void (*Printer_tick)(SNMTT_Printer *) and
 *
 * 		void (*BSP_heartBeats)(struct BSP_DBG *)
 *
 * Frequency: BSP_TICKS_PER_SEC
 */

void Timer0_ISR_Handler (void) interrupt TMR0_VECTOR {

    BSP_heartBeats(&AO_BSP_DBG);

    Printer_tick(&SNMTT_PrtDbg);

	return;

}
