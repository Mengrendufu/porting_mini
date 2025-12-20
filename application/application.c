/*****************************************************************************
 ******************************* SUNNY MATATO ********************************
 ****************************************************************************/

#include "snmtt_port.h"

#include "bsp.h"

#include "application.h"

void AO_ctor(void) {

#ifndef SNMTT_DBG_UNUSE
	SNMTT_PrtDbg_ctor(&SNMTT_PrtDbg);
#endif

	return;

}
