void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    String x_str=Serial.readStringUntil('R');
    String y_str=Serial.readStringUntil('G');
    String z_str=Serial.readStringUntil('B\n');
    int x=x_str.toInt();
    int y=y_str.toInt();
    int z=z_str.toInt();
    if(x >255)
    {
      x=255;    
    }
    if(x <0)
    {
      x=0;    
    }
    if(y >255)
    {
      y=255;    
    }
    if(y <0)
    {
      y=0;    
    }
    if(z >255)
    {
      z=255;    
    }
    if(z <0)
    {
      z=0;    
    }
    Serial.println(x);
    Serial.println(y);
    Serial.println(z);
    analogWrite(11,x);
    analogWrite(10,y);
    analogWrite(9,z);
  }
}
