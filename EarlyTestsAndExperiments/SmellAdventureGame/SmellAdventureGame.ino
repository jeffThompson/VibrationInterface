
#include <Valve.h>
#include <Servo.h>    // required for the Valve class

/*
SMELL ADVENTURE GAME
 Jeff Thompson | 2013 | www.jeffreythompson.org
 
 Valves require the Arduino Servo library!
 
 C++ classes based on this tutorial:
 www.cplusplus.com/doc/tutorial/classes
 
 */

const int width = 20;
const int height = 20;

int level[height][width];
Valve v1, v2;

void setup() {
  createLevel();

  v1.initialize(7, 18, 60, 10);  // pin, closed position, open position, speed (ms)
  v2.initialize(8, 18, 60, 10);
}

void loop() {
  v1.open();
  v2.open();
  
  delay(1000);
  
  v1.close();
  v2.close();
  
  delay(1000);
}
