
// normal step from tile to tile
void stepVibration(int motorPin) {
  digitalWrite(motorPin, HIGH);
  delay(150);
  digitalWrite(motorPin, LOW);
}

// fall off edge
void fallVibration(int motorPin) {
  
  if (debug) Serial.println("Faaaaallllinnngggg...!");
  
  for (int i=255; i>=60; i-=1) {
    analogWrite(upMotor, i);
    analogWrite(rightMotor, i);
    analogWrite(downMotor, i);
    analogWrite(leftMotor, i);
    analogWrite(ledPin, i);
    delay(20);
  }
  digitalWrite(upMotor, LOW);
  digitalWrite(rightMotor, LOW);
  digitalWrite(downMotor, LOW);
  digitalWrite(leftMotor, LOW);
  digitalWrite(ledPin, LOW);
  delay(250);

  // thump!
  digitalWrite(upMotor, HIGH);
  digitalWrite(rightMotor, HIGH);
  digitalWrite(downMotor, HIGH);
  digitalWrite(leftMotor, HIGH);
  digitalWrite(ledPin, HIGH);
  delay(150);

  digitalWrite(upMotor, LOW);
  digitalWrite(rightMotor, LOW);
  digitalWrite(downMotor, LOW);
  digitalWrite(leftMotor, LOW);
  digitalWrite(ledPin, LOW);
  delay(50);

  analogWrite(upMotor, 100);
  analogWrite(rightMotor, 100);
  analogWrite(downMotor, 100);
  analogWrite(leftMotor, 100);
  analogWrite(ledPin, 100);
  delay(150);

  digitalWrite(upMotor, LOW);
  digitalWrite(rightMotor, LOW);
  digitalWrite(downMotor, LOW);
  digitalWrite(leftMotor, LOW);
  digitalWrite(ledPin, LOW);
}

// hit walls (not used in this version)
void hitWall(int motorPin) {
  for (int i=0; i<5; i++) {
    if (i % 2 == 0) {
      digitalWrite(motorPin, HIGH);
      delay(wallVibe[i]);
    }
    else {
      digitalWrite(motorPin, LOW);
      delay(wallVibe[i]);
    }
  }
  digitalWrite(motorPin, LOW);
}


