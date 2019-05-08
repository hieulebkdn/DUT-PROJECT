int ledPins[] = {3,4,5,6,7,8,9,10,11,12};
int pinCount = 10;
int timer[] ={500,400,300,200,100,100,200,300,400,500};
void setup() {
   for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
  }
}

void loop() {
   // loop from the lowest pin to the highest:
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    // turn the pin on:
    digitalWrite(ledPins[thisPin], HIGH);
    delay(timer[thisPin]);
    // turn the pin off:
    digitalWrite(ledPins[thisPin], LOW);
  }

  // loop from the highest pin to the lowest:
  for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) {
    // turn the pin on:
    digitalWrite(ledPins[thisPin], HIGH);
    delay(timer[thisPin]);
    // turn the pin off:
    digitalWrite(ledPins[thisPin], LOW);
  }
}
