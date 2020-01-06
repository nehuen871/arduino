#include <Wire.h>    // incluye libreria para interfaz I2C A4 yA5 reservados para el tiempo
#include <RTClib.h>   // incluye libreria para el manejo del modulo RTC

RTC_DS3231 rtc;     // crea objeto del tipo RTC_DS3231
int switchState = 0;
int switchState2 = 0;
void setup()
{
  Serial.begin(57600);
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  if (! rtc.begin()) {       // si falla la inicializacion del modulo
  Serial.println("Modulo RTC no encontrado !");  // muestra mensaje de error
  while (1);         // bucle infinito que detiene ejecucion del programa
  }
//rtc.adjust(DateTime(__DATE__, __TIME__));  // funcion que permite establecer fecha y horario al momento de la compilacion. Comentar esta linea  y volver a subir para normal operacion
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

 DateTime fecha = rtc.now();      // funcion que devuelve fecha y horario en formato
            // DateTime y asigna a variable fecha
 Serial.print(fecha.day());     // funcion que obtiene el dia de la fecha completa
 Serial.print("/");       // caracter barra como separador
 Serial.print(fecha.month());     // funcion que obtiene el mes de la fecha completa
 Serial.print("/");       // caracter barra como separador
 Serial.print(fecha.year());      // funcion que obtiene el año de la fecha completa
 Serial.print(" ");       // caracter espacio en blanco como separador
 Serial.print(fecha.hour());      // funcion que obtiene la hora de la fecha completa
 Serial.print(":");       // caracter dos puntos como separador
 Serial.print(fecha.minute());      // funcion que obtiene los minutos de la fecha completa
 Serial.print(":");       // caracter dos puntos como separador
 Serial.println(fecha.second());    // funcion que obtiene los segundos de la fecha completa

  
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

int prenderLed(){
  digitalWrite (3, HIGH);
}

int apagarLed(){
  digitalWrite (3, LOW);
}
