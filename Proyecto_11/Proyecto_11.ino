#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4 ,3, 2);
const int switchPin = 6;
int switchState = 0;
int prevSwtichState = 0;
int reply;
char *primes[]={"Para!", "Cortala!", "No jodas!", "Me molesta!", "Basta!", "Ya fue!", "Posta?", "La cortamos?", "Vas a seguir?", "buenooo", "ufffff", "Ok Chau!", "Me vas a romper!"};
void setup(){
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  lcd.print("No me muevas!");
}

void loop(){
  switchState = digitalRead(switchPin);
  if(switchState != prevSwtichState){
    if(switchState == LOW) {
      reply = random(12);
      lcd.clear();
      lcd.print("No me muevas!");
      lcd.setCursor(0, 1);
      lcd.print(primes[reply]);
   }
  }   

prevSwtichState = switchState;

}
