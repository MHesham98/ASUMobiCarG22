void setup() 
{ 
Serial.begin(9600); 
 pinMode(13,OUTPUT);
 pinMode(12,OUTPUT);
 pinMode(11,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(7,OUTPUT);
} 
void loop() 
{ 
if (Serial.available() > 0) 
{ 
 char Data = Serial.read();  
 if(Data == 'F')        //move forwards 
 { 
   digitalWrite(13,1);
  digitalWrite(12,0);
  analogWrite(11,200);
  digitalWrite(4,1);
  digitalWrite(7,0);
  analogWrite(5,200);
 } 
 else if (Data == 'B')       //move backwards 
 { 
   digitalWrite(13,0);
  digitalWrite(12,1);
  analogWrite(11,200);
  digitalWrite(4,0);
  digitalWrite(7,1);
  analogWrite(5,200);
  
  
 } 
 else if (Data == 'S')     //stop!! 
 {    
   digitalWrite(13,0);
  digitalWrite(12,0);
  analogWrite(11,0);
  digitalWrite(4,0);
  digitalWrite(7,0);
  analogWrite(5,0);
 } 
 else if (Data == 'R')    //right 
 { 
   digitalWrite(13,1);
  digitalWrite(12,0);
  analogWrite(11,200);
  digitalWrite(4,0);
  digitalWrite(7,0);
  analogWrite(5,0);
 } 
 else if (Data == 'L')     //left 
 { 
   digitalWrite(13,0);
  digitalWrite(12,0);
  analogWrite(11,200);
  digitalWrite(4,1);
  digitalWrite(7,0);
  analogWrite(5,200);
 } 

 } 
} 
