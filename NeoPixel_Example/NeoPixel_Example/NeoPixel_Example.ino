#include <Adafruit_NeoPixel.h>

const int LED_PIN = 1;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(1, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin(); // Turn all pixels off
}

void loop() {
  // Fade in green: 
  for(int i=0;i<255;i++){
    pixels.setPixelColor(0, pixels.Color(0,i,0)); 
    pixels.show();
    delay(1); 
  }
  
  // Fack back to off:
  for(int i=255;i>0;i--){
    pixels.setPixelColor(0, pixels.Color(0,i,0)); 
    pixels.show(); 
    delay(1); 
  }
}
