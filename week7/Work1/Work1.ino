const int buttonPin1 = D1; // the number of the pushbutton pin
const int buttonPin2 = D2; // the number of the pushbutton pin

const int debouch_ms = 50;
int input_int = 0;
int current_state[6] = {0, 0, 0, 0, 0, 0};
int led_pin[6] = {D8, D7, D6, D5, D4, D3};

// Variables will change:
int buttonState1;
int lastButtonState1 = 1;
int buttonState2;
int lastButtonState2 = 1;
int count = 1, toggle_n = 0;
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  int i = 0;
  while (i <= 5)
  {
    pinMode(led_pin[i], OUTPUT);
    i++;
  }

}

void loop()
{
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);
  if (buttonState1 != lastButtonState1)
  {
    delay(debouch_ms);
    if (digitalRead(buttonPin1) == 0)
    {
      plus_count();
    }
  }
  if (buttonState2 != lastButtonState2)
  {
    delay(debouch_ms);
    if (digitalRead(buttonPin2) == 0)
    {
      minus_count();
    }
  }

  if(count == 0){
    led(0,0,0,0,0,0);
  }
  else if(count == 1){
    led(1,0,0,0,0,0);
  }
  else if(count == 2){
    led(1,1,0,0,0,0);
  }
  else if(count == 3){
    led(1,1,1,0,0,0);
  }
  else if(count == 4){
    led(1,1,1,1,0,0);
  }
  else if(count == 5){
    led(1,1,1,1,1,0);
  }
  else if(count == 6){
    led(1,1,1,1,1,1);
  }

  lastButtonState1 = buttonState1;
  lastButtonState2 = buttonState2;
}

void led(int l1, int l2, int l3, int l4, int l5, int l6)
{
  digitalWrite(led_pin[0], l1);
  digitalWrite(led_pin[1], l2);
  digitalWrite(led_pin[2], l3);
  digitalWrite(led_pin[3], l4);
  digitalWrite(led_pin[4], l5);
  digitalWrite(led_pin[5], l6);
}
void plus_count()
{
  if (count == 6)
  {
    count = 6;
  }
  else
  {
    count++;
  }
}
void minus_count()
{
  if (count == 0)
  {
    count = 0;
  }
  else
  {
    count--;
  }
}