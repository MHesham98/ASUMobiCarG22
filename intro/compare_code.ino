//pin def
int led1=13;
int led2=12;
int led3=11;

int in1=A0;
int in2=A1;
int in3=A2;
//global
int i;
//function of compare
void compare(int x,int y,int z)
{
  if(x>y&&x>z)
  digitalWrite(led1,1);
  else if(y>x&&y>z)
    digitalWrite(led2,1);
    else
      digitalWrite(led3,1);
  }
  
void setup()
{
  for( i=13;i>=11;i--)
  {
  pinMode(i,OUTPUT);
  }
}
void loop()
{
  int x=analogRead(in1);
  int y=analogRead(in2);
  int z=analogRead(in3);
  compare(x,y,z);
  delay(1000);
  digitalWrite(led1,0);
  digitalWrite(led2,0);
  digitalWrite(led3,0);



}
  

