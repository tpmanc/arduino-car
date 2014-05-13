void setup () {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(A0,INPUT);
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  Serial.begin(9600);
}
void loop() {
  Serial.println(analogRead(A0));
  delay(30); 
}
