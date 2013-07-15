
void vibrateNeighbors() {

  delay(60);     // slight delay = moment after joystick is pressed to feel vibe start better
  int tx, ty;    // temp variables for neighboring tiles

  // up
  ty = y-1;
  if (tx < 0) ty = h-1;
  if (level[ty][x] != 0) neighborVibe(upMotor);

  // right
  tx = x+1;
  if (tx > w-1) tx = 0;
  if (level[y][tx] != 0) neighborVibe(rightMotor);

  // down
  ty = y+1;
  if (ty > h-1) ty = 0;
  if (level[ty][x] != 0) neighborVibe(downMotor);

  // left
  tx = x-1;
  if (tx < 0) tx = w-1;
  if (level[y][tx] != 0) neighborVibe(leftMotor);
}

void neighborVibe(int whichMotor) {
  digitalWrite(whichMotor, HIGH);
  delay(neighborVibeTime);
  digitalWrite(whichMotor, LOW);
  delay(neighborOffTime);
}
