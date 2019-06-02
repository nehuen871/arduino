/*Para el relay primera pata positivo segunda va al arduino y tercera al negativo, la referencia es (- + s)*/
int switchState = 0;
int switchState2 = 0;
void setup() {
  // put your setup code here, to run once:
    pinMode(2, INPUT);
    pinMode(3, OUTPUT);
}

void loop() {
  switchState = digitalRead(2);
  if (switchState == HIGH) {
    digitalWrite (3, LOW);
  }else{
    digitalWrite (3, HIGH);
  } 
  
}
