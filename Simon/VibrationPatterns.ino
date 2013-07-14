
// short pulse of motor
void vibrate(int motorPin) {
  digitalWrite(motorPin, HIGH);
  analogWrite(ledPin, ledBrightness);
  delay(playbackSpeed);
  
  digitalWrite(motorPin, LOW);
  digitalWrite(ledPin, LOW);
  delay(offTime);
}

// error pattern when input is wrong
void grumbleVibration() {

  for (int i=0; i<4; i++) {
    digitalWrite(upMotor, HIGH);
    digitalWrite(rightMotor, HIGH);
    digitalWrite(downMotor, HIGH);
    digitalWrite(leftMotor, HIGH);
    analogWrite(ledPin, ledBrightness);
    delay(50);

    digitalWrite(upMotor, LOW);
    digitalWrite(rightMotor, LOW);
    digitalWrite(downMotor, LOW);
    digitalWrite(leftMotor, LOW);
    digitalWrite(ledPin, LOW);
    delay(50);
  }
  
  // wait a moment before replaying pattern
  delay(200);
}

