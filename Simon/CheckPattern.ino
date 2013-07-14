
void checkPattern() {

  // stop recording (and restart when joystick moves again)
  recording = false;

  // check to see if the response matches the pattern
  boolean correct = true;
  for (int i=0; i<level; i++) {
    if (response[i] != call[i]) {
      correct = false;
      break;
    }
  }

  // got it right? :)
  if (correct) {
    if (debug) Serial.println("\nCORRECT!");

    if (level < maxLevel) {
      level++;                                          // increase the level
      if (appendToPattern) call[level] = random(0,4);   // append to existing pattern
      else createPattern();                             // or create a new pattern
      playPattern();                                    // and play it back so we can hear it
    }
    else {
      setup();                                          // got to max level? you win! (and restart)
    }
  }

  // got it wrong :(
  else {
    if (debug) Serial.println("\nWRONG! :(");
    grumbleVibration();                          // let us know we got it wrong
    playPattern();                               // not right, play it again
  }
}


