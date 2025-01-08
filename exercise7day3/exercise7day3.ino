// pin variables for the arduino board
int redPin = 8;
int greenPin = 9;
int bluePin = 10;

int red = 255;   // Start with full red
int green = 0;   // Green starts at 0
int blue = 0;    // Blue starts at 0

const int fade = 1;

// color variables for the serial monitor for exercise 7c
//int redValue;
//int greenValue;
//int blueValue;

void setup() { 
  Serial.begin(9600); 
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  analogWrite(bluePin, 0);
  delay(1000);
  } 

void loop() { 
  // checks if red value is maxed out, and if so it will decrease the red value and increase the blue value untill it reaches 255
  if(red == 255){
    while (red > 0 && blue < 255) {
      red -= fade;   // Decrease red
      blue += fade;  // Increase blue
      analogWrite(redPin, red);
      analogWrite(bluePin, blue);
      delay(100);     // Adjust delay for smoothness
    }

// checks if blue value is maxed out, and if so it will decrease the blue value and increase the green value untill it reaches 255
  if(blue == 255){
    while (blue > 0 && green < 255) {
      blue -= fade;   // Decrease blue
      green += fade;  // Increase green
      analogWrite(bluePin, blue);
      analogWrite(greenPin, green);
      delay(100);     // Adjust delay for smoothness
    }

// checks if green value is maxed out, and if so it will decrease the green value and increase the red value untill it reaches 255
  if(green == 255){
    while (green > 0 && red < 255) {
      green -= fade;   // Decrease green
      red += fade;  // Increase red
      analogWrite(greenPin, green);
      analogWrite(redPin, red);
      delay(100);     // Adjust delay for smoothness   
  }
// this configuration makes sure that the fading loops forever.


// this part of the code is used for exercise 7c.
  /*
  if (Serial.available() > 0) { // Check if data is available
    redValue = Serial.parseInt();   // Parse red value
    greenValue = Serial.parseInt(); // Parse green value
    blueValue = Serial.parseInt();  // Parse blue value

    // print all values of the different colors
    Serial.print("Red: ");
    Serial.print(redValue);
    Serial.print(", Green: ");
    Serial.print(greenValue);
    Serial.print(", Blue: ");
    Serial.println(blueValue);
    

    // set the values from the serial monitor to the correct pins
    analogWrite(redPin, redValue);   // Set red channel brightness
    analogWrite(greenPin, greenValue); // Set green channel brightness
    analogWrite(bluePin, blueValue);  // Set blue channel brightness
    */
   }
  }
 }
}