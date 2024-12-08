#include <Servo.h>

Servo myServo; 
int servoPin = 9;  // Servo signal pin

void setup() {
  myServo.attach(servoPin);  
  Serial.begin(9600);  
}

void loop() {
  if (Serial.available() > 0) {
    int angle = Serial.parseInt();  
    if (angle >= 0 && angle <= 180) {
      myServo.write(angle);  
      Serial.print("Servo moved to angle: ");
      Serial.println(angle);  
    } else {
      Serial.println("Invalid angle. Please enter a value between 0 and 180.");
    }
  }
}
