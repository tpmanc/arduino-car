void setup () {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(A0,INPUT);
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  Serial.begin(9600);
  
}
int prevTime = 0;
int curTime = 0;
int time = 0;
float carSpeed = 0;
boolean wheelRotation = false;
void loop() {
  if ( analogRead(A0)<14 ) {
    //if (prevTime != 0) {
      if (wheelRotation == false){
        curTime= millis();
        time = curTime - prevTime;
        wheelRotation = true;
        prevTime = curTime;
        
        carSpeed = 6.28*1*time*1000*60 ;
        Serial.println(time);
      }
    //} 
  }
  if ( analogRead(A0)>60 ) {
    wheelRotation = false; 
  }
  delay(30);
}
