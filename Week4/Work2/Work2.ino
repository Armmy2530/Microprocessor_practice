// Author: Armmy2530
// Create Time: 15/12/2022 10:35

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
int n_text = 32, count_text = 32,m_text=1;
void setup()//method used to run the code for once
{
  lcd.begin(16, 2);//LCD order
  lcd.init();
  lcd.backlight();
  Serial.begin(115200);
  delay(1000);//delay of 1 second
}

void loop() //used to run the code repeatedly
{
  if (count_text == 32 && m_text ==0) {
    lcd.clear();
    lcd.setCursor(16, 0); //Setting the cursor on LCD
    lcd.print("Prompiriya poolwirat");//prints on LCD
    lcd.setCursor(16, 1); //Setting the cursor on LCD
    lcd.print("63030212205         ");//prints on LCD
    count_text = 0;
    m_text = 1;
  }
  else if (count_text == 37 && m_text == 1) {
    lcd.clear();
    lcd.setCursor(16, 0); //Setting the cursor on LCD
    lcd.print("Sutthikan panla");//prints on LCD
    lcd.setCursor(16, 1); //Setting the cursor on LCD
    lcd.print("6303102122040  ");//prints on LCD
    count_text = 0;
    m_text = 0;
  }
  Serial.println(String(count_text)+"  " +String(m_text));
  lcd.scrollDisplayLeft();//builtin command to scroll left the text
  count_text++;
  delay(300);// delay of 150 msec
}
