#include <TFT_eSPI.h>
#include <Multichannel_Gas_GMXXX.h>
#include <Wire.h>
#include "DHT.h"

GAS_GMXXX<TwoWire> gas;

TFT_eSPI tft;
TFT_eSprite spr = TFT_eSprite(&tft);

#define DHTPIN 0
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(3);

  gas.begin(Wire, 0x08);

  dht.begin();

  spr.createSprite(tft.width(), tft.height());

}

void loop() {

  int no2, c2h5ch, voc, co;


  spr.fillSprite(TFT_BLACK);
  spr.setFreeFont(&FreeSansBoldOblique18pt7b);
  spr.setTextColor(TFT_WHITE);
  spr.drawString("Gas Monitor", 60 - 15, 10 , 1);
  for (int8_t line_index = 0; line_index < 5 ; line_index++)
  {
    spr.drawLine(0, 50 + line_index, tft.width(), 50 + line_index, TFT_GREEN);
  }

  spr.drawRoundRect(5, 60, (tft.width() / 2) - 20 , tft.height() - 65 , 10, TFT_WHITE); // L1


  // VOC

  voc = gas.getGM502B();
  if (voc > 999) voc = 999;
  Serial.print("VOC: ");
  Serial.print(voc);
  Serial.println(" ppm");


  spr.setFreeFont(&FreeSansBoldOblique12pt7b);
  spr.setTextColor(TFT_RED);
  spr.drawString("VOC", 7 , 65 , 1);
  spr.setFreeFont(&FreeSansBoldOblique12pt7b);
  spr.setTextColor(TFT_WHITE);
  spr.drawNumber(voc, 15, 100, 1);
  spr.setTextColor(TFT_GREEN);
  spr.drawString("ppm", 55, 108, 1);


  //CO

  co = gas.getGM702B();
  if (co > 999) co = 999;
  Serial.print("CO: ");
  Serial.print(co);
  Serial.println(" ppm");

  spr.setFreeFont(&FreeSansBoldOblique12pt7b);
  spr.setTextColor(TFT_RED);
  spr.drawString("CO", 7 , 150 , 1);
  spr.setFreeFont(&FreeSansBoldOblique12pt7b);
  spr.setTextColor(TFT_WHITE);
  spr.drawNumber(co, 15, 185, 1);
  spr.setTextColor(TFT_GREEN);
  spr.drawString("ppm", 55, 193, 1);

  //Temp

  float t = dht.readTemperature();
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println( "*C");

  spr.drawRoundRect((tft.width() / 2) - 10  , 60, (tft.width() / 2) / 2 , (tft.height() - 65) / 2 , 10, TFT_BLUE); // s1

  spr.setFreeFont(&FreeSansBoldOblique9pt7b);
  spr.setTextColor(TFT_RED) ;
  spr.drawString("Temp", (tft.width() / 2) - 1  , 70 , 1); // Print the test text in the custom font
  spr.setTextColor(TFT_WHITE);
  spr.drawNumber(t, (tft.width() / 2) - 1 , 100, 1);
  spr.setTextColor(TFT_GREEN);
  spr.drawString("oC", (tft.width() / 2) + 20, 100, 1);


  //NO2

  no2 = gas.getGM102B();
  if (no2 > 999) no2 = 999;
  Serial.print("NO2: ");
  Serial.print(no2);
  Serial.println(" ppm");

  spr.drawRoundRect(((tft.width() / 2) + (tft.width() / 2) / 2) - 5  , 60, (tft.width() / 2) / 2 , (tft.height() - 65) / 2 , 10, TFT_BLUE); // s2

  spr.setFreeFont(&FreeSansBoldOblique9pt7b);
  spr.setTextColor(TFT_RED) ;
  spr.drawString("NO2", ((tft.width() / 2) + (tft.width() / 2) / 2)   , 70 , 1); // Print the test text in the custom font
  spr.setTextColor(TFT_WHITE);
  spr.drawNumber(no2, ((tft.width() / 2) + (tft.width() / 2) / 2)  , 100, 1);
  spr.setTextColor(TFT_GREEN);
  spr.drawString("ppm", ((tft.width() / 2) + (tft.width() / 2) / 2) + 30 , 110, 1);



  //Humdity

  float h = dht.readHumidity();
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println( "%");

  spr.drawRoundRect((tft.width() / 2) - 10 , (tft.height() / 2) + 30, (tft.width() / 2) / 2 , (tft.height() - 65) / 2 , 10, TFT_BLUE); // s3

  spr.setFreeFont(&FreeSansBoldOblique9pt7b);
  spr.setTextColor(TFT_RED) ;
  spr.drawString("Humi", (tft.width() / 2) - 1 , (tft.height() / 2) + 40 , 1); // Print the test text in the custom font
  spr.setTextColor(TFT_WHITE);
  spr.drawNumber(h, (tft.width() / 2) - 1 , (tft.height() / 2) + 70, 1);
  spr.setTextColor(TFT_GREEN);
  spr.drawString("%", (tft.width() / 2) + 21, (tft.height() / 2) + 70, 1);


  //C2H5CH

  c2h5ch = gas.getGM302B();
  if (c2h5ch > 999) c2h5ch = 999;
  Serial.print("C2H5CH: ");
  Serial.print(c2h5ch);
  Serial.println(" ppm");

  spr.drawRoundRect(((tft.width() / 2) + (tft.width() / 2) / 2) - 5  , (tft.height() / 2) + 30, (tft.width() / 2) / 2 , (tft.height() - 65) / 2 , 10, TFT_BLUE); // s4

  spr.setFreeFont(&FreeSansBoldOblique9pt7b);
  spr.setTextColor(TFT_RED) ;
  spr.drawString("Ethyl", ((tft.width() / 2) + (tft.width() / 2) / 2)   , (tft.height() / 2) + 40 , 1); // Print the test text in the custom font
  spr.setTextColor(TFT_WHITE);
  spr.drawNumber(c2h5ch, ((tft.width() / 2) + (tft.width() / 2) / 2) , (tft.height() / 2) + 70, 1);
  spr.setTextColor(TFT_GREEN);
  spr.drawString("ppm", ((tft.width() / 2) + (tft.width() / 2) / 2) + 30 , (tft.height() / 2) + 80, 1);

  Serial.println("--------------------------------------------------------");


  spr.pushSprite(0, 0);

  delay(2000);


}
