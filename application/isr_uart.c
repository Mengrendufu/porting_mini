/*****************************************************************************
 ******************************* SUNNY MATATO ********************************
 ****************************************************************************/

#include "snmtt_port.h"

#include "bsp.h"

#include "application.h"

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {

	extern UART_HandleTypeDef huart1;

	if (huart1.Instance == USART1) {

		SNMTT_Printer_isr(&SNMTT_PrtDbg);

	}

	return;

}
