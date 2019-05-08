#include <TimerOne.h>

int latchPin = 8;
int clockPin = 12;
int dataPin = 11;

int image = 0;
byte row = B10000000;

byte led[8][8] = {  
//  {195, 195, 195, 255, 255, 195, 195, 195},  //image0
//   {60, 24, 24, 24, 24, 24, 24, 60},  //image0
//    {248, 192, 192, 248, 248, 192, 192, 248},  //image0
//     { 126, 126,102, 102, 102, 102, 102, 102},  //image0
//       {195, 195, 195, 255, 255, 195, 195, 195},  //image0
//   {60, 24, 24, 24, 24, 24, 24, 60},  //image0
//    {248, 192, 192, 248, 248, 192, 192, 248},  //image0
//     { 126, 126,102, 102, 102, 102, 102, 102},  //image0
 
 
 {0, 56, 124, 186, 146, 130, 68, 56}, //image1
 {0, 56, 116, 242, 242, 130, 68, 56}, //image2
 {0, 56, 68, 226, 242, 226, 68, 56},  //image3
 {0, 56, 68, 130, 242, 242, 116, 56}, //image4
 {0, 56, 68, 130, 146, 186, 124, 56}, //image5
 {0, 56, 68, 130, 158, 158, 92, 56},  //image6
 {0, 56, 68, 142, 158, 142, 68, 56}   //image7
};

void setup(){
  Serial.begin(9600);
  
  pinMode(latchPin  , OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop(){
  image++;
  
  if (image>7) { image =0;}
  for(int i= 0; i < 255; i++){
    row = B10000000;
    Hinh();
  }
}

void Hinh(){
  Serial.print(B0000001);
  for (byte i = 0; i < 8; i++) {
    digitalWrite(latchPin, LOW);
    LuuTungBitCua1Hang(~led[image][i] );
    LuuTungBitCua1Hang(row);
    digitalWrite(latchPin, HIGH);
    row = row >> 1;  // hàng tiếp theo

//    if(row < B0000001){
//      row = B10000000;
//    }
  }
}

void LuuTungBitCua1Hang(byte byteRow){
  boolean pinState;
  digitalWrite(dataPin, LOW);
  // ----- Từng bit của hàng
  for (int k=0; k<8; k++) {
    digitalWrite(clockPin, LOW);
    if (byteRow & (1<<k)) {
      pinState = HIGH;
    }
    else {
      pinState = LOW;
    }
    digitalWrite(dataPin, pinState);
    digitalWrite(clockPin, HIGH);
    digitalWrite(dataPin, LOW);
  }
  digitalWrite(clockPin, LOW);
}
