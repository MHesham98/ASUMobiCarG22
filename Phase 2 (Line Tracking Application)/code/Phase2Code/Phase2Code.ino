
//pinat el motors
#define motor1Enable 10
#define motor1Forward 4
#define motor1Backward 5
#define motor2Enable 11
#define motor2Forward 6
#define motor2Backward 7
#define comparisonPin A5

int motor1Speed = 50;
int motor2Speed = 50;
int IR[3];

//el functions

int adc(int analogread)
{
  if(analogread>analogRead(comparisonPin))
  {
    return 0;
    }
    return 1;
  }
  
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


  

  
void setup() {
  // setup el motor

pinMode(motor1Enable,OUTPUT);
pinMode(motor1Forward,OUTPUT);
pinMode(motor1Backward,OUTPUT);
pinMode(motor1Enable,OUTPUT);
pinMode(motor1Forward,OUTPUT);
pinMode(motor1Backward,OUTPUT);


 
 Serial.begin(9600);



}

void loop() {

  
  IR[0] = adc(analogRead(A0));
  IR[1] = adc(analogRead(A1));
  IR[2] = adc(analogRead(A2));
Serial.print(analogRead(A0));
Serial.print(" ");
Serial.print(analogRead(A1));
Serial.print(" ");
Serial.print(analogRead(A2));
Serial.print(" ");
Serial.print(comparisonPin);
Serial.println();
  if(IR[0] == 0 && IR[1] == 1 && IR[2] == 0)
  {
    //moveForward();
    Serial.println("Forward");
    }
   else if(IR[0] == 0 && IR[1] == 0 && IR[2] == 0)
  {
    //moveForward();
    Serial.println("Forward");
    } 
  else if(IR[0] == 1 && IR[1] == 1 && IR[2] == 1)
  {
    //moveForward();
    Serial.println("Forward");
    }
  else if(IR[0] == 1 && IR[1] == 0 && IR[2] == 0)
  {
    //moveLeft();
    Serial.println("LEFT");
    }
  else if(IR[0] == 1 && IR[1] == 1 && IR[2] == 0)
  {
    //moveLeft();
    Serial.println("LEFT");
    }  
  else  if(IR[0] == 0 && IR[1] == 0 && IR[2] == 1)
  {
    //moveRight();
    Serial.println("RIGHT");
    }
  else if(IR[0] == 0 && IR[1] == 1 && IR[2] == 1)
  {
    //moveRight();
    Serial.println("RIGHT");
    }
    
 delay(500);   
  
}
