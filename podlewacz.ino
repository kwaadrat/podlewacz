#include <Wire.h>
#include "rgb_lcd.h"

#include <math.h>

const int B = 4275;               // B value of the thermistor
const int R0 = 100000;            // R0 = 100k
const int pinTempSensor = A0;     // Grove - Temperature Sensor connect to A0

const int C = 4275;               // C value of the thermistor
const int R1 = 100000;            // R1 = 100k
const int pinTempSensor2 = A2;     // Grove - Temperature Sensor connect to A2


rgb_lcd lcd;

void setup() 
{

}

void loop() 
{

int a = analogRead(pinTempSensor);

    float R = 1023.0/a-1.0;
    R = R0*R;

    float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15; 

int b = analogRead(pinTempSensor2);

		float R2 = 1023.0/b-1.0;
		R2 = R1*R2;

    float temperature2 = 1.0/(log(R2/R1)/C+1/298.15)-273.15;
  
lcd.begin(16, 2);
      lcd.print("In. temp: ");
      lcd.print(temperature);
   
lcd.setCursor(0, 1);
        lcd.print("Out. temp: ");
        lcd.print(temperature2);

    delay(100);
}
