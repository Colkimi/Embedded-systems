# Embedded systems

A collection of small Arduino Uno projects for learning basic electronics,
sensor input, output control, and LCD displays. Each project includes an
Arduino sketch and a short guide, and most projects include a Wokwi simulation
link for experimenting without physical hardware.

## Projects

| Project | What it demonstrates | Documentation | Sketch |
|---|---|---|---|
| Basic on/off | Turn an LED on and off with separate push buttons | [Guide](./basic-on-off/basic-on-off.md) | [Sketch](./basic-on-off/basic-on-off.ino) |
| Potentiometer-controlled LED | Map an analog potentiometer value to LED blink speed | [Guide](./potentiometer-controlled-led/pcl.md) | [Sketch](./potentiometer-controlled-led/pcl.ino) |
| PIR motion security system | Detect motion, sound an alarm, and count intrusion events | [Guide](./motion%20sensor/pir-sensor.md) | [Sketch](./motion%20sensor/pir-sensor.ino) |
| Temperature and humidity monitor | Read a DHT22 sensor and display values on an I2C LCD | [Guide](./Temperature%20and%20humidity%20sensor/DH-sensor.md) | [Sketch](./Temperature%20and%20humidity%20sensor/DH-sensor.ino) |

## Getting started

### Hardware

Most projects use an Arduino Uno, a breadboard, jumper wires, LEDs, buttons,
or sensors. See the guide for each project for its complete parts list and
pin assignments.

### Software

1. Install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Connect an Arduino Uno, or open the project's Wokwi simulation.
3. Open the corresponding `.ino` file.
4. Select **Arduino Uno** under **Tools → Board** and select the connected
   serial port.
5. Install any libraries listed in the project guide using
   **Tools → Manage Libraries**.
6. Upload the sketch, or start the simulation.

The sketches use the Arduino IDE's standard project layout: the `.ino` file
contains the complete program for that example. Serial output, where provided,
uses **9600 baud**.

## Simulations

The project guides contain the simulation links and project-specific setup
details:

- [Basic on/off simulation guide](./basic-on-off/basic-on-off.md)
- [Potentiometer-controlled LED simulation guide](./potentiometer-controlled-led/pcl.md)
- [PIR motion simulation guide](./motion%20sensor/pir-sensor.md)
- [Temperature and humidity simulation guide](./Temperature%20and%20humidity%20sensor/DH-sensor.md)

Wokwi simulations are optional; they do not replace checking the wiring and
component ratings of a physical circuit.

## Repository layout

```text
.
├── basic-on-off/
├── motion sensor/
├── potentiometer-controlled-led/
└── Temperature and humidity sensor/
```

Each directory contains the sketch and its related Markdown documentation.

## Contributing

When adding an example:

1. Put the sketch and its documentation in a dedicated directory.
2. Document the required components, wiring, libraries, and expected behavior.
3. Add the project to the table above.
4. Include a Wokwi link when a simulation is available.
5. Keep pin assignments and library names consistent between the sketch and
   its documentation.
