
/*
LEVEL GENERATION TEST
 Jeff Thompson | 2013 | www.jeffreythompson.org
 
 A test to see how long it takes to generate levels of
 various sizes and depths.
 
 Statistics running on my Uno, from reset to 
 level finished being created:
   
   # steps   w      h      time (ms)
   1000      10     10     145
   2000      10     10     290
   1000      20     20     145
   2000      20     20     289
   1000      28     28     145
   2000      28     28     289
 
 (seems like a 2d array larger than 28x28 will break everything and crash)
 
 Created with generous support from Harvestworks' Cultural Innovation Fund program.
 
 */

const int numSteps = 1000;   // depth of random walk
const int w = 28;            // array dimensions
const int h = 28;
int level[h][w];             // array itself


void setup() {

  // set start time
  long startTime = millis();
  Serial.begin(9600);

  // give us some details
  Serial.print("\n- - - - - - - -\nLevel dims:   ");
  Serial.print(w);
  Serial.print(" x ");
  Serial.print(h);
  Serial.print("\n");

  Serial.print("# of steps:   ");
  Serial.print(numSteps);
  Serial.print("\n");

  // fill level
  for (int ty=0; ty<h; ty++) {
    for (int tx=0; tx<w; tx++) {
      level[ty][tx] = 0;
    }
  }

  // random walk to carve level
  int tx = random(255);
  int ty = random(255);
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
    level[ty][tx] = 1;       // update level
  }

  // print the results
  long totalTime = millis() - startTime;
  Serial.print("Loading time: ");
  Serial.print(totalTime);
  Serial.print(" ms");
}


void loop() {
  // nothing here!
}




