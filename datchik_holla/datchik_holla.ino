void setup () {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(A0,INPUT);
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  Serial.begin(9600);
  
}
int count = 0;
void loop() {
  int val = analogRead(A0);
  if (( val < 15 )&&( val > 11 )){
    count = count + 1;
    Serial.println(count);
  }
  delay(100); 
}
