// Author: Belta
// Create Time: 25/11/2022 20:37

void setup() {
  // put your setup code here, to run once:
  for(int i = 8;i >= 3;i--)
  {
   pinMode(i,OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 8;i >= 3;i--)
  {
   digitalWrite(i,HIGH);
   delay(200);
  }
  for(int i = 8;i >= 3;i--)
  {
   digitalWrite(i,LOW);
  }
  delay(500);
}
