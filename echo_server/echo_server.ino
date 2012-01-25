#include <glcd.h>
#include <fonts/allFonts.h>

void setup() {
  GLCD.Init();
  GLCD.SelectFont(System5x7);
  GLCD.println("Initialized\n");
  Serial.begin(9600);
}

void loop()
{
  char char;
  String str = "";

  if(Serial.available())
  {
    char = Serial.read();
    str += String(char);
    Serial.write(char);
  }

  GLCD.print(str);
}
