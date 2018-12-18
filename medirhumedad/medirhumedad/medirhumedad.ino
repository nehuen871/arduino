/*const int sensorPin = 2;
 
void setup()
{
   Serial.begin(9600);
   pinMode(sensorPin, INPUT);
}
 
void loop()
{
   int humedad = digitalRead(sensorPin);

   if (humedad == HIGH)
   {
      Serial.println("El estado de la humedad esta en alto");   
      
   }
   delay(1000);
}*/

void setup()
{
   Serial.begin(115200);
}
void loop()
{
  int lectura = analogRead(A0);
  Serial.print("La lectura es");
  Serial.println(lectura);
  delay(1000);
  int lecturaPorcentaje = map(lectura,1023,0,0,100);
  Serial.print("La humedad es del ");
  Serial.print(lecturaPorcentaje);
  Serial.println("%");
  
}
