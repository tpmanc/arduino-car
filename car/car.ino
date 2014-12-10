#include
SoftwareSerial mySerial(10, 11); // RX, TX
int prevTime, curTime, time, speedIndex;
double carSpeed, tempSpeed, speedLimit, wheelRadius;
boolean wheelRotation;
char str;
void setup()
{
mySerial.begin(57600);
pinMode(13,OUTPUT);// Лампочка
pinMode(4,OUTPUT); // ЗАДНИЙ МОТОР
pinMode(5,OUTPUT); // ЗАДНИЙ МОТОР
pinMode(6,OUTPUT); // ПЕРЕНИЙ МОТОР
pinMode(7,OUTPUT); // ПЕРЕДНИЙ МОТОР
pinMode(2,OUTPUT); // ДАТЧИК
pinMode(3,OUTPUT); // ДАТЧИК
pinMode(A0,INPUT); // ВЫХОД С ДАТЧИКА
digitalWrite(2,HIGH); // ПИТАНИЕ ДАТЧИКА
digitalWrite(3,LOW); // ПИТАНИЕ ДАТЧИКА
Serial.begin(9600);
prevTime = 0;
wheelRadius = 0.01; // !!!!РАДИУС КОЛЕСА!!!!В МЕТРАХ
speedIndex = 220;
int tempLimit=255;
}
void loop() // run over and over
{
if (mySerial.available()) {
if (mySerial.overflow()){};
str = mySerial.read();
char str1 = mySerial.read();
char str2 = mySerial.read();
char str3 = mySerial.read();
char speedMagor = mySerial.read();
char speedMiddle = mySerial.read();
char speedMinor = mySerial.read();
if ( ((int(speedMagor)-48) >= 0) && ( (int(speedMiddle)-48) >= 0 ) && ( (int(speedMinor)-48) >= 0 ) ){
speedLimit = (int(speedMagor)-48)*100+(int(speedMiddle)-48)*10+(int(speedMinor)-48);
}
if (str == 'F') {
analogWrite(5,speedIndex);
analogWrite(4,0);
} else {
if (str1 == 'B') {
analogWrite(5,0);
analogWrite(4,255);
} else {
analogWrite(5,0);
analogWrite(4,0);
}
}
if (str2 == 'L') {
digitalWrite(7,HIGH);
digitalWrite(6,LOW);
}else {
if (str3 == 'R') {
digitalWrite(7,LOW);
digitalWrite(6,HIGH);
}else {
digitalWrite(6,LOW);
digitalWrite(7,LOW);
}
}
}
if ( analogRead(A0)<16 ) {
if (wheelRotation == false){
curTime= millis();
time = curTime - prevTime;
wheelRotation = true;
prevTime = curTime;
tempSpeed = 6.28*wheelRadius/time*100*60*60;//km/ч *10^(-2)
if ((tempSpeed > 2)&&(tempSpeed < 200 )){
Serial.println(carSpeed);
carSpeed = tempSpeed;
}
if (carSpeed > speedLimit) {
//speedIndex = (1 - speedLimit/carSpeed)*carSpeed - speedLimit);
speedIndex = speedIndex * speedLimit / carSpeed + 90;
if (speedIndex>220) {
speedIndex = 220;
}
if (speedIndex<150) {
speedIndex = 150;
}
if (speedLimit == 0){
speedIndex = 220;
}
}
}
}
if ( analogRead(A0)>100 ) {
wheelRotation = false;
}
}
