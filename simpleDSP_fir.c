
#include "simpleDSP_fir.h"

void firInit(FIR *fir, int coefBLen, float *coefsB)
{
    fir->coefBLen = coefBLen;
    fir->coefsB = (float *)malloc(fir->coefBLen * 4);
    fir->dlyX = (float *)malloc(fir->coefBLen * 4);
    for (int i = 0; i < fir->coefBLen; i++)
        fir->dlyX[i] = 0.0;
    fir->coefsB = coefsB;
}

float firFilt(FIR *fir, int input)
{
    float acc = 0.0;
    fir->dlyX[0] = input;
    for (int i = 0; i < fir->coefBLen; i++)
        acc += fir->coefsB[i] * fir->dlyX[i];
    for (int i = (fir->coefBLen) - 1; i > 0; i--)
        fir->dlyX[i] = fir->dlyX[i - 1];
    return acc;
}
