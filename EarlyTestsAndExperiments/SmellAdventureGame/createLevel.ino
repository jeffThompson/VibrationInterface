
void createLevel() { 
  for (int y=0; y<height; y++) {
    for (int x=0; x<width; x++) {
      level[y][x] = random(0,5);
    }
  }
}
