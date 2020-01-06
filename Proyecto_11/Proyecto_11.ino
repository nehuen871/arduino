#include <LiquidCrystal.h>
#include <Wire.h>    // incluye libreria para interfaz I2C
#include <RTClib.h>   // incluye libreria para el manejo del modulo RTC
RTC_DS3231 rtc; 
LiquidCrystal lcd(12, 11, 5, 4 ,3, 2);
int printF = 0;
int reply;
const int switchPin = 6;
void setup(){
  Serial.begin(9600);    // inicializa comunicacion serie a 9600 bps
   lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  lcd.print("No me muevas!");
  Wire.begin(); // Inicia el puerto I2C
rtc.begin(); // Inicia la comunicaci¢n con el RTC
  lcd.clear();
  
 if (! rtc.begin()) {       // si falla la inicializacion del modulo
 Serial.println("Modulo RTC no encontrado !");  // muestra mensaje de error
 while (1);         // bucle infinito que detiene ejecucion del programa
 }
 //rtc.adjust(DateTime(__DATE__, __TIME__));  // funcion que permite establecer fecha y horario
  lcd.begin(16, 2);
}

void loop(){
  DateTime fecha = rtc.now();
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
 lcd.setCursor(0,0);
lcd.print("D:");
lcd.print(fecha.year(), DEC);
lcd.print("/");
lcd.print(fecha.month(), DEC);
lcd.print("/");
lcd.print(fecha.day(), DEC);
lcd.print(" ");
lcd.setCursor(0,1);
lcd.print("T: ");
lcd.print(fecha.hour(), DEC);
lcd.print(":");
lcd.print(fecha.minute(), DEC);
lcd.print(":");
lcd.print(fecha.second(), DEC);
delay(1000); // La informaci¢n se actualiza cada 1 seg.
lcd.setCursor(0,0);
lcd.print("               ");
lcd.setCursor(0,1);
lcd.print("               ");
}
