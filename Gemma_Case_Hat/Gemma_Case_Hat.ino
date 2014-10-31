/*
 * Gemma-Powered Sherlock Holme "Case Hat"
 *  This project is the Sherlock Holmes "Case Hat"; 
 *  the twist here is that it's been powered up using
 *  a Gemma microcontroller with an ultrasonic 
 *  rangefinder attached to the rear bill that will 
 *  alert the wearer to people or objects behind them, 
 *  giving them a Holmes-esque sense of situational 
 *  awareness
 *
 *  Copyright (c) 2014 Tyler Crumpton
 */

#include <Adafruit_NeoPixel.h>

const int BUZZER_PIN = 0;
const int LED_PIN    = 1;
const int PING_PIN   = 2;

#define ALARM_DISTANCE 50

int getDistance();
void soundTheAlarm();
void fadeInLed();
void fadeOutLed();
void serColor(int pingDistance);

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(1, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(PING_PIN, OUTPUT);
  Serial.begin(9600);
}

volatile long pingDistance = -1;
long currentTime;

void loop() {
  getDistance();
  
  if (pingDistance < ALARM_DISTANCE && pingDistance != -1) {
    soundTheAlarm();
  }
  else {
    setColor(pingDistance);
  } 
}

int getDistance() {
  digitalWrite(PING_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(PING_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(PING_PIN, LOW);
  
  pinMode(2, INPUT);
  int echoTime = pulseIn(PING_PIN, HIGH, 10000);
  int distanceCM = (echoTime / 29.1) / 2;
  
  pinMode(PING_PIN, OUTPUT);
  
  return distanceCM;
}

void soundTheAlarm() {
  for (int i=0; i<5; ++i)
  {
    tone(BUZZER_PIN,1000); // 1 kHz "High" tone
    fadeInLed();
    tone(BUZZER_PIN,500);  // 500 Hz "Low" tone
    fadeOutLed();
  }
  noTone(BUZZER_PIN); // Stop the tone
}

void fadeInLed() {
  // Fade in red: 
  for(int i=0; i<254; i+=2) {
    pixels.setPixelColor(0, pixels.Color(i,0,0)); 
    pixels.show();
    delay(1); 
  }
}

void fadeOutLed() {
// Fade back to off: 
  for(int i=254; i>0; i-=2) {
    pixels.setPixelColor(0, pixels.Color(i,0,0)); 
    pixels.show();
    delay(1); 
  }
}

void setColor(int pingDistance) {
  if (pingDistance == 0 || pingDistance > 100) {
    // Far away
    pixels.setPixelColor(0, pixels.Color(0,0,0)); 
  }
  else if (pingDistance > 50) {
    // Kinda close
    int lightVal = ( ( pingDistance - 50 ) * 255 ) / 50;
    pixels.setPixelColor(0, pixels.Color(0,lightVal,0)); 
  }
  else {
    // Really close
    int lightVal = ( pingDistance * 255 ) / 50; 
    pixels.setPixelColor(0, pixels.Color(lightVal,0,0)); 
  }
  pixels.show();
}

