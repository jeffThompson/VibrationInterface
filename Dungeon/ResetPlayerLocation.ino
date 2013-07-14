
void resetPlayerLocation() {

  // since the regular 'random' function will repeat the same #, we
  // read an analog pin as a seed #
  randomSeed(analogRead(A5));
  x = random(0,w);
  y = random(0,h);

  // don't respawn into a wall!
  while(level[y][x] == 0) {
    x = random(0,w);
    y = random(0,h);
  }

  if (debug) {
    Serial.print("Player starting position: ");
    Serial.print(x);
    Serial.print(", ");
    Serial.print(y);
    Serial.print("\n\n");
  }
}  


