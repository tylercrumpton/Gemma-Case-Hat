const int      LED_PIN      = 1     ;
const int      PING_PIN     = 2     ;
const long int PING_TIMEOUT = 10000 ;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(PING_PIN, OUTPUT);
  digitalWrite(PING_PIN, LOW);
  
  // Comment out this and other serial lines if using this on 
  //  the Gemma:
  Serial.begin(9600); 
}

void loop() {
  digitalWrite(PING_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(PING_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(PING_PIN, LOW);
  
  pinMode(2, INPUT);
  int echoTime = pulseIn(PING_PIN, HIGH, PING_TIMEOUT);
  int distanceCM = (echoTime / 29.1) / 2;
  
  // Uncomment this line if using the Gemma, so you can see
  //  what the measured value is:
  //blinkDistance(distanceCM);
  
  // Comment out this and other serial lines if using this on 
  //  the Gemma:
  Serial.println(distanceCM);
  
  pinMode(PING_PIN, OUTPUT);
  delay(10);
  
}

void blinkDistance(int distance){
  int timesToBlink = (distance)/2 + 1;
  
  for (int i=0; i<timesToBlink; ++i) {
    digitalWrite(LED_PIN, HIGH);
    delay(200);
    digitalWrite(LED_PIN, LOW);
    delay(200);
  }
}
