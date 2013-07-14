/*
FOUR-CHANNEL VIBRATION
 Jeff Thompson | 2013 | www.jeffreythompson.org
 
 */

boolean printDebug = true;

int upMotor = 5;
int rightMotor = 6;
int downMotor = 10;
int leftMotor = 9;

int buttonPin = 7;

int horizPot = A0;
int vertPot = A1;

int panHoriz, panVert;
int up, right, down, left;

void setup() {
  pinMode(upMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
  pinMode(downMotor, OUTPUT);
  pinMode(leftMotor, OUTPUT);
  pinMode(buttonPin, INPUT);

  if (printDebug) {
    Serial.begin(9600);
  }
}

void loop() {
  if (printDebug) {
    Serial.print(digitalRead(buttonPin));
    Serial.print(":   ");
  }
  
  panHoriz = map(analogRead(horizPot), 0,1023, 255,0);
  panVert = map(analogRead(vertPot), 0,1023, 255,0);

  fourChannelPanning(&up, &right, &down, &left, panHoriz, panVert);
  analogWrite(upMotor, up);
  analogWrite(rightMotor, right);
  analogWrite(downMotor, down);
  analogWrite(leftMotor, left);
}

void fourChannelPanning(int* u, int* r, int* d, int* l, int panHoriz, int panVert) {
  int range = 256;
  *l = int(sin(panHoriz * PI/(range*2)) * range);
  *r = int(cos(panHoriz * PI/(range*2)) * range);
  *u = int(sin(panVert * PI/(range*2)) * range);
  *d = int(cos(panVert * PI/(range*2)) * range);

  if (printDebug) {
    Serial.print(*u);
    Serial.print(" U  |  ");
    Serial.print(*d);
    Serial.print(" D  |  ");
    Serial.print(*r);
    Serial.print(" R  |  ");
    Serial.print(*l);
    Serial.print(" L\n");
  }
}

/*int dist(int x, int y) {
 int dx = x - centerX;
 int dy = y - centerY;
 return sqrt(dx*dx + dy*dy);
 }*/

