#include <NewPing.h>
#define sensor1 2
#define sensor2 3
#define sensor3 4

#define M1A 6
#define M1B 7
#define M2A 8
#define M2B 9


#define EN1 5
#define EN2 10

# define echo A0
#define trig A1

NewPing sonar(trig,echo, 200);
char Bluetooth;
int l1;
int l2;
int l3;
int Laststate;

int drive_distance = 150;   // cm
int motor_power = 90;      // 0-255
const int motor_offset = 5;       // Diff. when driving straight
const int wheel_d = 64;           // Wheel diameter (mm)
const float wheel_c = PI * wheel_d; // Wheel circumference (mm)
const int counts_per_rev = 20;   // (4 pairs N-S) * (48:1 gearbox) * (2 falling/rising edges) = 384



#define  enc_l_pin 12        
#define  enc_r_pin 13

volatile unsigned long enc_l = 0;
volatile unsigned long enc_r = 0;




//prototypes for functions
void Forward(int speed);
void Backward(int speed);
void Right(int speed);
void Left(int speed);
void Stop();
void countLeft();
void countRight();
void driveStraight(float dist, int power);




void setup()
{
pinMode(echo,OUTPUT);
 pinMode(trig,OUTPUT);
 pinMode(M1A,OUTPUT);
 pinMode(M1B,OUTPUT);
 pinMode(M2A,OUTPUT);
 pinMode(M2B,OUTPUT);
 pinMode(EN1,OUTPUT);
 pinMode(EN2,OUTPUT);
 pinMode(sensor1,INPUT);
 pinMode(sensor2,INPUT);
 pinMode(sensor3,INPUT);
 Serial.begin(9600);


attachInterrupt(digitalPinToInterrupt(enc_l_pin), countLeft, CHANGE);
attachInterrupt(digitalPinToInterrupt(enc_r_pin), countRight, CHANGE);

 }

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0)
{
  Bluetooth=Serial.read();
  Serial.println(Bluetooth);
  if(Bluetooth=='Q')
  {
    Serial.println("I am In If");
    Phase1();
    }

  if(Bluetooth=='W')
  {
    Phase2();
    }  
  if(Bluetooth=='E')
  {
    Phase3();
    }

  }
}

void Phase1()
{
  Serial.println("I am in Phase 1");
while(1)
{
  Bluetooth = Serial.read();
 if(Bluetooth=='W')
 Phase2();
 if(Bluetooth=='E')
 Phase3();


 unsigned int distanceInCms = sonar.ping() / US_ROUNDTRIP_CM;
       if(Bluetooth == 'F' && distanceInCms<40) Forward(255);
      else if(Bluetooth=='F') Forward(255);
      else if(Bluetooth=='B') Backward(255);
       else if(Bluetooth=='R') Right(255);
       else if(Bluetooth=='L') Left(255);
       else Stop();
  
  
  }
}
void Phase2()
{
  Serial.println("I am in Phase 2");
while(1)
{
  Bluetooth = Serial.read();
 if(Bluetooth=='Q')
 Phase1();
 if(Bluetooth=='E')
 Phase3();

l1=digitalRead(sensor1);
l2=digitalRead(sensor2);
l3=digitalRead(sensor3);
if((l1==0&&l2==1&&l3==1 )||(l1==0&&l2==0&&l3==1))
        {
          Left(90);
          Laststate=1;
         }
         else if((l1==1&&l2==1&&l3==0)||(l1==1&&l2==0&&l3==0))
         {
          Right(90);
          Laststate=3;
          } 
          else if(l1==1&&l2==0&&l3==1) 
         {
          Forward(90);
          Laststate=2;
          }
          else if((l1==0&&l2==0&&l3==0)||(l1==1&&l2==1&&l3==1)) 
          { 
              if(Laststate==2)Forward(90);
              else if(Laststate==3) Right(90);
              else if(Laststate==1) Left(90);
            
            }
  
  }
}
void Phase3()
{
   Serial.println("I am in Phase 3");
while(1)
{
 Bluetooth = Serial.read();
 if(Bluetooth=='W')
 Phase2();
 if(Bluetooth=='Q')
 Phase1();
  
if(Bluetooth=='L')
driveStraight(drive_distance, motor_power); 
  }

}
// directions functions
void Forward(int speed)
{
      digitalWrite(M1A,HIGH);
      digitalWrite(M1B,LOW);

      digitalWrite(M2A,LOW);
      digitalWrite(M2B,HIGH);
      analogWrite(EN1,speed);
      analogWrite(EN2,speed);
  }
