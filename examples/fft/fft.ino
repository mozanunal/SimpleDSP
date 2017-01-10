#include "simpleDSP_fft.h"

#define DATA_LEN 8

COMPLEX data[DATA_LEN]= {
  26.0, 0.0,
  26.0, 0.0,
  26.0, 0.0,
  26.0, 0.0,
  26.0, 0.0,
  26.0, 0.0,
  26.0, 0.0,
  26.0, 0.0
};

long startTime;
long calcTime;

void setup() {
  Serial.begin(9600);
  startTime = millis();
  FFT(data,DATA_LEN);
  IFFT(data,DATA_LEN);
  calcTime = millis()-startTime;
  Serial.print("Total calculation time: ");
  Serial.println(calcTime);
  for (int i=0; i<DATA_LEN; i++)
  {
    Serial.print(data[i].real);
    Serial.print("\t");
    Serial.println(data[i].imag);
  }
}

void loop() {
  // put your main code here, to run repeatedly:


}