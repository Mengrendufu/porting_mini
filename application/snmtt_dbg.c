/*****************************************************************************
 ******************************* SUNNY MATATO ********************************
 ****************************************************************************/

#include "snmtt_port.h"

#include "bsp.h"

#include "application.h"

SNMTT_DBG_DEFINE_AO

/**
 * pool & queue
 */

SNMTT_DBG_DEFINE_PSTO

SNMTT_DBG_DEFINE_QSTO

/**
 * SNMTT_PutHandler
 */

#ifndef SNMTT_DBG_UNUSE

static void SNMTT_PrtDbg_output(SNMTT_Printer * const me) SNMTT_REENTRANT;

#endif

void SNMTT_PrtDbg_ctor(SNMTT_Printer *me) {

#ifndef SNMTT_DBG_UNUSE

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

#else

    (void)me;

#endif

    return;

}

/* TODO: Complete the function */

/*
 * Define the output handler here
 */

static void SNMTT_PrtDbg_output(SNMTT_Printer * const me) SNMTT_REENTRANT {

    --me->tranCnt;

    /**
     * Output a byte via uart
     */

    return;

}
