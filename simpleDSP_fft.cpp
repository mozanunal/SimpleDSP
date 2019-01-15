/*
N point Complex fft and inverse fft functions
*/

#include "simpleDSP_fft.h"

void FFT(COMPLEX *Y, int N) /*input sample array, # of points      */
{
    COMPLEX temp1, temp2;     /*temporary storage variables          */
    int i, j, k;              /*loop counter variables               */
    int upper_leg, lower_leg; /*index of upper/lower butterfly leg   */
    int leg_diff;             /*difference between upper/lower leg   */
    int num_stages = 0;       /*number of FFT stages, or iterations  */
    int index, step;          /*index and step between twiddle factor*/

    /* log(base 2) of # of points = # of stages  */
    i = 1;
    do
    {
        num_stages += 1;
        i = i * 2;
    } while (i != N);

    /* starting difference between upper and lower butterfly legs*/
    leg_diff = N / 2;
    /* step between values in twiddle factor array twiddle.h     */
    step = 256 / N;
    /* For N-point FFT                                           */

    for (i = 0; i < num_stages; i++)
    {
        index = 0;
        for (j = 0; j < leg_diff; j++)
        {
            for (upper_leg = j; upper_leg < N; upper_leg += (2 * leg_diff))
            {
                lower_leg = upper_leg + leg_diff;
                temp1.real = (Y[upper_leg]).real + (Y[lower_leg]).real;
                temp1.imag = (Y[upper_leg]).imag + (Y[lower_leg]).imag;
                temp2.real = (Y[upper_leg]).real - (Y[lower_leg]).real;
                temp2.imag = (Y[upper_leg]).imag - (Y[lower_leg]).imag;
                (Y[lower_leg]).real = temp2.real * (w[index]).real - temp2.imag * (w[index]).imag;
                (Y[lower_leg]).imag = temp2.real * (w[index]).imag + temp2.imag * (w[index]).real;
                (Y[upper_leg]).real = temp1.real;
                (Y[upper_leg]).imag = temp1.imag;
            }
            index += step;
        }
        leg_diff = leg_diff / 2;
        step *= 2;
    }
    /* bit reversal for resequencing data */
    j = 0;
    for (i = 1; i < (N - 1); i++)
    {
        k = N / 2;
        while (k <= j)
        {
            j = j - k;
            k = k / 2;
        }
        j = j + k;
        if (i < j)
        {
            temp1.real = (Y[j]).real;
            temp1.imag = (Y[j]).imag;
            (Y[j]).real = (Y[i]).real;
            (Y[j]).imag = (Y[i]).imag;
            (Y[i]).real = temp1.real;
            (Y[i]).imag = temp1.imag;
        }
    }
    return;
}

void IFFT(COMPLEX *Y, int N) /*input sample array, # of points      */
{
    COMPLEX temp1, temp2;     /*temporary storage variables          */
    int i, j, k;              /*loop counter variables               */
    int upper_leg, lower_leg; /*index of upper/lower butterfly leg   */
    int leg_diff;             /*difference between upper/lower leg   */
    int num_stages = 0;       /*number of FFT stages, or iterations  */
    int index, step;          /*index and step between twiddle factor*/

    for (i = 0; i <= 127; i++)
    {
        w[i].real = w[i].real;
        w[i].imag = -w[i].imag;
    }

    /* log(base 2) of # of points = # of stages  */
    i = 1;
    do
    {
        num_stages += 1;
        i = i * 2;
    } while (i != N);

    /* starting difference between upper and lower butterfly legs*/
    leg_diff = N / 2;
    /* step between values in twiddle factor array twiddle.h     */
    step = 256 / N;
    /* For N-point FFT                                           */

    for (i = 0; i < num_stages; i++)
    {
        index = 0;
        for (j = 0; j < leg_diff; j++)
        {
            for (upper_leg = j; upper_leg < N; upper_leg += (2 * leg_diff))
            {
                lower_leg = upper_leg + leg_diff;
                temp1.real = (Y[upper_leg]).real + (Y[lower_leg]).real;
                temp1.imag = (Y[upper_leg]).imag + (Y[lower_leg]).imag;
                temp2.real = (Y[upper_leg]).real - (Y[lower_leg]).real;
                temp2.imag = (Y[upper_leg]).imag - (Y[lower_leg]).imag;
                (Y[lower_leg]).real = temp2.real * (w[index]).real - temp2.imag * (w[index]).imag;
                (Y[lower_leg]).imag = temp2.real * (w[index]).imag + temp2.imag * (w[index]).real;
                (Y[upper_leg]).real = temp1.real;
                (Y[upper_leg]).imag = temp1.imag;
            }
            index += step;
        }
        leg_diff = leg_diff / 2;
        step *= 2;
    }
    /* bit reversal for resequencing data */
    j = 0;
    for (i = 1; i < (N - 1); i++)
    {
        k = N / 2;
        while (k <= j)
        {
            j = j - k;
            k = k / 2;
        }
        j = j + k;
        if (i < j)
        {
            temp1.real = (Y[j]).real;
            temp1.imag = (Y[j]).imag;
            (Y[j]).real = (Y[i]).real;
            (Y[j]).imag = (Y[i]).imag;
            (Y[i]).real = temp1.real;
            (Y[i]).imag = temp1.imag;
        }
    }
    return;
}

