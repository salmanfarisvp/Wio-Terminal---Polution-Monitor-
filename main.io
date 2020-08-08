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
  spr.setTextColor(TFT_BLUE);
  spr.drawString("Pollution Monitor", 20, 10 , 1);// Print the test text in the custom font
  for (int8_t line_index = 0; line_index < 5 ; line_index++)
  {
    spr.drawLine(0, 50 + line_index, tft.width(), 50 + line_index, TFT_GREEN);
  }

  spr.drawRoundRect(5, 60, (tft.width() / 2)-20 , tft.height() - 65 , 10, TFT_WHITE); // L1

  spr.drawRoundRect((tft.width() / 2)-10  , 60, (tft.width() / 2) / 2 , (tft.height() - 65) / 2 , 10, TFT_BLUE); // s1

  spr.drawRoundRect(((tft.width() / 2) + (tft.width() / 2) / 2)- 5  , 60, (tft.width() / 2) / 2 , (tft.height() - 65) / 2 , 10, TFT_RED); // s2

  spr.drawRoundRect((tft.width() / 2) - 10 , (tft.height()/2)+30, (tft.width() / 2) / 2 , (tft.height() - 65) / 2 , 10, TFT_BLUE); // s3

  spr.drawRoundRect(((tft.width() / 2) + (tft.width() / 2) / 2) - 5  , (tft.height()/2)+30, (tft.width() / 2) / 2 , (tft.height() - 65) / 2 , 10, TFT_RED); // s4

  spr.pushSprite(0, 0);

}


