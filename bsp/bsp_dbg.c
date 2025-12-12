/*****************************************************************************
 ******************************* SUNNY MATATO ********************************
 ****************************************************************************/

#include "snmtt_port.h"

#include "bsp.h"

#include "application.h"

/**
 * BSP DBG
 */

/* get each single digit of [0, 65535] */

#if BSP_BREATH_TICK_OUT_ENABLE

static void u16_to_5digits(uint16_t x, uint8_t *dig) {

	uint32_t t;

	uint16_t q;

	int16_t r;

    t = (uint32_t)x * 0x199A;

    q = t >> 16;

    r = x - q * 10;

    if (r < 0) {
        r += 10;
        q -= 1;
    }
    dig[4] = (uint8_t)r;

    x = q;
    t = (uint32_t)x * 0x199A;
    q = t >> 16;
    r = x - q * 10;
    if (r < 0) {
        r += 10;
        q -= 1;
    }
    dig[3] = (uint8_t)r;

    x = q;
    t = (uint32_t)x * 0x199A;
    q = t >> 16;
    r = x - q * 10;
    if (r < 0) {
        r += 10;
        q -= 1;
    }
    dig[2] = (uint8_t)r;

    x = q;
    t = (uint32_t)x * 0x199A;
    q = t >> 16;
    r = x - q * 10;
    if (r < 0) {
        r += 10;
        q -= 1;
    }
    dig[1] = (uint8_t)r;

    dig[0] = q;

	return;

}

#endif  /* BSP_BREATH_TICK_OUT_ENABLE */

struct BSP_DBG AO_BSP_DBG = {

    0x00,

    BSP_BREATH_TICKS_PER_SEC,

    BSP_BREATH_TICKS_PER_SEC,

    0

};

void BSP_heartBeats(struct BSP_DBG *me) {

	if (me->ctr != 0) {

		--me->ctr;

		if (me->ctr == 0) {

			me->ctr = me->interval;

			me->trigger = 0xFF;

		}

	}

	return;

}

void BSP_breathe(struct BSP_DBG *me) {

#if BSP_BREATH_TICK_OUT_ENABLE

	unsigned char digits[5];

#endif  /* BSP_BREATH_TICK_OUT_ENABLE */

	if (me->trigger) {

		me->trigger = 0x00;

		me->ticks == 0xFFFF ? me->ticks = 0 : ++me->ticks;

#if BSP_BREATH_TICK_OUT_ENABLE

		u16_to_5digits(me->ticks, digits);

		SNMTT_DBG_FRMT_START
		/* DEBUG        012345678901234 */
		SNMTT_DBG_FRMT("BSPTick:_____CR");
		SNMTT_DBG_PAYLOAD(8)  = '0' + digits[0];
		SNMTT_DBG_PAYLOAD(9)  = '0' + digits[1];
		SNMTT_DBG_PAYLOAD(10) = '0' + digits[2];
		SNMTT_DBG_PAYLOAD(11) = '0' + digits[3];
		SNMTT_DBG_PAYLOAD(12) = '0' + digits[4];
		SNMTT_DBG_PAYLOAD(13) = '\r';
		SNMTT_DBG_PAYLOAD(14) = '\n';
		SNMTT_DBG_FRMT_END

		if (me->ticks == 1) {



        }

#endif  /* BSP_BREATH_TICK_OUT_ENABLE */

	}

	return;

}
