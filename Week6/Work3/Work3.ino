#include "SPI.h"
#include "MFRC522.h"

#define SS_PIN 10
#define RST_PIN 9
#define LED_PIN A0
#define buzzer_PIN 2 


MFRC522 rfid1(SS_PIN, RST_PIN);

MFRC522::MIFARE_Key key;

void setup() {
    Serial.begin(9600);
    SPI.begin();
    rfid1.PCD_Init();
    pinMode(buzzer_PIN, OUTPUT);
}

void loop() {
  if (!rfid1.PICC_IsNewCardPresent() || !rfid1.PICC_ReadCardSerial())
    return;

  // Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = rfid1.PICC_GetType(rfid1.uid.sak);
  // Serial.println(rfid1.PICC_GetTypeName(piccType));

  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }

  String strID = "";
  for (byte i = 0; i < 4; i++) {
    strID +=
    (rfid1.uid.uidByte[i] < 0x10 ? "0" : "") +
    String(rfid1.uid.uidByte[i], HEX) +
    (i!=3 ? ":" : "");
  }
  strID.toUpperCase();

  Serial.print("Tap card key: ");
  Serial.print(strID);

  // โค้ดส่วนควบคุมหลอด LED โดยเอาค่าจากตัวแปร strID มาเทียบ
  if (strID.indexOf("03:9C:80:CB") >= 0) {
    Serial.println(" Accept");
    digitalWrite(buzzer_PIN,1);
    delay(200);
    digitalWrite(buzzer_PIN,0);
    delay(200);
    digitalWrite(buzzer_PIN,1);
    delay(200);
    digitalWrite(buzzer_PIN,0);;
  } else {
    Serial.println(" Denied");

    digitalWrite(buzzer_PIN,1);
    delay(500);
    digitalWrite(buzzer_PIN,0);
  }

  rfid1.PICC_HaltA();
  rfid1.PCD_StopCrypto1();
}