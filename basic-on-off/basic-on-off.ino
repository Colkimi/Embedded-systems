
const int LED_PIN = 8;
const int onButton = 7;
const int offButton = 2;

void setup() {
  pinMode(LED_PIN, OUTPUT);

  pinMode(onButton, INPUT_PULLUP);
  pinMode(offButton, INPUT_PULLUP);

  digitalWrite(LED_PIN, LOW);
}

void loop() {
  if(digitalRead(onButton) == LOW) {
    digitalWrite(LED_PIN, HIGH);
    delay(50);
  }
  
  if(digitalRead(offButton) == LOW){
    digitalWrite(LED_PIN, LOW);
    delay(50);
  }
  
}
