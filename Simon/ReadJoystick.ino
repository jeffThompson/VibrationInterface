
void readJoystick() {

  // read joystick
  prevHoriz = horiz;
  prevVert = vert;
  horiz = analogRead(horizPin);
  vert = analogRead(vertPin);

  // if previous reading was in the center (ie: not held in a direction)
  if (prevHoriz > lowThresh && prevHoriz < highThresh && prevVert > lowThresh && prevVert < highThresh) {

    // right
    if (horiz < lowThresh) {
      checkIfRecording();                     // if not already recording, reset and start
      if (debug) Serial.print("  R");         // print direction
      response[index] = 1;                    // set response to direction # (1 = right, 2 = down, etc)
      index++;                                // increment index
      vibrate(rightMotor);                    // and vibrate so we know the direction has been saved
    }

    // left
    else if (horiz > highThresh) {
      checkIfRecording();
      if (debug) Serial.print("  L");
      response[index] = 3;
      index++;
      vibrate(leftMotor);
    }

    // up
    if (vert > highThresh) {
      checkIfRecording();
      if (debug) Serial.print("  U");
      response[index] = 0;
      index++;
      vibrate(upMotor);
    }

    // down
    else if (vert < lowThresh) {
      checkIfRecording();
      if (debug) Serial.print("  D");
      response[index] = 2;
      index++;
      vibrate(downMotor);
    }
  }
}

void checkIfRecording() {
  if (!recording) {
    recording = true;                                // changes button to 'confirm' as opposed to playback
    index = 0;                                       // reset index to store response in
    if (debug) Serial.println("\nRecording...");     // let us know
  }
}







