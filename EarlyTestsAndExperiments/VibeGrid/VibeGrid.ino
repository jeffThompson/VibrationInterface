
int minLED = 0;
int maxLED = 50;

// right
int rightMotor = 6;
int rightButton = 2;
int rightLED = 10;

// middle
int middleMotor = 11;

// left
int leftMotor = 9;
int leftButton = 3;
int leftLED = 11;

// level
const int numPx = 20;
int level[numPx];
boolean playback = false;

// debug
boolean printDebug = true;


void setup() {
  if (printDebug) {
    Serial.begin(9600);
  }

  pinMode(rightMotor, OUTPUT);
  pinMode(middleMotor, OUTPUT);
  pinMode(leftMotor, OUTPUT);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(leftButton, INPUT_PULLUP);
  pinMode(rightLED, OUTPUT);  
  pinMode(leftLED, OUTPUT);

  for (int i=0; i<numPx; i++) {
    if (random(100) > 50 || i == 0 || i == numPx-1) {
      level[i] = 1;
    }
    else {
      level[i] = 0;
    }
  }
}

void loop() {

  if (digitalRead(leftButton) == LOW && digitalRead(rightButton) == LOW) {
    for (int i=0; i<numPx; i++) {

      if (printDebug) {
        Serial.print(level[i]);
        Serial.print("  ");
      }

      if (level[i] == 0) {
        digitalWrite(leftMotor, LOW);
        digitalWrite(leftLED, LOW);
        digitalWrite(rightMotor, LOW);
        digitalWrite(rightLED, LOW);
      }
      else {
        int pan = map(i, 0,numPx, 255,50);
        int fade = map(i, 0,numPx, maxLED,minLED);
        
        // left
        analogWrite(leftMotor, pan);
        analogWrite(leftLED, fade);
        
        // middle
        if (pan < 127) {
          analogWrite(middleMotor, map(pan, 0,126, 50,255));
        }
        else {
          analogWrite(middleMotor, map(pan, 127,255, 255,50));
        }
        
        // right
        analogWrite(rightMotor, map(pan, 255,50, 50,255));
        analogWrite(rightLED, map(fade, maxLED,minLED, minLED,maxLED));
      }
      delay(100);
    }

    Serial.println("\n");
    digitalWrite(leftMotor, LOW);
    digitalWrite(leftLED, LOW);
    digitalWrite(rightMotor, LOW);
    digitalWrite(rightLED, LOW);
  }
}

