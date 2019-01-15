/* begin simpleDSP_iir.h */
#ifndef _SIMPLEDSP_IIR_H
#define _SIMPLEDSP_IIR_H

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

void init(IIR *iir, int coefBLen, float *coefsB, int coefALen, float *coefsA);
float filt(IIR *iir, int input);

#endif /* end simpleDSP_iir.h */
