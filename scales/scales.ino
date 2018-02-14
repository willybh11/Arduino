#include <pitches.h>

//www.elegoo.com
//3016.13.08

#include "pitches.h"

// notes in the melody:
int C[] = {
  NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_A3, NOTE_B3, NOTE_C4
};

int Cm7[] = {
  NOTE_C3, NOTE_D3, NOTE_DS3, NOTE_F3, NOTE_G3, NOTE_A3, NOTE_AS3, NOTE_C4
};

int C_penta[] = {
  NOTE_C3, NOTE_DS3, NOTE_F3, NOTE_FS3, NOTE_G3, NOTE_AS3, NOTE_C4, 
};





int duration = 300;  // 300 miliseconds

void setup() {

}

void loop() {
  for (int thisNote = 0; thisNote < 7; thisNote++) {
    // pin8 output the voice, every scale is 0.3 sencond
    tone(8, C_penta[thisNote], duration);

    // Output the voice after several minutes
    delay(300);
  }

  // restart after two seconds
  delay(300);
  for (int thisNote = 6; thisNote > -1; thisNote--) {
    // pin8 output the voice, every scale is 0.3 sencond
    tone(8, C_penta[thisNote], duration);

    // Output the voice after several minutes
    delay(300);
  }
  delay(300);
  }

