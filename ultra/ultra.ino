


int trig = D1;
int echo = D0;
int dist,dur;

void setup()
{
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}
void loop() {
   
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  dur =pulseIn(echo,HIGH);
  dist =(dur/2)/29.1;
  Serial.println(dur);
}
