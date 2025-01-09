#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int prevstate = 0; 
int BTNstate = 0; 
int i = 1;


int count=1;

//led pins used 
int LEDPin1=6;
int LEDPin2=7;
int LEDPin3=8;
int LEDPin4=9;
int LEDPin5=10;

//button pin used 
int ButtonPin=13;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("BTN number");
  Serial.begin(115200);// enable serial monitor
  
  pinMode(LEDPin1, OUTPUT);//setup led pins
  pinMode(LEDPin2, OUTPUT);//setup led pins
  pinMode(LEDPin3, OUTPUT);//setup led pins
  pinMode(LEDPin4, OUTPUT);//setup led pins
  pinMode(LEDPin5, OUTPUT); //setup led pins
  pinMode(ButtonPin, INPUT_PULLUP); // setup button pin
}


void loop() {

BTNstate = !digitalRead(ButtonPin);
if(BTNstate != prevstate){
    if (BTNstate==HIGH){
      lcd.setCursor(0, 1);
      // print the number of seconds since reset:
      lcd.print((int)1+(count/100));
    }
}


if(count >= 1 && count <= 100){
          digitalWrite(LEDPin1, HIGH);
          digitalWrite(LEDPin2, LOW);
          digitalWrite(LEDPin3, LOW);
          digitalWrite(LEDPin4, LOW);
          digitalWrite(LEDPin5, LOW);
        }
if(count >= 101 && count <= 200){
          digitalWrite(LEDPin1, LOW);
          digitalWrite(LEDPin2, HIGH);
        }
if(count >= 201 && count <= 300){
          digitalWrite(LEDPin2, LOW);
          digitalWrite(LEDPin3, HIGH);
        }
if(count >= 301 && count <= 400){
          digitalWrite(LEDPin3, LOW);
          digitalWrite(LEDPin4, HIGH);
        }
if(count >= 401 && count <= 500){
          digitalWrite(LEDPin4, LOW);
          digitalWrite(LEDPin5, HIGH);
        }
count++;
delay(1);
count=count%500;

}
 
