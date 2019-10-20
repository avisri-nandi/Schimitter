#include <ServoTimer2.h>

ServoTimer2 servo;
int value = 0;
int c_value = 750;

void setup() {
  Serial.begin(9600);
  servo.attach(9); // Attach Servo to Pin 9
}

void loop() {
  
  Serial.println("Enter a Degree Value : - ");
  while(value = Serial.read()) {
    if(value > 180 || value < 0) {
      Serial.println("Error! Enter value withing 0 - 180 Range");
      break;
    } else {
      c_value = map(value,0,180,750,2250);
      Serial.print("Sending ");
      Serial.print(value);
      Serial.print(" Degrees | ");
      Serial.print(c_value);
      Serial.println(" to the servo.\n");
      servo.write(c_value);
    }
  }
}