
void createLevel() {

  // set player location randomly
  x = random(0,w);
  y = random(0,h);
  
  // fill level with walls
  for (int ty=0; ty<h; ty++) {
    for (int tx=0; tx<w; tx++) {
      level[ty][tx] = 0;
    }
  } 

  // random walk to carve level
  int tx = x;
  int ty = y;
  for (int i=0; i<numSteps; i++) {
    switch(random(0,4)) {
    case 0:                  // up
      ty -= 1;
      if (ty < 0) ty = h-1;
      break;
    case 1:                  // right
      tx += 1;
      if (tx > w-1) tx = 0;
      break;
    case 2:                  // down
      ty += 1;
      if (ty > h-1) ty = 0;
      break;
    case 3:                  // left
      tx -= 1;
      if (tx < 0) tx = w-1;
      break;
    }
    
    // lighten as we traverse an already-traversed tile
    if (level[ty][tx] == 0) {
      level[ty][tx] = baseHeight;
    }
    else {
      level[ty][tx] += heightInc;
      level[ty][tx] = constrain(level[ty][tx], 0,255);
    }
  }
}



