//test git
int switchState = 0;
int switchState2 = 0;
int D=100;

void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(2, INPUT);
  pinMode(6, INPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);
  switchState2 = digitalRead(6);
  if (switchState == LOW) {
    // el botónno estápulsado
    digitalWrite (3, LOW); // LED verde
    digitalWrite (4, LOW); // LED rojos
    digitalWrite (5, LOW); // LED rojos
  }else{ //el botón esta úlsado
    digitalWrite (3, LOW);
    digitalWrite (4, LOW);
    digitalWrite (5, LOW);
    delay(D); //espera un cuarto de segundo //permuta los LEDs
    for (int i=0; i <= 10; i++){
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      delay(D);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      delay(D);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      delay(D);
    }
  }

  if (switchState2 == LOW) {
    // el botónno estápulsado
    digitalWrite (3, LOW); // LED verde
    digitalWrite (4, LOW); // LED rojos
    digitalWrite (5, LOW); // LED rojos
  }else{ //el botón esta úlsado
    digitalWrite (3, LOW);
    digitalWrite (4, LOW);
    digitalWrite (5, LOW);
    delay(D); //espera un cuarto de segundo //permuta los LEDs
    for (int i=0; i <= 10; i++){
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      delay(D);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      delay(D);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      delay(D);
    }
  }
}
