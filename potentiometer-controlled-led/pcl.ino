const int potPin = A1;
const int ledPin = 5;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read potentiometer
  int potValue = analogRead(potPin);

  int blinkDelay = map(potValue, 0, 1023, 0, 255);

  digitalWrite(ledPin, HIGH);
  delay(blinkDelay);

  // Turn LED OFF
  digitalWrite(ledPin, LOW);
  delay(blinkDelay);

  // Display readings
  Serial.print("Potentiometer: ");
  Serial.print(potValue);

  Serial.print(" | blink delay: ");
  Serial.println(blinkDelay);

  delay(100);
}
