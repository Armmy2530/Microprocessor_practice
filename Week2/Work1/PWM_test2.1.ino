void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //pinMode(A0,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x=analogRead(A0);
  float y=analogRead(A0)/506.00;
  Serial.print("analog:");
  Serial.print(x);
  Serial.print("\t");
  Serial.print("voltage:");
  Serial.println(y*5.00);
}
