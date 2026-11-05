# PIR Motion Security System

An Arduino Uno security-system example that detects motion with a PIR sensor,
counts distinct motion events, and reports the system state on a 16×2 I2C LCD.
When the system is armed and motion is detected, the LED turns on and the
buzzer sounds.

## Wokwi simulation

[Open the PIR sensor simulation](https://wokwi.com/projects/479791056976702465)

The simulation is useful for checking the alarm behavior before assembling the
circuit. The PIR sensor may need a few seconds to settle when the simulation
starts.

## Hardware requirements

| Component | Quantity | Purpose |
|---|---:|---|
| Arduino Uno | 1 | Microcontroller |
| PIR motion sensor | 1 | Detects motion |
| 16×2 LCD with I2C backpack | 1 | Displays system state and count |
| Buzzer | 1 | Audible alarm |
| LED | 1 | Visual alarm indicator |
| Push button | 1 | Arms or disarms the system |
| Resistor | 1 | Current limiting for the LED |
| Breadboard and jumper wires | As needed | Circuit assembly |

## Wiring

The pin assignments used by [`pir-sensor.ino`](./pir-sensor.ino) are:

| Device | Arduino pin | Notes |
|---|---|---|
| PIR signal | D8 | PIR power goes to 5V and GND |
| Buzzer | D13 | Connect the other terminal to GND |
| LED | D9 | Connect the LED in series with a current-limiting resistor to GND |
| Push-button | D7 | Connect the other side to GND; the sketch enables `INPUT_PULLUP` |
| LCD SDA | A4 | I2C data on an Arduino Uno |
| LCD SCL | A5 | I2C clock on an Arduino Uno |
| LCD VCC/GND | 5V/GND | I2C backpack power |

The sketch expects the LCD I2C address to be `0x27`. If the display does not
respond, scan the I2C bus and update the address in the sketch if necessary.

## Required software

- Arduino IDE
- Arduino Uno board support
- [`LiquidCrystal I2C`](https://www.arduino.cc/reference/en/libraries/liquidcrystal-i2c/)
  library

Install the library from **Tools → Manage Libraries** in the Arduino IDE.

## How it works

1. The system starts disarmed and initializes the LCD for five seconds.
2. Press the push button once to arm the system; press it again to disarm it.
3. While armed, a PIR `HIGH` signal turns on the LED and buzzer and shows
   `MOTION DETECTED` on the LCD.
4. Each transition from no motion to motion increments the intrusion count.
5. Disarming turns off the LED and buzzer but preserves the count until the
   board is reset.

The button is debounced in software, and the LCD is only rewritten when its
content changes to reduce unnecessary display updates.

## Expected display

```text
SYSTEM DISARMED
COUNT: 0
```

Other states include `SYSTEM ARMED` and `MOTION DETECTED`. Motion events are
also logged to the Serial Monitor at **9600 baud**.

## Upload and run

1. Open `motion sensor/pir-sensor.ino` in the Arduino IDE.
2. Select **Arduino Uno** and the correct serial port.
3. Install `LiquidCrystal I2C` if it is not already installed.
4. Upload the sketch.
5. Open the Serial Monitor at 9600 baud.
6. Wait for the PIR sensor to initialize, then press the button to arm the
   system.

## Troubleshooting

- **LCD is blank:** Check 5V, GND, SDA, and SCL. Confirm the I2C address is
  `0x27`; some backpacks use a different address.
- **Motion is detected immediately:** Allow the PIR sensor to finish its
  warm-up period after power-on.
- **Button behavior is reversed:** The button must connect D7 to GND. The
  sketch uses the internal pull-up resistor, so a pressed button reads `LOW`.
- **LED is dim or fails:** Verify the LED polarity and use a suitable
  current-limiting resistor.
