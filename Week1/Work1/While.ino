void setup() {
  // put your setup code here, to run once:
  int i = 8;
  while(i>=3){
    pinMode(i,OUTPUT);
    i--;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int i = 8;
  while(i>=3){
    digitalWrite(i,1);
    i--;
    delay(200);
  }
  i = 8;
  while(i>=3){
    digitalWrite(i,0);
    i--;
  }
  delay(1000);
}
