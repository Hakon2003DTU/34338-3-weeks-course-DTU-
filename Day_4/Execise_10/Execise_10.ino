int sensorPin = A0;    // select the input pin for the tempreture sensor
int sensorValue = 0;  // variable to store the value coming from the sensor
float voltage=0;      // variable used to calculate the tempreture
float Tempreture=0;      // variable used to calculate the tempreture 

int greenpin= 5;
int yellowpin= 6;
int redpin= 7;


void setup() {
  Serial.begin(9600); // enable serial moniter 
}

void loop() {

  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);  // reading analog 
  voltage = sensorValue * 5.0 / 1023.0; // calculating voltage 
  Tempreture=voltage*100  ;// calculating the tempreture

   if (Tempreture<28){
    digitalWrite(greenpin,HIGH);
    digitalWrite(yellowpin,LOW); 
    digitalWrite(redpin,LOW);  
   }
   else if (Tempreture>28 && Tempreture<29){
    digitalWrite(greenpin,LOW);
    digitalWrite(yellowpin,HIGH); 
    digitalWrite(redpin,LOW);
   }
   else{
    digitalWrite(greenpin,LOW);
    digitalWrite(yellowpin,LOW); 
    digitalWrite(redpin,HIGH);
   }

  Serial.print("Tempreture value:");
  Serial.print(Tempreture);
  Serial.print("\xC2\xB0"); // shows degree symbol
  Serial.println("C");
  delay(100);
  
}
