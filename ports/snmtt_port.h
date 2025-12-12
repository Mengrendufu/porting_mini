/*****************************************************************************
 ******************************* SUNNY MATATO ********************************
 ****************************************************************************/

#ifndef _snmtt_port_h_
#define _snmtt_port_h_

/**
 * system clock frequency preset (Hz)
 */

#define SYSTEM_CLOCK_FREQUENCY  72000000UL

/**
 * core-specific
 */

#include "stm32f1xx_hal.h"

/**
 * read-only
 */

#define SNMTT_ROM

/**
 * ram declaration
 */

#define SNMTT_RAM

/**
 * explicit reentrant notation
 */

#define SNMTT_REENTRANT

/**
 * SunnyMatato disabling/enabling interrupts
 */

#define SNMTT_INT_DISABLE() do {			\
                                            \
    __disable_irq();                        \
											\
} while (0)

#define SNMTT_INT_ENABLE() do {   			\
											\
	__enable_irq();							\
											\
} while (0)

/**
 * common
 */

#include <stdint.h>

#include <stdbool.h>

#include "ops_bits.h"

#include "snmtt_printer.h"

#endif  /* snmtt_port_h_ */
