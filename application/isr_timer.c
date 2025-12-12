/*****************************************************************************
 ******************************* SUNNY MATATO ********************************
 ****************************************************************************/

#include "snmtt_port.h"

#include "bsp.h"

#include "application.h"

/**
 * system clock tick ISR
 */

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {

	if (htim->Instance == TIM6) {

        BSP_heartBeats(&AO_BSP_DBG);

        Printer_tick(&SNMTT_PrtDbg);

	}

	return;

}
