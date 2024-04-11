#include <Servo.h>

Servo myservo;  // Create a Servo object to control a servo motor
int angle = 90;  // Initial angle of the servo motor

void setup() {
  Serial.begin(9600);  // Initialize serial communication at 9600 baud
  myservo.attach(9);   // Attach the servo motor to digital port 9
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();  // Read the command from the serial port
    Serial.println('received command = ', command);

    if (command == 'M') {
      // Command to move the servo motor to the left
      angle = constrain(angle + 90, 0, 180);
      myservo.write(angle);
      delay(5000);
      angle = constrain(angle - 90, 0, 180);
      myservo.write(angle);
    }
  }
}
