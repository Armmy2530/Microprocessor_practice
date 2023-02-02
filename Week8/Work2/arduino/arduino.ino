#include <SoftwareSerial.h>
#include <DHT.h>


#define DHTPIN 13
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);

SoftwareSerial ArduinoSerial(3, 2); // RX, TX
void setup() {
  Serial.begin(115200);
  ArduinoSerial.begin(9600);
  dht.begin();
}
void loop()
{
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  ArduinoSerial.print(temperature);
  ArduinoSerial.print(",");
  ArduinoSerial.print(humidity);
  ArduinoSerial.print("\n");

  Serial.println(String(temperature)+" "+ String(humidity));
  delay(100);
}
