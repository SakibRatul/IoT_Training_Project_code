/*This code generates a PWM (Pulse Width Modulation) signal on pin 11 of the Arduino, 
causing an LED or other connected device to gradually brighten and then dim in a smooth, fading manner.*/

int pwm = 11;

void setup() {
  pinMode(pwm, OUTPUT);
}

void loop() {
  // Increasing the intensity
  for (int i = 0; i <= 255; i++) {
    analogWrite(pwm, i);
    delay(10);  // Adjust delay as needed for smooth transition
  }
  
  // Decreasing the intensity
  for (int i = 255; i >= 0; i--) {
    analogWrite(pwm, i);
    delay(10);  // Adjust delay as needed for smooth transition
  }
}