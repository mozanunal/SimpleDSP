
#include "simpleDSP_fir.h"

void init(FIR *fir, int coefLen, float *coef)
{
    fir->coefLen = coefLen;
    fir->H = (float *)malloc(fir->coefLen * 4);
    fir->dly = (float *)malloc(fir->coefLen * 4);
    for (int i = 0; i < fir->coefLen; i++)
        fir->dly[i] = 0.0;
    fir->H = coef;
}

float filt(FIR *fir, int input)
{
    float acc = 0.0;
    fir->dly[0] = input;
    for (int i = 0; i < fir->coefLen; i++)
        acc += fir->H[i] * fir->dly[i];
    for (int i = (fir->coefLen) - 1; i > 0; i--)
        fir->dly[i] = fir->dly[i - 1];
    return acc;
}
