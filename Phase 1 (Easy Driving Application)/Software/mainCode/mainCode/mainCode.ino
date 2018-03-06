
//pinat el motors
#define motor1Enable 3
#define motor1Forward 13
#define motor1Backward 4
#define motor2Enable 5
#define motor2Forward 7
#define motor2Backward 8

int motor1Speed = 255;
int motor2Speed = 255;

//pinat el ultrasonic wel limit
#define trigPin 9
#define echoPin 10
#define obstacleLimit 20

//pinat el bluetooth

//el functions
void moveForward()
  {
    analogWrite(motor1Enable,motor1Speed);
    analogWrite(motor2Enable,motor2Speed);

    digitalWrite(motor1Forward, HIGH);
    digitalWrite(motor2Forward, HIGH);
    
    digitalWrite(motor1Backward, LOW);
    digitalWrite(motor2Backward, LOW);
  }


void moveBackward()
  {
    analogWrite(motor1Enable,motor1Speed);
    analogWrite(motor2Enable,motor2Speed);

    digitalWrite(motor1Forward, LOW);
    digitalWrite(motor2Forward, LOW);
    
    digitalWrite(motor1Backward, HIGH);
    digitalWrite(motor2Backward, HIGH);
  }


void moveLeft()
  {
    analogWrite(motor1Enable,motor1Speed);
    analogWrite(motor2Enable,motor2Speed);

    digitalWrite(motor1Forward, HIGH);
    digitalWrite(motor2Forward, LOW);
    
    digitalWrite(motor1Backward, LOW);
    digitalWrite(motor2Backward, HIGH);
  }


void moveRight()
  {
    analogWrite(motor1Enable,motor1Speed);
    analogWrite(motor2Enable,motor2Speed);

    digitalWrite(motor1Forward, LOW);
    digitalWrite(motor2Forward, HIGH);
    
    digitalWrite(motor1Backward, HIGH);
    digitalWrite(motor2Backward, LOW);
  }

  
void Stop()
  {
    analogWrite(motor1Enable,motor1Speed);
    analogWrite(motor2Enable,motor2Speed);

    digitalWrite(motor1Forward, LOW);
    digitalWrite(motor2Forward, LOW);
    
    digitalWrite(motor1Backward, LOW);
    digitalWrite(motor2Backward, LOW);
  }


  char carDirection()
    {
      if(Serial.available() > 0)
      {
        return Serial.read();   
      }
    return 'N';
    }

float ultrasonicDistance()
  {
    long duration;
    float distance;

    //the trigger wave is low for 2 microseconds followed by by high for 10 microseconds
    
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW); 

    //Calculating the duration the wave took to tarvel double the distance(raye7-rage3)  
    
    duration = pulseIn(echoPin, HIGH);
    distance= duration*0.01715;  //distance = velocity * time   ---> 343m/s * 10^2 * duration * 10^-6   and divide by 2 to get the actual distacne
    return distance;
  }
    
bool obstacle()
{
  if (ultrasonicDistance()>obstacleLimit)
  {
   return true;
   }
   return false;
  }
  
void setup() {
  // setup el motor

pinMode(motor1Enable,OUTPUT);
pinMode(motor1Forward,OUTPUT);
pinMode(motor1Backward,OUTPUT);
pinMode(motor1Enable,OUTPUT);
pinMode(motor1Forward,OUTPUT);
pinMode(motor1Backward,OUTPUT);

 //pins el bluetooth w el serial
 Serial.begin(9600);

 //pins el ultrasonic
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);

}

void loop() {
  // movement
switch(carDirection())
{
  case 'F':
  moveForward();
  break;

  case 'B':
  moveBackward();
  break;

  case 'L':
  moveLeft();
  break;

  case 'R':
  moveRight();
  break;

  case 'N':
  break;

  }

  if(obstacle() == true)
  {
    Stop();
    }
}
