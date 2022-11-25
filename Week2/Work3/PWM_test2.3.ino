// Author: Belta
// Create Time: 25/11/2022 20:37

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //if(Serial.available()>0)
  //{
  /*String x_str=Serial.readStringUntil('R');
    String y_str=Serial.readStringUntil('G');
    String z_str=Serial.readStringUntil('B\n');
    int x=x_str.toInt();
    int y=y_str.toInt();
    int z=z_str.toInt();*/
  for (int i = 0; i <= 255; i++)
  {
    analogWrite(11, i);
    delay(10);
  }
  for (int i = 0; i <= 255; i++)
  {
    analogWrite(10, i);
    delay(10);
  }
  for (int i = 255; i >= 0; i--)
  {
    analogWrite(11, i);
    delay(10);
  }
  for (int i = 0; i <= 255; i++)
  {
    analogWrite(9, i);
    delay(10);
  }
  for (int i = 255; i >= 0; i--)
  {
    analogWrite(10, i);
    delay(10);
  }
  for (int i = 0; i <= 255; i++)
  {
    analogWrite(11, i);
    delay(10);
  }
  for (int i = 0; i <= 255; i++)
  {
    //analogWrite(11, i);
    analogWrite(10, i);
    //analogWrite(9, i);
    delay(10);
  }
  for (int i = 255; i >= 0; i--)
  {
    analogWrite(11, i);
    analogWrite(10, i);
    analogWrite(9, i);
    delay(10);
  }

}
