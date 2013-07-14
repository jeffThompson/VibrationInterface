
// normal step from tile to tile
void stepVibration(int motorPin) {
  digitalWrite(motorPin, HIGH);
  delay(150);
  digitalWrite(motorPin, LOW);
}

// hit walls
void hitWall(int motorPin) {
  //digitalWrite(motorPin, HIGH);
  //delay(120);
  //digitalWrite(motorPin, LOW);

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
