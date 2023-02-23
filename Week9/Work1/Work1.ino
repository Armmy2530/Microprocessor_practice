// Author: Armmy2530
// Create Time: 16/2/2023 8:06

const int buttonPin1 = D6;    // the number of the pushbutton pin
const int buttonPin2 = D7;    // the number of the pushbutton pin
const int o1 = D2;    // the number of the pushbutton pin
const int o2 = D3;    // the number of the pushbutton pin
const int debouch_ms = 50;

// Variables will change:
int buttonState1;            
int lastButtonState1 = 1;   
int buttonState2;        
int lastButtonState2 = 1;   
int count = 0,toggle_n = 0,toggle_n2 = 0;

void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(o1, OUTPUT);
  pinMode(o2, OUTPUT);
  Serial.begin(115200);
  // set initial LED state
}

void loop() {
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);
  if(buttonState1 != lastButtonState1){
    delay(debouch_ms);
    if(digitalRead(buttonPin1)==0){
      toggle();
    }
  }
  if(buttonState2 != lastButtonState2){
    delay(debouch_ms);
    if(digitalRead(buttonPin2)==0){
       toggle2();
    }
  }
  Serial.println(String(buttonState1)+" "+String(buttonState2)+" "+String(toggle_n)+" "+String(toggle_n2));
  digitalWrite(o1,toggle_n);
  digitalWrite(o2,toggle_n2);
  lastButtonState1 = buttonState1;
  lastButtonState2 = buttonState2;
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
