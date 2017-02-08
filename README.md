# SimpleDSP
A basic dsp library for arduino and most of the microcontrollers which can be programmed in C/C++

## Performance:

### Arduino Nano
* fft 16 points: 2 ms
* fft 32 points: 6 ms
* fft 64 points: 16 ms
* fir filter 10 coeficients: 190 us
* fir filter 23 coeficients: 453 us
* fir filter 46 coeficients: 900 us

for 10 coeficients implementation max frequency 5khz

## Arduino Due
* fft 64 points: 2 ms
* fft 128 points: 6 ms
* fft 256 points: 10 ms
