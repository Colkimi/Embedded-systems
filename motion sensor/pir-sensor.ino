
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Pin assignments
const int pirPin = 8;
const int buzzerPin = 13;
const int ledPin = 9;
const int buttonPin = 7;

// LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// System state
bool systemArmed = false;

// Intrusion counter
unsigned int intrusionCount = 0;
int previousMotionState = LOW;

// Button debouncing
int buttonState = HIGH;
int lastButtonReading = HIGH;

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

// LCD display tracking
String lastLine1 = "";
String lastLine2 = "";

void updateLCD(String line1, String line2) {

  if (line1 != lastLine1 || line2 != lastLine2) {

    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 0);
    lcd.print(line1);

    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print(line2);

    lastLine1 = line1;
    lastLine2 = line2;
  }
}

void setup() {

  Serial.begin(9600);

  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();

  updateLCD("SECURITY SYSTEM", "Initializing...");

  delay(5000);

  updateLCD("SYSTEM DISARMED", "COUNT: 0");

  Serial.println("Security System Ready");
}

void loop() {

  // 1. Read and debounce button
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonReading) {
    lastDebounceTime = millis();
  }

  if (millis() - lastDebounceTime > debounceDelay) {

    if (reading != buttonState) {

      buttonState = reading;

      if (buttonState == LOW) {

        systemArmed = !systemArmed;

        if (systemArmed) {
          Serial.println("SYSTEM ARMED");
        } else {
          Serial.println("SYSTEM DISARMED");

          digitalWrite(ledPin, LOW);
          noTone(buzzerPin);
        }
      }
    }
  }

  lastButtonReading = reading;

  // 2. Read PIR sensor
  int motion = digitalRead(pirPin);

  // 3. Detect a NEW motion event
  if (systemArmed &&
      motion == HIGH &&
      previousMotionState == LOW) {

    intrusionCount++;

    Serial.print("INTRUSION DETECTED! Total: ");
    Serial.println(intrusionCount);
  }

  // 4. Control alarm and LCD
  if (!systemArmed) {

    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);

    updateLCD("SYSTEM DISARMED",
              "COUNT: " + String(intrusionCount));

  } else {

    if (motion == HIGH) {

      digitalWrite(ledPin, HIGH);
      tone(buzzerPin, 1000);

      updateLCD("MOTION DETECTED",
                "COUNT: " + String(intrusionCount));

    } else {

      digitalWrite(ledPin, LOW);
      noTone(buzzerPin);

      updateLCD("SYSTEM ARMED",
                "COUNT: " + String(intrusionCount));
    }
  }

  // 5. Remember current PIR state
  previousMotionState = motion;
}
