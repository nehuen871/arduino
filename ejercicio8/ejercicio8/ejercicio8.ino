const int switchPin = 0;
unsigned long previousTime = 0;
int swichState = 0;
int prevSwitchsState = 0;
int led = 2;
long interval = 600;

void setup() {
  // put your setup code here, to run once:
  for(int x = 2 ;x <8; x++){
    pinMode(x,OUTPUT);
  }
  pinMode(switchPin,INPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis();
  Serial.println(currentTime);
  if(currentTime - previousTime > interval){
    previousTime = currentTime;
    digitalWrite(led , HIGH);
    led++;
    if(led == 7){
      }
  }
  swichState = digitalRead(switchPin); 

  if(swichState != prevSwitchsState){
    for(int x = 2;x<8;x++){
      digitalWrite(x, LOW);
    }
    led = 2;
    previousTime = currentTime;
    prevSwitchsState = swichState;
  }
}
