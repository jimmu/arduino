int potPin = A2;
int ledPin = 13;
int val = 0;

void setup(){
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  val = map(analogRead(potPin),0,1023,15,250);
  Serial.println(val);
  digitalWrite(ledPin, HIGH);
  delay(val);
  digitalWrite(ledPin, LOW);
  delay(val);
}
