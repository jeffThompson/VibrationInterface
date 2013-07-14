
void printLevel() {

  // iterate level
  for (int ty=0; ty<h; ty++) {
    for (int tx=0; tx<w; tx++) {

      // print player's position
      if (ty == y && tx == x) Serial.print("X");

      // level tiles
      else {
        if (level[ty][tx] == 0) Serial.print("#");  // wall
        else Serial.print(" ");                     // floor
      }
      Serial.print(" ");    // space between tiles
    }
    Serial.print("\n");     // new line at end of row
  }

  // separator between level printing
  Serial.print("\n\n");
}




