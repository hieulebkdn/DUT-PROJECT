int ledr1 = 8;
int ledr2 = 9;
int ledy = 10;
int ledb1 = 11;
int ledb2 = 12;
int button = 2;
bool check = false;
unsigned long buttonPushedMillis;

void setup() {
  pinMode(button,INPUT);
  pinMode(ledr1,OUTPUT);
  pinMode(ledr2,OUTPUT);
  pinMode(ledy,OUTPUT);
  pinMode(ledb1,OUTPUT);
  pinMode(ledb2,OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  digitalWrite(ledb1,HIGH);
  digitalWrite(ledb2,HIGH);

  int state = digitalRead(button);
  if(state == HIGH) {
    buttonPushedMillis = currentMillis;
    check = true;
  }
  if(check){
    if((unsigned long)(currentMillis - buttonPushedMillis) >= 5000){
      digitalWrite(ledb1,LOW);
      digitalWrite(ledb2,LOW);
      digitalWrite(ledy,HIGH);
      delay(100);

      digitalWrite(ledy,LOW);
      digitalWrite(ledr1,HIGH);
      digitalWrite(ledr2,HIGH);
      delay(5000);

      digitalWrite(ledr1,LOW);
      digitalWrite(ledr2,LOW);
      digitalWrite(ledy,HIGH);
      delay(100);

      digitalWrite(ledy,LOW);
      digitalWrite(ledb1,HIGH);
      digitalWrite(ledb2,HIGH);

      delay(1000);
      check = false;
    }
  }
}
