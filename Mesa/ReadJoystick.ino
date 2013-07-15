
void readJoystick() {

  // read joystick
  prevHoriz = horiz;
  prevVert = vert;
  horiz = analogRead(horizPin);
  vert = analogRead(vertPin);

  // requires reset to center to trigger movement
  if (prevHoriz > lowThresh && prevHoriz < highThresh && prevVert > lowThresh && prevVert < highThresh) {
    movePlayer();
  }

  // alternative if statement that allows continuous movement
  // if ((prevHoriz > lowThresh && prevHoriz < highThresh) || (prevVert > lowThresh && prevVert < highThresh)) {
}
