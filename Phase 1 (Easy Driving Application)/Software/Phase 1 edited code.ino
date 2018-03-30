//Bluetooth module
#include <SoftwareSerial.h>
#define rxPin 0
#define txPin 1
SoftwareSerial rf(rxPin,txPin);
char state ;
//H bridge Module

 int in1 = 8;
 int in2 = 9; 

 int in3 = 12;
 int in4 = 13;

//ultrasonic
const int trigPin = 10;
const int echoPin = 11;
// defines variables


//servo module
#include <Servo.h>
Servo SM ; // define the name of the  servo object
int servo_angle= 0; // set the angle of the servo



float ultraread();
 void FWD(void);
void Back(void);
void Stop(void);
  void Right(void);
  void Left(void);
void Avoid(void);

void setup() {
  // put your setup code here, to run once:
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
SM.attach(6);//servo definition
SM.write(90);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);

pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
rf.begin(9600);
}

void loop() {



Serial.println("STart   ");
if(rf.available()){
  state=rf.read();
  Serial.println("STAT IS :   ");
  Serial.println(state);
  }

  if(state=='S'){Stop();}
else if(state=='F'){FWD();}
else if(state=='B'){Back();}
else if(state=='R'){Right();}
else if(state=='L'){Left();}
else if (state=='v' ||state=='V'){Avoid();}


}


  void FWD(void){

digitalWrite(in1, HIGH); 
digitalWrite(in2, LOW);
 
digitalWrite(in3, HIGH); 
digitalWrite(in4, LOW);
Serial.println("    fw");
Serial.println();
Serial.println(ultraread());




  }
  void Back(void){

digitalWrite(in1, LOW); 
digitalWrite(in2, HIGH);
  
digitalWrite(in3, LOW); 
digitalWrite(in4, HIGH);

Serial.println(" bk");

  }

  void Stop(void){

digitalWrite(in1, LOW); 
digitalWrite(in2, LOW);

digitalWrite(in3, LOW); 
digitalWrite(in4, LOW);

  }

  void Right(void){
    
  
digitalWrite(in1, LOW); 
digitalWrite(in2, LOW);
 
digitalWrite(in3, HIGH); 
digitalWrite(in4, LOW);

    }

    void Left(void){
    

digitalWrite(in1, HIGH); 
digitalWrite(in2, LOW);

digitalWrite(in3, LOW); 
digitalWrite(in4, LOW);

    }

  

float ultraread(){
int duration=0;
int distanceCm=0;
 
   // put your main code here, to run repeatedly:
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distanceCm= duration*0.034/2;
// Prints the distance on the Serial Monitor
return distanceCm;
}





void Avoid(void){
  float dist=ultraread() ;
  while(1){
    dist=ultraread();
    if(dist<20){while(1){Stop();
   dist=ultraread();
   Serial.println("LOL");
   if(dist>20){break;}
    }
      }
      else{Serial.println("STart   ");
if(rf.available()){
  state=rf.read();
  Serial.println("STAT ISXXXX :   ");
  Serial.println(state);
  }
if(state=='S'){Stop();}
else if(state=='F'){FWD();}
else if(state=='B'){Back();}
else if(state=='R'){Right();}
else if(state=='L'){Left();}
else if(state=='v' ||state=='V'){break;}
 
    }
    }
    }
  
