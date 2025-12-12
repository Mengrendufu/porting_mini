/*****************************************************************************
 ******************************* SUNNY MATATO ********************************
 ****************************************************************************/

#ifndef _snmtt_printer_h_
#define _snmtt_printer_h_

#define SNMTT_PRT_CRITICAL_ENTRY()  SNMTT_INT_DISABLE()

#define SNMTT_PRT_CRITICAL_EXIT()   SNMTT_INT_ENABLE()

#define SNMTT_ROUNDUP(x_, y_)           \
                                        \
            (((x_) - 1U) / (y_) + 1U)

#define SNMTT_N_ELEM(arr_)                          \
                                                    \
            (sizeof((arr_)) / sizeof((arr_)[0]))

/**
 * Sunny Matato
 */

typedef void (*SNMTT_PutHandler)(void * const me);

typedef struct SNMTT_Printer {

    /**
     * attrs for polymorphism
     */

    SNMTT_PutHandler output;

    unsigned char msgLen;

    /**
     * polling
     */

    unsigned char volatile isBusy;  /* transmit proceedure */

    unsigned char volatile isPollingReady;

    unsigned char volatile pollingCtr;

    unsigned char volatile pollingInterval;

    /**
     * frame pool
     */

    void ** volatile freeHead;

    void **start;

    void **end;

    unsigned char blockSize;

    unsigned char nTot;

    unsigned char volatile nFree;

    unsigned char nMin;

    /**
     * queue
     */

    void **ring;

    unsigned char volatile head;

    unsigned char volatile tail;

    unsigned char qLen;

    unsigned char volatile nUsed;

    unsigned char qMin;

    /**
     * for isr
     */

    unsigned char *frame;

    unsigned char volatile tranCnt;

} SNMTT_Printer;

/**
 * constructor
 */

void SNMTT_Printer_ctor(

    SNMTT_Printer *me,

    SNMTT_PutHandler output,

    unsigned char msgLen,

    unsigned char pollingInterval,

    void *poolSto,

    unsigned int poolSize,

    unsigned char blockSize,

    void *qSto,

    unsigned char qLen);

/**
 * time event (Systick_handler)
 */

void Printer_tick(SNMTT_Printer *me);

/**
 * super loop
 */

void SNMTT_Printer_run(SNMTT_Printer *me);

/**
 * isr
 */

void SNMTT_Printer_isr(SNMTT_Printer *me);

/**
 * ready for print
 */

void SNMTT_Printer_vomit(SNMTT_Printer *me, unsigned char *msg);

/**
 * for polymorphism
 */

void SNMTT_Printer_byteDelivery(SNMTT_Printer *me) SNMTT_REENTRANT;

/**
 * memory copy
 */

void SNMTT_memcpy(

    unsigned char *from,

    unsigned char *to,

    unsigned char mLen);

#endif  /* _snmtt_printer_h_ */
