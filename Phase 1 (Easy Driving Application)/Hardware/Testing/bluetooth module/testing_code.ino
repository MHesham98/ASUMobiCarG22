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
  digitalWrite(13,1);
  digitalWrite(12,0);
  analogWrite(11,200);
  digitalWrite(4,1);
  digitalWrite(7,0);
  analogWrite(5,200);
  
  
 }
