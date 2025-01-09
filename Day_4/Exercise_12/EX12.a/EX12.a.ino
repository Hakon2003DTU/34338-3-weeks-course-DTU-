
int count=1;

//led pins used 
int LEDPin1=6;
int LEDPin2=7;
int LEDPin3=8;
int LEDPin4=9;
int LEDPin5=10;


void setup() {
  pinMode(LEDPin1, OUTPUT);//setup led pins
  pinMode(LEDPin2, OUTPUT);//setup led pins
  pinMode(LEDPin3, OUTPUT);//setup led pins
  pinMode(LEDPin4, OUTPUT);//setup led pins
  pinMode(LEDPin5, OUTPUT); //setup led pins
}


void loop() {


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
 
