#include <glcd.h>
#include <fonts/allFonts.h>

int trigger = 12;
int echo    = 13;

void setup(){
  GLCD.Init();
  GLCD.SelectFont(System5x7);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT); 
}

void loop(){
  int distance  = calculateDistance();
  displayOutput(distance);
  delay(100);
}

int calculateDistance(){
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger, LOW);
  return (pulseIn(echo, HIGH)/58);
}

void displayOutput(int distance){
  GLCD.ClearScreen();
  GLCD.print("Distance: ");
  GLCD.print(distance);
  GLCD.print("cm");
}