
/*
SIMON
 Jeff Thompson | 2013 | www.jeffreythompson.org
 
 A Simon-like game for a 4-direction vibration interface.
 
 Created with generous support from Harvestworks' Cultural Innovation Fund program.
 
 For EagleCAD schematic/PCB files, lasercutting part files, and a BOM, see the 
 'LasercutPartsCADFiles' folder. 
 */

const boolean debug = true;       // debug over serial USB?

// pins
const int horizPin = A1;          // horizontal joystick
const int vertPin = A0;           // vertical
const int buttonPin = 7;          // button from joystick
const int ledPin = 11;            // LED (must be a PWM pin)

const int upMotor = 10;           // motor pins
const int rightMotor = 5;
const int downMotor = 6;
const int leftMotor = 9;

// threshold for joystick
int lowThresh = 512-450;          // 512 = 1024/2
int highThresh = 512+450;

// vibration
const int playbackSpeed = 250;    // duration vibrating for each direction (ms)
const int offTime = 50;           // space between directions
const int ledBrightness = 10;     // brightness for playback (0 = off, 255 = max brightness)

// pattern variables
boolean appendToPattern = true;   // true = add to existing pattern, false = new pattern each level
int level = 4;                    // initial # of items in pattern
const int maxLevel = 100;         // max # of items
int call[maxLevel];               // array to store pattern to match
int response[maxLevel];           // array to store input
int index;                        // position in array for storing/reading

// other variables
int horiz, prevHoriz, vert, prevVert;   // joystick readings
int buttonState, prevButtonState;       // button reading
boolean recording = false;              // flag for reading joystick input

void setup() {

  // if specified, start serial connection for debugging, print some details
  if (debug) {
    Serial.begin(9600);
    Serial.println(); 
    Serial.println("Game:          Simon");
    Serial.println("Made by:       Jeff Thompson");
    Serial.println("More info:     www.jeffreythompson.org");
    Serial.print("Pattern length:  ");
    Serial.println(level);
    Serial.print("Pattern mode:    ");
    if (appendToPattern) Serial.print("append to previous");
    else Serial.print("new each level");
    Serial.println("\n");
  }

  // setup button input
  pinMode(buttonPin, INPUT);
  prevButtonState = LOW;

  // setup motor and LED pins
  pinMode(upMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
  pinMode(downMotor, OUTPUT);
  pinMode(leftMotor, OUTPUT);
  pinMode(ledPin, OUTPUT);

  // create pattern!
  createPattern();
  playPattern();
  
  // reset variables (if player has beat the game)
  level = 4;   // reset length of level
  index = 0;
}

void loop() {
  
  // check for movement of joystick
  readJoystick();

  // read button
  buttonState = digitalRead(buttonPin);
  if (buttonState != prevButtonState && buttonState == HIGH) {
    if (!recording) playPattern();
    else checkPattern();
  }
  prevButtonState = buttonState;
}


