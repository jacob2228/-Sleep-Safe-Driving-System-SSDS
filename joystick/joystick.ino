#define xpin A0
#define ypin A1
int x,y;
void setup() {
  
 pinMode(xpin,INPUT);

// pinMode(ypin,INPUT);
 Serial.begin(9600);

}

void loop() {
x=analogRead(xpin);
y=analogRead(ypin);
Serial.println(x);
Serial.print("\t");
Serial.println(y);

}
