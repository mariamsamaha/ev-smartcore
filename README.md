# 🚗 Electric Vehicle Climate Control & Safety Check System

## 📌 Project Overview

This project focuses on building a **Climate Control System** and **Safety Check System** for an electric vehicle using Arduino. It simulates real-time vehicle features such as:

* **Temperature regulation**
* **Seat belt and door lock validation**
* **Ambient light-based lighting**
* **Accelerator/brake input simulation**

## ⭐Features

### Climate Control System
* Allows passengers to set desired temperature via a **keypad**
* Based on the input, the **heater** or **cooling fan** is activated
* Displays **real-time temperature**, **fan speed**, and **heater status** on the **LCD display**

### Safety Check System
* Prevents the vehicle from moving unless **all seat belts are fastened** and **all doors are locked**
* LCD provides **feedback and warnings**

### Additional Functions
* Simulated **vehicle movement** based on accelerator/brake pedal input
* **Automatic headlights** triggered by **ambient light** using LDR
* **Real-time system status** displayed on the LCD

## 📦Components List

| Component Name | Required Quantity |
|---|---|
| Arduino Uno | 1 |
| DC Motor (4WD chassis) | 1 |
| Motor Driver (L298N) | 1 |
| Potentiometer | 1 |
| Pressure Sensor | 1 |
| LCD Display 16x2 | 1 |
| LEDs | 10 |
| Resistors | 20 |
| Light Dependent Resistor (LDR) | 1 |
| Temperature Sensor (LM35) | 1 |
| Cooling Fan (DC fan) | 1 |
| Keypad Module (4x4 Keypad) | 1 |
| Seat Belt Sensors (Push Buttons) | 5 |
| Door Lock Sensors | 2 |
| Jumper Wires | 30 |
| Voltage Regulator (7805) | 1 |
| Battery Pack (Li-Ion or Li-Po) | 1 |
| Arduino USB Programming Cable | 1 |

## System Architecture

### Microcontroller
* **Arduino Uno**

### Input Devices
* Keypad
* Temperature Sensor (LM35)
* Pressure / Accelerator / Brake Sensors
* Seat Belt & Door Lock Switches
* LDR (Ambient Light Detection)

### Output Devices
* LCD Display
* Fan
* Heater
* Headlights
* Brake Lights
* DC Motor

## Code Modules

### climate_control.ino
* Reads current temperature from the **LM35 sensor**
* Accepts desired temperature from the **keypad**
* Controls **fan or heater** based on input
* Displays **current temperature, desired temperature**, and **system state** on the LCD

### safety_check.ino
* Reads input from **seat belt** and **door lock** sensors
* **Blocks motor movement** if safety conditions are not met
* Displays **status messages** on the LCD


## Installation & Setup

### Hardware Assembly
- Connect all components according to the circuit diagram
- Ensure proper power distribution using the voltage regulator
- Test individual connections before powering the system

### Software Setup
- Install Arduino IDE
- Upload the respective code modules to your Arduino Uno
- Ensure all required libraries are installed

### Testing
- Test climate control functionality
- Verify safety check operations
- Validate automatic lighting system

## Usage

1. Power on the system using the battery pack
2. Set desired temperature using the keypad
3. Fasten all seat belts and lock all doors for vehicle operation
4. Use accelerator/brake sensors to simulate vehicle movement
5. Monitor system status on the LCD display

## Troubleshooting

- **LCD not displaying**: Check connections and power supply
- **Temperature sensor not responding**: Verify LM35 wiring and voltage
- **Motors not working**: Check motor driver connections and power
- **Safety system not engaging**: Test individual sensor inputs

## Future Enhancements

- Integration with smartphone app
- GPS tracking system
- Battery monitoring dashboard
- Remote climate control
- Advanced security features

## Author

*Mariam Samaha
Bachelor of Science in Computer Science
Zewail City University, Egypt*

---
