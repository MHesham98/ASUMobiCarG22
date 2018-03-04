#include <AFMotor.h>

//creates two objects to control the terminal 3 and 4 of motor shield 
//AF_DCMotor motor1(3); 
//AF_DCMotor motor2(4); 

char command; 


void setup() {
/*int Motor1Enable = 3; 
int Motor1forward = 13; //3ayzen n8yrha 3ashan 2 de fel gyroscope
int Motor1backward = 4;   

int Motor2Enable = 5; 
int Motor2forward = 7;
int Motor2backward = 8;*/   

/*Motor Connections as Shown Above*/
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
pinMode(Motor1Enable,OUTPUT);
pinMode(Motor1forward, OUTPUT); 
pinMode(Motor1backward, OUTPUT);
pinMode(Motor2Enable,OUTPUT);
pinMode(Motor2forward, OUTPUT); 
pinMode(Motor2backward, OUTPUT);

}
void forward()
{
  analogWrite(Motor1Enable, 255); 
analogWrite(Motor2Enable, 255); 

digitalWrite(Motor1forward, HIGH); 
digitalWrite(Motor2forward, HIGH);  

digitalWrite(Motor1backward, LOW); 
digitalWrite(Motor2backward, LOW);

}

void back()
{
  analogWrite(Motor1Enable, 255); 
analogWrite(Motor2Enable, 255); 

digitalWrite(Motor1forward, LOW); 
digitalWrite(Motor2forward, LOW);  

digitalWrite(Motor1backward, HIGH); 
digitalWrite(Motor2backward, HIGH);

}

void left()
{
  analogWrite(Motor1Enable, 255); 
analogWrite(Motor2Enable, 255); 

digitalWrite(Motor1forward, HIGH); 
digitalWrite(Motor2forward, LOW);  

digitalWrite(Motor1backward, LOW); 
digitalWrite(Motor2backward, HIGH);

}

void right()
{
  analogWrite(Motor1Enable, 255); 
analogWrite(Motor2Enable, 255); 

digitalWrite(Motor1forward, LOW); 
digitalWrite(Motor2forward, HIGH);  

digitalWrite(Motor1backward, HIGH); 
digitalWrite(Motor2backward, LOW);

}

void Stop()
{
  
  digitalWrite(Motor1forward, LOW); 
digitalWrite(Motor2forward, LOW);  

digitalWrite(Motor1backward, LOW); 
digitalWrite(Motor2backward, LOW);  

}



void loop() {
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    Stop(); //initialize with motors stoped
    //Change pin mode only if new command is different from previous.   
    //Serial.println(command);
    switch(command){
    case 'F':  
      forward();
      break;
    case 'B':  
       back();
      break;
    case 'L':  
      left();
      break;
    case 'R':
      right();
      break;
    }
  } 
}


}
