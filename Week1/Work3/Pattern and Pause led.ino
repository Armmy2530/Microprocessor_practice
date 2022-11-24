// Author: Armmy2530
// Create Time:24/11/2022 19:52

int input_int = 0;
int playpause = 0;
int current_state[6] = {0, 0, 0, 0, 0, 0};
int current_sq = -1,current_pattern = 0;
int led_pin[6] = {8, 7, 6, 5, 4, 3};
int delay_ms = 400,pev_ms = 0;
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
  int current_ms = millis();
  if (Serial.available())
  {
    int raw_data = Serial.parseInt();
    if(raw_data == 0){if(playpause==0){playpause = 1;} else{playpause = 0;}}
    else{current_pattern = raw_data; current_sq=-1;}
  }

  if(playpause == 0){
    if(current_ms - pev_ms >= delay_ms){
      if(current_pattern == 1){pattern1();}
      else if(current_pattern == 2){pattern2();} 
      else if(current_pattern == 3){pattern3();} 
      pev_ms = current_ms;
    }
  }
  else if(playpause == 1){pev_ms = current_ms;}
  Serial.println(String(current_pattern)+" "+String(current_sq)+" "+String(playpause));
  delay(10);
}
void pattern1() {
  current_sq++;
  if (current_sq == 0) {
    led(0, 0, 0, 0, 0, 0);
  }
  else if (current_sq == 1) {
    led(1, 0, 0, 0, 0, 0);
  }
  else if (current_sq == 2) {
    led(1, 1, 0, 0, 0, 0);
  }
  else if (current_sq == 3) {
    led(1, 1, 1, 0, 0, 0);
  }
  else if (current_sq == 4) {
    led(1, 1, 1, 1, 0, 0);
  }
  else if (current_sq == 5) {
    led(1, 1, 1, 1, 1, 0);
  }
  else if (current_sq == 6) {
    led(1, 1, 1, 1, 1, 1);
    current_sq = -1;
  }
}
void pattern2() {
  current_sq++;
  if (current_sq == 0) {
    led(0, 0, 0, 0, 0, 0);
  }
  else if (current_sq == 1) {
    led(0, 0, 0, 0, 0, 1);
  }
  else if (current_sq == 2) {
    led(0, 0, 0, 0, 1, 1);
  }
  else if (current_sq == 3) {
    led(0, 0, 0, 1, 1, 1);
  }
  else if (current_sq == 4) {
    led(0, 0, 1, 1, 1, 1);
  }
  else if (current_sq == 5) {
    led(0, 1, 1, 1, 1, 1);
  }
  else if (current_sq == 6) {
    led(1, 1, 1, 1, 1, 1);
    current_sq=-1;
  }
}
void pattern3() {
  current_sq++;
  if (current_sq == 0) {
    led(1, 0, 1, 0, 1, 0);
  }
  else if (current_sq == 1) {
    led(0, 1, 0, 1, 0, 1);
    current_sq=-1;
  }
}

void led(int l1, int l2, int l3, int l4, int l5, int l6) {
  digitalWrite(led_pin[0], l1);
  digitalWrite(led_pin[1], l2);
  digitalWrite(led_pin[2], l3);
  digitalWrite(led_pin[3], l4);
  digitalWrite(led_pin[4], l5);
  digitalWrite(led_pin[5], l6);
}
