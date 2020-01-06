#include <Servo.h>
Servo myServo;
const int piezo = A0;
const int switchPin = 2;
const int yellowLed = 3;
const int greenLed = 4;
const int redLed = 5;
int knockVal;
int switchVal;
const int quiteKnock = 5;
const int loudKnock = 100;
boolean locked = false;
int numberOfknocks = 0;

void setup(){
  myServo.attach(9);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
  digitalWrite(greenLed, HIGH);
  myServo.write(0);
  //Serial.println("La caja esta abierta");
  }

void loop(){
  /*if(locked == false){
    switchVal = digitalRead(switchPin);
    if(switchVal == HIGH){
      locked = true;
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
      myServo.write(90);
      Serial.println("La caja esta cerrada");
      delay(1000);
    }
  }
  if(locked == true){
    knockVal = analogRead(piezo);
    if(numberOfknocks < 3 && knockVal > 0){
      if(checkForKnock(knockVal) == true){
        numberOfknocks++;
      }
        Serial.print(3-numberOfknocks);
        Serial.println("Moras golpes para ir");
      }
     if(numberOfknocks >= 3){
      locked = false;
      myServo.write(0);
      delay(20);
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, LOW);
      Serial.println("La caja está abierta");
     }
  }*/
  if(locked == false){
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
      myServo.write(90);
      Serial.println("La caja esta abierta");
      delay(1000);
      knockVal = analogRead(piezo);
    if(numberOfknocks < 3 && knockVal > 0){
      if(checkForKnock(knockVal) == true){
        numberOfknocks++;
      }
        Serial.print(3-numberOfknocks);
        Serial.println(" golpes faltan");
      }
     if(numberOfknocks >= 3){
      locked = true;
      myServo.write(0);
      delay(20);
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, LOW);
      Serial.println("La caja está cerrada");
     }
  }else{
    knockVal = analogRead(piezo);
    //Serial.println(knockVal);
    if(numberOfknocks < 3 && knockVal > 0){
      if(checkForKnock(knockVal) == false){
        numberOfknocks = numberOfknocks -1;
      }
        Serial.print(3-numberOfknocks);
        Serial.println(" golpes faltan");
      }
     if(numberOfknocks <= 0){
      locked = false;
      myServo.write(90);
      delay(20);
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
      Serial.println("La caja está abierta");
    }
  }
}
boolean checkForKnock(int value){
      if(value < loudKnock){
      digitalWrite(yellowLed, HIGH);
      delay(50);
      digitalWrite(yellowLed, LOW);
      Serial.print("Valor de golpe valido");
      Serial.println(value);
      return true;
      }
  else{
      Serial.print("Valor del golpe no válido");
      Serial.println(value);
      return false;
  }
}
