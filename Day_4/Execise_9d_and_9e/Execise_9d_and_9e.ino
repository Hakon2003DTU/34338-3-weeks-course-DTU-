int sensorPin = A0;    // select the input pin for the tempreture sensor
int sensorValue = 0;  // variable to store the value coming from the sensor
float voltage=0;      // variable used to calculate the tempreture
float Tempreture=0;      // variable used to calculate the tempreture 

void setup() {
  Serial.begin(9600); // enable serial moniter 
}

void loop() {

  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);  // reading analog 
  voltage = sensorValue * 5.0 / 1023.0; // calculating voltage 
  // Map the sensor value to LED brightness levels
  Tempreture=voltage*100  ;

  Serial.print("sensor value:");
  Serial.print(sensorValue);
  Serial.print("voltage:");
  Serial.print(voltage,3);
  Serial.print("Tempreture value:");
  Serial.print(Tempreture);
  Serial.print("\xC2\xB0"); // shows degree symbol
  Serial.println("C");
  delay(10);
}
