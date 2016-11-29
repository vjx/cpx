#include <Adafruit_CircuitPlayground.h>
#include <Wire.h>
#include <SPI.h>

#define A12_IN  A11
#define TEMPIN A0
int tempMax = analogRead(TEMPIN)+1;
int tempMin = analogRead(TEMPIN)-1;
bool leftButtonPressed;
bool rightButtonPressed;
int brilho = 128;

void setup() {
  Serial.begin(115200);
  CircuitPlayground.begin();
  CircuitPlayground.clearPixels();
  CircuitPlayground.setBrightness(brilho);

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

  leftButtonPressed = CircuitPlayground.leftButton();
  rightButtonPressed = CircuitPlayground.rightButton();
  
  if (leftButtonPressed) {
    brilho = brilho - 20;
  } 
  if (rightButtonPressed) {
    brilho = brilho + 20;
  }
  if (brilho > 248 ) {
    brilho = 255;
  }
  if (brilho < 1) {
   brilho = 1;
  }
   
  CircuitPlayground.setBrightness(brilho);  
  int tempMapped = map(tempValue, tempMin, tempMax, 0, 255);

for(int i=10; i>=0; --i) {
  CircuitPlayground.setPixelColor(i, tempMapped, 0, 255-tempMapped);
  delay (50);
  }
   
//Serial.println(tempMapped);
//Serial.println(tempMin);
//Serial.println(tempMax);
Serial.println(brilho);
//Serial.println("XXXXXXXXXXXXXX");
 
 delay(500);
} 
