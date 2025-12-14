/*****************************************************************************
 ******************************* SUNNY MATATO ********************************
 ****************************************************************************/

#ifndef _snmtt_port_h_
#define _snmtt_port_h_

/**
 * system clock frequency preset (Hz)
 */

#define SYSTEM_CLOCK_FREQUENCY  33177600UL

/**
 * core-specific header file
 *
 * example:
 *
 * #include "stm32f1xx_hal.h"
 */

#include "STC8H.h"

/**
 * read-only key code
 */

#define SNMTT_ROM  code

/**
 * ram declaration keycode
 */

#define SNMTT_RAM  xdata

/**
 * explicit reentrant keycode
 */

#define SNMTT_REENTRANT  reentrant

/**
 * SunnyMatato disabling/enabling interrupts
 */

#define SNMTT_INT_DISABLE() do {    \
                                    \
    BITS_RESET_U8(IE, 7);           \
                                    \
} while (0)

#define SNMTT_INT_ENABLE() do {     \
                                    \
    BITS_SET_U8(IE, 7);             \
                                    \
} while (0)

/**
 * standard types： self-definition: "stdbool.h", "stdint.h"
 *
 *      or compiler depended: <stdbool.h>, <stdint.h>
 */

#include "stdbool.h"

#include "stdint.h"

/**
 * common
 */

#include "ops_bits.h"

#include "snmtt_printer.h"

#endif  /* snmtt_port_h_ */
