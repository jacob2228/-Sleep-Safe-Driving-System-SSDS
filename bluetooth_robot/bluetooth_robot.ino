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
  //cekBluetooth();
  play();
}
