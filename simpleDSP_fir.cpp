
#include "simpleDSP_fir.h"

void init (FIR *fir, int N, float *coef)
{
  fir->n = N;
  fir->H = (float *) malloc(fir->n*4);
  fir->dly = (float *) malloc(fir->n*4);
  for (int i = 0; i < fir->n; i++) fir->dly[i] = 0.0;
  fir->H = coef;
}


float filt(FIR *fir, int input)
{
  float acc = 0.0;
  fir->dly[0] = input;
  for (int i = 0; i < fir->n; i++)
    acc += fir->H[i] * fir->dly[i];
  for (int i = (fir->n)-1; i > 0; i--)
    fir->dly[i] = fir->dly[i-1];   
  return acc;
}

 
