/*****************************************************************************
 ******************************* SUNNY MATATO ********************************
 ****************************************************************************/

#include "snmtt_port.h"

#include "bsp.h"

#include "application.h"

/**
 * Output handler
 */

static void SNMTT_PrtDbg_output(SNMTT_Printer * const me) SNMTT_REENTRANT;

SNMTT_Printer SNMTT_PrtDbg;

unsigned char SNMTT_PrtDbg_frame[SNMTT_PRT_MSGLEN_DBG];

/**
 * pool & queue
 */

static struct SNMTT_Block_dbg SNMTT_PrtDbg_pSto[SNMTT_PRT_PSIZE_DBG];

static void *                 SNMTT_PrtDbg_qSto[SNMTT_PRT_QSIZE_DBG];

void SNMTT_PrtDbg_ctor(SNMTT_Printer *me) {

    SNMTT_Printer_ctor(

        me,

        (SNMTT_PutHandler)&SNMTT_PrtDbg_output,

        SNMTT_PRT_MSGLEN_DBG,

        BSP_TICKS_PER_SEC / 100,

        (void *)SNMTT_PrtDbg_pSto,

        sizeof(SNMTT_PrtDbg_pSto),

        sizeof(SNMTT_PrtDbg_pSto[0]),

        (void *)SNMTT_PrtDbg_qSto,

        SNMTT_PRT_QSIZE_DBG);

    return;

}

/* TODO: Complete the function */

/**
 * Define the output handler here
 */

static void SNMTT_PrtDbg_output(SNMTT_Printer * const me) SNMTT_REENTRANT {

    --me->tranCnt;

    /**
     * Output a byte via uart
     */

    return;

}
