// Author: Armmy2530
//Create Time:24/11/2022 19:52

int input_int = 0;
int current_state[6] = {0, 0, 0, 0, 0, 0};
int led_pin[6] = {8, 7, 6, 5, 4, 3};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int i = 8;
  while (i >= 3) {
    pinMode(i, OUTPUT);
    i--;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
  { 
    int raw_data = Serial.parseInt();
    Serial.println(raw_data);
    input_int = raw_data - 1;
    if (input_int >= 0 && input_int <= 5) {
      if (current_state[input_int] == 0)
      {
        digitalWrite(led_pin[input_int], 1);
        current_state[input_int] = 1;
        Serial.println("LED:" + String(input_int+1) + " ON");
      }
      else {
        digitalWrite(led_pin[input_int], 0);
        current_state[input_int] = 0;
        Serial.println("LED:" + String(input_int+1) + " OFF");
      }
    }
    else{
      Serial.println("ERROR");
    }
  }
  delay(10);
}
