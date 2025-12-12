/*****************************************************************************
 ******************************* SUNNY MATATO ********************************
 ****************************************************************************/

#ifndef _ops_bits_h_
#define _ops_bits_h_

/**
 * bit operation
 */

/* 8-bit */

#define BITS_SET_U8(target_, bit_)		\
										\
	((target_) |= (0x01 << (bit_)))

#define BITS_RESET_U8(target_, bit_)	\
										\
	((target_) &= (~(0x01 << (bit_))))

/* 16-bit */

/* 32-bit */

#endif  /* _ops_bits_h_ */
