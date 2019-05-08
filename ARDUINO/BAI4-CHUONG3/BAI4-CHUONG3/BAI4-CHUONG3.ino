//byte ledPin = {4,5,6,7,8,9,10,11,12,13};

void setup() {
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {  
  for(int x = 4; x < 14; x++){
    digitalWrite(x, LOW);
  }
  
  delay(100);
  
  for(int x = 4; x < 14; x++){
    float a = analogRead(A0);  
    float b = a*2500/1023;
    digitalWrite(x, HIGH);
    Serial.println(b);
    delay(b);
    //digitalWrite(x, LOW);
  }
  
}
