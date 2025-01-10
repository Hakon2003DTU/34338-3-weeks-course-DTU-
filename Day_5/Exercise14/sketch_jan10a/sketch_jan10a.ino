// struct setup to only be read once
struct FARM {   // Structure declaration
  String animal;           // Members 
  int age;
  float weight;       
  int lifeexp;
  char feed[20];
}; // End the structure with a semicolon
struct FARM F1 = {"Cow", 4, 600, 20, "Hay"};
struct FARM F2 = {"pig", 6, 250, 30, "mud"};
struct FARM F3 = {"chicken", 1, 4, 15, "corn"};
struct FARM F4 = {"Horse", 10, 750, 17, "Hay"};
struct FARM F5 = {"Dog", 8, 30, 15, "dog food"};
void setup() {
Serial.begin(9600); // enable serial moniter 
}


// function for animal to be displayed on LCD
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

//swab function
void SwapAnimal (struct FARM *a, struct FARM *b) {
struct FARM temp;
temp=*a; 
*a = *b; 
*b = temp; 
}


void loop() {


display(&F1); // display animal 1

delay(2000);
display(&F2); // display animal 2

delay(2000);


SwapAnimal(&F1,&F2); // swab animal 1 and animal 2



display(&F1); // display animal 1

delay(2000);
display(&F2); // display animal 2

delay(2000);

delay(10000);
}
