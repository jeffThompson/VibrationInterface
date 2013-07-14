
void createPattern() {

  // since the regular 'random' function will repeat the same #s 
  // each time we make a new pattern, we read an analog pin as a seed
  randomSeed(analogRead(A5));    // read an unconnected pin

  for (int i=0; i<level; i++) {
    call[i] = random(0,4);       // random (u/r/d/l)
  }
}


