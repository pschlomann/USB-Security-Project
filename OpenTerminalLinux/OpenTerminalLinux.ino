#include "DigiKeyboard.h"

void setup() {
  // Wait for the machine to detect the DigiSpark, then send a wake-up signal
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);
  
  // Allow for full keyboard access and open a Terminal
  DigiKeyboard.sendKeyStroke(MOD_CONTROL_RIGHT); // If in VirtualBox, will allow for left CTRL usage
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_T, MOD_CONTROL_LEFT | MOD_ALT_LEFT);
  DigiKeyboard.delay(500);
}

void loop() {
  
}
