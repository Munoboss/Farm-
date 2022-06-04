const int pushButton[] ={2,3,4,5};
const int relayPin[]={11,10,9,8};
String relayNames[] ={"CH1", "CH2","CH3","CH4"};
int pushed[] ={0,0,0,0};
int relayStatus[] ={HIGH,HIGH,HIGH,HIGH};


void setup() {
 
  Serial.begin(9600);
  for(int i=0; i<4; i++)
  {
    pinMode(pushButton[i], INPUT_PULLUP); 
    pinMode(relayPin[i], OUTPUT);   
    digitalWrite(relayPin[i], HIGH);


}

void loop() {


  for(int i=0; i<4; i++)
  {
     int  val = digitalRead(pushButton[i]);   
    if(val == HIGH && relayStatus[i] == LOW){
  
      pushed[i] = 1-pushed[i];
      delay(100);
    }// if   

  relayStatus[i] = val;

      if(pushed[i] == HIGH){
        Serial.print(relayNames[i]);
        Serial.println(" ON");
        digitalWrite(relayPin[i], LOW); 
       
      }else{
        Serial.print(relayNames[i]);
        Serial.println(" OFF");
        digitalWrite(relayPin[i], HIGH);
   
      }// else   
 
  }// for 
    Serial.println("=="); 
  delay(100);
}// loop end
