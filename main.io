#include <TFT_eSPI.h>

TFT_eSPI tft;
TFT_eSprite spr = TFT_eSprite(&tft);


void setup() {
  tft.begin();
  tft.setRotation(3);
  spr.createSprite(tft.width(), tft.height());

}

void loop() {
  spr.fillSprite(TFT_BLACK);
  spr.setFreeFont(&FreeSansBoldOblique18pt7b);
  spr.setTextColor(TFT_WHITE);
  spr.drawString("Pollution Monitor", 20, 10 , 1);// Print the test text in the custom font
  for (int8_t line_index = 0; line_index < 5 ; line_index++)
  {
    spr.drawLine(0, 50 + line_index, tft.width(), 50 + line_index, TFT_GREEN);
  }

  spr.drawRoundRect(5, 60, (tft.width() / 2) - 20 , tft.height() - 65 , 10, TFT_WHITE); // L1
  int val = 256;

  // VOC
  spr.setFreeFont(&FreeSansBoldOblique12pt7b);
  spr.setTextColor(TFT_RED);
  spr.drawString("VOC", 7 , 65 , 1);
  spr.setFreeFont(&FreeSansBoldOblique12pt7b);
  spr.setTextColor(TFT_WHITE);
  spr.drawNumber(val, 15, 100, 1);
  spr.setTextColor(TFT_GREEN);
  spr.drawString("ppm", 55, 108, 1);


  //CO
  spr.setFreeFont(&FreeSansBoldOblique12pt7b);
  spr.setTextColor(TFT_RED);
  spr.drawString("CO", 7 , 150 , 1);
  spr.setFreeFont(&FreeSansBoldOblique12pt7b);
  spr.setTextColor(TFT_WHITE);
  spr.drawNumber(val, 15, 185, 1);
  spr.setTextColor(TFT_GREEN);
  spr.drawString("ppm", 55, 193, 1);

  //Temp
  spr.drawRoundRect((tft.width() / 2) - 10  , 60, (tft.width() / 2) / 2 , (tft.height() - 65) / 2 , 10, TFT_BLUE); // s1

  spr.setFreeFont(&FreeSansBoldOblique9pt7b);
  spr.setTextColor(TFT_RED) ;
  spr.drawString("Temp", (tft.width() / 2) - 5  , 70 , 1); // Print the test text in the custom font
  spr.setTextColor(TFT_WHITE);
  spr.drawNumber(val, (tft.width() / 2) - 5 , 100, 1);
  spr.setTextColor(TFT_GREEN);
  spr.drawString("oC", (tft.width() / 2) + 30, 100, 1);


  //NO2
  spr.drawRoundRect(((tft.width() / 2) + (tft.width() / 2) / 2) - 5  , 60, (tft.width() / 2) / 2 , (tft.height() - 65) / 2 , 10, TFT_BLUE); // s2

  spr.setFreeFont(&FreeSansBoldOblique9pt7b);
  spr.setTextColor(TFT_RED) ;
  spr.drawString("NO2", ((tft.width() / 2) + (tft.width() / 2) / 2)   , 70 , 1); // Print the test text in the custom font
  spr.setTextColor(TFT_WHITE);
  spr.drawNumber(val, ((tft.width() / 2) + (tft.width() / 2) / 2)  , 100, 1);
  spr.setTextColor(TFT_GREEN);
  spr.drawString("ppm", ((tft.width() / 2) + (tft.width() / 2) / 2) + 30 , 110, 1);



  //Humdity
  spr.drawRoundRect((tft.width() / 2) - 10 , (tft.height() / 2) + 30, (tft.width() / 2) / 2 , (tft.height() - 65) / 2 , 10, TFT_BLUE); // s3

  spr.setFreeFont(&FreeSansBoldOblique9pt7b);
  spr.setTextColor(TFT_RED) ;
  spr.drawString("Humi", (tft.width() / 2) - 5 , (tft.height() / 2) + 40 , 1); // Print the test text in the custom font
  spr.setTextColor(TFT_WHITE);
  spr.drawNumber(val, (tft.width() / 2) - 5 , (tft.height() / 2) + 70, 1);
  spr.setTextColor(TFT_GREEN);
  spr.drawString("%", (tft.width() / 2) + 30, (tft.height() / 2) + 70, 1);


  //C2H5CH
  spr.drawRoundRect(((tft.width() / 2) + (tft.width() / 2) / 2) - 5  , (tft.height() / 2) + 30, (tft.width() / 2) / 2 , (tft.height() - 65) / 2 , 10, TFT_BLUE); // s4

  spr.setFreeFont(&FreeSansBoldOblique9pt7b);
  spr.setTextColor(TFT_RED) ;
  spr.drawString("Ethyl", ((tft.width() / 2) + (tft.width() / 2) / 2)   , (tft.height() / 2) + 40 , 1); // Print the test text in the custom font
  spr.setTextColor(TFT_WHITE);
  spr.drawNumber(val, ((tft.width() / 2) + (tft.width() / 2) / 2) , (tft.height() / 2) + 70, 1);
  spr.setTextColor(TFT_GREEN);
  spr.drawString("ppm", ((tft.width() / 2) + (tft.width() / 2) / 2) + 30 , (tft.height() / 2) + 80, 1);




  spr.pushSprite(0, 0);

}


