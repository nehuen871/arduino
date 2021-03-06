#include <RTClib.h>   // incluye libreria para el manejo del modulo RTC
RTC_DS3231 rtc;     // crea objeto del tipo RTC_DS3231
/*Para el relay primera pata positivo segunda va al arduino y tercera al negativo, la referencia es (- + s)*/
void setup() {
    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    //Serial.begin(9600);    // inicializa comunicacion serie a 9600 bps PARA TIEMPO
     if (! rtc.begin()) {       // si falla la inicializacion del modulo
     while (1);         // bucle infinito que detiene ejecucion del programa
     }
    //rtc.adjust(DateTime(__DATE__, __TIME__));
    //Serial.begin(115200);/*Para medir humedad*/
}

void loop() {
  delay(1000);
  DateTime fecha = rtc.now();
  int hora = fecha.hour();
  //logTiempo();
  if(hora > 7 && hora < 20){
    prenderLedAmarilla(1);
    prenderExtractor(1);
    prenderLedVioleta(1);
    prenderLedBlanca(1);
  }else{
    prenderLedAmarilla(0);
    prenderExtractor(0);
    prenderLedVioleta(0);
    prenderLedBlanca(0);
  }
  digitalWrite (0, LOW);/*NADA*/
  digitalWrite (13, LOW);/*NADA*/


  int lecturaA0 = analogRead(A0);/* MEDIDOR BAJO*/
  int lecturaPorcentajeA0 = map(lecturaA0,1023,0,0,100);

  int lecturaA1 = analogRead(A1);/* MEDIDOR MEDIO*/
  int lecturaPorcentajeA1 = map(lecturaA1,1023,0,0,100);

  int lecturaA2 = analogRead(A2);/* MEDIDOR ALTO*/
  int lecturaPorcentajeA2 = map(lecturaA2,1023,0,0,100);


  if(lecturaPorcentajeA0 < 50 && lecturaPorcentajeA1 < 50 && lecturaPorcentajeA2 < 50 ){
    delay(2000);
    prenderValvulaInterior(1);
  }else{
     prenderValvulaInterior(0);
  }
  //logHumedad(lecturaPorcentajeA0,lecturaPorcentajeA1,lecturaPorcentajeA2);
}

int prenderExtractor(int prender){
  if(prender == 1){
    digitalWrite (3, HIGH);/*Extractor*/
  }else{
    digitalWrite (3, LOW);/*Extractor*/
  }
}

int prenderLedAmarilla(int prender){
  if(prender == 1){
    digitalWrite (1, HIGH);/*luz AMARILLA*/
    digitalWrite (6, HIGH);/*Ventilador led AMARILLA*/
  }else{
    digitalWrite (1, LOW);/*luz AMARILLA*/
    digitalWrite (6, LOW);/*Ventilador led AMARILLA*/
  }
}

int prenderLedVioleta(int prender){
  if(prender == 1){
    digitalWrite (2, HIGH);/*luz VIOLETA*/
    digitalWrite (8, HIGH);/*Ventilador led VIOLETA*/
  }else{
    digitalWrite (2, LOW);/*luz VIOLETA*/
    digitalWrite (8, LOW);/*Ventilador led VIOLETA*/
  }
}

int prenderLedBlanca(int prender){
  if(prender == 1){
    digitalWrite (7, HIGH);/*luz BLANCA*/
    digitalWrite (4, HIGH);/*Ventilador led BLANCA*/
  }else{
    digitalWrite (7, LOW);/*luz BLANCA*/
    digitalWrite (4, LOW);/*Ventilador led BLANCA*/
  }
}

int prenderValvulaA(int prender){
   if(prender == 1){
    digitalWrite (9,  HIGH);/*vALVULA A*/
   }else{
    digitalWrite (9,  LOW);/*vALVULA A*/
   }
}
int prenderValvulaB(int prender){
  if(prender == 1){
    digitalWrite (10, HIGH);/*vALVULA B*/
  }else{
    digitalWrite (10, LOW);/*vALVULA B*/
  }
}
int prenderValvulaC(int prender){
  if(prender == 1){
    digitalWrite (11, HIGH);/*vALVULA C*/
  }else{
    digitalWrite (11, LOW);/*vALVULA C*/
  }
}
int prenderValvulaD(int prender){
  if(prender == 1){
    digitalWrite (12, HIGH);/*vALVULA D*/
  }else{
    digitalWrite (12, LOW);/*vALVULA D*/
  }
}
int prenderValvulaInterior(int prender){
  if(prender == 1){
    digitalWrite (5, HIGH);/*vALVULA INTERIOR*/
  }else{
    digitalWrite (5, LOW);/*vALVULA INTERIOR*/
  }
}
/*funcion para loger el tiempo en la consula*/
int logTiempo(){
  DateTime fecha = rtc.now();
  Serial.print(fecha.hour());      // funcion que obtiene la hora de la fecha completa
  Serial.print(":");       // caracter dos puntos como separador
  Serial.println(fecha.minute());      // funcion que obtiene los minutos de la fecha completa
  delay(1000);
}

int logHumedad(int lecturaPorcentajeA0, int lecturaPorcentajeA1, int lecturaPorcentajeA2){
  Serial.print("A0 La humedad es del ");
  Serial.println(lecturaPorcentajeA0);
  Serial.print("A1 La humedad es del ");
  Serial.println(lecturaPorcentajeA1);
  Serial.print("A2 La humedad es del ");
  Serial.println(lecturaPorcentajeA2);
}
