
#include <NewPing.h>
NewPing sonar(13, 12, 200);
#define M1A 6
#define M1B 7

#define M2A 8
#define M2B 9


#define EN1 5
#define EN2 10

char k;

void setup() 
{ 
Serial.begin(9600); 
 pinMode(13,OUTPUT);
 pinMode(12,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(7,OUTPUT);
 
} 
void loop() 
{ 
 
if (Serial.available() > 0) 
{ 
 unsigned int distanceInCms = sonar.ping() / US_ROUNDTRIP_CM;
 Serial.println("Distance: " + String(distanceInCms) + "cm");
 char Data = Serial.read();  
 if(Data=='F' && distanceInCms<30); // just do not do anything
else if(Data == 'F')        //move forwards 
 { 
   forward();
 } 
 else if (Data == 'B')       //move backwards 
 { 
 backward();
 } 
 else if (Data == 'R')    //right 
 { 
   right();
 } 
 else if (Data == 'L')     //left 
 { 
   left();
 } 
 } 
} 
void forward()
{
 digitalWrite(12,1);
  analogWrite(3,200);
  digitalWrite(7,1);
  analogWrite(5,200);
};
void backward()
{
 digitalWrite(13,1);
  analogWrite(5,200);
  digitalWrite(8,1);
  analogWrite(3,200);
};
void left()
{
  digitalWrite(7,1);
  analogWrite(5,200);
};

void right()
{
  digitalWrite(12,1);
  analogWrite(3,200);
};
