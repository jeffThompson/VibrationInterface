#include <Servo.h>

/*
SMELL VALVE CONTROL TEST
 Jeff Thompson | 2013 | www.jeffreythompson.org
 
 Variable-speed for a servo-powered valve, designed
 for a smell-based videogame. 
 */

int closedPos = 18;   // angle when valve is close
int openPos = 60;     // open angle
int motorSpeed = 10;  // speed in ms

int servoPin = 7;     // pin servo is connected to
Servo s;              // servo object

void setup() {
  s.attach(servoPin); // initialize servo
  s.write(closedPos); // start at closed position
  delay(500);         // wait a bit
}

void loop() {

  // open valve
  for (int pos=closedPos; pos<=openPos; pos++) {
    s.write(pos);
    delay(motorSpeed);
  }

  // wait a moment
  delay(1000);

  // close valve
  for (int pos=openPos; pos>=closedPos; pos-=1) {
    s.write(pos);
    delay(motorSpeed);
  }

  // wait again
  delay(1000);
}


