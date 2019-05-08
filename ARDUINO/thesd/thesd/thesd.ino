/*
  SD card read/write

 This example shows how to read and write data to and from an SD card file
 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** SCK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)

 created   Nov 2010
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */

#include <SPI.h>
#include <SD.h>

File myFile;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);



  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


Serial.print("Khoi dong SD card...");

  if (!SD.begin(4)) { // check loi
    Serial.println("Loi khoi dong!");
    while (1);
  }
  Serial.println("Khoi dong SD card thanh cong");

  if(SD.exists("test01.txt")){
    SD.remove("test01.txt");
  }

  myFile = SD.open("test01.txt", FILE_WRITE);     //tao 1 file moi là test.txt
  if (myFile) {
    Serial.print("Dang viet vao file...");
    
    myFile.println("Nam dep trai"); // noi dung viet vao file
    // close the file:
    myFile.close();
    Serial.println("Ket thuc");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }

  Serial.println("mo file test.txt de doc du lieu");

  myFile = SD.open("test01.txt");   // mo lai file test01 trong the nho ra xem
  if (myFile) {
    Serial.println("test01.txt:");

    while (myFile.available()) {
      Serial.write(myFile.read());     // ghi noi dung trong file ra ngoai
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}

void loop() {
}