COMPLEX w[] = {
    1.00000, -0.00000,
    0.99970, -0.02454,
    0.99880, -0.04907,
    0.99729, -0.07356,
    0.99518, -0.09802,
    0.99248, -0.12241,
    0.98918, -0.14673,
    0.98528, -0.17096,
    0.98079, -0.19509,
    0.97570, -0.21910,
    0.97003, -0.24298,
    0.96378, -0.26671,
    0.95694, -0.29028,
    0.94953, -0.31368,
    0.94154, -0.33689,
    0.93299, -0.35990,
    0.92388, -0.38268,
    0.91421, -0.40524,
    0.90399, -0.42756,
    0.89322, -0.44961,
    0.88192, -0.47140,
    0.87009, -0.49290,
    0.85773, -0.51410,
    0.84485, -0.53500,
    0.83147, -0.55557,
    0.81758, -0.57581,
    0.80321, -0.59570,
    0.78835, -0.61523,
    0.77301, -0.63439,
    0.75721, -0.65317,
    0.74095, -0.67156,
    0.72425, -0.68954,
    0.70711, -0.70711,
    0.68954, -0.72425,
    0.67156, -0.74095,
    0.65317, -0.75721,
    0.63439, -0.77301,
    0.61523, -0.78835,
    0.59570, -0.80321,
    0.57581, -0.81758,
    0.55557, -0.83147,
    0.53500, -0.84485,
    0.51410, -0.85773,
    0.49290, -0.87009,
    0.47140, -0.88192,
    0.44961, -0.89322,
    0.42756, -0.90399,
    0.40524, -0.91421,
    0.38268, -0.92388,
    0.35990, -0.93299,
    0.33689, -0.94154,
    0.31368, -0.94953,
    0.29028, -0.95694,
    0.26671, -0.96378,
    0.24298, -0.97003,
    0.21910, -0.97570,
    0.19509, -0.98079,
    0.17096, -0.98528,
    0.14673, -0.98918,
    0.12241, -0.99248,
    0.09802, -0.99518,
    0.07356, -0.99729,
    0.04907, -0.99880,
    0.02454, -0.99970,
    -0.00000, -1.00000,
    -0.02454, -0.99970,
    -0.04907, -0.99880,
    -0.07356, -0.99729,
    -0.09802, -0.99518,
    -0.12241, -0.99248,
    -0.14673, -0.98918,
    -0.17096, -0.98528,
    -0.19509, -0.98079,
    -0.21910, -0.97570,
    -0.24298, -0.97003,
    -0.26671, -0.96378,
    -0.29028, -0.95694,
    -0.31368, -0.94953,
    -0.33689, -0.94154,
    -0.35990, -0.93299,
    -0.38268, -0.92388,
    -0.40524, -0.91421,
    -0.42756, -0.90399,
    -0.44961, -0.89322,
    -0.47140, -0.88192,
    -0.49290, -0.87009,
    -0.51410, -0.85773,
    -0.53500, -0.84485,
    -0.55557, -0.83147,
    -0.57581, -0.81758,
    -0.59570, -0.80321,
    -0.61523, -0.78835,
    -0.63439, -0.77301,
    -0.65317, -0.75721,
    -0.67156, -0.74095,
    -0.68954, -0.72425,
    -0.70711, -0.70711,
    -0.72425, -0.68954,
    -0.74095, -0.67156,
    -0.75721, -0.65317,
    -0.77301, -0.63439,
    -0.78835, -0.61523,
    -0.80321, -0.59570,
    -0.81758, -0.57581,
    -0.83147, -0.55557,
    -0.84485, -0.53500,
    -0.85773, -0.51410,
    -0.87009, -0.49290,
    -0.88192, -0.47140,
    -0.89322, -0.44961,
    -0.90399, -0.42756,
    -0.91421, -0.40524,
    -0.92388, -0.38268,
    -0.93299, -0.35990,
    -0.94154, -0.33689,
    -0.94953, -0.31368,
    -0.95694, -0.29028,
    -0.96378, -0.26671,
    -0.97003, -0.24298,
    -0.97570, -0.21910,
    -0.98079, -0.19509,
    -0.98528, -0.17096,
    -0.98918, -0.14673,
    -0.99248, -0.12241,
    -0.99518, -0.09802,
    -0.99729, -0.07356,
    -0.99880, -0.04907,
    -0.99970, -0.02454};
