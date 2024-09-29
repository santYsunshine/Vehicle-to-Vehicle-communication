#include <EEPROM.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include<String.h>
char ch;
const int M1 = 5;
const int M2 = 6;
const int M3 = 7;
const int M4 = 8;
const int buttonPin1 = A0;
int buttonState1 = 0;
const int buttonPin2 = A1;
int buttonState2 = 0;
b
const int buttonPin3 = A2;
int buttonState3 = 0;
const int buttonPin4 = A3;
int buttonState4 = 0;
const int buttonPin5 = A4;
int buttonState5 = 0;
const int buttonPin6 = A5;
int buttonState6 = 0;
LiquidCrystal lcd(2,3,4,9,10,11);
int Y = 1;
// value read from the pot
/************************ULTRASONIC***********************************/
int cur_US;
int set_US;
int pingPin = 13; //13; trigger
int inPin = 12; //12; echo68
long duration, inches, cm;
int dist,normal,high,dist_cm;
long microsecondsToInches(long microseconds) {
// According to Parallax's datasheet for the PING))), there are
// 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
// second). This gives the distance travelled by the ping, outbound
// and return, so we divide by 2 to get the distance of the obstacle.
// See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
return microseconds / 74 / 2;
}
long microsecondsToCentimeters(long microseconds) {
// The speed of sound is 340 m/s or 29 microseconds per centimeter.
// The ping travels out and back, so to find the distance of the
// object we take half of the distance travelled.
return microseconds / 29 / 2;
}
/***********************************************************************/
void setup()
{
pinMode(M1,OUTPUT);
digitalWrite(M1,LOW);
pinMode(M2,OUTPUT);
digitalWrite(M2,LOW);
pinMode(M3,OUTPUT);
digitalWrite(M3,LOW);69
pinMode(M4,OUTPUT);
digitalWrite(M4,LOW);
pinMode(buttonPin1, INPUT);
pinMode(buttonPin2, INPUT);
pinMode(buttonPin3, INPUT);
pinMode(buttonPin4, INPUT);
pinMode(buttonPin5, INPUT);
pinMode(buttonPin6, INPUT);
lcd.begin(16,2);
Serial.begin(9600);
//SPLASH SCREEN
lcd.setCursor(0,0);
lcd.print(" WIRELESS V2V COMMUNICATIONS OF UNMANNED
AERIAL VEHICLES WITH ");
lcd.setCursor(0,1);
lcd.print("
CHARGER OF TESLA COIL
WIRELESS NETWORK TRACKING AND EMP
");
for (int positionCounter = 0; positionCounter < 80; positionCounter++)
{
// scroll one position left:
lcd.scrollDisplayRight();
// wait a bit:
delay(100);
delay(1);70
lcd.clear();
//SPLASH SCREEN END
}
int i = 2000;
int ii = 3400;
void loop()
{
while(1)
{
buttonState1 = digitalRead(buttonPin1);
buttonState2 = digitalRead(buttonPin2);
buttonState3 = digitalRead(buttonPin3);
buttonState4 = digitalRead(buttonPin4);
buttonState5 = digitalRead(buttonPin5);
buttonState6 = digitalRead(buttonPin6);
inches = microsecondsToInches(duration);
cm = microsecondsToCentimeters(duration);
ch = Serial.read();
if(buttonState1==LOW )
{
lcd.setCursor(0,0);
lcd.print("V.No =TNXX LXXXX
");71
lcd.setCursor(0,1);
lcd.print("V2V - Right turn
");
delay(350);
lcd.clear();
}
else if(buttonState2==LOW )
{
lcd.setCursor(0,0);
lcd.print("V.No =TNXX LXXXX
");
lcd.setCursor(0,1);
lcd.print("V2V - Over Speed
");
delay(350);
lcd.clear();
}
else if(buttonState3==LOW )
{
lcd.setCursor(0,0);
lcd.print("V.No =TNXX LXXXX
lcd.setCursor(0,1);
lcd.print("V2V - Break
delay(350);
lcd.clear();
");
");72
}
else if(buttonState4==LOW )
{
lcd.setCursor(0,0);
lcd.print("V.No =TNXX LXXXX
");
lcd.setCursor(0,1);
lcd.print("V2V - Left turn
delay(350);
lcd.clear();
}
else
{
lcd.setCursor(0,1);
lcd.print("");
}
if(buttonState5==LOW )
{
lcd.setCursor(0,0);
lcd.print("Infront Of Obj...");
digitalWrite(M1,LOW);
digitalWrite(M2,LOW);
digitalWrite(M3,LOW);
");73
digitalWrite(M4,LOW);
}
if(buttonState6==LOW )
{
lcd.setCursor(0,0);
lcd.print("Backside Object...");
delay(200);
lcd.clear();
}
if (ch=='e' ) {
lcd.setCursor(0,0);
lcd.print(" STOP
");
digitalWrite(M1,LOW);
digitalWrite(M2,LOW);
digitalWrite(M3,LOW);
digitalWrite(M4,LOW);
}
if (ch=='E' ) {
lcd.setCursor(0,0);
lcd.print(" STOP
digitalWrite(M1,LOW);
digitalWrite(M2,LOW);
");74
digitalWrite(M3,LOW);
digitalWrite(M4,LOW);
}
if (ch=='a' ) {
Y=1;
lcd.setCursor(0,0);
lcd.print(" Manual Control
");
digitalWrite(M1,LOW);
digitalWrite(M2,LOW);
digitalWrite(M3,LOW);
digitalWrite(M4,LOW);
delay(i);
}
if (ch=='A') {
Y=2;
lcd.setCursor(0,0);
lcd.print("Select Your Zone
digitalWrite(M1,LOW);
digitalWrite(M2,LOW);
digitalWrite(M3,LOW);
digitalWrite(M4,LOW);
delay(i);
");75
}
/*****************************ULTRASONIC******************************/
digitalWrite(pingPin, LOW);
delayMicroseconds(2);
digitalWrite(pingPin, HIGH);
delayMicroseconds(10);
digitalWrite(pingPin, LOW);
delayMicroseconds(2);
pinMode(pingPin, OUTPUT);
pinMode(inPin, INPUT);
duration = pulseIn(inPin, HIGH);
lcd.setCursor(10,1);
lcd.print("CM=");
lcd.print(cm);
delay(100);
lcd.clear();
/*****************************ULTRASONIC******************************/
if (ch=='b' && Y==1) {
lcd.setCursor(0,0);
lcd.print(" FORWARD
digitalWrite(M1,HIGH);
digitalWrite(M2,LOW);
");76
digitalWrite(M3,HIGH);
digitalWrite(M4,LOW);
}
if (ch=='B' && Y==1) {
lcd.setCursor(0,0);
lcd.print(" FORWARD
");
digitalWrite(M1,HIGH);
digitalWrite(M2,LOW);
digitalWrite(M3,HIGH);
digitalWrite(M4,LOW);
}
if (ch=='h' && Y==1) {
lcd.setCursor(0,0);
lcd.print(" REVERSE
digitalWrite(M2,HIGH);
digitalWrite(M1,LOW);
digitalWrite(M4,HIGH);
digitalWrite(M3,LOW);
if(buttonState6==LOW )
{
lcd.setCursor(0,0);
lcd.print("InBack Of Obj...");
");77
digitalWrite(M1,LOW);
digitalWrite(M2,LOW);
digitalWrite(M3,LOW);
digitalWrite(M4,LOW);
}
}
if (ch=='H' && Y==1) {
lcd.setCursor(0,0);
lcd.print(" REVERSE
digitalWrite(M2,HIGH);
digitalWrite(M1,LOW);
digitalWrite(M4,HIGH);
digitalWrite(M3,LOW);
if(buttonState6==LOW )
{
lcd.setCursor(0,0);
lcd.print("InBack Of Obj...");
digitalWrite(M1,LOW);
digitalWrite(M2,LOW);
digitalWrite(M3,LOW);
digitalWrite(M4,LOW);
}
");78
}
if (ch=='d' && Y==1) {
lcd.setCursor(0,0);
lcd.print(" LEFT
");
digitalWrite(M1,HIGH);
digitalWrite(M2,LOW);
digitalWrite(M3,LOW);
digitalWrite(M4,LOW);
}
if (ch=='D' && Y==1) {
lcd.setCursor(0,0);
lcd.print(" LEFT
");
digitalWrite(M1,HIGH);
digitalWrite(M2,LOW);
digitalWrite(M3,LOW);
digitalWrite(M4,LOW);
}
if (ch=='f' && Y==1) {
lcd.setCursor(0,0);
lcd.print(" RIGHT
digitalWrite(M1,LOW);
digitalWrite(M2,LOW);
");79
digitalWrite(M4,LOW);
digitalWrite(M3,HIGH);
}
if (ch=='F' && Y==1) {
lcd.setCursor(0,0);
lcd.print(" RIGHT
digitalWrite(M1,LOW);
digitalWrite(M2,LOW);
digitalWrite(M4,LOW);
digitalWrite(M3,HIGH);
//zone
if (ch=='b' && Y==2) {
lcd.setCursor(0,0);
lcd.print("YOUR ZONE 1");
digitalWrite(M1,HIGH);
digitalWrite(M2,LOW);
digitalWrite(M3,HIGH);
digitalWrite(M4,LOW);
delay(i);
digitalWrite(M1,LOW);
digitalWrite(M2,LOW);
digitalWrite(M4,LOW);
");80
digitalWrite(M3,HIGH);
delay(ii);
digitalWrite(M1,HIGH);
digitalWrite(M2,LOW);
digitalWrite(M3,HIGH);
digitalWrite(M4,LOW);
delay(i*4);
digitalWrite(M1,HIGH);
digitalWrite(M2,LOW);
digitalWrite(M3,LOW);
digitalWrite(M4,LOW);
delay(ii);
digitalWrite(M1,HIGH);
digitalWrite(M2,LOW);
digitalWrite(M3,HIGH);
digitalWrite(M4,LOW);
delay(i*3);
lcd.setCursor(0,0);
lcd.print("SUCESSFULLY... ");
digitalWrite(M1,LOW);
digitalWrite(M2,LOW);
digitalWrite(M3,LOW);81
digitalWrite(M4,LOW);
}
//zone 2
if (ch=='c' && Y==2) {
lcd.setCursor(0,0);
lcd.print("YOU ZONE 2");
digitalWrite(M1,HIGH);
digitalWrite(M2,LOW);
digitalWrite(M3,HIGH);
digitalWrite(M4,LOW); //stright
delay(i*4);
digitalWrite(M1,LOW);
digitalWrite(M2,LOW);
digitalWrite(M4,LOW);
digitalWrite(M3,HIGH); //right
delay(ii);
digitalWrite(M1,HIGH);
digitalWrite(M2,LOW);
digitalWrite(M3,HIGH);
digitalWrite(M4,LOW); //stright
delay(i);
digitalWrite(M1,LOW);82
digitalWrite(M2,LOW);
digitalWrite(M4,LOW);
digitalWrite(M3,HIGH); //right
delay(ii);
digitalWrite(M1,HIGH);
digitalWrite(M2,LOW);
digitalWrite(M3,HIGH);
digitalWrite(M4,LOW);
delay(i*3);
digitalWrite(M1,HIGH); //left
digitalWrite(M2,LOW);
digitalWrite(M3,LOW);
digitalWrite(M4,LOW);
delay(ii);
digitalWrite(M1,HIGH);
digitalWrite(M2,LOW);
digitalWrite(M3,HIGH);
digitalWrite(M4,LOW); //stright
delay(i);
digitalWrite(M1,HIGH);
digitalWrite(M2,LOW);
digitalWrite(M3,LOW);83
digitalWrite(M4,LOW); // left
delay(ii);
digitalWrite(M1,HIGH);
digitalWrite(M2,LOW);
digitalWrite(M3,HIGH);
digitalWrite(M4,LOW);
delay(i*3);
digitalWrite(M1,LOW);
digitalWrite(M2,LOW);
digitalWrite(M4,LOW);
digitalWrite(M3,HIGH); //right
delay(ii);
digitalWrite(M1,HIGH);
digitalWrite(M2,LOW);
digitalWrite(M3,HIGH);
digitalWrite(M4,LOW);
delay(i*2 );
digitalWrite(M1,LOW);
digitalWrite(M2,LOW);
digitalWrite(M4,LOW);
digitalWrite(M3,HIGH); //right
delay(ii);84
digitalWrite(M1,HIGH);
digitalWrite(M2,LOW);
digitalWrite(M3,HIGH);
digitalWrite(M4,LOW);
delay(i*1 );
lcd.setCursor(0,0);
lcd.print("SUCESSFULLY... ");
digitalWrite(M1,LOW);
digitalWrite(M2,LOW);
digitalWrite(M3,LOW);
digitalWrite(M4,LOW);
}
if (ch=='d' && Y==2) {
lcd.setCursor(0,0);
lcd.print("YOU ZONE 3");
digitalWrite(M1,HIGH);
digitalWrite(M2,LOW);
digitalWrite(M3,HIGH);
digitalWrite(M4,LOW); //stright
delay(i*2 );
digitalWrite(M1,HIGH); //left
digitalWrite(M2,LOW);85
digitalWrite(M3,LOW);
digitalWrite(M4,LOW);
delay(ii);
digitalWrite(M1,HIGH);
digitalWrite(M2,LOW);
digitalWrite(M3,HIGH);
digitalWrite(M4,LOW); //stright
delay(i );
digitalWrite(M1,LOW);
digitalWrite(M2,LOW);
digitalWrite(M4,LOW);
digitalWrite(M3,HIGH); //right
delay(ii);
digitalWrite(M1,HIGH);
digitalWrite(M2,LOW);
digitalWrite(M3,HIGH);
digitalWrite(M4,LOW); //stright
delay(i*3);
digitalWrite(M1,HIGH); //left
digitalWrite(M2,LOW);
digitalWrite(M3,LOW);
digitalWrite(M4,LOW);86
delay(ii);
digitalWrite(M1,HIGH);
digitalWrite(M2,LOW);
digitalWrite(M3,HIGH);
digitalWrite(M4,LOW); //stright
delay(i*2);
digitalWrite(M1,HIGH); //left
digitalWrite(M2,LOW);
digitalWrite(M3,LOW);
digitalWrite(M4,LOW);
delay(ii);
digitalWrite(M1,HIGH);
digitalWrite(M2,LOW);
digitalWrite(M3,HIGH);
digitalWrite(M4,LOW); //stright
delay(i*2);
lcd.setCursor(0,0);
lcd.print("SUCESSFULLY... ");
digitalWrite(M1,LOW);
digitalWrite(M2,LOW);
digitalWrite(M3,LOW);
digitalWrite(M4,LOW);87
}
//zone 4
if (ch=='e' && Y==2) {
lcd.setCursor(0,0);
lcd.print("YOU ZONE 4");
digitalWrite(M1,HIGH);
digitalWrite(M2,LOW);
digitalWrite(M3,HIGH);
digitalWrite(M4,LOW); //stright
delay(i);
digitalWrite(M1,HIGH); //left
digitalWrite(M2,LOW);
digitalWrite(M3,LOW);
digitalWrite(M4,LOW);
delay(ii);
digitalWrite(M1,HIGH);
digitalWrite(M2,LOW);
digitalWrite(M3,HIGH);
digitalWrite(M4,LOW); //stright
delay(i*2);
lcd.setCursor(0,0);
lcd.print("SUCESSFULLY... ");88
digitalWrite(M1,LOW);
digitalWrite(M2,LOW);
digitalWrite(M3,LOW);s
digitalWrite(M4,LOW);
}
}
}