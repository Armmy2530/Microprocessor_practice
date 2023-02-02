#include <SoftwareSerial.h>
int val = 0;
SoftwareSerial ArduinoSerial(3, 2); // RX, TX
void setup() {
  Serial.begin(115200);
  ArduinoSerial.begin(9600);
  pinMode(9, OUTPUT);
}
void loop() {
  while (ArduinoSerial.available() > 0) {
    val = ArduinoSerial.parseInt();
    Serial.println(val);
    int pwm = map(val,0,1023,0,255);
    analogWrite(9, pwm);
  }
  delay(1);
}
