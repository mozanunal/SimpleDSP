/* begin simpleDSP_iir.h */
#ifndef _SIMPLEDSP_IIR_H
#define _SIMPLEDSP_IIR_H

#ifdef __cplusplus
  extern "C" {
#endif

#include "simpleDSP_Global.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct
{
	int coefALen;
	float *coefsA;
	int coefBLen;
	float *coefsB;
	float *dlyX;
	float *dlyY;
}IIR;

void iirInit(IIR *iir, int coefBLen, float *coefsB, int coefALen, float *coefsA);
float iirFilt(IIR *iir, int input);

#ifdef __cplusplus
  }
#endif

#endif /* end simpleDSP_iir.h */
