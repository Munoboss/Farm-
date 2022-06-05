int Sensor = 0 ; 	
int Umbral = 32 ;
int LedRojo= 13;
int Motor= 11;
  
void setup()
{
  pinMode(Motor, OUTPUT);
  pinMode(LedRojo, OUTPUT);
  Serial.begin(9600);
}

void loop()
{ int lectura = analogRead(Sensor);  
  float voltage =  5.0 /1024 * lectura; 
  float temp = voltage * 100 -50;
  
  if (temp > Umbral){
  	digitalWrite(LedRojo, HIGH);   
    digitalWrite(Motor, HIGH);
  }
  else {
  	digitalWrite(LedRojo, LOW); 
    digitalWrite(11, LOW);
  }
 Serial.print(Umbral);
  delay(1000);
}
