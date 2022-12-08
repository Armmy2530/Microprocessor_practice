// Author: Armmy2530
// Create Time: 1/12/2022 8:35

const int buttonPin1 = 2;    // the number of the pushbutton pin
const int buttonPin2 = 3;    // the number of the pushbutton pin
const int ledPin = 13;
const int debouch_ms = 50;

// Variables will change:
int buttonState1;
int lastButtonState1 = 1;
int buttonState2;
int lastButtonState2 = 1;
int count = 0;
static unsigned long lastInterruptTime = 0;
void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(buttonPin1), sw1_debouch , FALLING);
    attachInterrupt(digitalPinToInterrupt(buttonPin2), sw2_debouch , FALLING);
  // set initial LED state
}

void loop() {
  //  Serial.println(String(buttonState1)+" "+String(buttonState2));
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(2000);                       // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(2000);
}
void sw1_debouch() {
  //detachInterrupt(digitalPinT
    unsigned long interruptTime = millis();
    if (interruptTime - lastInterruptTime > 300) {
      
      if (count == 99) {
        count = 0;
      }
      else {
        count++;
      }
      Serial.println("Count UP = " + String(count));
 
    }
    lastInterruptTime = interruptTime;
}

void sw2_debouch() {
  //detachInterrupt(digitalPinT
    unsigned long interruptTime = millis();
    if (interruptTime - lastInterruptTime > 300) {
      
      if (count == 0){
        count = 99;
      }
      else {
        count--;
      }
      Serial.println("Count DOWN = " + String(count));
 
    }
    lastInterruptTime = interruptTime;
}
