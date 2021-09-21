#include <SoftwareSerial.h>
SoftwareSerial mySerial(7,8);//(TX,RX)


const byte CTRL1=9;
const byte CTRL2=6;
const byte DIR1M1 = 8; 
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
  
 
  pinMode(DIR1M1,OUTPUT);
  pinMode(DIR2M1,OUTPUT);
  pinMode(CTRL1,OUTPUT);
 
  pinMode(DIR1M2,OUTPUT);
  pinMode(DIR2M2,OUTPUT);
  pinMode(CTRL2,OUTPUT);
  /////////////
  
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  


 

  
  
}
void shortest() 

void front()
{
 analogWrite(CTRL1,250);
 analogWrite(CTRL2,250); 
 digitalWrite(DIR1M1,LOW);
 digitalWrite(DIR2M1,HIGH);
 
 digitalWrite(DIR1M2,HIGH);
 digitalWrite(DIR2M2,LOW);
 
}
void back()
{
  analogWrite(CTRL1,250);
 analogWrite(CTRL2,250); 
  digitalWrite(DIR1M1,HIGH);
  digitalWrite(DIR2M1,LOW);
  
  digitalWrite(DIR1M2,LOW);
  digitalWrite(DIR2M2,HIGH);
  
}

void right()
{analogWrite(CTRL1,250);
 analogWrite(CTRL2,250); 
 digitalWrite(DIR1M1,LOW);
 digitalWrite(DIR2M1,HIGH);
 
 digitalWrite(DIR1M2,LOW);
 digitalWrite(DIR2M2,HIGH);
 
}
void left()
{
  analogWrite(CTRL1,250);
 analogWrite(CTRL2,250); 
 digitalWrite(DIR1M1,HIGH);
 digitalWrite(DIR2M1,LOW);

 digitalWrite(DIR1M2,HIGH);
 digitalWrite(DIR2M2,LOW);
 
}

