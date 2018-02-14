#include <pitches.h>
#include <Keypad.h>

//Keypad Setup
const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad


//Note Setup
int notes[32] = {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99};
int noteslen = -1;
int scale[10] = {};
int C7[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C4
};
int Cm7[] = {
  NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_C4
};
int CmMaj7[] = {
  NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_GS4, NOTE_B4, NOTE_C5, NOTE_C4
};
int Cdim[] = {
  NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_A4, NOTE_C5, NOTE_C4
};

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  Serial.println("Booting up...");
  tone(12, NOTE_C4, 200);
  delay(300);
  tone(12, NOTE_F4, 100);
  delay(100);
  tone(12, NOTE_G4, 100);
  delay(200);
  tone(12, NOTE_B4, 150);
  delay(200);
  tone(12, NOTE_C5, 200);
  delay(200);
  tone(12, NOTE_C6, 50);
  delay(100);
  tone(12, NOTE_C6, 50);
  delay(100);
  tone(12, NOTE_C6, 50);
  delay(50);
  Serial.println("Done!");
  Serial.println("Functions:\nA -> C7\nB -> Cm7\nC -> CmMaj7\nD -> Cdim\n* -> Recite\n# -> Reset");

}

void loop() {
  while (1) {
    char customKey = customKeypad.getKey();

    if (customKey) {
      int note = customKey - '0';
      if (customKey == '*') {
        recite();
        break;
      }
      if (customKey == '#') { //reset memory
        reset();
        break;
      }
      if ( note == 0) {
        add_rest();
        break;
      }
      if ( note < 10) {
        add_note(note);
      }
      else {
        if (customKey == 'A') {
          for (int i = 0; i < 9; i++) {
            scale[i] = C7[i];
          };
        }
        if (customKey == 'B') {
          for (int i = 0; i < 9; i++) {
            scale[i] = Cm7[i];
          };
        }
        if (customKey == 'C') {
          for (int i = 0; i < 9; i++) {
            scale[i] = CmMaj7[i];
          };
        }
        if (customKey == 'D') {
          for (int i = 0; i < 9; i++) {
            scale[i] = Cdim[i];
          };
        };
        Serial.println("Key Changed!");
      }
    }
  }
}

void recite() {
  Serial.println("Reciting...");
  for (int i = 0; i < 32; i++) { //Recite memory
    if (notes[i] != 99) {
      if (notes[i] == 11) {
        delay(400);
      } else {
        tone(12, scale[notes[i]], 200);
        delay(400);
      }
    }
  }
  Serial.println("Done!");
}

void reset() {
  Serial.println("Resetting...");
  for (int i = 0; i < 32; i++) {
    notes[i] = 99;
  }
  int noteslen = -1;
  Serial.println("Done!");
}

void add_rest() {
  noteslen++;
  notes[noteslen] = 11;
  Serial.println("Rest added.");
}

void add_note(int n) {
  noteslen++;
  notes[noteslen] = n - 1;
  Serial.println("New note added.");
  tone(12, scale[n - 1], 100);
}


