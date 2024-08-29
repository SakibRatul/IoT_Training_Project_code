#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

int relay1 = 2;
int relay2 = 3;
int waterLevelSensorPin = A0; // Assuming you connect the sensor to analog pin A0

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3f, 16, 2);

void setup() {
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(waterLevelSensorPin, INPUT); 
  digitalWrite(relay1, HIGH); 
  digitalWrite(relay2, HIGH); 
  Serial.begin(9600);
  
  // initialize the LCD
  lcd.init();
  
  // turn on the backlight
  lcd.backlight();

  lcd.print("Motor Control");
  lcd.setCursor(0, 1); // Move to the second line
  lcd.print("Based on Water");
  delay(2000);
  lcd.clear(); // Clear the initial message
}

void loop() {
  int waterLevel = analogRead(waterLevelSensorPin);

  // Check if water level is high (you'll need to adjust the threshold value)
  if (waterLevel > 500) { // Adjust 500 based on your sensor and setup
    // Stop the motor
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    
    lcd.setCursor(0, 0); 
    lcd.print("Water: ");
    lcd.print(waterLevel);
    lcd.setCursor(0, 1); 
    lcd.print("Motor Stopped   "); 
  } else {
    // Rotate the motor (you'll need to set the appropriate relay states for your motor)
    digitalWrite(relay1, LOW); // Adjust these based on your motor wiring
    digitalWrite(relay2, HIGH); // Adjust these based on your motor wiring
    
    lcd.setCursor(0, 0); 
    lcd.print("Water: ");
    lcd.print(waterLevel);
    lcd.setCursor(0, 1); 
    lcd.print("Motor Rotating "); 
  }

  delay(500); // Add a small delay to avoid reading the sensor too frequently
}