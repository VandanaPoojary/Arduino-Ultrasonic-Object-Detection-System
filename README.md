# Arduino Ultrasonic Object Detection and Level Monitoring System

## 📌 Overview

This project is an Arduino UNO based object detection and level monitoring system using an HC-SR04 ultrasonic sensor.

The ultrasonic sensor measures the distance between the sensor and the object. The Arduino calculates the object level percentage based on a predefined height of 20 cm.

Three LEDs and a buzzer provide visual and audio indications depending on the detected level.

## 🔧 Components Used

- Arduino UNO
- HC-SR04 Ultrasonic Sensor
- Green LED
- Yellow LED
- Red LED
- Buzzer
- Resistors
- Breadboard
- Jumper Wires

## 🔌 Pin Connections

| Component | Arduino UNO Pin |
|---|---|
| HC-SR04 Trig | D9 |
| HC-SR04 Echo | D10 |
| Green LED | D2 |
| Yellow LED | D3 |
| Red LED | D4 |
| Buzzer | D5 |

## ⚙️ Working Principle

The HC-SR04 ultrasonic sensor sends an ultrasonic pulse and measures the time taken for the echo to return.

The Arduino calculates the distance using:

```text
Distance = Duration × 0.0343 / 2
```

The object level is then calculated using:

```text
Object Level = Object Height - Measured Distance
```

The project uses an object height of 20 cm and converts the calculated level into a percentage.

## 🚦 Level Indication

| Level | Green LED | Yellow LED | Red LED | Buzzer |
|---|---|---|---|---|
| Below 35% | ON | OFF | OFF | OFF |
| 35% - 74% | OFF | ON | OFF | OFF |
| 75% and above | OFF | OFF | ON | ON |

## 🖥️ Serial Monitor

The Arduino displays the measured distance, calculated object level, percentage, and system status on the Serial Monitor.

Example:

```text
Distance: 15.20 cm | objectDist: 4.80 cm | Level: 24.00%
Status: LOW DISTANCE
```

## 💻 Software Used

- Arduino IDE
- Embedded C / Arduino Programming

## 🎯 Applications

- Object detection
- Level monitoring
- Water tank level monitoring
- Distance measurement
- Warning and alert systems

## 🚀 Future Improvements

- Add an LCD or OLED display
- Add IoT connectivity
- Send level alerts to a mobile application
- Add automatic pump control
- Store sensor readings for monitoring

## 👩‍💻 Project

Developed as a practical electronics and embedded systems project using Arduino UNO and ultrasonic sensing technology.
