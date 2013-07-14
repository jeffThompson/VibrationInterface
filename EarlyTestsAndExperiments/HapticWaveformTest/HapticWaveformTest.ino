/*
HAPTIC WAVEFORM TEST
 Jeff Thompson | 2013 | www.jeffreythompson.org
 
 Plays
 
 */

// array to define the waveform (off, on, off, etc)
int waveform[] = { 
  0, 45, 38, 47, 44, 41, 60, 51, 52, 34 };
int outputPin = 9;

// other variables for waveform control
boolean playing = false;
boolean loopPlayback = false;
int index = 0;
long prevMillis = 0;
int waveformLen;

// button to trigger waveform
int buttonPin = 2;
int prevState = LOW;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(outputPin, OUTPUT);
  waveformLen = sizeof(waveform)/sizeof(int);  // get # of elements in the array
}

void loop() {

  int buttonState = digitalRead(buttonPin);
  if (buttonState != prevState) {
    if (buttonState == HIGH) {
      index = 0;
      playing = true;
    }
    else {
      playing = false;
    }
  }
  prevState = buttonState;

  if (playing) {
    playWaveform();
  } 
}

void playWaveform() {
  if (millis() > prevMillis + waveform[index]) {
    if (index % 2 == 0) {
      digitalWrite(outputPin, HIGH);
    }
    else {
      digitalWrite(outputPin, LOW);
    }
    prevMillis = millis();
    
    index += 1;
    if (index == waveformLen) {
      if (loopPlayback == false) {
        digitalWrite(outputPin, LOW);  // turn off (safety)
        playing = false;
      }
      index = 0;
    }
  } 
}


