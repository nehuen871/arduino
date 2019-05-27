const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;
const int directionSwichPin = 4;
const int onOffSwitchStateSwitchPin = 5;
const int potPin = A0;
int onOffSwitchState = 0;
int previousOnOffSwitchSate = 0;
int directionSwitchState = 0;
int previousdirectionSwitchState = 0;
int motorEnabled = 0;
int motorSpeed = 0;
int motroDirection = 1;

void setup() {
  pinMode(directionSwichPin, INPUT);
  pinMode(onOffSwitchStateSwitchPin, INPUT);
  pinMode(controlPin1,OUTPUT);
  pinMode(controlPin2,OUTPUT);
  pinMode(enablePin,OUTPUT);
  digitalWrite(enablePin,LOW);
}

void loop() {
  onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
  delay(1);
  directionSwitchState = digitalRead(directionSwichPin);
  motorSpeed = analogRead(potPin)/4;

  if(onOffSwitchState != previousOnOffSwitchSate){
    if(onOffSwitchState == HIGH){
      motorEnabled = !motorEnabled;
    }
  }

  if(directionSwitchState != previousdirectionSwitchState){
    if(directionSwitchState == HIGH){
      motroDirection = !motroDirection;
    }
  
  }

  if(motroDirection == 1){
    digitalWrite(controlPin1,HIGH);
    digitalWrite(controlPin2,LOW);
  }else{
    digitalWrite(controlPin1,LOW);
    digitalWrite(controlPin2,HIGH);
  }

  if(motorEnabled == 1){
    analogWrite(enablePin,motorSpeed);
  }else{
    analogWrite(enablePin,0);
  }

  previousdirectionSwitchState = directionSwitchState;
  previousOnOffSwitchSate = onOffSwitchState;
  
}
