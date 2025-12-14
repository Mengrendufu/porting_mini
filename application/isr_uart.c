/*****************************************************************************
 ******************************* SUNNY MATATO ********************************
 ****************************************************************************/

#include "snmtt_port.h"

#include "bsp.h"

#include "application.h"

/**
 * uart ISR for void (*SNMTT_Printer_isr)(SNMTT_Printer *)
 */

void UART1_ISR_Handler (void) interrupt UART1_VECTOR {

    /**
     * ISR transimit
     */

    if (TI) {

        TI = 0;

        SNMTT_Printer_isr(&SNMTT_PrtDbg);

    }

    /**
     * ISR receive
     */

    if (RI) {

        RI = 0;

    }

    return;

}
