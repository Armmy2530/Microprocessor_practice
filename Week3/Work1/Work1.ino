// Author: Armmy2530
// Create Time: 1/12/2022 8:15

const int buttonPin1 = 2;    // the number of the pushbutton pin
const int buttonPin2 = 3;    // the number of the pushbutton pin
const int debouch_ms = 50;

// Variables will change:
int buttonState1;            
int lastButtonState1 = 1;   
int buttonState2;        
int lastButtonState2 = 1;   
int count = 0;

void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  Serial.begin(9600);
  // set initial LED state
}

void loop() {
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);
  if(buttonState1 != lastButtonState1){
    delay(debouch_ms);
    if(digitalRead(buttonPin1)==0){
       plus_count();
    }
  }
  if(buttonState2 != lastButtonState2){
    delay(debouch_ms);
    if(digitalRead(buttonPin2)==0){
       minus_count();
    }
  }
//  Serial.println(String(buttonState1)+" "+String(buttonState2));
  lastButtonState1 = buttonState1;
  lastButtonState2 = buttonState2;
}
void plus_count(){
  if(count == 99){
    count = 0;
  }
  else{count++;}
  Serial.println("Count UP = " + String(count));
}
void minus_count(){
  if(count == 0){
    count = 99;
  }
  else{count--;}
  Serial.println("Count DOWN = " + String(count));
}
