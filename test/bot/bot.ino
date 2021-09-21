#include <SoftwareSerial.h>
SoftwareSerial mySerial(7,8);//(TX,RX)
//initial motor
const byte PWMKI  = 11; //pin PWM L293
const byte DIR1KI = 13; //pin direction1 L293 
const byte DIR2KI = 2;  //pin direction2 L293

const byte PWMKA = 3; 
const byte DIR1KA = 9;
const byte DIR2KA = 4;
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
  //setup motor (pin arduino sebagai output)
  pinMode(PWMKI,OUTPUT);
  pinMode(DIR1KI,OUTPUT);
  pinMode(DIR2KI,OUTPUT);
  pinMode(PWMKA,OUTPUT);
  pinMode(DIR1KA,OUTPUT);
  pinMode(DIR2KA,OUTPUT);
  /////////////
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  //cekMotor();
  cekBluetooth();
 //play();
}
void play()
{
 char inByte;
 while (mySerial.available() <= 0) {}
 inByte = mySerial.read();
 Serial.println(inByte);
 if(inByte==48) Rem();
 else if(inByte==49) Maju(255,255);
 else if(inByte==50) Belki(255,255);
 else if(inByte==51) Mundur(255,255);
 else if(inByte==52) Belka(255,255);
 
}
void kananMaju(unsigned char kec)
{
  digitalWrite(DIR1KA,LOW); //DIR1KA output LOW
  digitalWrite(DIR2KA,HIGH);//DIR2KA output HIGH
  analogWrite(PWMKA,kec);   //PWMKA output kec
}

void kiriMaju(unsigned char kec)
{
  digitalWrite(DIR1KI,LOW);
  digitalWrite(DIR2KI,HIGH);
  analogWrite(PWMKI,kec);
}

void kananMundur(unsigned char kec)
{
  digitalWrite(DIR1KA,HIGH);//DIR1KA output HIGH
  digitalWrite(DIR2KA,LOW); //DIR2KA output LOW
  analogWrite(PWMKA,kec);   //PWMKA output kec
}

void kiriMundur(unsigned char kec)
{
  digitalWrite(DIR1KI,HIGH);
  digitalWrite(DIR2KI,LOW);
  analogWrite(PWMKI,kec);
}

void kananRem()
{
  digitalWrite(DIR1KA,HIGH);//DIR1KA output HIGH
  digitalWrite(DIR2KA,HIGH);//DIR2KA output HIGH
  analogWrite(PWMKA,255);   //PWMKA output 255
}

void kiriRem()
{
  digitalWrite(DIR1KI,HIGH);
  digitalWrite(DIR2KI,HIGH);
  analogWrite(PWMKI,255);
}

void Maju(unsigned char kecKiri,unsigned char kecKanan)
{
  kananMaju(kecKanan);
  kiriMaju(kecKiri); 
}

void Mundur(unsigned char kecKiri,unsigned char kecKanan)
{
  kananMundur(kecKanan);
  kiriMundur(kecKiri); 
}

void Belka(unsigned char kecKiri,unsigned char kecKanan)
{
  kananMundur(kecKanan);
  kiriMaju(kecKiri); 
}

void Belki(unsigned char kecKiri,unsigned char kecKanan)
{
  kananMaju(kecKanan);
  kiriMundur(kecKiri); 
}

void Rem()
{
  kananRem();
  kiriRem(); 
}

void cekMotor()
{
  Maju(100,100); //robot maju
  delay(1000); Rem(); delay(500); //robot ngerem
  Mundur(100,100); //robot mundur
  delay(1000); Rem(); delay(500); //robot ngerem
  Belka(100,100); // robot belok kanan
  delay(1000); Rem(); delay(500); //robot ngerem
  Belki(100,100); // robot belok kiri
  delay(1000); Rem(); delay(500); //robot ngerem
}
