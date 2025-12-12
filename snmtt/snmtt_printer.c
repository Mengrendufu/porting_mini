/*****************************************************************************
 ******************************* SUNNY MATATO ********************************
 ****************************************************************************/

#include "snmtt_port.h"

#include "snmtt_printer.h"

void SNMTT_Printer_ctor(

    SNMTT_Printer *me,

    SNMTT_PutHandler output,

    unsigned char msgLen,

    unsigned char pollingInterval,

    void *poolSto,

    unsigned int poolSize,

    unsigned char blockSize,

    void *qSto,

    unsigned char qLen)
{

    void **fb;

    unsigned char nextLink;

    unsigned int poolSize_;


    me->output = output;

    me->msgLen = msgLen;


    me->isBusy = 0x00;

    me->isPollingReady = 0x00;

    me->pollingInterval = pollingInterval;

    me->pollingCtr = me->pollingInterval;


    poolSize_ = poolSize;

    me->freeHead = (void **)poolSto;

    me->blockSize = (unsigned char)sizeof(void *);

    /**
     * link shift round-up
     */

    nextLink = (unsigned char)1;

    while (me->blockSize < blockSize) {

        me->blockSize += (unsigned char)sizeof(void *);

        ++nextLink;

    }

    fb = me->freeHead;

    me->nTot = 1;

    poolSize_ -= (unsigned int)me->blockSize;

    while (poolSize_ >= (unsigned int)blockSize) {

        fb[0] = &fb[nextLink];

        fb = (void **)fb[0];

        ++me->nTot;

        poolSize_ -= (unsigned int)blockSize;

    }

    fb[0] = (void *)0;

    me->start = me->freeHead;

    me->end = fb;

    me->nFree = me->nTot;

    me->nMin = me->nTot;


    me->ring = (void **)qSto;

    me->head = 0;

    me->tail = 0;

    me->qLen = qLen;

    me->nUsed = 0;

    me->qMin = me->qLen;

    return;

}

void Printer_tick(SNMTT_Printer *me) {

    if (me->pollingCtr != 0) {

        --me->pollingCtr;

        if (me->pollingCtr == 0) {

            me->isPollingReady = 0xFF;

            me->pollingCtr = me->pollingInterval;

        }

    }

    return;

}

void SNMTT_Printer_run(SNMTT_Printer *me) {

    if (me->isPollingReady) {

        me->isPollingReady = 0x00;

        if (!me->isBusy) {

            if (me->nUsed != 0) {

                me->frame = (unsigned char *)me->ring[me->tail];

                me->tail == 0 ? me->tail = me->qLen - 1 : --me->tail;

                --me->nUsed;

                me->isBusy = 0xFF;

                me->tranCnt = me->msgLen;

                (*me->output)(me);

            }

        }

    }

    return;

}

void SNMTT_Printer_isr(SNMTT_Printer *me) {

    bool isGc;

    SNMTT_PRT_CRITICAL_ENTRY();

    isGc = false;

    if (me->msgLen > 1) {

        if (me->tranCnt == 0) {

            isGc = true;

        } else {

            (*me->output)(me);

        }

    } else {

        isGc = true;

    }

    if (isGc) {

        ((void **)(me->frame))[0] = (void *)me->freeHead;

        me->freeHead = (void **)me->frame;

        ++me->nFree;

        me->isBusy = 0x00;

    }

    SNMTT_PRT_CRITICAL_EXIT();

    return;

}

void SNMTT_Printer_vomit(SNMTT_Printer *me, unsigned char *msg) {

    unsigned char *fb;

    SNMTT_PRT_CRITICAL_ENTRY();

    if (me->nFree > 0) {

        /**
         * get frame from pool
         */

        fb = (unsigned char *)me->freeHead;

        me->freeHead = (void **)(me->freeHead[0]);

        --me->nFree;

        if (me->nMin > me->nFree) {

            me->nMin = me->nFree;

        }

        /**
         * payload
         */

        SNMTT_memcpy(msg, fb, me->msgLen);

        /**
         * en queue
         */

        if (me->nUsed < me->qLen) {

            me->ring[me->head] = (void *)fb;

            me->head == 0 ? me->head = me->qLen - 1 : --me->head;

            ++me->nUsed;

            if (me->qMin > me->qLen - me->nUsed) {

                me->qMin = me->qLen - me->nUsed;

            }

        } else {  /* full */

            /**
             * tail free, memory gc
             */

            ((void **)(me->ring[me->tail]))[0] = (void *)me->freeHead;

            me->freeHead = (void **)me->ring[me->tail];

            ++me->nFree;

            me->tail == 0 ? me->tail = me->qLen - 1 : --me->tail;

            /**
             * en queue
             */

            me->ring[me->head] = (void *)fb;

            me->head == 0 ? me->head = me->qLen - 1 : --me->head;

        }

    }

    SNMTT_PRT_CRITICAL_EXIT();

    return;

}

void SNMTT_memcpy(

    unsigned char *from,

    unsigned char *to,

    unsigned char mLen)
{

    uint8_t icpy;

    for (icpy = 0; icpy < mLen; ++icpy) {

        to[icpy] = from[icpy];

    }

    return;

}
