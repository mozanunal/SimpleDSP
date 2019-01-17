/* begin simpleDSP_fir.h */
#ifndef _SIMPLEDSP_FIR_H
#define _SIMPLEDSP_FIR_H

#ifdef __cplusplus
  extern "C" {
#endif

#include "simpleDSP_Global.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int coefBLen;
    float *coefsB;
    float *dlyX;
}FIR;

void firInit(FIR *fir, int coefBLen, float *coefsB);
float firFilt(FIR *fir, int input);

#ifdef __cplusplus
  }
#endif

#endif /*end simpleDSP_fir.h */
