#include <LiquidCrystal.h>
//#include <Stats.h>

LiquidCrystal lcd(0,1,2,3,4,5);
//Stats stats(5);
const int trigPin = 7;
const int echoPin = 8;

void setup(){
  lcd.begin(16,2);
  lcd.clear();
  lcd.print("Hello");
  delay(3000);
  lcd.setCursor(0,1);
  lcd.print("David");
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

}
void loop(){
  long duration, cm, lastCm;
  cm = 0;
  lastCm = 0;
  //digitalWrite(trigPin, LOW);
  //delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  //cm = stats.medianFive(cm);
  if (cm != lastCm){
    lcd.setCursor(7,3);
    lcd.print(cm);
    lcd.print("cm   ");
    lastCm = cm;
  }
 
  delay(1000);
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

