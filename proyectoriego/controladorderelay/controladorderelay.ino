/*Para el relay primera pata positivo segunda va al arduino y tercera al negativo, la referencia es (- + s)*/
int switchState = 0;
int switchState2 = 0;
void setup() {
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
}

void loop() {
  digitalWrite (1, LOW);
  digitalWrite (2, LOW);
  digitalWrite (3, LOW);
  digitalWrite (4, LOW);
  digitalWrite (5, LOW);
  digitalWrite (6, LOW);
  digitalWrite (7, LOW);
}
