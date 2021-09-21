#include <SoftwareSerial.h>
SoftwareSerial mySerial(7,8);//(TX,RX)

int STATE = 1;
int flag = 0;
int DIST1,DIST2;
int TRIG1 = 2;
int ECHO1 = 3;
int TRIG2 = 4;
int ECHO2 = 5;
const byte CTRL1=9;
const byte CTRL2=6;
const byte DIR1M1 = 13; 
const byte DIR2M1 = 12; 

const byte DIR1M2 = 11;
const byte DIR2M2 = 10;
/////////////////////
char SERIAL_TEXT[50]; //var text serial

void cekBluetooth()
{
  mySerial.listen();
  while (mySerial.available() > 0) {
    char inByte = mySerial.read();
    Serial.println(inByte);
  }
}


void setup() {
  
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(TRIG1,OUTPUT);
  pinMode(ECHO1,INPUT);
  pinMode(TRIG2,OUTPUT);
  pinMode(ECHO2,INPUT);
  pinMode(DIR1M1,OUTPUT);
  pinMode(DIR2M1,OUTPUT);
 
  pinMode(DIR1M2,OUTPUT);
  pinMode(DIR2M2,OUTPUT);
  /////////////
  
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  
  //cekBluetooth();
  //if (analogRead(A1)>1000) STATE = 1;
  //else STATE = 0;
  //Serial.print(analogRead(A1));
  //Serial.print(' ');
  //Serial.println(STATE);
  if(STATE!=1) play();
  else 
  {
    DIST1 = ultra(TRIG1);
    Serial.println(DIST1);
    //DIST2 = ultra(TRIG2);
    parking(DIST1,DIST2);
    //stable();
  }
  
}
void play()
{
 char inByte;
 while (mySerial.available() <= 0) {}
 inByte = mySerial.read();
 //Serial.println(inByte);
 if(inByte=='S') stable();  
 else if(inByte=='F') front();
 else if(inByte=='B') back();
 else if(inByte=='R') left();
 else if(inByte=='L') right();
 
}
void stable()
{
  digitalWrite(DIR1M1,LOW);
  digitalWrite(DIR2M1,LOW);
  
  digitalWrite(DIR1M2,LOW);
  digitalWrite(DIR2M2,LOW);
  
}
void front()
{
 digitalWrite(DIR1M1,LOW);
 digitalWrite(DIR2M1,HIGH);
 
 digitalWrite(DIR1M2,HIGH);
 digitalWrite(DIR2M2,LOW);
 
}
void back()
{
  digitalWrite(DIR1M1,HIGH);
  digitalWrite(DIR2M1,LOW);
  
  digitalWrite(DIR1M2,LOW);
  digitalWrite(DIR2M2,HIGH);
  
}

void right()
{
 digitalWrite(DIR1M1,LOW);
 digitalWrite(DIR2M1,HIGH);
 
 digitalWrite(DIR1M2,LOW);
 digitalWrite(DIR2M2,HIGH);
 
}
void left()
{
 digitalWrite(DIR1M1,HIGH);
 digitalWrite(DIR2M1,LOW);

 digitalWrite(DIR1M2,HIGH);
 digitalWrite(DIR2M2,LOW);
 
}
void parking(int d1,int d2)
{ 

 
    if((d1<0 || d1 >50)&& flag <5)
   {  analogWrite(CTRL1,250);
      analogWrite(CTRL2,50);
      front();
   }
 
  else if(d1 <= 50 && flag <1100 ) 
  {
 
  flag= flag + 1;  
  analogWrite(CTRL1,15);
  analogWrite(CTRL2,210);
  front();
   
  }
  else
  {
    stable();
  }
  
  
}
int ultra(int TRIG)
{
  digitalWrite(TRIG,HIGH);
  delay(10);
  digitalWrite(TRIG,LOW);
  int dur1 =pulseIn(ECHO1,HIGH);
  int DIST = (dur1/2)/2.91;
  return DIST;
}






