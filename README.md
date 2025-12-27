# Arduino-Based Smart Vending Machine

## Description
This project is an Arduino-based vending machine using:
- HC-05 Bluetooth module
- QR-based payment verification
- Master–Slave Arduino architecture
- Servo motors and relay module

## Features
- QR payment verification via mobile
- Bluetooth communication using HC-05
- Keypad-based product selection
- LCD display for status updates
- Automatic reset after dispensing

## Hardware Used
- Arduino Uno (x2)
- HC-05 Bluetooth Module
- Servo Motors
- Relay Module
- 16x2 I2C LCD
- Keypad
- Power Supply

## How it works
1. User scans QR code
2. Payment confirmed via Bluetooth
3. Keypad enabled
4. Selected product dispensed
5. System resets

## Connections
Master Arduino Connections (Handles Bluetooth, LCD, Buzzer, Communication)
➡ Bluetooth Module (HC-05)
HC-05 TX → Arduino Pin 8 (RX of AltSoftSerial)
HC-05 RX → Arduino Pin 9 (TX of AltSoftSerial)
HC-05 VCC → 5V
HC-05 GND → GND
➡ LCD Display (I2C - 16x2)
LCD SDA → Arduino A4
LCD SCL → Arduino A5
LCD VCC → 5V
LCD GND → GND
➡ Buzzer
Buzzer + (Positive) → Arduino Pin 9
Buzzer - (Negative) → GND
➡ Communication with Slave Arduino (AltSoftSerial)
Master Arduino Pin 3 (TX) → Slave Arduino Pin 2 (RX)
Master Arduino Pin 2 (RX) → Slave Arduino Pin 3 (TX)
Master GND → Slave GND

## Author
Gurnoor Singh
