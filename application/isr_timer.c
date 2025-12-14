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

 void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {

	if (htim->Instance == TIM6) {

        BSP_heartBeats(&AO_BSP_DBG);

        Printer_tick(&SNMTT_PrtDbg);

	}

	return;

}
