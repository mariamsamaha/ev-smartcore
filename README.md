# 🚗 Electric Vehicle Climate Control & Safety Check System
📌 Project Overview
This project focuses on building a Climate Control System and Safety Check System for an electric vehicle using Arduino. It simulates real-time vehicle features such as temperature regulation, safety validation (seat belt and door lock checks)

#Features:
This project simulates core features of an electric vehicle including:

-Climate Control System: Allows passengers to set desired temperature using a keypad. Based on input, the heater or cooling fan is activated. Real-time temperature, fan speed, and heater status are shown on an LCD.

-Safety Check System: Prevents the vehicle from moving unless all seat belts are fastened and doors are locked. Feedback is provided through the LCD.

Additional Functions:

Vehicle movement based on accelerator/brake pedal input.

Automatic headlights based on ambient light via LDR.

Real-time status updates on LCD.

##📦 Components List:
| **Component Name**                       | **Required Quantity** |
| ---------------------------------------- | --------------------- |
| Arduino Uno                              | 1                     |
| DC Motor (4WD chassis)                   | 1                     |
| Motor Driver (L298N)                     | 1                     |
| Potentiometer                            | 1                     |
| Pressure Sensor                          | 1                     |
| LCD Display 16x2                         | 1                     |
| LEDs                                     | 10                    |
| Resistors                                | 20                    |
| Light Dependent Resistor (LDR)           | 1                     |
| Temperature Sensor (LM35)                | 1                     |
| Cooling Fan (DC fan)                     | 1                     |
| Keypad Module (4x4 Keypad)               | 1                     |
| Seat Belt Sensors (Push Button Switches) | 5                     |
| Door Lock Sensors                        | 2                     |
| Jumper Wires                             | 30                    |
| Voltage Regulator (7805)                 | 1                     |
| Battery Pack (Li-Ion or Li-Po)           | 1                     |
| Arduino USB Programming Cable            | 1                     |

##🧠 System Architecture
Microcontroller: Arduino Uno

Input Devices:

Keypad

Temperature Sensor (LM35)

Pressure/Acceleration/Brake Sensors

Seat Belt and Door Lock Switches

LDR for ambient light detection

Output Devices:

LCD Display

Fan

Heater

Headlights

Brake Lights

Motor

##🧾 Code Modules
climate_control.ino
Reads current temperature using LM35.

Accepts desired temperature from keypad.

Activates heater or fan accordingly.

Displays current temp, desired temp, and system state on LCD.

safety_check.ino
Reads seat belt and door lock status.

Blocks motor if any belt is unfastened or door is unlocked.

Displays status message on LCD.




