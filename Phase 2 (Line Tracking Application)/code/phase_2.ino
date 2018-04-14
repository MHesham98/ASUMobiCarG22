int sensorleft=11;
int sensorcenter=10;
int sensorright=9;
int l1=1;
int l2=1;//readings of sensors
int l3=1;

void setup() {
   pinMode(13,OUTPUT);
 pinMode(12,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(7,OUTPUT);
  pinMode(9,INPUT);
 pinMode(10,INPUT);
 pinMode(11,INPUT);
 Serial.begin(9600);
}

void loop() {
 l1=digitalRead(sensorleft);
l2=digitalRead(sensorcenter);
l3=digitalRead(sensorright);

if((l1==1&&l2==1&&l3==1)||(l1==0&&l2==0&&l3==0)) //stop
{
   digitalWrite(13,0);
  digitalWrite(12,0);
  analogWrite(3,0);
  digitalWrite(8,0);
  digitalWrite(7,0);
  analogWrite(5,0);
}
else if(l1==1&&l2==0&&l3==0||l1==1&&l2==1&&l3==0)   //left turn
{
  digitalWrite(13,1);
  digitalWrite(12,0);
  analogWrite(3,110);
  digitalWrite(8,0);
  digitalWrite(7,0);
  analogWrite(5,110);
 }
 else if(l1==0&&l2==0&&l3==1||l1==0&&l2==1&&l3==1) //right turn
{
  digitalWrite(13,0);
  digitalWrite(12,0);
  analogWrite(3,110);
  digitalWrite(8,0);
  digitalWrite(7,1);
  analogWrite(5,110);
  }
  else if(l1==0&&l2==1&&l3==0)  //go forward straight
  {
     
  digitalWrite(13,1);
  digitalWrite(12,0);
  analogWrite(5,110);
  digitalWrite(8,0);
  digitalWrite(7,1);
  analogWrite(3,110);
   }
}



