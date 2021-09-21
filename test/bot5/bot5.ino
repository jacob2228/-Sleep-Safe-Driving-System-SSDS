#include <VirtualWire.h>
#include<Servo.h>
float i,val=0,tp=0;
int trig = A0;
int echo = 4;
Servo myservo;

int dist1;
int dist2,dur2;
int dist3,dur3;
int ir;
int temp=0;
int flag=1,flag1;
const byte CTRL1=3;
const byte CTRL2=6;
const byte DIR1M1 = 8; 
const byte DIR2M1 = 12; 

const byte DIR1M2 = 11;
const byte DIR2M2 = 10;
const int receive_pin = 2;
int jstate;

void setup()
{ 
    Serial.begin(9600);	// Debugging only
    Serial.println("setup");

    // Initialise the IO and ISR
    vw_set_rx_pin(receive_pin);
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);	 // Bits per sec

    vw_rx_start();  // Start the receiver PLL running
 myservo.attach(5);
  pinMode(0,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(DIR1M1,OUTPUT);
  pinMode(DIR2M1,OUTPUT);
  pinMode(CTRL1,OUTPUT);
 
  pinMode(DIR1M2,OUTPUT);
  pinMode(DIR2M2,OUTPUT);
  pinMode(CTRL2,OUTPUT);
}

void loop()
{
  
   
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
  
    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
	int i;

        digitalWrite(13, true); // Flash a light to show received good message
	// Message with a good checksum received, dump it.
        Serial.print("Got: ");
	
	for (i = 0; i < buflen; i++)
	{
	    Serial.print(buf[i], HEX);
	    Serial.print(" ");
             jstate=buf[i];
	}
	Serial.println("");
 
        digitalWrite(13, false);
    }
        
   int n=Serial.read();
n=n-48;


if((n==-49))
{ 
  i=100;
 goto last2;

}
else if(n==(-35))
{
  i=100;
  dist1=tp;
  tp=0;
  goto last2;
}

 
    if(n==-2)
    {
     i=i*10; 
    }
    else
    {
      tp=tp+n*i;
    } 
  i=i/10;
 last1:
 last2:
  delay(100);

    // if(jstate==61)   
   //{
     autoparking();
   //}
}
void autoparking()
{
  shortest();
  if(ir>1000)
  { 
    if(dist2>10)
     {
       if(dist1>100)
         {
           front(100,200);
           flag1=1;
         }
         else
         {
           back(100,200);
           delay(500);
           back(150,150);
           delay(1000);
         }
      }
     else
     { 
       if(flag1==1)
       {
         front(250,100);
         delay(500);
         flag=0;
       }
       front(200,200);
     }
  }
  else
  { 
    if(flag==1)
      {
        front(250,100);
        delay(1000);
      }
    flag=0;  
  }
}
void shortest()
{ 
  for(i=80;i<110;i++)
  {
    myservo.write(i);
   digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  dur2 =pulseIn(echo,HIGH);
  dist2 =(dur2/2)/29.1;
  if(dist2<temp)
  {
    temp=dist2;
    
  }
  
   dist2=temp;
 }
}
/*void drive(int jstate)
{
    
  
   switch(jstate)
    {
      case 0:stable();break;
      case 1:left();break;
      case 2:right();break;
      case 3:front();break;
      case 4:back();break;
    }
}
*/
void stable()
{
  digitalWrite(DIR1M1,LOW);
  digitalWrite(DIR2M1,LOW);
  
  digitalWrite(DIR1M2,LOW);
  digitalWrite(DIR2M2,LOW);
  
}
void front(int speed1,int speed2)
{
 analogWrite(CTRL1,speed1);
 analogWrite(CTRL2,speed2); 
 digitalWrite(DIR1M1,LOW);
 digitalWrite(DIR2M1,HIGH);
 
 digitalWrite(DIR1M2,HIGH);
 digitalWrite(DIR2M2,LOW);
 
}
void back(int speedb1,int speedb2)
{
  analogWrite(CTRL1,speedb1);
 analogWrite(CTRL2,speedb2); 
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