void Backward(int speed)
{
  digitalWrite(M1A,LOW);
      digitalWrite(M1B,HIGH);

      digitalWrite(M2A,HIGH);
      digitalWrite(M2B,LOW);
      analogWrite(EN1,speed);
      analogWrite(EN2,speed);
  }
  void Right(int speed)
  {
      digitalWrite(M1A,HIGH);
      digitalWrite(M1B,LOW);

      digitalWrite(M2A,LOW);
      digitalWrite(M2B,LOW);

           analogWrite(EN1,speed);
      analogWrite(EN2,speed);
    }

void Left(int speed)
{     
      digitalWrite(M1A,LOW);
      digitalWrite(M1B,LOW);

      digitalWrite(M2A,LOW);
      digitalWrite(M2B,HIGH);
           analogWrite(EN1,speed);
      analogWrite(EN2,speed);
  }
  void Stop()
  {
      digitalWrite(M1A,LOW);
      digitalWrite(M1B,LOW);
      digitalWrite(M2A,LOW);
      digitalWrite(M2B,LOW);
      digitalWrite(EN1,LOW);
      digitalWrite(EN2,LOW);
     
    }



    void driveStraight(float dist, int power) {

  unsigned long num_ticks_l;
  unsigned long num_ticks_r;

  int power_l = motor_power;
  int power_r = motor_power;

 
 unsigned long diff_l;
  unsigned long diff_r;

 enc_l = 0;
  enc_r = 0;

  unsigned long enc_l_prev = enc_l;
  unsigned long enc_r_prev = enc_r;

float num_rev = (dist * 10) / wheel_c;  // Convert to mm
  unsigned long target_count = num_rev * counts_per_rev;


  Serial.print("Driving for ");
  Serial.print(dist);
  Serial.print(" cm (");
  Serial.print(target_count);
  Serial.print(" ticks) at ");
  Serial.print(power);
  Serial.println(" motor power");


    // Drive until one of the encoders reaches desired count
  while ( (enc_l < target_count) && (enc_r < target_count) ) {

    // Sample number of encoder ticks
    num_ticks_l = enc_l;
    num_ticks_r = enc_r;

    // Print out current number of ticks
    Serial.print(num_ticks_l);
    Serial.print("\t");
    Serial.println(num_ticks_r);

    // Drive
    drive(power_l,power_r);

    // Number of ticks counted since last time
    diff_l = num_ticks_l - enc_l_prev;
    diff_r = num_ticks_r - enc_r_prev;

    // Store current tick counter for next time
    enc_l_prev = num_ticks_l;
    enc_r_prev = num_ticks_r;

     if ( diff_l > diff_r ) {
      power_l -= motor_offset;
      power_r += motor_offset;
    }

    // If right is faster, slow it down and speed up left
    if ( diff_l < diff_r ) {
      power_l += motor_offset;
      power_r -= motor_offset;
    }

    // Brief pause to let motors respond
    delay(20);
  }


  Stop();

  
    }

void drive(int power_a, int power_b) {

  // Constrain power to between -255 and 255
  power_a = constrain(power_a, -255, 255);
  power_b = constrain(power_b, -255, 255);

  // Left motor direction
  if ( power_a < 0 ) {
    digitalWrite(M1A, LOW);
    digitalWrite(M1B, HIGH);
  } else {
    digitalWrite(M1A, HIGH);
    digitalWrite(M1B, LOW);
  }

  // Right motor direction
  if ( power_b < 0 ) {
    digitalWrite(M2A, LOW);
    digitalWrite(M2B, HIGH);
  } else {
    digitalWrite(M2A, HIGH);
    digitalWrite(M2B, LOW);
  }

  // Set speed
  analogWrite(EN1, abs(power_a));
  analogWrite(EN2, abs(power_b));
}


    void countLeft() {
  enc_l++;
}

void countRight() {
  enc_r++;
}


