const int sensorPin = A0;
const float baselineTemp = 25.0;

void setup(){
    Serial.begin (9600); 
      for(int pinNumber = 2; pinNumber<5; pinNumber++){
          pinMode(pinNumber, OUTPUT);
          digitalWrite(pinNumber, LOW);
          }
}

void loop(){
    int sensorVal = analogRead (sensorPin);
      Serial.print("Senosr Value: ");
      Serial.print(sensorVal);


    /*transforma volts a grados centigrados*/
    float voltage = (sensorVal/1024.0) * 5.0;
      Serial.print(", Volts: ");
      Serial.print(voltage);
      Serial.print(" , degrees C: ");
    float temperature = (voltage - .5) *100;
      Serial.println(temperature);
    /* fin */
    if(temperature < baselineTemp){
      digitalWrite (2, LOW);
      digitalWrite (3, LOW);
      digitalWrite (4, LOW);
    }else if(temperature >= baselineTemp+1 && temperature < baselineTemp+1.5){
            digitalWrite(2, HIGH);
            digitalWrite(3, LOW);
            digitalWrite(4, LOW);
    }else if(temperature >= baselineTemp+1.5 && temperature < baselineTemp+2.5){
            digitalWrite(2, HIGH);
            digitalWrite(3, HIGH);
            digitalWrite(4, LOW);
    }else if(temperature >= baselineTemp+2.5){
            digitalWrite(2, HIGH);
            digitalWrite(3, HIGH);
            digitalWrite(4, HIGH);
    }
}
