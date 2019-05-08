int led13 = 13;

void setup() {
  // put your setup code here, to run once:
    pinMode(led13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int x=0; x<3; x++){
   digitalWrite(led13,HIGH);
   delay(250);
   digitalWrite(led13,LOW);
   delay(150);
  }
   delay(5000);
  for(int i=0; i<3; i++){
   digitalWrite(led13,HIGH);
   delay(600);
   digitalWrite(led13,LOW);
   delay(300);
  }
   delay(5000);
   
}
