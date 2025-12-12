/*****************************************************************************
 ******************************* SUNNY MATATO ********************************
 ****************************************************************************/

#ifndef _stdint_h_
#define _stdint_h_

/**
 * 8-bit
 */

typedef unsigned char uint8_t;

typedef signed char    int8_t;

/**
 * 16-bit
 */

typedef unsigned int uint16_t;

typedef signed int    int16_t;

/**
 * 32-bit
 */

typedef unsigned long int uint32_t;

typedef signed long int    int32_t;

/**
 * Minimum-width integer types
 */

/* 8-bit */

typedef uint8_t uint_least8_t;

typedef int8_t   int_least8_t;

/* 16-bit */

typedef uint16_t uint_least16_t;

typedef int16_t   int_least16_t;

/* 32-bit */

typedef uint32_t uint_least32_t;

typedef int32_t   int_least32_t;

/**
 * Fastest minimum-width integer types.
 * Not actually guaranteed to be fastest for all purposes.
 * Here we use the exact-width types for 8 and 16-bit ints.
 */

/* 8-bit */

typedef uint8_t uint_fast8_t;

typedef int8_t   int_fast8_t;

/* 16-bit */

typedef uint16_t uint_fast16_t;

typedef int16_t   int_fast16_t;

/* 32-bit */

typedef uint32_t uint_fast32_t;

typedef int32_t   int_fast32_t;

#endif  /* _stdint_h_ */
