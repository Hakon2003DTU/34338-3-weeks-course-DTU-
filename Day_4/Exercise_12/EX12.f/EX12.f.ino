/**
 * @file EX12.f.ino
 * @author Hakon, Sørenand Anel (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int prevstate = 0; 
int BTNstate = 0; 

int hits=0;
int misses=0;
int count=1;
int LED=0;

//led pins used 
int LEDPin1=6;
int LEDPin2=7;
int LEDPin3=8;
int LEDPin4=9;
int LEDPin5=10;

//button pin used 
int ButtonPin=13;


/**
 * @brief no inputs and enables the LCD display, serial monitor, sets LEDS as outputs and button pin enables pullup resistors   
 * 
 */
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(115200);// enable serial monitor

  pinMode(LEDPin1, OUTPUT);//setup led pins
  pinMode(LEDPin2, OUTPUT);//setup led pins
  pinMode(LEDPin3, OUTPUT);//setup led pins
  pinMode(LEDPin4, OUTPUT);//setup led pins
  pinMode(LEDPin5, OUTPUT); //setup led pins
  pinMode(ButtonPin, INPUT_PULLUP); // setup button pin
}

/**
 * @brief Checks if the button is pressed and desides if it is a hit or miss. Desides which pattern to run on the LEDS (One after another or Random).  
 * 
 */
void loop() {

BTNstate = !digitalRead(ButtonPin);
if(BTNstate != prevstate){
    if (BTNstate==HIGH && count >= 201 && count <= 300){
      hits++;
      FLOW();
    }
    else if (BTNstate==HIGH){
      misses++;
      OFF();
    }
}

if (hits<8){
  normalLED(); // LEDS turn on one after another
}
else if (hits> 7){
  RandomLED();
}

count++;
delayMicroseconds(1000-(50*hits));

if (hits==10){ // wining seuence 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("You WIN");
  
  for(int i=0 ; i < 100; i++){ // flashes the lights in pattern to show win 
    FLOW();
  }
  
}
else if (count==301){ // prints out hit and misses after the perioder where hit and misses can change 
  lcd.setCursor(1,0);
  lcd.print("misses:");
  lcd.print(misses);
  lcd.setCursor(1,1);
  lcd.print("hits:");
  lcd.print(hits);
}
count=count%500;

}


/**
 * @brief no inputs makes the LEDs og random 
 * 
 */
void RandomLED(){
    if (count%100==0){
      digitalWrite(LED, LOW);
      LED=random(LEDPin1, LEDPin5+1);
    }
    digitalWrite(LED, HIGH);
    

}

/**
 * @brief no inputs. Running the LEDS on after another depending on count
 * 
 */
void normalLED(){
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

}

/**
 * @brief Makes the LED go in a pattern to show that the corect LED has been hit
 * 
 */
void FLOW(){          
          digitalWrite(LEDPin1, LOW);
          digitalWrite(LEDPin2, LOW);
          digitalWrite(LEDPin3, HIGH);
          digitalWrite(LEDPin4, LOW);
          digitalWrite(LEDPin5, LOW);
          delay(200);
          digitalWrite(LEDPin1, LOW);
          digitalWrite(LEDPin2, HIGH);
          digitalWrite(LEDPin3, LOW);
          digitalWrite(LEDPin4, HIGH);
          digitalWrite(LEDPin5, LOW);
          delay(200);
          digitalWrite(LEDPin1, HIGH);
          digitalWrite(LEDPin2, LOW);
          digitalWrite(LEDPin3, LOW);
          digitalWrite(LEDPin4, LOW);
          digitalWrite(LEDPin5, HIGH);
          delay(200);
          digitalWrite(LEDPin1, LOW);
          digitalWrite(LEDPin2, HIGH);
          digitalWrite(LEDPin3, LOW);
          digitalWrite(LEDPin4, HIGH);
          digitalWrite(LEDPin5, LOW);
          delay(200);
          digitalWrite(LEDPin1, LOW);
          digitalWrite(LEDPin2, LOW);
          digitalWrite(LEDPin3, HIGH);
          digitalWrite(LEDPin4, LOW);
          digitalWrite(LEDPin5, LOW);
          delay(100);
}

/**
 * @brief No Input. turns all LEDS off.
 * 
 */
void OFF(){
          digitalWrite(LEDPin1, LOW);
          digitalWrite(LEDPin2, LOW);
          digitalWrite(LEDPin3, LOW);
          digitalWrite(LEDPin4, LOW);
          digitalWrite(LEDPin5, LOW);
          delay(1000);
}

 
