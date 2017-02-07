/*This is a signal sum of 800 hz and 3.2 khz sine waves
which sampled in 10khz and 32 of this samples are 
create a data array.
In this example first fft later inverse fft of 
signal calculated by arduino after the process output 
data will be same with input as we expected.
*/

#include "simpleDSP_fir.h"


#define N 46                      /*length of impulse response*/
float DLY[N];            		/*delay samples                 */
const float H[N] = {/* filter coefficients*/
0.00113053589111100,
0.00101072486672204,
0.000468847235288906,
0.000603489038578611,
-0.00208429064928862,
-0.00340892103405782,
-0.00362003403497889,
-0.00179251511006564,
0.00229274890344763,
0.00758093034996730,	
0.0117041456801663,	
0.0117198866352666,	
0.00550311571071171,	
-0.00673606239661105,	
-0.0215570909070923,	
-0.0326442238558300,	
-0.0325783280789586,	
-0.0155583311041979,	
0.0199164513221244,	
0.0695391190116097,	
0.123656990515743,	
0.169767912370886,	
0.196291877716615,	
0.196291877716615,	
0.169767912370886,	
0.123656990515743,	
0.0695391190116097,	
0.0199164513221244,	
-0.0155583311041979,	
-0.0325783280789586,	
-0.0326442238558300,	
-0.0215570909070923,	
-0.00673606239661105,	
0.00550311571071171,	
0.0117198866352666,	
0.0117041456801663,	
0.00758093034996730,	
0.00229274890344763,	
-0.00179251511006564,	
-0.00362003403497889,	
-0.00340892103405782,	
-0.00208429064928862,	
-0.000603489038578611,	
0.000468847235288906,	
0.00101072486672204,
0.00113053589111100
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

void loop() 
{
  // put your main code here, to run repeatedly:


}

