// Sensor pins
#define sensorPower 7
#define sensorPin A0

void setup() {
  pinMode(sensorPower, OUTPUT); // Set D7 as an OUTPUT
  digitalWrite(sensorPower, LOW); // Initially turn the sensor OFF
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin); 
  int waterLevelCm = map(sensorValue, 0, 1023, 0, 100); // Adjust mapping if needed

  // Determine water level based on distance thresholds
  String levelDescription;
  if (waterLevelCm <= 50) {
    levelDescription = "Base Level";
  } else if (waterLevelCm <= 70) {
    levelDescription = "Medium Level";
  } else {
    levelDescription = "Deep Level";
  }

  Serial.print("Water level is in ");
  Serial.print(levelDescription);
  Serial.print(" (");
  Serial.print(waterLevelCm);
  Serial.println(" cm)");

  delay(1000); 
}