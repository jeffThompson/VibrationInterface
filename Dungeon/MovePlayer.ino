
void movePlayer() {

  // right
  if (horiz < lowThresh) {
    x += 1;
    if (x > w-1) x = 0;

    if (level[y][x] == 0) {
      hitWall(rightMotor);
      if (x-1 < 0) {
        x = w-1;
      }
      else {
        x -= 1;
      }
    }
    else {
      stepVibration(rightMotor);
      if (debug) printLevel();
    }
  }

  // left
  else if (horiz > highThresh) {
    x -= 1;
    if (x < 0) x = w-1;

    if (level[y][x] == 0) {
      hitWall(leftMotor);
      if (x+1 > w-1) {
        x = 0;
      }
      else {
        x += 1;
      }
    }
    else {
      stepVibration(leftMotor);
      if (debug) printLevel();
    }
  }

  // up
  if (vert > highThresh) {
    y -= 1;
    if (y < 0) y = h-1;

    if (level[y][x] == 0) {
      hitWall(upMotor);
      if (y+1 > h-1) {
        y = 0;
      }
      else {
        y += 1;
      }
    }
    else {
      stepVibration(upMotor);
      if (debug) printLevel();
    }
  }

  // down
  else if (vert < lowThresh) {
    y += 1;
    if (y > h-1) y = 0;

    if (level[y][x] == 0) {
      hitWall(downMotor);
      if (y-1 < 0) {
        y = h-1;
      }
      else {
        y -= 1;
      }
    }
    else {
      stepVibration(downMotor);
      if (debug) printLevel();
    }
  }
}




