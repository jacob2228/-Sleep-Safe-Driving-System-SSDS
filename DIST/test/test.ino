
float i,val=0,tp=0;
void setup() {
  pinMode(0,INPUT);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int n=Serial.read();
n=n-48;
Serial.print(n);
Serial.print("\t");

if((n==-49))
{ 
  i=100;
 goto last2;

}
else if(n==(-35))
{
  i=100;
  val=tp;
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
Serial.print(i);
Serial.print('\t');
Serial.print(val);
Serial.print("\t");
Serial.println(tp);
delay(100);
}
