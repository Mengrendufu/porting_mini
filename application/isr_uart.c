/*****************************************************************************
 ******************************* SUNNY MATATO ********************************
 ****************************************************************************/

#include "snmtt_port.h"

#include "bsp.h"

#include "application.h"

/* TODO: Add the function */

/**
 * uart ISR for void (*SNMTT_Printer_isr)(SNMTT_Printer *)
 */

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {

	extern UART_HandleTypeDef huart1;

	if (huart1.Instance == USART1) {

		SNMTT_Printer_isr(&SNMTT_PrtDbg);

	}

	return;

}
