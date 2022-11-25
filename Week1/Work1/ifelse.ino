// Author: Belta
// Create Time: 25/11/2022 20:37

int i = 8;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  if( i == 8)
  {
    analogWrite(i,255);
    i--;
  }
  else if( i == 7)
  {
    analogWrite(i,255);
    i--;
  }
  else if( i == 6)
  {
    analogWrite(i,255);
    i--;
  }
  else if( i == 5)
  {
    analogWrite(i,255);
    i--;
  }
  else if( i == 4)
  {
    analogWrite(i,255);
    i--;
  }
  else if( i == 3)
  {
    analogWrite(i,255);
    i--;
  }
  else if( i == 2)
  {
    digitalWrite(8,LOW);
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    digitalWrite(3,LOW);
    delay(300);
    i=8;
  }
  else 
  {
    
  }
  delay(200);
}
