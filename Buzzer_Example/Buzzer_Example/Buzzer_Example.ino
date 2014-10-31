const int BUZZER_PIN = 2;

void setup(){
  for (int i=0; i<5; ++i)
  {
    tone(BUZZER_PIN,1000); // 1 kHz "High" tone
    delay(100);
    tone(BUZZER_PIN,500);  // 500 Hz "Low" tone
    delay(100);
  }
  noTone(BUZZER_PIN); // Stop the tone
}
void loop(){
  // Nothing in the loop.
}
