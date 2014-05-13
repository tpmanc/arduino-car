

void setup() {
  pinMode(A0, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  
  int str = analogRead(0);
  Serial.print(str);
}
