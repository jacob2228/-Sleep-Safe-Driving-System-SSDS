#include <SoftwareSerial.h>
SoftwareSerial mySerial(7,8);//(TX,RX)

long duration;
int distance;

int trigPin=4;
int echoPin=5;
int n=0;
int DIR1M1=12;
int DIR2M1=11;
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
  
  // put your setup code here, to run once:
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(5,INPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  
  //cekBluetooth();
   digitalWrite(trigPin,LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration=pulseIn(echoPin, HIGH);

  distance=duration*0.034/2;
  if(distance>20) 
  {
    play();
    n=0;
  }
  else 
  {
       char inByte;
       while (mySerial.available() <= 0) {}
       inByte = mySerial.read();
       if(inByte=='F') front();
       
    else if(n=0)
    {
    digitalWrite(12,LOW);
    digitalWrite(11,HIGH);
    delay(1000);
    n=1;
    }
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH); 
  }
  
}
void play()
{
 char inByte;
 while (mySerial.available() <= 0) {}
 inByte = mySerial.read();
 Serial.println(inByte);
 if(inByte=='S') stable();  
 else if(inByte=='F') front();
 else if(inByte=='B') back();

 
}
void stable()
{
  digitalWrite(DIR1M1,LOW);
  digitalWrite(DIR2M1,LOW);

}
void front()
{
 digitalWrite(DIR1M1,LOW);
 digitalWrite(DIR2M1,HIGH);
 
 
 
}
void back()
{
  digitalWrite(DIR1M1,HIGH);
  digitalWrite(DIR2M1,LOW);
  
  
}


