int incomingByte = 0;
void setup() {
  Serial.begin(115200); // setup window
  pinMode(13, OUTPUT); //setup led pins
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}
void loop() {

  if (Serial.available() > 0) {
    incomingByte = Serial.read(); // read from window
    int val = incomingByte - 88; // pin in use
    Serial.print("I received: ");
    Serial.print((char)incomingByte);
    if (val <= 13 && val >= 9) { // led turn on
      digitalWrite(val, HIGH);
    } else {                    // led turn off
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
    }
  }
}
