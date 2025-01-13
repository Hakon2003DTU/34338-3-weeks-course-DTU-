/* task 
17a: Print the WiFi RSSI of the ESP8266 to a ThingSpeak channel
17b: Add a two variable graph and fill it with either
• RSSI and LED on/off
• Data from two of your sensors
(you will need to add this to your breadboard)
17c: Explore the possibilities writing to and reading from ThingSpeak
*/


#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
//#include <WiFi.h>

const char* ssid = "Hakoniphone"; //username of WiFi
const char* pass = "hakon2003";   // Password of Wifi

WiFiClient client;

unsigned long channelID = 2808259;        //your TS channal
const char * APIKey = "N6U2NV58FVH6SL9B"; //your APIKey
const int postDelay = 20 * 1000;          //post data every 20 seconds

const char* server = "api.thingspeak.com";

int sensorPin1 = A0;    // select the input pin for the potentiometer
int sensorValue1 = 0;   // variable to store the value coming from the sensor
int count=0;            // counitng to turn off LED 
int statusCode = 0;     // used to check status



void setup() {
  Serial.begin(115200);   // enable serial monitor 
  WiFi.begin(ssid, pass); // cornecting to WiFi
  pinMode(5, OUTPUT);      // set pin 5 as output 
  ThingSpeak.begin(client); // Cornect to ThingSpeak
  client.connect(server, 80); //connect(URL, Port)
}


void loop() {

// Get WiFi RSSI
  int rssi = WiFi.RSSI();
  Serial.print("RSSI: ");
  Serial.println(rssi);
  
  
  
  // Reading the potentiometer value
  sensorValue1 = analogRead(sensorPin1);
  Serial.println(sensorValue1); // 
  ThingSpeak.setField(1,sensorValue1); //set data on the 1 graph
  //ThingSpeak.writeFields(channelID, APIKey);//post everything to TS
  
  if (count > 2){ // tuns on LED
    digitalWrite(5, HIGH);// turning LED on
    ThingSpeak.setField(2,1); //set data on the 2 graph 
    ThingSpeak.writeFields(channelID, APIKey);//post to the thingSpeak  
  }
  else { // turns off LED 
    ThingSpeak.setField(2,0); //set data on the 2 graph 
    ThingSpeak.writeFields(channelID, APIKey);//post to the thingSpeak
    digitalWrite(5, LOW); // turning LED off
  }
  
  client.stop();
  delay(postDelay); //wait and then post again*/
   


 // reading part    
  float temperatureInF2 = ThingSpeak.readFloatField(channelID, 1);
  float temperatureInF1 = ThingSpeak.readFloatField(channelID, 2);

  statusCode = ThingSpeak.getLastReadStatus(); // checking status
 if(statusCode == 200){ // if there is nothing wronge
   Serial.println(String(temperatureInF2));
   Serial.println(String(temperatureInF2));
 }
 else{ // wrinting error code 
   Serial.println("Problem reading channel. HTTP error code " + String(statusCode)); 
 }

  delay(postDelay); //wait and then post again

  //changing the counte LED 
  count++; 
  count=count%4;
}
