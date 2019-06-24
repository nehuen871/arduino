int switchState = 0;
int switchState2 = 0;
void setup()
{
   Serial.begin(57600);
   pinMode(2, INPUT);
   pinMode(3, OUTPUT);
}
void loop()
{
  Serial.print("A0 La humedad es del ");
  Serial.println(analogRead(0));
  Serial.print("A1 La humedad es del ");
  Serial.println(analogRead(1));
  Serial.print("A2 La humedad es del ");
  Serial.println(analogRead(2));
  if(analogRead(0) > 300){
    abrirValvulaDeAgua();
  }else{
    cerraValvulaDeAgua();
  }
  delay(1000);
}

int abrirValvulaDeAgua() {
  switchState = digitalRead(2);
  digitalWrite (3, HIGH);
  return 1;
}

int cerraValvulaDeAgua() {
  switchState = digitalRead(2);
  digitalWrite (3, LOW);
  return 0;
}
