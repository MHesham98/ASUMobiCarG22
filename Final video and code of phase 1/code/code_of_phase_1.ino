
#include <NewPing.h>
NewPing sonar(13, 12, 200);
#define M1A 6
#define M1B 7

#define M2A 8
#define M2B 9


#define EN1 5
#define EN2 10

char k;

void setup() {
  // put your setup code here, to run once:
  pinMode(M1A,OUTPUT);
  pinMode(M1B,OUTPUT);

  pinMode(M2A,OUTPUT);
  pinMode(M2B,OUTPUT);

  pinMode(EN1,OUTPUT);
  pinMode(EN2,OUTPUT);

  
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() >0){
 
 unsigned int distanceInCms = sonar.ping() / US_ROUNDTRIP_CM;
 Serial.println("Distance: " + String(distanceInCms) + "cm");
  
    k=Serial.read();
    if(k== 'F'&& distanceInCms<100);
    else if(k == 'F')
    {

      digitalWrite(M1A,HIGH);
      digitalWrite(M1B,LOW);

      digitalWrite(M2A,LOW);
      digitalWrite(M2B,HIGH);


      digitalWrite(EN1,HIGH);
      digitalWrite(EN2,HIGH);
      
     }
     else if(k == 'B'){
      digitalWrite(M1A,LOW);
      digitalWrite(M1B,HIGH);

      digitalWrite(M2A,HIGH);
      digitalWrite(M2B,LOW);


      digitalWrite(EN1,HIGH);
      digitalWrite(EN2,HIGH);
      
      }
      else if(k == 'L'){
      digitalWrite(M1A,LOW);
      digitalWrite(M1B,LOW);

      digitalWrite(M2A,LOW);
      digitalWrite(M2B,HIGH);


      digitalWrite(EN1,HIGH);
      digitalWrite(EN2,HIGH);
      
      }
      else if(k == 'R'){
      digitalWrite(M1A,HIGH);
      digitalWrite(M1B,LOW);

      digitalWrite(M2A,LOW);
      digitalWrite(M2B,LOW);


      digitalWrite(EN1,HIGH);
      digitalWrite(EN2,HIGH);
      
      }
      else{
        
        digitalWrite(M1A,LOW);
      digitalWrite(M1B,LOW);

      digitalWrite(M2A,LOW);
      digitalWrite(M2B,LOW);


      digitalWrite(EN1,LOW);
      digitalWrite(EN2,LOW);
      
        }
    
  }

}
    
    
