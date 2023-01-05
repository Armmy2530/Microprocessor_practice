int steps[8][4] = {{1, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 1}, {1, 0, 0, 1}};
int intt[4] = {8, 9, 10, 11};
int I_new = 0;
int I_old = 0;
int st_new = 0;
int st_old = 0;
int ct = 0;

int CLK = 2;
int DT = 3;
int SW = 4;
int RotPosition = 0;
int rotation;
int value;

void setup() {
  for (int i = 0; i <= 3; i++)
  {
    pinMode(intt[i], OUTPUT);
  }
  Serial.begin(115200);
  pinMode (CLK, INPUT);
  pinMode (DT, INPUT);
  pinMode (SW, INPUT);
  rotation = digitalRead(CLK);
  //  control('F', 500);
  //  control('B', 500);
}

void loop() {
  Serial.println(String(End()) + " " + String(digitalRead(SW)) + " " + String(ct) );
  I_new = End();
  if ( digitalRead(SW) == 0 )
  {
    if ( I_old > I_new )
    {
      control('B', abs(I_new - I_old) * 200);
    }
    if ( I_old < I_new )
    {
      control('F', abs(I_new - I_old) * 200);
    }
    I_old = I_new;
  }
}

int End()
{
  value = digitalRead(CLK);
  if (value != rotation) { // we use the DT pin to find out which way we turning.
    if (digitalRead(DT) != value) {  // Clockwise
      RotPosition ++;
    } else { //Counterclockwise
      RotPosition--;
    }
//        Serial.print("Encoder RotPosition: ");
//        Serial.println(RotPosition);
//     this will print in the serial monitor.

  }
  rotation = value;
  return RotPosition / 2;
}
//void control(int u , int i)
//{
//  st_new = st_old;
//  I_new = i;
//  while ( I_new != I_old )
//  {
//    if ( I_old < I_new )
//    {
//      st_new++;
//      if ( st_new > 7 )
//      {
//        st_new = 0;
//      }
//      I_old++;
//    }
//    if ( I_old > I_new )
//    {
//      st_new--;
//      if ( st_new < 0 )
//      {
//        st_new = 7;
//      }
//      I_old--;
//    }
//    op(st_new);
//    delay(1);
//    Serial.println(I_old);
//  }
//  I_new = I_old;
//  st_old = st_new;
//}
void control(char u , int i)
{
  ct = 0;
  st_new = st_old;
  while ( ct != i )
  {
    if ( u == 'F' )
    {
      st_new++;
      if ( st_new > 7 )
      {
        st_new = 0;
      }
      ct++;
    }
    if ( u == 'B' )
    {
      st_new--;
      if ( st_new < 0 )
      {
        st_new = 7;
      }
      ct++;
    }
    Serial.println(String(End()) + " " + String(digitalRead(SW)) + " " + String(ct) );
    op(st_new);
    delay(1);
  }
  st_old = st_new;
}
void op(int i)
{
  digitalWrite(intt[0], steps[i][0]);
  digitalWrite(intt[1], steps[i][1]);
  digitalWrite(intt[2], steps[i][2]);
  digitalWrite(intt[3], steps[i][3]);
}
