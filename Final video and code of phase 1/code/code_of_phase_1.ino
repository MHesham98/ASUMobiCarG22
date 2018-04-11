
#include <NewPing.h>
NewPing sonar(9, 10, 200);
// prototybes of functions
void forward();
void backward();
void left();
void right();

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
 if(Data=='F' && distanceInCms<30)
 {
  digitalWrite(13,0);
  digitalWrite(12,0);
  analogWrite(3,0);
  digitalWrite(8,0);
  digitalWrite(7,0);
  analogWrite(5,0);
 }
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
  digitalWrite(12,0);
  analogWrite(5,200);
  digitalWrite(8,1);
  digitalWrite(7,0);
  analogWrite(3,200);
};
void left()
{
 digitalWrite(13,0);
  digitalWrite(12,0);
  analogWrite(3,200);
  digitalWrite(8,0);
  digitalWrite(7,1);
  analogWrite(5,200);
};

void right()
{
 digitalWrite(13,0);
  digitalWrite(12,1);
  analogWrite(3,200);
  digitalWrite(8,0);
  digitalWrite(7,0);
};
