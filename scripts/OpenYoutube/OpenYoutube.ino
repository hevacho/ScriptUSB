#include <Keyboard.h>
#include <Keyboard_es_ES.h>
#define KEY_DELAY 10 // delay between keystrokes for slow computers

const char command[] = "https://www.youtube.com/watch?v=Qq4j1LtCdww";
int i = 0;

void setup() {
  Keyboard.begin(KeyboardLayout_es_ES);
  delay(2000); // delay before start to give time for reprogramming if needed
}

void loop() {
  if (i == 0) {
   
    // Pressing Win+r shortcut
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    delay(KEY_DELAY);
    Keyboard.releaseAll();
    delay(KEY_DELAY * 5);
    
    Keyboard.print(command);
    delay(KEY_DELAY);
    
    Keyboard.write(KEY_RETURN); // Press Enter key
    i++;
  }
}
