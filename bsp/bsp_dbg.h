/*****************************************************************************
 ******************************* SUNNY MATATO ********************************
 ****************************************************************************/

#ifndef _bsp_dbg_h_
#define _bsp_dbg_h_

#define BSP_BREATH_TICKS_PER_SEC  (BSP_TICKS_PER_SEC / 1)

struct BSP_DBG {

    unsigned char volatile trigger;

    unsigned char volatile ctr;

    unsigned char volatile interval;

    uint16_t ticks;

};

extern struct BSP_DBG AO_BSP_DBG;

void BSP_heartBeats(struct BSP_DBG *me);

void BSP_breathe(struct BSP_DBG *me);

#endif  /* _bsp_dbg_h_ */
