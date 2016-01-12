#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

void setup(){
  lcd.clear();
  lcd.print("Hello");
}
void loop(){
  lcd.clear();
  lcd.print("Hello");
  delay(10);
}

