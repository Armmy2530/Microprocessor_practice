// Author: Armmy2530
// Create Time: 1/12/2022 8:35
#include <ESP8266WiFi.h>
const int RelayPin = D2;
const int RelayPin2 = D3;
const int debouch_ms = 50;

const char* ssid = "ARMMY2530-ACER 9420";
const char* pass = "arm254889";
String ip = "";
WiFiServer server(80);

// Variables will change:
int count = 0,toggle_n = 0,toggle_n2 = 0;

void setup()
{
  pinMode(RelayPin, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  Serial.begin(115200);
  WiFi.begin(ssid,pass);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Wifi connected");
  server.begin();
  Serial.println("Server started");
  Serial.println(WiFi.localIP());
  ip = IpAddress2String(WiFi.localIP());
  Serial.println(ip);
  // set initial Relay state
}

void loop()
{
  WiFiClient client =  server.available();
  if(!client){return;}
  
  while(!client.available()){
    delay(1);
  }
  String req = client.readStringUntil('/r');
  Serial.println(req);
  client.flush();
  if(req.indexOf("/s1")!= -1){
    toggle();
    Serial.println("~~~~~~~~~~~~~~toggle relay~~~~~~~~~~~~~~~~~~~");
    digitalWrite(RelayPin,toggle_n);
  }
  if(req.indexOf("/s2")!= -1){
    toggle2();
    Serial.println("~~~~~~~~~~~~~~toggle relay~~~~~~~~~~~~~~~~~~~");
    digitalWrite(RelayPin2,toggle_n2);
  }
  String web = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
  web += "<html>\r\n";
  web += "<body>\r\n";
  web += "<h1>Pre-Electronics Engineering</h1>\r\n";
  web += "<h2>Light Status</h2>\r\n";
  web += "<p>\r\n";
  if ((toggle_n == 0 && toggle_n2 == 1) ||(toggle_n == 1 && toggle_n2 == 0) )
    web += "Light On\r\n";
  else
    web += "Light Off\r\n";
  web += "</p>\r\n";
  web += "<p>\r\n";
  web += "<a href=\"/s1\"><button>SW1</button></a>\r\n";
  web += "<a href=\"/s2\"><button>SW2</button></a>\r\n";
  web += "</p>\r\n";
  web += "</body>\r\n";
  web += "</html>\r\n";
  client.print(web);
  client.print("<meta http-equiv='refresh' content = '10;URL=http:/'/>\r\n");
}

void toggle() {
  if (toggle_n == 1) {
    toggle_n = 0;
  }
  else {
    toggle_n = 1;
  }
}

void toggle2() {
  if (toggle_n2 == 1) {
    toggle_n2 = 0;
  }
  else {
    toggle_n2 = 1;
  }
}


String IpAddress2String(const IPAddress& ipAddress)
{
    return String(ipAddress[0]) + String(".") +
           String(ipAddress[1]) + String(".") +
           String(ipAddress[2]) + String(".") +
           String(ipAddress[3]);
}