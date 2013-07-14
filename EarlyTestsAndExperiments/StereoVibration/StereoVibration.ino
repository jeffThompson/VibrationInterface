/*
STEREO VIBRATION
 Jeff Thompson | 2013 | www.jeffreythompson.org
 
 Interrupt example via:
 http://www.dave-auld.net/index.php?option=com_content&view=article&id=107:arduino-interrupts&catid=53:arduino-input-output-basics&Itemid=107
 
 */

// parameters
int pulseTime = 200;
boolean printDebug = false;   // print what's happening over serial

// pin setup
int motor1 = 9;
int motor2 = 10;
int potPin = 5;
int buttonPin = 2;

// other variables set in code
int pan = 0;
volatile boolean on = false;  // volatile stores in RAM for interrupt
int left, right;

void setup() {
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  attachInterrupt(0, toggleVibration, RISING);    // 0 = interrupt #, not pin #

  if (printDebug) {
    Serial.begin(9600);
  }
}

void loop() {

  // if on, vibrate according to joystick position
  if (on) {
    analogWrite(motor1, left);
    analogWrite(motor2, right);

    // pulse on/off
    delay(pulseTime);
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
    delay(pulseTime);
  }

  // if off, turn off motors
  else {
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
  }
}

// interrupt triggers vibration on/off
void toggleVibration() {
  on = !on;
}

// more natural panning for vibration
void equalPowerPanning(int* l, int* r, int pan) {
  int range = 256;
  *l = int(sin(pan * PI/(range*2)) * range);
  *l = constrain(*l, 0,255);
  *r = int(cos(pan * PI/(range*2)) * range);
  *r = constrain(*r, 0,255);

  if (printDebug) {
    Serial.print(*l);
    Serial.print(" L  |  ");
    Serial.print(*r);
    Serial.print(" R\n");
  }
}






