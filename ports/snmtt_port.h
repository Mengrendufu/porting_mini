/*****************************************************************************
 ******************************* SUNNY MATATO ********************************
 ****************************************************************************/

#ifndef _snmtt_port_h_
#define _snmtt_port_h_

/* TODO */

/**
 * system clock frequency preset (Hz)
 */

#define SYSTEM_CLOCK_FREQUENCY

/* TODO */

/**
 * core-specific header file
 *
 * example:
 *
 * #include "stm32f1xx_hal.h"
 */

/* TODO */

/**
 * read-only key code
 */

#define SNMTT_ROM

/* TODO */

/**
 * ram declaration keycode
 */

#define SNMTT_RAM

/* TODO */

/**
 * explicit reentrant keycode
 */

#define SNMTT_REENTRANT

/* TODO */

/**
 * SunnyMatato disabling/enabling interrupts
 */

#define SNMTT_INT_DISABLE() do {
} while (0)

#define SNMTT_INT_ENABLE() do {
} while (0)

/* TODO */

/**
 * standard types： self-definition: "stdbool.h", "stdint.h"
 *
 *      or compiler depended: <stdbool.h>, <stdint.h>
 */

/**
 * common
 */

#include "ops_bits.h"

#include "snmtt_printer.h"

#endif  /* snmtt_port_h_ */
