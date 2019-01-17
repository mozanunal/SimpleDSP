# SimpleDSP
A basic dsp library for arduino and most of the microcontrollers which can be programmed in C/C++

## Performance:

### Arduino Nano
* FFT 16 points: 2 ms
* FFT 32 points: 6 ms
* FFT 64 points: 16 ms
* fir filter 10 coeficients: 190 us
* fir filter 23 coeficients: 453 us
* fir filter 46 coeficients: 900 us

for 10 coeficients implementation max frequency 5khz

## Arduino Due
* FFT 64 points: 2 ms
* FFT 128 points: 6 ms
* FFT 256 points: 10 ms

## Fast Fourier Transform (FFT) and Inverse Fast Fourier Transform (IFFT)

[detailed info](https://en.m.wikipedia.org/wiki/Fast_Fourier_transform)

### Arduino Example

FFT and IFFT functions require 2 arguments.
data 
data lenght
Do not forget to add `#include "simpleDSP_FFT.h"`

[Full example for FFT and IFFT please refer here](/examples/fft_ifft/fft_ifft.ino)

[FFT spectrum example](/examples/fft_spectrum/fft_spectrum.ino)

```
  FFT(data,DATA_LEN);
  IFFT(data,DATA_LEN);
  calcTime = millis()-startTime;
  Serial.print("Total calculation time: ");
  Serial.println(calcTime);
```

## FIR Filter

### Theory

[detailed info](https://en.wikipedia.org/wiki/Finite_impulse_response)

### Arduino Example

FIR is filter structure which keep delays and coeficients of filter. filtFIR function require 2 arguments.
FIR instance and data
Do not forget to add `#include "simpleDSP_fir.h"`


```
    Serial.begin(9600);
    firInit(&fir1, 46, coef);
    Serial.println("FIR filter initiliaze finished");
    float a;
    startTime = micros();
    for (int i = 0; i < 255; i++)
    {
        a = firFilt(&fir1, input[i]);
    }
    calcTime = micros() - startTime;
    Serial.print("Total calculation time: ");
    Serial.println(calcTime);
```

## IIR Filter

### Theory

[detailed info](https://en.wikipedia.org/wiki/Infinite_impulse_response)

### Arduino Example

IIR is filter structure which keep delays and coeficient of filter. filtFIR function require 2 arguments.
data 
data lenght
Do not forget to add `#include "simpleDSP_fir.h"`


```
    Serial.begin(9600);
    iirInit(&iir1, 4, coefB, 4, coefA);
    Serial.println("IIR filter initiliaze finished");
    float a;
    startTime = micros();
    for (int i = 0; i < 255; i++)
    {
        a = iirFilt(&iir1, input[i]);
    }
    calcTime = micros() - startTime;
    Serial.print("Total calculation time: ");
    Serial.println(calcTime);
```



## Octave Test Code

This code create sample data and plot the signal and its FFT. The octave code only needed for testing of function.


Create sample signal which is at 10 kHz sample rate and it is the combination of  3.2 kHz and 800 Hz sine waves.
```octave
N=255;
f1=800;
f2=3200;
fo=10000;
for i=1:1:N
x(i)=1000*cos(2*pi*f1*i/fo)+1000*cos(2*pi*f2*i/fo);
printf("%d\n",x(i));
end
```


Calculate and plot x and FFT of x. For fft x axis values are calculated using `kor=(1:N)*fo/N;`
```octave
plot(x);
X=abs(FFT(x));
figure;
kor=(1:N)*fo/N;
plot(kor,X);
```

**Output from octave**

Graph of Raw Signal

![inputa](https://cloud.githubusercontent.com/assets/13440502/22374756/305a1d4e-e4b0-11e6-821a-9213b4f8a136.png)

Graph of FFT Signal

![inputf](https://cloud.githubusercontent.com/assets/13440502/22374762/3abf9eee-e4b0-11e6-8e26-c0758e6c13a3.png)

[you can use octave from here](octave-online.net)

### Filter Design Using Octave

output of fir functions can be used as filter coeficients

[Resource for FIR](https://octave.sourceforge.io/signal/function/fir1.html)

Examples:

```
 freqz (fir1 (40, 0.3));
 freqz (fir1 (15, [0.2, 0.5], "stop"));  # note the zero-crossing at 0.1
 freqz (fir1 (15, [0.2, 0.5], "stop", "noscale"));
```
filter frequency response

![function reference fir1](https://cloud.githubusercontent.com/assets/13440502/22388029/20f5a6fc-e4e7-11e6-99ed-885fe116be1d.png)

[Resource for IIR](https://octave.sourceforge.io/signal/function/butter.html)

desi
```
figure
[b, a] = butter(3, 0.3, "low");
y = filter(b,a,x);
plot(y)
```

**Output from octave**


output 

![output](https://cloud.githubusercontent.com/assets/13440502/22374514/24a63a88-e4af-11e6-8bd8-b7fa703bd459.png)

output signal FFT

![outputf](https://cloud.githubusercontent.com/assets/13440502/22374645/b0cbd266-e4af-11e6-9266-32aafec12986.png)



