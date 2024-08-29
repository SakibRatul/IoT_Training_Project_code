//HW-038 water level sensor. the condition is when water level become high then motor rotation will be stop, 
//other then motor will continue rotate. print water value also
//just rotate the motor base on the based on water level value

int relay1 = 2;
int relay2 = 3;
int waterLevelSensorPin = A0; // Assuming you connect the sensor to analog pin A0

void setup() {
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(waterLevelSensorPin, INPUT); 
  digitalWrite(relay1, HIGH); 
  digitalWrite(relay2, HIGH); 
  Serial.begin(9600);
  Serial.println("Motor Control Based on Water Level");
  delay(2000);
}

void loop() {
  int waterLevel = analogRead(waterLevelSensorPin);

  // Check if water level is high (you'll need to adjust the threshold value)
  if (waterLevel > 500) { // Adjust 500 based on your sensor and setup
    // Stop the motor
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    Serial.print("Water level high: ");
    Serial.print(waterLevel);
    Serial.println(", motor stopped"); 
  } else {
    // Rotate the motor (you'll need to set the appropriate relay states for your motor)
    digitalWrite(relay1, LOW); // Adjust these based on your motor wiring
    digitalWrite(relay2, HIGH); // Adjust these based on your motor wiring
    Serial.print("Water level: ");
    Serial.println(waterLevel);
    Serial.println("Motor rotating"); 
  }

  delay(500); // Add a small delay to avoid reading the sensor too frequently
}