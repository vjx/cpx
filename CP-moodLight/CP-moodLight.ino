#include <Adafruit_CircuitPlayground.h>
#include <Wire.h>
#include <SPI.h>

#define A12_IN  A11

bool leftButtonPressed;
bool rightButtonPressed;
int brilho = 1;
int tempoVolta = 333;

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.clearPixels();
  CircuitPlayground.setBrightness(brilho);
  }

void loop() {

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

// Primeiro Efeito azul -> rosa -> azul:

  for(int cor=0; cor<=255; cor++) {
    for(int i=10; i>=0; --i) {
      CircuitPlayground.setPixelColor(i, cor, 0, 255);
      delay (tempoVolta);
    }
  } 
delay (5000);

for(int cor=255; cor>=0; cor--) {
    for(int i=10; i>=0; --i) {
      CircuitPlayground.setPixelColor(i, cor, 0, 255);
      delay (tempoVolta);
    }
  } 
delay (5000);

// Segundo Efeito azul -> verde -> azul:

  for(int cor=0; cor<=255; cor++) {
    for(int i=10; i>=0; --i) {
      CircuitPlayground.setPixelColor(i, 0, cor, 255-cor);
      delay (tempoVolta);
    }
  }
   
delay (5000);

for(int cor=255; cor>=0; cor--) {
    for(int i=10; i>=0; --i) {
      CircuitPlayground.setPixelColor(i, 0, cor, 255-cor);
      delay (tempoVolta);
    }
  } 
 delay (5000);
   
} 
