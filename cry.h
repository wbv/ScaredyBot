#ifndef CRY_PIN
#define CRY_PIN 11
#endif

void cry_setup() {
  pinMode(CRY_PIN, OUTPUT);
}

void cry() {
  static unsigned pitch = 1760; // 1760 Hz = A6
  for (int i = 0; i < (1760-1485); i += 1) {
    tone(CRY_PIN, pitch - i);
    delay(5);
  }
}

void cry_selftest() {
  unsigned long pitch;
  
  Serial.println("Enter a pitch to play (between 31 & 65535 Hz)"
                 "\nEnter 1 to mute");
  
  while (true) {
    if (Serial.available()) {
      /* Read in a pitch */
      pitch = Serial.parseInt();
      
      if (pitch == 1) {
        noTone(CRY_PIN);
        Serial.println("muting");
      } else {
        Serial.print("playing tone at ");
        pitch = min(65535, max(31, pitch));
        tone(CRY_PIN, pitch);
        Serial.print(pitch);
        Serial.print("Hz\n");
      }
      
      /* Read from the Serial thing so long as there's something to read */
      //for (;Serial.read() != -1;);
    }
  }
}

