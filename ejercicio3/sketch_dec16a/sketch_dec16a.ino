const int greenLEDPin = 9;
const int redLEDPin = 11;
const int blueLEDPin = 10;

const int greenSensorPin = A0;
const int redSensorPin = A1;
const int blueSensorPin = A2;

int greenValue = 0;
int redValue = 0;
int blueValue = 0;

int greenSensorValue = 0;
int redSensorValue = 0;
int blueSensorValue = 0;
int promedioRed = 0;
int promedioBlue = 0;
int promedioGreen = 0;

void setup() {
  Serial.begin(9600);
  pinMode(greenLEDPin,OUTPUT);
  pinMode(redLEDPin,OUTPUT);
  pinMode(blueLEDPin,OUTPUT);
}

void loop() {
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);

  Serial.print("Raw sensor values \t Red: ");
  Serial.print(redSensorValue);
  Serial.print("\t Blue: ");
  Serial.print(blueSensorValue);
  Serial.print("\t Green: ");
  Serial.println(greenSensorValue);

  redValue = redSensorValue/4;
  blueValue = blueSensorValue/4;
  greenValue = greenSensorValue/4;
  promedioRed += redValue /2;
  promedioBlue += blueValue /2;
  promedioGreen += greenValue /2;
  
  Serial.print("Map sensor values \t Red: ");
  Serial.print(redValue);
  Serial.print("\t Blue: ");
  Serial.print(blueValue);
  Serial.print("\t Green: ");
  Serial.println(greenValue);

  analogWrite(redLEDPin,redValue);
  analogWrite(blueLEDPin,blueValue);
  analogWrite(greenLEDPin,greenValue);
}
