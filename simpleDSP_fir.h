/* begin simpleDSP_fir.h */
#ifndef _SIMPLEDSP_FIR_H
#define _SIMPLEDSP_FIR_H

#include "simpleDSP_Global.h"
#include <stdio.h>
#include <stdlib.h>

struct FIR
{
    int coefLen;
    float *H;
    float *dly;
};

void initFIR(FIR *fir, int coefLen, float *coef);
float filtFIR(FIR *fir, int input);

#endif /* end simpleDSP_fir.h */
