/*****************************************************************************
 ******************************* SUNNY MATATO ********************************
 ****************************************************************************/

#ifndef _bsp_h_
#define _bsp_h_

/**
 * TODO
 *
 * systick frequency (Hz)
 */

#define BSP_TICKS_PER_SEC

/**
 * BSP initialization
 */

void BSP_init(void);

/**
 * BSP handlers
 */

/**
 * TODO
 *
 * BSP DBG
 */

/* tick output switch */

#define BSP_BREATH_TICK_OUT_ENABLE  1

#include "bsp_dbg.h"

#endif  /* _bsp_h_ */
