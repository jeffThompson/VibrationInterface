
void printLevel() {

  // clear screen between level printings, a hack that doesn't 
  // really work in the Serial Monitor but works great in the
  // 'ReadLevelWithPython.py' script
  // Via: http://stackoverflow.com/a/2084521
  Serial.print(char(27));
  Serial.println("[2J");

  // iterate nearby tiles
  for (int ty=y-visionDistance; ty<=y+visionDistance; ty++) {
    for (int tx=x-visionDistance; tx<=x+visionDistance; tx++) {

      // print player's position
      if (ty == y && tx == x) {
        Serial.print("X");
      }

      // level tiles
      else {
        if (level[ty][tx] == 0) Serial.print("`");
        else Serial.print("+");
      }
      Serial.print("  ");  // space between tiles
    }
    Serial.print("\n");    // newline between rows
  }

  // iterate entire level
  /*for (int ty=0; ty<h; ty++) {
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
   Serial.print("\n\n");*/
}

