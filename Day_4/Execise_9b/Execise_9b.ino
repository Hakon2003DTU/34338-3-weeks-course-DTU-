void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  char c;
  for (int i = 0; i < 4; i++) {
    c = '0' + i*2;
    Serial.print(c);
    Serial.write(176);
  } 
}


void loop() {
  // put your main code here, to run repeatedly:

}
