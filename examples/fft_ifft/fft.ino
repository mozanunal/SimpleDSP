#include "simpleDSP_fft.h"

#define DATA_LEN 32

COMPLEX data[DATA_LEN]= 
{
1380.30387436698, 0.0,
1411.95640122018, 0.0,
1509.33975623973, 0.0,
1680.97457720023, 0.0,
1945.62587488903, 0.0,
2341.52925818755, 0.0,
2948.35729012667, 0.0,
3949.59187366481, 0.0,
5862.08882614601, 0.0,
10877.1835331189, 0.0,
57733.7247892472, 0.0,
18723.4608750840, 0.0,
8298.42015377624, 0.0,
5427.67344196089, 0.0,
4083.68378659686, 0.0,
3304.24870517258, 0.0,
2795.46623030534, 0.0,
2437.40771712744, 0.0,
2172.01084844531, 0.0,
1967.76373917975, 0.0,
1806.10353733366, 0.0,
1675.40258778435, 0.0,
1568.02578276502, 0.0,
1478.77466877542, 0.0,
1404.01359504832, 0.0,
1341.15564969180, 0.0,
1288.35041545534, 0.0,
1244.29204061566, 0.0,
1208.10451406246, 0.0,
1179.28219795848, 0.0,
1157.67736663769, 0.0,
1143.53841226378, 0.0,
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
    Serial.print(data[i].real/DATA_LEN);
    Serial.print("\t\t");
    Serial.println(data[i].imag/DATA_LEN);
  }
}

void loop() {
  // put your main code here, to run repeatedly:


}