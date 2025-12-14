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

#define BITS_SET_U16(target_, bit_)		\
										\
	((target_) |= (0x0001 << (bit_)))

#define BITS_RESET_U16(target_, bit_)	\
										\
	((target_) &= (~(0x0001 << (bit_))))

/* 32-bit */

#define BITS_SET_U32(target_, bit_)		\
										\
	((target_) |= (0x0001 << (bit_)))

#define BITS_RESET_U32(target_, bit_)	\
										\
	((target_) &= (~(0x0001 << (bit_))))

#endif  /* _ops_bits_h_ */
