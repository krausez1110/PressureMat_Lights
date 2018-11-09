/*
 * Author: SMRAZA KEEN
 * Date:2016/6/29
 * IDE V1.6.9
 * Email:TechnicSmraza@outlook.com
 * Function:
 */
const int TrigPin = 2;
const int EchoPin = 3;
float cm;
void setup()
{
Serial.begin(9600);
pinMode(TrigPin, OUTPUT);
pinMode(EchoPin, INPUT);
pinMode(LED_BUILTIN, OUTPUT);
}

void LED(float a) {
  int d;
  if(a>200)
  {
    d=1000;
  }
  else if(a<200 && a>100)
  {
    d=500;
  }
  else if(a<100 && a>50)
  {
    d=100;
  }
  else if(a<50)
  {
    d=0;
    digitalWrite(LED_BUILTIN, HIGH);
    
  }
  if(d>0)
  {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(d);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(d);    // wait for a second
  }
  Serial.print("\t");
  Serial.print("Delay: ");
  Serial.print(d);
  Serial.print("\t");
  Serial.print("cm: ");
  Serial.print(a);
  Serial.print("\t");
}

void loop()
{
  while(1)
  {
digitalWrite(TrigPin, LOW);       
delayMicroseconds(2);
digitalWrite(TrigPin, HIGH);
delayMicroseconds(10);
digitalWrite(TrigPin, LOW);
cm = pulseIn(EchoPin, HIGH) / 58.0; //The echo time is converted into cm
cm = (int(cm * 100.0)) / 100.0;     //Keep two decimal places
LED(cm);
Serial.print("Distance\t=\t");
Serial.print(cm);
Serial.print("cm");
Serial.println();
delay(1000);
  }
}
