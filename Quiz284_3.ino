
#include <SoftwareSerial.h>

int buttonState = 0;
int red = 7; // declaring output pins to red,green,blue
int green = 8;
int blue = 9;
// setting button inputs for red,green,blue
const int buttonPinRED = 2; // Using built in resistor
const int buttonPinGREEN= 3; // Using built in resistor
const int buttonPinBLUE = 4; // Using built in resistor
int push = 0; // intial push switch statement variable

void setup(){    
  pinMode(red, OUTPUT); // Assigning pin outputs
  pinMode(green, OUTPUT); 
  pinMode(blue,  OUTPUT);

  pinMode(buttonPinRED, INPUT_PULLUP); // Assigning pin inputs with internal pullup
  pinMode(buttonPinGREEN, INPUT_PULLUP);      
  pinMode(buttonPinBLUE, INPUT_PULLUP);
  startup();
} 
void loop(){
    // the start of chaos. multiple if's to determine led color output
   if (digitalRead(buttonPinRED) == LOW & digitalRead(buttonPinGREEN) == HIGH & digitalRead(buttonPinBLUE) == HIGH) {
      push = 1; }
    
    else if (digitalRead(buttonPinGREEN) == LOW &  digitalRead(buttonPinRED) == HIGH &  digitalRead(buttonPinBLUE) == HIGH)  {
      push = 2; }  
  
    else if (digitalRead(buttonPinBLUE) == LOW & digitalRead(buttonPinGREEN) == HIGH &  digitalRead(buttonPinRED) == HIGH) {
      push = 3; }  

    else if (digitalRead(buttonPinRED) == LOW & digitalRead(buttonPinGREEN) == LOW & digitalRead(buttonPinBLUE) == HIGH) {
      push = 4; }  

    else if (digitalRead(buttonPinGREEN) == LOW & digitalRead(buttonPinBLUE) == LOW & digitalRead(buttonPinRED) == HIGH) {
      push = 5; }  

    else if (digitalRead(buttonPinBLUE) == LOW & digitalRead(buttonPinRED) == LOW & digitalRead(buttonPinGREEN) == HIGH) {
      push = 6; } 

    else if (digitalRead(buttonPinRED) == LOW & digitalRead(buttonPinGREEN) == LOW & digitalRead(buttonPinBLUE)) {
      push = 7; }   

    // Switch statement that reads the push variable from the 'if' conditions for a case # 
    // each case except 8 delays on for 1 second then turns off by 'push 8' switch statement  
switch (push) {
  case 1: //Red LED output 
    digitalWrite(red,  HIGH); 
    delay (1000);
    push = 8;
    break;
  case 2: //Green LED output
    digitalWrite(green,  HIGH); 
    delay (1000);
    push = 8;
    break;
  case 3: //Blue LED output
    digitalWrite(blue,  HIGH);
    delay (1000);
    push = 8;
    break;
  case 4: //Red and Green LED output
    digitalWrite(red,  HIGH);
    digitalWrite(green,  HIGH);
    delay (1000);
    push = 8;
    break;
  case 5: //Green and Blue LED output
    digitalWrite(green,  HIGH);
    digitalWrite(blue,  HIGH);
    delay (1000);
    push = 8;
    break;
  case 6: //Blue and Red LED output
    digitalWrite(blue,  HIGH);
    digitalWrite(red,  HIGH);
    delay (1000);
    push = 8;
    break;
  case 7: //Red, Green and Blue LED output
    digitalWrite(red,  HIGH); 
    digitalWrite(green,  HIGH);
    digitalWrite(blue,  HIGH);
    delay (1000);
    push = 8;
    break; 
  case 8: // Turns all colors off  
    digitalWrite(red,  LOW); 
    digitalWrite(green,  LOW);
    digitalWrite(blue,  LOW);
  default:
    break;
 
    
  }

    
}

 // attempted to call a method to flash the leds at start up, but it was angry at me
    void startup() {
         
      digitalWrite(red, HIGH);
      delay (250);
      digitalWrite(red, LOW);
      delay (250);
      digitalWrite(red, HIGH);
      delay (250); 
      digitalWrite(red, LOW);   
      digitalWrite(green, HIGH);
      delay (250);
      digitalWrite(green, LOW);
      delay (250);
      digitalWrite(green, HIGH);
      delay (250);
      digitalWrite(green, LOW);
      digitalWrite(blue, HIGH);
      delay (250); 
      digitalWrite(blue, LOW);
      delay (250);
      digitalWrite(blue, HIGH);
      digitalWrite(blue, LOW);
    }
