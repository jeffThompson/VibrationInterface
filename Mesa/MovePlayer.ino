
void movePlayer() {

  // right
  if (horiz < lowThresh) {
    x += 1;
    if (x > w-1) x = 0;

    if (level[y][x] == 0) {
      fallVibration(rightMotor);
      setup();
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
      fallVibration(leftMotor);
      setup();
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
      fallVibration(upMotor);
      setup();
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
      fallVibration(downMotor);
      setup();
    }
    else {
      stepVibration(downMotor);
      if (debug) printLevel();
    }
  }
}


