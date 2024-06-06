#include <Arduino.h>
#include "ads7844.h"
#include "SPI.h"

//Set the CS Pin

ADS7844 ads7844(10);

void setup() {
  Serial.begin(115200);
  while(!Serial.available());
  //Read one channel 
  Serial.print("ADS7844 Value : ");
  Serial.println(ads7844.read_CH(0));
}

void loop() {
  delay(1000);
  uint16_t data[8];
  //Read All channels into data
  ads7844.readALL(data);
  for (int x = 0; x < 8; x++)
  {
    Serial.printf("Data of chan : %x :: %x \n\r",x,data[x]);
  }
}

