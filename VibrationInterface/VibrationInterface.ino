
/*
VIBRATION INTERFACE
 Jeff Thompson | 2013 | www.jeffreythompson.org
 
 Created with generous support from Harvestworks' Cultural Innovation Fund program.
 
 For EagleCAD schematic/PCB files, lasercutting part files, and a BOM, see the 
 'LasercutPartsCADFiles' folder.
 
 TO DO - PROGRAMMING:
 + is it mesa where you're feeling the edges of the abyss? touch them and die, so feel around?
 + instructions how?
 + test level sizes and performance
 + can serial debug be a secret that launches when plugged in? can it launch the terminal?
 + set tile height? hook up LED

 */


const boolean debug = true;    // debug over serial USB?

// pins
const int horizPin = A1;       // horizontal joystick
const int vertPin = A0;        // vertical
const int buttonPin = 7;       // button from joystick
const int ledPin = 11;         // LED (must be a PWM pin)

const int upMotor = 10;        // motor pins
const int rightMotor = 5;
const int downMotor = 6;
const int leftMotor = 9;

// threshold for joystick
int lowThresh = 512-450;       // 512 = 1024/2
int highThresh = 512+450;

// level array ( set dynamically in setup)
const int w = 28;               // level dimensions
const int h = 28;
const int numSteps = 80;        // # of steps to create the level
const int baseHeight = 20;      // starting tile height
const int heightInc = 2;        // +inc when traversing a tile
int level[h][w];                // the level itself!

// vibration variables
int neighborVibeTime = 250;    // time motors are on in ms 
int neighborOffTime = 40;      // time off between directions
int wallVibe[] = {             // wall hit pattern
  40, 30, 80, 30, 40 };

// other variables
int x,y;                                // current position in the level
int horiz, prevHoriz, vert, prevVert;   // joystick readings
int buttonState, prevButtonState;       // button reading

void setup() {

  createLevel();
  resetPlayerLocation();

  // setup button input
  pinMode(buttonPin, INPUT);
  prevButtonState = LOW;

  // setup motor and LED pins
  pinMode(upMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
  pinMode(downMotor, OUTPUT);
  pinMode(leftMotor, OUTPUT);
  pinMode(ledPin, OUTPUT);

  // if specified, start serial connection for debugging
  if (debug) {
    Serial.begin(9600);
    printLevel();
  }
}

void loop() {

  // read joystick values
  readJoystick();

  // read button
  buttonState = digitalRead(buttonPin);
  if (buttonState != prevButtonState && buttonState == HIGH) {
    vibrateNeighbors();
  }
  prevButtonState = buttonState;

  // LED to current terrain height
  analogWrite(ledPin, map(level[y][x], 0,255, 0,50));
}



