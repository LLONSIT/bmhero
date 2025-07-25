/*====================================================================
 * auxbus.c
 *
 * Copyright 1993, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

#include <libaudio.h>
#include "synthInternals.h"

Acmd* alAuxBusPull(void* filter, s16* outp, s32 outCount, s32 sampleOffset, Acmd* p) {
    Acmd* ptr = p;
    ALAuxBus* m = (ALAuxBus*) filter;
    ALFilter** sources = m->sources;
    s32 i;

    /*
     * clear the output buffers here
     */
    aClearBuffer(ptr++, AL_AUX_L_OUT, outCount << 1);
    aClearBuffer(ptr++, AL_AUX_R_OUT, outCount << 1);

    for (i = 0; i < m->sourceCount; i++) {
        ptr = (sources[i]->handler)(sources[i], outp, outCount, sampleOffset, ptr);
    }

    return ptr;
}

s32 alAuxBusParam(void* filter, s32 paramID, void* param) {
    ALAuxBus* m = (ALAuxBus*) filter;
    ALFilter** sources = m->sources;

    switch (paramID) {

        case (AL_FILTER_ADD_SOURCE):
            sources[m->sourceCount++] = (ALFilter*) param;
            break;

        default:
            /* ??? */
            break;
    }

    return 0;
}
