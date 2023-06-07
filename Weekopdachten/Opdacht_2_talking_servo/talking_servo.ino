#include <Servo.h>

Servo myservo0;  // create servo object to control a servo
Servo myservo1;  // create servo object to control a servo

int potpin   = A0;    // analog pin used to connect the potentiometer
int val      = -1;        // variable to read the value from the analog pin
int prev_val = -1;
int writen   = 0;

int buttonPin = 7;
int pwmPinServo0 = 8;
int pwmPinServo1 = 9;

void setup() {
  pinMode(buttonPin,INPUT);
  myservo0.attach(pwmPinServo0);  // attaches the servo on pin 9 to the servo object
  myservo1.attach(pwmPinServo1);  // attaches the servo on pin 8 to the servo object
  myservo1.write(writen);
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it for use with the servo (value between 0 and 180)
  myservo0.write(val);                 // sets the servo position according to the scaled value
  delay(50);                           // waits for the servo to get there
  if(digitalRead(buttonPin)) {
    if(writen < 180){
      writen += 4;
      myservo1.write(writen);
      delay(50);
    }
  }
  else {
    if(writen > 0){
      writen -= 4;
      myservo1.write(writen);
      delay(50);
    }
  }
  
}
