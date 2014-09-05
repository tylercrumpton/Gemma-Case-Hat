const int LED_PIN = 1;

void setup() {
  delay(3000);
  
  pinMode(LED_PIN, OUTPUT);
  
  blinkDebug(3);
  delay(2000);
  
  blinkDebug(2.4);
  delay(2000);
  
  blinkDebug(2.6);
  delay(2000);
}

void loop() {
}

void blinkDebug(double debugValue){
  int roundedValue = (debugValue+.5);
  for (int i=0; i<roundedValue; ++i) {
    digitalWrite(LED_PIN, HIGH);
    delay(200);
    digitalWrite(LED_PIN, LOW);
    delay(200);
  }
}
