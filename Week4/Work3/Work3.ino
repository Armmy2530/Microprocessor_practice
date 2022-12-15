// Author: Armmy2530
// Create Time: 15/12/2022 10:35

#include "DHT.h"

#define DHTPIN 13
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);
int current_ms = millis(), pev_ms = 0, delay_ms = 2000;

void setup() {
  Serial.begin(115200);
  DDRD = 0xFF;
  dht.begin();
  display(2);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  current_ms = millis();

  // Check if any reads failed and exit early (to try again).
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  int value = map(analogRead(A0),200,520,0,100);
  if(value >100){value = 100;}else if(value <0){value = 0;}
  if (current_ms - pev_ms >= delay_ms) {
    Serial.print(F("Brightness: "));
    Serial.print(value);
    Serial.print(F("%  Humidity: "));
    Serial.print(humidity);
    Serial.print(F("%  Temperature: "));
    Serial.print(temperature);
    Serial.println(F("°C "));
    pev_ms = current_ms ;
  }
  display(map(analogRead(A0),200,520,0,6));

  // Wait a few seconds between measurements.
}

void display(int value) {
  if (value == 0) {
    PORTD = 0x00;
  }
  else if (value == 1) {
    PORTD = 0x04;
  }
  else if (value == 2) {
    PORTD = 0x0C;
  }
  else if (value == 3) {
    PORTD = 0x1C;
  }
  else if (value == 4) {
    PORTD = 0x3C;
  }
  else if (value >= 5) {
    PORTD = 0x7C;
  }
}
