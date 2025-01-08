int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
float voltage=0;      // variable used to calculate the voltage 
int RED=8;
int GREEN=9;
int BLUE=10;

void setup() {
  // enable serial moiter 
  Serial.begin(9600);
  pinMode(RED, OUTPUT);  // sets the pin as output
  pinMode(GREEN, OUTPUT);  // sets the pin as output
  pinMode(BLUE, OUTPUT);  // sets the pin as output
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);  // reading analog 

  // Map the sensor value to LED brightness levels
  int blueValue = map(sensorValue, 0, 1023, 255, -150); // Blue decreases as voltage increases


  if (blueValue < 0){blueValue=0;} // stop from getting to 

  // Output to the RGB LED
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  analogWrite(BLUE, blueValue);


}


  
