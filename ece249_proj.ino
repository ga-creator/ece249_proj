#include <LiquidCrystal.h>

// Initialize the LiquidCrystal library with the pins connected to the LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Define the pin for the potentiometer
const int potPin = A0; // Pin connected to the potentiometer
const int pumpPin = 10; // Pin connected to the pump relay or control circuit

void setup() {
    lcd.begin(16, 2); // Set up the LCD's number of columns and rows
    pinMode(pumpPin, OUTPUT); // Set pumpPin as an output
    digitalWrite(pumpPin, HIGH); // Turn off the pump initially
}

void loop() {
    int waterLevel = analogRead(potPin); // Read the potentiometer value
    int levelPercentage = map(waterLevel, 0, 1023, 0, 100); // Map to percentage
    
    // Display water level percentage on LCD
    lcd.clear(); // Clear the LCD screen
    lcd.setCursor(0, 0); // Set cursor to the first row
    lcd.print("Water Level: "); 
    lcd.print(levelPercentage);
    lcd.print("%");

    // Check if water level is 100%
    if (levelPercentage >= 100) { // Check for tank full condition
        lcd.setCursor(0, 1); // Move to the second row
        lcd.print("Tank Full     "); // Add spaces to clear previous text
        digitalWrite(pumpPin, LOW); // Turn off the pump
    } else {
        lcd.setCursor(0, 1); // Move to the second row
        lcd.print("Pump ON       "); // Add spaces to clear previous text
        digitalWrite(pumpPin, HIGH); // Turn on the pump
    }

    delay(500); // Delay for a short period
}
