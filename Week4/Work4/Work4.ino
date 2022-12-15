// Author: Armmy2530
// Create Time: 15/12/2022 10:35

#include "DHT.h"
#include <LiquidCrystal_I2C.h>


#define DHTPIN 13
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 20, 4);
int current_ms = millis(), pev_ms = 0, pev_ms2 = 0, delay_ms = 100;
unsigned long int hour = 0, minu = 0, second = -1, pev_s = 0;

const int buttonPin1 = 7;    // the number of the pushbutton pin
const int debouch_ms = 50;

// Variables will change:
int buttonState1;
int lastButtonState1 = 1;
int count = 1;
int value = 0;

void setup() {
  Serial.begin(115200);
  Serial.println(F("DHT22 example!"));
  dht.begin();
  lcd.begin(16, 2);//LCD order
  lcd.init();
  lcd.backlight();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  time();
  current_ms = millis();

  int buttonState1 = digitalRead(buttonPin1);
  if (buttonState1 != lastButtonState1) {
    delay(debouch_ms);
    if (digitalRead(buttonPin1) == 0) {
      plus_count();
    }
  }

  // Check if any reads failed and exit early (to try again).
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  value = map(analogRead(A0),200,520,0,100);
  if(value >100){value = 100;}else if(value <0){value = 0;}

  if (current_ms - pev_ms2 >= delay_ms) {
    if (count == 1) {
//      lcd.setCursor(0, 1);
//      lcd.print("Temp         "+fix_digit(temperature)+"C");
      lcd.setCursor(0, 1);
      lcd.print("Temp         "+fix_digit(temperature)+"C");
    } 
    else if (count == 2) {
//      lcd.setCursor(0, 1);
//      lcd.print("humidit        "+"%");
      lcd.setCursor(0, 1);
      lcd.print("humidit      "+fix_digit(humidity)+"%");
    }
    else if (count == 3) {
//      lcd.setCursor(0, 1);
//      lcd.print("Brightness    "+"%");
      lcd.setCursor(0, 1);
      lcd.print("Brightness  "+fix_digit_blank(value)+"%");
    }
    pev_ms2 = current_ms ;
    Serial.println("update");
  }
  Serial.println(digitalRead(7));
  lastButtonState1 = buttonState1;
  // Wait a few seconds between measurements.
}

void time() {
  unsigned long int current_s = current_ms / 1000;
  if (current_s - pev_s >= 1) {
    pev_s = current_s;
    second++;
    lcd.setCursor(0, 0);
//    lcd.print("                   ");
    lcd.setCursor(0, 0);
    lcd.print("    " + fix_digit(hour) + ":" + fix_digit(minu) + ":" + fix_digit(second));
  }
  if (second == 60) {
    second = 0;
    minu++;
    lcd.setCursor(0, 0);
//    lcd.print("                   ");
    lcd.setCursor(0, 0);
    lcd.print("    " + fix_digit(hour) + ":" + fix_digit(minu) + ":" + fix_digit(second));
  }
  if (minu == 60) {
    minu = 0;
    hour++;
    lcd.setCursor(0, 0);
//    lcd.print("                   ");
    lcd.setCursor(0, 0);
    lcd.print("    " + fix_digit(hour) + ":" + fix_digit(minu) + ":" + fix_digit(second));
  }
}

String fix_digit(int value) {
  if (value / 10 == 0) {
    return ("0" + String(value));
  }
  else {
    return String(value);
  }
}
String fix_digit_blank(int value) {
  if (value / 10 == 0) {
    return ("  " + String(value));
  }
  else if (value / 10 == 10) {
    return (String(value));
  }
  else {
    return (" " + String(value));
  }
}
void plus_count() {
  if (count == 3) {
    count = 1;
  }
  else {
    count++;
  }
  // Serial.println("Count UP = " + String(count));
}
