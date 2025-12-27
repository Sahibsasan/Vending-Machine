#include <LiquidCrystal_I2C.h> //MASTER CODE
#include <AltSoftSerial.h>
#include <SoftwareSerial.h>

#define BUZZER 7

// AltSoftSerial for Bluetooth (HC-05) (Fixed RX=9, TX=8)
AltSoftSerial BTSerial; 

// SoftwareSerial for Slave Arduino Communication (TX=2, RX=3)
#define SLAVE_TX 2
#define SLAVE_RX 3
SoftwareSerial SlaveSerial(SLAVE_RX, SLAVE_TX);

// LCD Display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    pinMode(BUZZER, OUTPUT);
    digitalWrite(BUZZER, LOW);

    Serial.begin(9600);       // Serial Monitor
    BTSerial.begin(9600);     // Bluetooth Communication
    SlaveSerial.begin(9600);  // Communication with Slave

    lcd.begin();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Scan the QR Code");

    Serial.println("Waiting for Bluetooth signal...");
}

void loop() {
    if (BTSerial.available()) {
        String receivedData = BTSerial.readString();
        receivedData.trim(); // Remove spaces and newlines

        Serial.print("Received: ");
        Serial.println(receivedData);

        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("Payment Rs" + receivedData);
        lcd.setCursor(1, 1);
        lcd.print("Processing...");

        activateBuzzer();

        if (receivedData == "10.99") {
            SlaveSerial.println("M1");
        } else if (receivedData == "20.99") {
            SlaveSerial.println("M2");
        } else if (receivedData == "30.99") {
            SlaveSerial.println("M3");
        } else if (receivedData == "40.99") {
            SlaveSerial.println("M4");
        } else {
            Serial.println("Invalid Payment Amount");
        }

        delay(5000);
        resetLCD();  //Return to initial state
    }
}

void activateBuzzer() {
    Serial.println("Activating buzzer...");
    digitalWrite(BUZZER, HIGH);
    delay(1000);
    digitalWrite(BUZZER, LOW);
}

void resetLCD() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Scan the QR Code");
}