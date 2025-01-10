
struct FARM {   // Structure declaration
  String animal;           // Member (int variable)
  int age;
  float weight;       // Member (char variable)
  int lifeexp;
  char feed[20];
}; // End the structure with a semicolon
struct FARM F1 = {"Cow", 4, 600, 20, "Hay"};
struct FARM F2 = {"pig", 6, 250, 30, "mud"};
struct FARM F3 = {"chicken", 1, 4, 15, "corn"};
struct FARM F4 = {"Horse", 10, 750, 17, "Hay"};
struct FARM F5 = {"Dog", 8, 30, 15, "dog food"};
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); // enable serial moniter 


}



void display(struct FARM *p){
  Serial.print("Animal: ");
Serial.print(p->animal);
Serial.println();
Serial.print("Animal age: ");
Serial.print(p->age);
Serial.print(" years");
Serial.println();
Serial.print("Animal weight: ");
Serial.print(p->weight);
Serial.print(" kg");
Serial.println();
Serial.print("Animal life expectancy: ");
Serial.print(p->lifeexp);
Serial.print(" years");
Serial.println();
Serial.print("Animal feed: ");
Serial.print(p->feed);
Serial.println();
}



void loop() {
  // put your main code here, to run repeatedly:


display(&F1);

delay(2000);
display(&F2);

delay(2000);
display(&F3);

delay(2000);
display(&F4);

delay(2000);
display(&F5);

delay(2000);


}
