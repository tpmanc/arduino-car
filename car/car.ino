#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() 
{
// set the data rate for the SoftwareSerial port
mySerial.begin(57600);
pinMode(13,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(9,OUTPUT);
//pinMode(10,OUTPUT);
//pinMode(A0,INPUT);
}

void loop() // run over and over
{
if (mySerial.available()) {

char str = mySerial.read();
char str1 = mySerial.read();
char str2 = mySerial.read();
char str3 = mySerial.read();

if (str == 'F') {
digitalWrite(13,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,LOW); 
} else {
if (str1 == 'B') {
digitalWrite(13,LOW);
digitalWrite(4,LOW);
digitalWrite(5,HIGH); 
} else {
digitalWrite(5,LOW);
digitalWrite(4,LOW); 
}
}

if (str2 == 'L') {
digitalWrite(13,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,LOW); 
}else {
if (str3 == 'R') {
digitalWrite(13,LOW);
digitalWrite(6,LOW);
digitalWrite(7,HIGH); 
}else {
digitalWrite(6,LOW);
digitalWrite(7,LOW); 
}
}
//millis() - подсчет времени в милисекундах 
mySerial.print(str);
mySerial.print(str1);
mySerial.print(str2);
mySerial.print(str3);
}
}