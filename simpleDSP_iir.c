
#include "simpleDSP_iir.h"

void initIIR(IIR *iir, int n1, float *coef1, int n2, float *coef2)
{
    fir->n = N;
    fir->H = (float *)malloc(fir->n * 4);
    fir->dly = (float *)malloc(fir->n * 4);
    for (int i = 0; i < fir->n; i++)
        fir->dly[i] = 0.0;
    fir->H = coef;
}

float filtIIR(IIR *iir, int input)
{
    float acc = 0.0;
    fir->dly[0] = input;
    for (int i = 0; i < fir->n; i++)
        acc += fir->H[i] * fir->dly[i];
    for (int i = (fir->n) - 1; i > 0; i--)
        fir->dly[i] = fir->dly[i - 1];
    return acc;
}
