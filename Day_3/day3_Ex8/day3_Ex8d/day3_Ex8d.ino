int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
float voltage=0;      // variable used to calculate the voltage 
void setup() {
  // enable serial moiter 
  Serial.begin(9600);

}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);  // reading analog 
  voltage = sensorValue * 5.0 / 1023.0; // calculating voltage 
  Serial.print("voltage:");  
  Serial.println(voltage,3);
}
