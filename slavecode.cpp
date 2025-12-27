#include <SoftwareSerial.h> // SLAVE CODE

// Define Serial Communication Pins for Master ↔ Slave
#define MASTER_TX 2
#define MASTER_RX 3
SoftwareSerial MasterSerial(MASTER_RX, MASTER_TX);

// Motor Driver (L293D) Corrected PWM & Control Pins
#define MOTOR1_EN 5  // ✅ PWM Pin
#define MOTOR1_IN1 6
#define MOTOR1_IN2 7

#define MOTOR2_EN 9  // ✅ PWM Pin
#define MOTOR2_IN1 10
#define MOTOR2_IN2 11

#define MOTOR3_EN 3  // ✅ PWM Pin
#define MOTOR3_IN1 4
#define MOTOR3_IN2 A1

#define MOTOR4_EN 6  // ✅ PWM Pin
#define MOTOR4_IN1 A2
#define MOTOR4_IN2 A3

void setup() {
    Serial.begin(9600);        // Debugging
    MasterSerial.begin(9600);  // Communication with Master

    // Initialize motor pins as OUTPUT
    pinMode(MOTOR1_EN, OUTPUT);
    pinMode(MOTOR1_IN1, OUTPUT);
    pinMode(MOTOR1_IN2, OUTPUT);
    
    pinMode(MOTOR2_EN, OUTPUT);
    pinMode(MOTOR2_IN1, OUTPUT);
    pinMode(MOTOR2_IN2, OUTPUT);
    
    pinMode(MOTOR3_EN, OUTPUT);
    pinMode(MOTOR3_IN1, OUTPUT);
    pinMode(MOTOR3_IN2, OUTPUT);
    
    pinMode(MOTOR4_EN, OUTPUT);
    pinMode(MOTOR4_IN1, OUTPUT);
    pinMode(MOTOR4_IN2, OUTPUT);

    Serial.println("Slave Ready...");
}

void loop() {
    if (MasterSerial.available()) {
        String command = MasterSerial.readString();
        command.trim();  // Remove spaces and newlines

        Serial.print("Received Command: ");
        Serial.println(command);

        if (command == "M1") {
            Serial.println("Running Motor 1...");
            runMotor(MOTOR1_EN, MOTOR1_IN1, MOTOR1_IN2);
        } 
        else if (command == "M2") {
            Serial.println("Running Motor 2...");
            runMotor(MOTOR2_EN, MOTOR2_IN1, MOTOR2_IN2);
        } 
        else if (command == "M3") {
            Serial.println("Running Motor 3...");
            runMotor(MOTOR3_EN, MOTOR3_IN1, MOTOR3_IN2);
        } 
        else if (command == "M4") {
            Serial.println("Running Motor 4...");
            runMotor(MOTOR4_EN, MOTOR4_IN1, MOTOR4_IN2);
        } 
        else {
            Serial.println("Invalid Command");
        }
    }
}

void runMotor(int en, int in1, int in2) {
    Serial.print("Activating motor on EN pin: ");
    Serial.println(en);

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    Serial.println("Motor Direction: Forward");

    analogWrite(en, 255);  // Full speed
    Serial.println("Motor is ON");

    delay(5000);  // Run motor for 5 seconds

    analogWrite(en, 0);  // Stop motor
    Serial.println("Motor is OFF");

    delay(1000);  // Wait before next command
}