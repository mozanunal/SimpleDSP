
#include "simpleDSP_iir.h"

void init(IIR *iir, int coefBLen, float *coefsB, int coefALen, float *coefsA)
{
    /* memory allocation for H and delay values */
    iir->coefsB = (float *)malloc(iir->coefBLen * 4);
    iir->coefsA = (float *)malloc(iir->coefALen * 4);
    iir->dlyX = (float *)malloc(iir->coefBLen * 4);
    iir->dlyY = (float *)malloc(iir->coefALen * 4);
    /* init parameters */
    iir->coefBLen = coefBLen;
    iir->coefALen = coefALen;
    iir->coefsB = coefsB;
    iir->coefsA = coefALen;
    for (int i = 0; i < iir->coefBLen; i++)
        iir->dlyX[i] = 0.0;
    for (int i = 0; i < iir->coefALen; i++)
        iir->dlyY[i] = 0.0;
}

float filt(IIR *iir, int input)
{
    // xn[6]=xn[5]
    // xn[5]=xn[4]
    // xn[4]=xn[3]
    // xn[3]=xn[2]
    // xn[2]=xn[1]
    // xn[1]=xn[0]
    // xn[0]= giris

    // yn[6]=yn[5]
    // yn[5]=yn[4]    
    // yn[4]=yn[3]
    // yn[3]=yn[2]
    // yn[2]=yn[1]
    // yn[1]=cikis
    // m1    = b2[0]*giris+b2[1]*xn[1]+b2[2]*xn[2]+b2[3]*xn[3]+b2[4]*xn[4]+b2[5]*xn[5]+b2[6]*xn[6]
    // m2    =            -a2[1]*yn[1]-a2[2]*yn[2]-a2[3]*yn[3]-a2[4]*yn[4]-a2[5]*yn[5]-a2[6]*yn[6]
    // cikis = m1 + m2
    // #print m1,m2
    // return cikis
    float acc1 = 0.0;
    float acc2 = 0.0;
    iir->dly[0] = input;
    for (int i = 0; i < fir->n; i++)
        acc += fir->H[i] * fir->dly[i];
    for (int i = (fir->n) - 1; i > 0; i--)
        fir->dly[i] = fir->dly[i - 1];
    return acc;
}
