
void playPattern() {
  
  for (int i=0; i<level; i++) {
    switch (call[i]) {
    case 0:
      vibrate(upMotor);
      if (debug) Serial.print("U  ");      
      break;
    case 1:
      vibrate(rightMotor);
      if (debug) Serial.print("R  ");
      break;
    case 2:
      vibrate(downMotor);
      if (debug) Serial.print("D  ");
      break;
    case 3:
      vibrate(leftMotor);
      if (debug) Serial.print("L  ");
      break;
    }
  }
  
  if (debug) Serial.println();
}


