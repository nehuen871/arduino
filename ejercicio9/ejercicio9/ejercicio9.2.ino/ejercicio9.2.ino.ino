
const int motorPin = 9;
const int potPin = A0;
int potVal;
int angle;

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  potVal = analogRead(potPin);
  angle = map(potVal,0,1023,0,255);
  analogWrite(motorPin, angle);
}
