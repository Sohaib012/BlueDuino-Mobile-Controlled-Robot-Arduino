#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2, 3); // RX, TX pins for Bluetooth

int motor1Pin1 = 8; // Motor 1 control pin 1
int motor1Pin2 = 9; // Motor 1 control pin 2
int motor2Pin1 = 10; // Motor 2 control pin 1
int motor2Pin2 = 11; // Motor 2 control pin 2
// #define enA 7
// #define enB 6

// int M1_Speed = 80; // speed of motor 1 
// int M2_Speed = 80; // speed of motor 2
// int LeftRotationSpeed = 250; // Left Rotation Speed
// int RightRotationSpeed = 250; // Right Rotation Speed


void setup() {
  // Define motor control pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  // Set up communication with Bluetooth module
  bluetooth.begin(9600);
}

void loop() {
  if (bluetooth.available() > 0) {
    char command = bluetooth.read();
    
    
    // Perform actions based on the received command
    switch (command) {
      case 'F':
        //for(int i=0;i<1000;i++){
          moveForward();
         // delay(100);}
        break;
      case 'B':
        //for(int i=0;i<1000;i++)
          moveBackward();
        break;
      case 'L':
       // for(int i=0;i<1000;i++)
          turnLeft();
        break;
      case 'R':
        //for(int i=0;i<1000;i++)
          turnRight();
        break;
      case 'S':
        //for(int i=0;i<1000;i++)
          stopMotors();
        break;
    }
    
  }
}

void moveForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);

  //analogWrite(enA, M1_Speed);
  //analogWrite(enB, M2_Speed);
}

void moveBackward() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);

 // analogWrite(enA, M1_Speed);
  //      analogWrite(enB, M2_Speed);

}

void turnLeft() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);

   //analogWrite(enA, LeftRotationSpeed);
     //   analogWrite(enB, RightRotationSpeed);
}

void turnRight() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);

  //// analogWrite(enA, LeftRotationSpeed);
   //     analogWrite(enB, RightRotationSpeed);
}

void stopMotors() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}
