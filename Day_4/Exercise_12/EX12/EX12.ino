#include <LiquidCrystal.h>



volatile bool BTN_Psh = false;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int prevstate = 0; 
int BTNstate = 0; 
int count = 0; 
int ledstate = 0; 
int i = 1;


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("BTN number");
  Serial.begin(115200);
  pinMode(10, OUTPUT); //setup led pins
  pinMode(9, OUTPUT);
 // pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(6, INPUT_PULLUP);
  int count = 0;
}

void 
          digitalWrite(10, LOW);
          digitalWrite(9, LOW);
          digitalWrite(8, HIGH);
          digitalWrite(7, LOW);
          digitalWrite(13, LOW);
          delay(200)
          digitalWrite(10, LOW);
          digitalWrite(9, HIGH);
          digitalWrite(8, LOW);
          digitalWrite(7, HIGH);
          digitalWrite(13, LOW);
          delay(200)
          digitalWrite(10, HIGH);
          digitalWrite(9, LOW);
          digitalWrite(8, LOW);
          digitalWrite(7, LOW);
          digitalWrite(13, HIGH);
          delay(200)
          digitalWrite(10, LOW);
          digitalWrite(9, LOW);
          digitalWrite(8, LOW);
          digitalWrite(7, LOW);
          digitalWrite(13, LOW);


void loop() {



if(count >= 1 && count <= 100){
          digitalWrite(10, HIGH);
          digitalWrite(9, LOW);
          digitalWrite(8, LOW);
          digitalWrite(7, LOW);
          digitalWrite(13, LOW);
        }
if(count >= 101 && count <= 200){
          digitalWrite(10, LOW);
          digitalWrite(9, HIGH);
        }
if(count >= 201 && count <= 300){
          digitalWrite(9, LOW);
          digitalWrite(8, HIGH);
        }
if(count >= 301 && count <= 400){
          digitalWrite(8, LOW);
          digitalWrite(7, HIGH);
        }
if(count >= 401 && count <= 500){
          digitalWrite(7, LOW);
          digitalWrite(13, HIGH);
        }
count ++;
delay(1);
if(count == 500){
  count = 0;
}   







BTNstate = !digitalRead(6);
if(BTNstate != prevstate){ 
  if (BTNstate==HIGH && count >= 1 && count <= 100){  
   lcd.setCursor(0, 1);
    // print the number of seconds since reset:
    lcd.print("RED   ");
  } 
if (BTNstate==HIGH && count >= 101 && count <= 200){  
   lcd.setCursor(0, 1);
    // print the number of seconds since reset:
    lcd.print("RED   ");

  } 
  if (BTNstate==HIGH && count >= 201 && count <= 300){  
   lcd.setCursor(0, 1);
    // print the number of seconds since reset:
    lcd.print("YELLOW");
  } 
  if (BTNstate==HIGH && count >= 301 && count <= 400){  
   lcd.setCursor(0, 1);
    // print the number of seconds since reset:
    lcd.print("GREEN ");
  } 
  if (BTNstate==HIGH && count >= 401 && count <=500){  
   lcd.setCursor(0, 1);
    // print the number of seconds since reset:
    lcd.print("GREEN ");
  } 
} 
prevstate=BTNstate;


}
 




/*if(BTNstate != prevstate){ 
  if (BTNstate==HIGH){  
   lcd.setCursor(0, 1);
    // print the number of seconds since reset:
    lcd.print(i);
  } 
  delay(50); 
} 
prevstate=BTNstate; */



