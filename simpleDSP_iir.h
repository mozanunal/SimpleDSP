/* begin simpleDSP_iir.h */
#ifndef _SIMPLEDSP_IIR_H
#define _SIMPLEDSP_IIR_H

#include "simpleDSP_Global.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int coefLen1;
	float *H;
	float *dly;
}IIR;

void initIIR(IIR *iir, int N1, float *coef1, int n2, float *coef2);
float filtIIR(IIR *iir, int input);

#endif /* end simpleDSP_iir.h */
