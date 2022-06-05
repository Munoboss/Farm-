
#include <LiquidCrystal.h>

int pot = A0;
float result = 0.0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(pot, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  result = analogRead(pot);
  lcd.begin(16, 2);
  if(result >145 && result<166)
  {
    
  lcd.setCursor(1, 0);
  lcd.print("Temp is norm");
    
}
  else //(result<145 && result >166)
  {
    lcd.setCursor(1, 0);
    lcd.print("Temp isn't norm");
  }
  Serial.println(result);
 // delay(100);
}
 