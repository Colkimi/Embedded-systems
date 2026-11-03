# Arduino Temperature & Humidity Monitoring System

An Arduino-based temperature and humidity monitoring project using a DHT11 or DHT22 sensor and a 16×2 LCD display with an I2C interface.

The system reads environmental temperature and humidity data from the DHT sensor and displays the measurements on the LCD in real time.

## Wokwi Simulation

Wokwi simulation project link:

[**Open Wokwi Simulation**](https://wokwi.com/projects/479688572481932289)

**Sample setup**
<img width="1770" height="1188" alt="image" src="https://github.com/user-attachments/assets/4b0fe147-b844-4c89-b9df-7c866f867ba3" />

## Hardware Requirements

The following components are required to build the project:

| Component | Description |
|---|---|
| Arduino Uno | Main microcontroller |
| DHT11 or DHT22 | Temperature and humidity sensor |
| 16×2 LCD Display (I2C) | Displays sensor readings |
| Breadboard | Circuit prototyping |
| Resistor | Pull-up resistor, if required by the sensor setup |
| Jumper Wires | Electrical connections |

## Software Requirements

- Arduino IDE
- USB cable for programming the Arduino Uno

## Required Libraries

Install the following libraries through the Arduino IDE Library Manager:

1. **DHT Sensor Library** – Used to communicate with the DHT11/DHT22 sensor.
2. **LiquidCrystal I2C** – Used to control the LCD display through the I2C interface.

## Project Functionality

- Reads temperature measurements from the DHT sensor.
- Reads relative humidity measurements.
- Displays temperature and humidity values on the 16×2 LCD.
- Continuously updates the displayed readings.

## Expected Output

The LCD displays the sensor readings in the following format:

```text
Temperature: 25.4 C
Humidity:    60.2 %
```

*Note: Actual readings depend on the surrounding environmental conditions.*

## Getting Started

1. Open the Wokwi simulation using the link above.
2. Ensure all required components and libraries are available.
3. Run the simulation.
4. Observe the temperature and humidity readings on the LCD display.

---

**Project:** Arduino Temperature & Humidity Monitoring System  
**Platform:** Arduino Uno  
**Simulation:** Wokwi
