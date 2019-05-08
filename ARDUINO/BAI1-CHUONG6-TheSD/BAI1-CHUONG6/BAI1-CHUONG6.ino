#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include "RTClib.h"
RTC_DS3231 rtc;

float tempC, tempF;
int hour, minute, second, day, month, year;
String nameFile = "TEMPLOG.TXT";
File myFile;

void getTimeDate(){
  DateTime now = rtc.now();
  hour = now.hour();
  minute = now.minute();
  second = now.second();
  day = now.day();
  month = now.month();
  year = now.year();
}

void getTemperature(){
  tempC = ((5*1000.0/1024.0) * analogRead(A0))/10.0;
  tempF = (tempC * 1.8) + 32;
}

void writeFile(){
   
  myFile = SD.open(nameFile,FILE_WRITE);
   
  if(myFile){
//    SD.remove(nameFile);
    Serial.println("Writing to this file...");
    getTimeDate();
    myFile.print(year);
    myFile.print("/");
    myFile.print(month);
    myFile.print("/");
    myFile.print(day);
    myFile.print(" ");
    myFile.print(hour);
    myFile.print(":");
    myFile.print(minute);
    myFile.print(":");
    myFile.print(second);
    myFile.println();
    getTemperature();
    myFile.print("Temperature:");
    myFile.print(tempC);
    myFile.print(" C");
    myFile.print(" ");
    myFile.print(tempF);
    myFile.println(" F");
    myFile.println();
    myFile.close();
    Serial.println("Done.");
  } else{
    Serial.println("error opening flie");
  }
}

void readFile(){
 
  myFile = SD.open(nameFile);
  if(myFile){
    Serial.println("Reading to this file...");
    Serial.print(nameFile);
    Serial.println(":");
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close();
  } else{
    Serial.println("error opening flie");
  }
}

void setup() {
  
  Serial.begin(9600);

  while(!Serial.available()){
    Serial.println("");
  }
  
  // RTC
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  
  // SD card
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.print("Initializing SD card...");
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
  
}

void loop() {
   SD.remove(nameFile);
  Serial.println("-------------------");
  
  delay(1000);  
  writeFile();
  delay(1000);
   readFile();
  delay(1000);
 
  
}
