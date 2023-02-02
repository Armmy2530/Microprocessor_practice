#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial NodeSerial(D3, D4); // RX | TX
void setup()
{
  Serial.begin(115200);
  pinMode(A0, INPUT);
  NodeSerial.begin(9600);
  lcd.init();
  lcd.backlight();
}
void loop()
{
  if(NodeSerial.available()>0)
  {
    String temp_str=NodeSerial.readStringUntil(',');
    String humidity_str=NodeSerial.readStringUntil('\n');
    Serial.println(temp_str + " " + humidity_str);
    lcd.setCursor(0,0);
    lcd.print("Temp: "+ temp_str+"          ");
    lcd.setCursor(0,1);
    lcd.print("Humidity: "+ humidity_str+"          ");
    delay(10);
  }
}
