/*Para el relay primera pata positivo segunda va al arduino y tercera al negativo, la referencia es (- + s)*/
void setup() {
  // put your setup code here, to run once:
    pinMode(0, OUTPUT);
}

void loop() {
    digitalWrite (0,LOW);
}
