// Author: Armmy2530
// Create Time: 1/12/2022 8:15

const int buttonPin1 = 2;    // the number of the pushbutton pin
const int buttonPin2 = 3;    // the number of the pushbutton pin
const int rp = 11;    // the number of the pushbutton pin
const int gp = 10;    // the number of the pushbutton pin
const int bp = 9;    // the number of the pushbutton pin
const int debouch_ms = 50;

// Variables will change:
int buttonState1;
int lastButtonState1 = 1;
int buttonState2;
int lastButtonState2 = 1;
int count = 1, toggle_n = 0;
int r = 0, g = 0, b = 0;
void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(rp, OUTPUT);
  pinMode(gp, OUTPUT);
  pinMode(bp, OUTPUT);
  Serial.begin(9600);
  // set initial LED state
}

void loop() {
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);
  if (buttonState1 != lastButtonState1) {
    delay(debouch_ms);
    if (digitalRead(buttonPin1) == 0) {
      plus_count();
    }
  }
  if (buttonState2 != lastButtonState2) {
    delay(debouch_ms);
    if (digitalRead(buttonPin2) == 0) {
      toggle();
    }
  }
  if (toggle_n == 1) {
    if (count == 1) {
      r = int(float(analogRead(A0)) / 1023 * 255);
      analogWrite(rp,r);
    }
    else if (count == 2) {
      g = int(float(analogRead(A0)) / 1023 * 255);
      analogWrite(gp, g);
    }
    else if (count == 3) {
      b = int(float(analogRead(A0)) / 1023 * 255);
      analogWrite(bp, b);
    }
  }
    Serial.println(String(buttonState1)+" "+String(buttonState2)+" "+String(analogRead(A0))+" "+String(count)+" "+String(toggle_n)+" "+String(r)+" "+String(g)+" "+String(b));
  lastButtonState1 = buttonState1;
  lastButtonState2 = buttonState2;
}
void plus_count() {
  if (count == 3) {
    count = 1;
  }
  else {
    count++;
  }
}
void minus_count() {
  if (count == 1) {
    count = 3;
  }
  else {
    count--;
  }
}
void toggle() {
  if (toggle_n == 1) {
    toggle_n = 0;
  }
  else {
    toggle_n = 1;
  }
}
