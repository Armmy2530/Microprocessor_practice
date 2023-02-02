#include <SoftwareSerial.h>

SoftwareSerial NodeSerial(D2, D3); // RX | TX
void setup()
{
  Serial.begin(115200);
  pinMode(A0, INPUT);
  NodeSerial.begin(9600);
}
void loop()
{
  int analog = analogRead(A0);
  NodeSerial.print(analog);
  NodeSerial.print("\n");
  Serial.println(analog);
}
