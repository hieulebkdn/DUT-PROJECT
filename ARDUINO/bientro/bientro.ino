int led[6] = {8,9,10,11,12,13};
void setup() {
  for(int i=0;i<6;i++)
  {
    pinMode(led[i],OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(A5);
  
  Serial.println(value);
 for(int i=0;i<6;i++)
  {
    digitalWrite(led[i],HIGH);
    delay(value);
  }

   for(int i=5;i>=0;i--)
  {
    digitalWrite(led[i],LOW);
    delay(value);
  }
}
