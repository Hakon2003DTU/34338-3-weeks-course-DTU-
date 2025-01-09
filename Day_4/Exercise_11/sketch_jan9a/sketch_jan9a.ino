#include <LiquidCrystal.h>




const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int sensorPin = A0;    // input pin for the potentiometer
int sensorValue = 0;
float Voltage=0;      // variable used to calculate the tempreture
float Tempreture=0;      // variable used to calculate the tempreture 
volatile bool Dt_tX = false;
 int count = 0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Temp reading");
  Serial.begin(115200);
}
void on_data_received(char analogRead(char data)) {
  // Set the internal signal high
  Dt_tX = true;
}

void loop() {
 
// read the value from the sensor:
  sensorValue = analogRead(sensorPin);  // reading analog 
  Voltage = sensorValue * 5.0 / 1023.0; // calculating voltage 
  // Map the sensor value to LED brightness levels
  Tempreture=Voltage*100  ;


  on_data_received(analogRead(sensorPin));
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  if (Dt_tX = true) {
    Dt_tX = false;
    lcd.setCursor(0, 1);
    // print the number of seconds since reset:
    lcd.print(Voltage);
    lcd.setCursor(5, 1);
    // print the number of seconds since reset:
    lcd.print(Tempreture);
    if (Tempreture >= 30) {
      lcd.setCursor(11, 1);
      // print the number of seconds since reset:
      lcd.print("temp!");
    }
  
    if (count % 50 == 0) {
      lcd.setCursor(0, 1);
      // print the number of seconds since reset:
      lcd.print("                  ");
    }

    count++;
    delay(50);  //wait 10ms
  }
}
