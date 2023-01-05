const int buttonPin1 = 4;    // the number of the pushbutton pin
const int debouch_ms = 50;
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = A0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
int buttonState1;
int lastButtonState1 = 1;
int count = 1, toggle_n = 0;
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(115200);
  pinMode(buttonPin1, INPUT);
  myservo.write(180);
}

void loop() {
  int buttonState1 = digitalRead(buttonPin1);
  if (buttonState1 != lastButtonState1) {
    delay(debouch_ms);
    if (digitalRead(buttonPin1) == 0) {
      toggle();
    }
  }
  val = map(analogRead(potpin) , 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  if (toggle_n == 1) {
    myservo.write(val);                  // sets the servo position according to the scaled value
  }
  lastButtonState1 = buttonState1;
  Serial.println(String(val) + String("  ") + String(toggle_n));
  //  delay(15);                           // waits for the servo to get there
}

void toggle() {
  if (toggle_n == 1) {
    toggle_n = 0;
  }
  else {
    toggle_n = 1;
  }
}
