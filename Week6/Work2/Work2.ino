#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

String equ_string = "",number_string="",op_string="";
int first_number,second_number,result_number;
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'c','0','=','/'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);//LCD order
  lcd.init();
  lcd.backlight();
}
  
void loop(){
  char key = keypad.getKey();
  if (key){
    equ_string += String(key);
    if(key == '+' || key == '-' || key == '*' || key == '/'){
      first_number = number_string.toInt();
      op_string = String(key);
      number_string = "";
    }
    else if(key == '='){
      equ_string.remove(equ_string.length()-1,1);
      second_number = number_string.toInt();
      if(op_string == "+"){
        result_number = first_number + second_number;
      }
      else if(op_string == "-"){
        result_number = first_number - second_number;
      }
      else if(op_string == "*"){
        result_number = first_number * second_number;
      }
      else if(op_string == "/"){
        result_number = first_number / second_number;
      }
      number_string = "";
      Serial.println("Answer: "+String(result_number));
      lcd.setCursor(16-(String(result_number)).length(),1);
      lcd.print(String(result_number));
    }
    else{number_string += String(key);}
    lcd.setCursor(0, 0);
    lcd.print(equ_string);
    
    if(key == 'c'){
      lcd.clear();
      equ_string = "";
      number_string = "";
      op_string = "";
      first_number = 0;
      second_number = 0;
      result_number = 0;
    }
//    Serial.print(key);
    Serial.println("  "+equ_string+" "+String(first_number)+"  "+String(second_number));
  }
}
