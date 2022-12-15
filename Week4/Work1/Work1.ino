// Author: Armmy2530
// Create Time: 15/12/2022 10:35

const int buttonPin1 = 8;    // the number of the pushbutton pin
const int buttonPin2 = 9;    // the number of the pushbutton pin
const int debouch_ms = 30;

// Variables will change:
int buttonState1;
int lastButtonState1 = 1;
int buttonState2;
int lastButtonState2 = 1;
int count = 0;
int current_ms = millis(), pev_ms = 0, btpev_ms = 0, refesh_ms = 500;
bool active_1 = false, active_2 = false;

const int num[] = { 0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10 };
const int digit[] = {0x04, 0x08};
void setup() {
  DDRD = 0xFF;
  DDRB = 0x0C;
  //  PORTB = 0x04;
  //  for(int x = 0;x <=9 ;x++){
  //    PORTD = num[x];
  //    delay(500);
  //  }
  //  PORTB = 0x08;
  //  for(int x = 0;x <=9 ;x++){
  //    PORTD = num[x];
  //    delay(500);
  //  }
}
// void loop(){}
void loop() {
  current_ms = millis();
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);
  if (buttonState1 != lastButtonState1 && !active_1) {
    btpev_ms = current_ms;
    active_1 = true;
  }
  if (buttonState2 != lastButtonState2 && !active_2) {
    btpev_ms = current_ms;
    active_2 = true;
  }
  
  if (active_1) {
    if (current_ms - btpev_ms >= debouch_ms) {
      if (digitalRead(buttonPin1) == 0) {
        plus_count();
        active_1 = false;
      }
    }
  }
  if (active_2) {
    if (current_ms - btpev_ms >= debouch_ms) {
      if (digitalRead(buttonPin2) == 0) {
        minus_count();
      }
      active_2 = false;
    }
  }
  //  Serial.println(String(buttonState1)+" "+String(buttonState2));
  lastButtonState1 = buttonState1;
  lastButtonState2 = buttonState2;

  display(count / 10, count - ((count / 10) * 10));
}

void plus_count() {
  if (count == 99) {
    count = 0;
  }
  else {
    count++;
  }
  // Serial.println("Count UP = " + String(count));
}
void minus_count() {
  if (count == 0) {
    count = 99;
  }
  else {
    count--;
  }
  // Serial.println("Count DOWN = " + String(count));
}

void display(int n2_digit, int n1_digit) {
  PORTB = 0x08;
  PORTD = num[n2_digit];
  delay(1);
  PORTB = 0x04;
  PORTD = num[n1_digit];
  delay(1);
}
