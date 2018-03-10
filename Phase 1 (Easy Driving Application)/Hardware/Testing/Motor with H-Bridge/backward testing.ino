void setup() {
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(7,OUTPUT);
}
void loop()
{
  digitalWrite(13,0);
  digitalWrite(12,1);
  analogWrite(11,200);
  digitalWrite(4,0);
  digitalWrite(7,1);
  analogWrite(5,200);
  
  
 }
