int val;
void setup()
{
  Serial.begin(9600);
  analogReference(EXTERNAL);
}
 
void loop()
{
  val=analogRead(A3);
  Serial.println(val);
  delay(1000);
}
