
int control =10;
void setup()
{
  pinMode(control,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  
  
}
void loop()
{
  analogWrite(control,255);
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
  delay(5000);
  analogWrite(control,100);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
  delay(5000); 
}  
