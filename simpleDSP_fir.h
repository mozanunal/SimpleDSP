/* begin simpleDSP_fir.h */
#ifndef _SIMPLEDSP_FIR_H
#define _SIMPLEDSP_FIR_H

#include "simpleDSP_Global.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct FIR
{
    int coefLen;
    float *H;
    float *dly;
}FIR;

void init(FIR *fir, int coefLen, float *coef);
float filt(FIR *fir, int input);

#endif /* end simpleDSP_fir.h */
