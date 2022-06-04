#include <DHT.h>
#include <LiquidCrystal.h>
#include <Servo.h>
#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT; 
#define DHT11_PIN 11


Servo myservo;  
LiquidCrystal lcd(A2, A3, A4, A5, 12, 10);

int trigPin = 2;
int echoPin = 3;
int led = 4;
int cooler=5;
int relay=6;
int relay2 = 7;
int aa1;
int buzzer1=8;
int blue=9;

void setup() {

 Serial.begin(9600);
 lcd.begin(16,2);
  pinMode(buzzer1,OUTPUT);
   pinMode(blue,OUTPUT);  
  pinMode(relay,OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(cooler,OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
   myservo.attach(9);
   lcd.setCursor(0,0);
  lcd.print("SMART BREADING!");
  lcd.setCursor(0,1);
  lcd.print("SYSTEM FOR COWS");
  for(int i=1;i<=3;i++){
    digitalWrite(buzzer1, HIGH);
    delay(100);
    digitalWrite(buzzer1, LOW);
    delay(100);
    digitalWrite(buzzer1, HIGH);
    delay(100);
    digitalWrite(buzzer1, LOW);
    delay(100); 
    }
  delay(1500);
  lcd.clear();
}
void loop() {
 DHT.read(DHT11_PIN);
  int d=analogRead(A0);
  int a=analogRead(A6);

  lcd.setCursor(13,1);
  lcd.print(DHT.temperature); 
  lcd.print("C");
  if(DHT.temperature>=35){
    lcd.clear();
    delay(200);
    digitalWrite(cooler,LOW);
    lcd.setCursor(13,1);
    lcd.print(DHT.temperature); 
    lcd.print("C");
    lcd.setCursor(1,0);
    lcd.print("COOLER TURN");
    lcd.setCursor(4,1);
    lcd.print("ON!");
    delay(2000);
  }
 
  else if(DHT.temperature<25){
     digitalWrite(cooler,HIGH);
  }

  if(a<=100){
  digitalWrite(buzzer1, HIGH);
 delay(100);
  digitalWrite(buzzer1, LOW);
  digitalWrite(blue,HIGH);
  lcd.setCursor(0,0);
  lcd.print("WATER ISN'T NORMAl");
  lcd.setCursor(0,1);
  lcd.print("PLEASE WATER");
  delay(200);
  digitalWrite(relay2, LOW);
  lcd.clear();
  }
  else{
  digitalWrite(relay2, HIGH);
     digitalWrite(blue,LOW);

    }
    long duration, distance;
  digitalWrite(trigPin, HIGH);
  digitalWrite (trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance = (duration/2)/29.1;

    if ((distance<10))
    {
      digitalWrite(relay,LOW);
}
      else if (distance>10)
      {
        digitalWrite(relay, HIGH);
        
      }

      
 }
