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
 * core-specific
 */

#include <STC8H.H>

/**
 * read-only
 */

#define SNMTT_ROM  code

/**
 * ram declaration
 */

#define SNMTT_RAM  xdata

/**
 * explicit reentrant notation
 */

#define SNMTT_REENTRANT  reentrant

/**
 * system reentrant stack configuration
 */

/* size of xram */

#define SYSTEM_RAM_LEN_XDATA  (0x1FFF + 1)

/* stack size */

#define SYSTEM_REENTRANT_STACK_SIZE  256

#define SNMTT_PORT_SYSTEM_REENTRANT_STACK_STO_INS()							\
																			\
		static unsigned char volatile SNMTT_RAM 							\
																			\
			_systemReentrantStackSto[SYSTEM_REENTRANT_STACK_SIZE]			\
																			\
				_at_ (SYSTEM_RAM_LEN_XDATA - SYSTEM_REENTRANT_STACK_SIZE)

/**
 * SunnyMatato disabling/enabling interrupts
 */

#define SNMTT_INT_DISABLE() do {			\
                                            \
    BITS_RESET_U8(IE, 7);                   \
											\
} while (0)

#define SNMTT_INT_ENABLE() do {   			\
											\
	BITS_SET_U8(IE, 7);						\
											\
} while (0)

/**
 * common
 */

#include "stdint.h"

#include "stdbool.h"

#include "ops_bits.h"

#include "snmtt_printer.h"

#endif  /* snmtt_port_h_ */
