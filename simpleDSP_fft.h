/* begin simpleDSP_fft.h */
#ifndef _SIMPLEDSP_FFT_H
#define _SIMPLEDSP_FFT_H

extern COMPLEX w[];

void FFT(COMPLEX *Y, int N);
void IFFT(COMPLEX *Y, int N);



#endif  /* end simpleDSP_fft.h */