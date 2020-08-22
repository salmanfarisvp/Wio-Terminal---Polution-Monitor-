


#include <Multichannel_Gas_GMXXX.h>
#include <Wire.h>
#include "DHT.h"

GAS_GMXXX<TwoWire> gas;

#define DHTPIN 0
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(115200);

  pinMode(WIO_MIC, INPUT);

  gas.begin(Wire, 0x08);

  dht.begin();

}

void loop() {


  int no2, c2h5ch, voc, co;

  no2 = gas.getGM102B();
  if (no2 > 999) no2 = 999;
  Serial.print("NO2: ");
  Serial.print(no2);
  Serial.println(" ppm");

  c2h5ch = gas.getGM302B();
  if (c2h5ch > 999) c2h5ch = 999;
  Serial.print("C2H5CH: ");
  Serial.print(c2h5ch);
  Serial.println(" ppm");

  voc = gas.getGM502B();
  if (voc > 999) voc = 999;
  Serial.print("VOC: ");
  Serial.print(voc);
  Serial.println(" ppm");

  co = gas.getGM702B();
  if (co > 999) co = 999;
  Serial.print("CO: ");
  Serial.print(co);
  Serial.println(" ppm");


  float t = dht.readTemperature();
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println( "*C");

  float h = dht.readHumidity();
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println( "%");

//  int noice = analogRead(WIO_MIC);
//  Serial.print("Noice: ");
//  Serial.print(noice);
//  Serial.println( " %");


  Serial.println("--------------------------------------------------------");


  delay(2000);

}
