#include <Adafruit_CircuitPlayground.h>
#include <Wire.h>
#include <SPI.h>

#define A12_IN  A11
#define TEMPIN A0
int tempMax = analogRead(TEMPIN)+1;
int tempMin = analogRead(TEMPIN)-1;

void setup() {
  Serial.begin(115200);
  CircuitPlayground.begin();
  CircuitPlayground.clearPixels();
  delay(1000);
  }

void loop() {
  uint16_t tempValue = analogRead(TEMPIN);
  
  if (tempMax < tempValue){
    tempMax = tempValue + 1;
  }
  if (tempMin > tempValue){
    tempMin = tempValue - 1;
  }
  if (tempMin < 0){
    tempMin = 0;
  }

  int tempMapped = map(tempValue, tempMin, tempMax, 0, 255);

for(int i=10; i>=0; --i) {
  CircuitPlayground.setPixelColor(i, tempMapped, 0, 255-tempMapped);
  delay (50);
  }
   
//Serial.println(tempMapped);
//Serial.println(tempMin);
//Serial.println(tempMax);
//Serial.println("XXXXXXXXXXXXXX");
 
 delay(500);
} 
