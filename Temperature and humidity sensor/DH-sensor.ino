
#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

// Common I2C address: 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

unsigned long previousMillis = 0;
const unsigned long interval = 2000;

void setup() {
  Serial.begin(9600);

  dht.begin();

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Environment");
  lcd.setCursor(0, 1);
  lcd.print("Monitor Starting");

  delay(2000);
  lcd.clear();
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    if (isnan(temperature) || isnan(humidity)) {
      lcd.setCursor(0, 0);
      lcd.print("Sensor Error    ");
      lcd.setCursor(0, 1);
      lcd.print("Check DHT22     ");

      Serial.println("Sensor reading failed!");
      return;
    }

    // Display temperature
    lcd.setCursor(0, 0);
    lcd.print("TEMP: ");
    lcd.print(temperature, 1);
    lcd.print((char)223);
    lcd.print("C   ");

    // Display humidity
    lcd.setCursor(0, 1);
    lcd.print("HUM:  ");
    lcd.print(humidity, 1);
    lcd.print("%    ");

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" C | Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  }
}
