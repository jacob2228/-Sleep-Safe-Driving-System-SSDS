void cekBluetooth()
{
  mySerial.listen();
  while (mySerial.available() > 0) {
    char inByte = mySerial.read();
    Serial.println(inByte);
  }
}

void play()
{
 char inByte;
 while (mySerial.available() <= 0) {}
 inByte = mySerial.read();
 if(inByte==48) Rem();
 else if(inByte==49) Maju(255,255);
 else if(inByte==50) Belki(255,255);
 else if(inByte==51) Mundur(255,255);
 else if(inByte==52) Belka(255,255);
 Serial.println(inByte);
}

