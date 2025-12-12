/*****************************************************************************
 ******************************* SUNNY MATATO ********************************
 ****************************************************************************/

#ifndef _snmtt_dbg_h_
#define _snmtt_dbg_h_

/**
 * id
 *
 * uart 1
 */

#define SNMTT_PRT_ID_DBG  1

#define SNMTT_PRT_POLLING_PER_SEC  100U

/**
 * configuration:
 *
 *      msgLen
 *
 *      nTot
 *
 *      qLen
 */

#define SNMTT_PRT_MSGLEN_DBG  15

#define SNMTT_PRT_PSIZE_DBG   10

#define SNMTT_PRT_QSIZE_DBG   SNMTT_PRT_PSIZE_DBG

/**
 * helper block
 */

struct SNMTT_Block_dbg {

    void * sto[ SNMTT_ROUNDUP(SNMTT_PRT_MSGLEN_DBG, sizeof(void*)) ];

};

/**
 * instance & constructor
 */

extern SNMTT_Printer SNMTT_PrtDbg;

void SNMTT_PrtDbg_ctor(SNMTT_Printer *me);

/* Board-Support-Package */

void SNMTT_PrtDbg_bspInit(void);

/**
 * output handlers
 */

/* example */

// /* DEBUG       0123456789012 - - */
// SNMTT_DBG_MSG("Hello, world!\r\n");

#define SNMTT_DBG_MSG(msg_)                                         \
                                                                    \
    SNMTT_Printer_vomit(&SNMTT_PrtDbg, (unsigned char *)(msg_));

/**
 * format debug
 */

extern unsigned char SNMTT_PrtDbg_frame[SNMTT_PRT_MSGLEN_DBG];

/* example */

// SNMTT_DBG_FRMT_START
// /* DEBUG        012345678901234 */
// SNMTT_DBG_FRMT("VOLT:__CURRT:__");
// SNMTT_DBG_PAYLOAD(6)  = (uint8_t)(((uint16_t)(vVolt)) >> 8);
// SNMTT_DBG_PAYLOAD(7)  = (uint8_t)(((uint16_t)(vVolt)) >> 0);
// SNMTT_DBG_PAYLOAD(13) = (uint8_t)(((uint16_t)(CURRT)) >> 8);
// SNMTT_DBG_PAYLOAD(14) = (uint8_t)(((uint16_t)(CURRT)) >> 0);
// SNMTT_DBG_FRMT_END

#define SNMTT_DBG_FRMT_START  do { \

#define SNMTT_DBG_FRMT(msg_)  do {              \
                                                \
            SNMTT_memcpy(                       \
                                                \
                    (unsigned char *)(msg_),    \
                                                \
                    SNMTT_PrtDbg_frame,         \
                                                \
                    SNMTT_PrtDbg.msgLen);       \
                                                \
        } while (0)

#define SNMTT_DBG_PAYLOAD(ip_)  (SNMTT_PrtDbg_frame[(ip_)])

#define SNMTT_DBG_FRMT_END                                          \
                                                                    \
            SNMTT_Printer_vomit(&SNMTT_PrtDbg, SNMTT_PrtDbg_frame); \
                                                                    \
        } while (0);

#endif  /* _snmtt_dbg_h_ */
