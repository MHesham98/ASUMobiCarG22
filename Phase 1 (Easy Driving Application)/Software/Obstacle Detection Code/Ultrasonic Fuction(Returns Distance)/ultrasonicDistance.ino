const int trigPin = 9;  //Any 2 Digital I/O Pins
const int echoPin = 10;

/*
Serial.begin(9600);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output which will trigger the square wave
pinMode(echoPin, INPUT); // Sets the echoPin as an Input which will recieve the square wave
*/
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
    //Serial.print("Distance: ");
    //Serial.println(distance);
    return distance;
  }

