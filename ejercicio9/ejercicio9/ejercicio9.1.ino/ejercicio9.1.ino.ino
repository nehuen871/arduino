
const int switchPin = 2;
const int motorPin = A1;
//const int motorPin = 9;
int voltaje;
int potPin = A0;
int potVal;
int velocidad;

void setup() {
     pinMode(motorPin, OUTPUT);
     pinMode(switchPin, INPUT);
     Serial.begin(9600);
}

void loop() {
     potVal = analogRead(potPin);
     Serial.print(" potVal: ");
     Serial.print(potVal);
     voltaje = map(potVal, 0, 1020,0,100);
     Serial.print(" voltaje: ");
     Serial.println(voltaje);
     analogWrite(motorPin, voltaje);
}
