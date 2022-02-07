#include "Keyboard.h"
#include <Keypad.h>

const int row1 = 5;
const int row2 = 4;
const int row3 = 3;
const int row4 = 2;
const int row5 = 6;

const int col1 = A0;
const int col2 = A1;
const int col3 = A2;
const int col4 = A3;
const int col5 = A4;

const byte ROWS = 5; 
const byte COLS = 5; 

char hexaKeys[ROWS][COLS] = {
    {'1',KEY_TAB,KEY_CAPS_LOCK,KEY_LEFT_SHIFT,KEY_LEFT_CTRL},
    {'2','q','a','z',' '},
    {'3','w','s','x','KEY_LEFT_ALT'},
    {'4','e','d','c',' '},
    {'5','r','f','v',' '}
};
byte rowPins[ROWS] = {row1, row2, row3, row4, row5};
byte colPins[COLS] = {col1, col2, col3, col4, col5};

Keypad kpd = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  pinMode(col1, OUTPUT);
  pinMode(col2, OUTPUT);
  pinMode(col3, OUTPUT);
  pinMode(col4, OUTPUT);
  pinMode(col5, OUTPUT);

  digitalWrite(col1, HIGH);
  digitalWrite(col2, HIGH);
  digitalWrite(col3, HIGH);
  digitalWrite(col4, HIGH);
  digitalWrite(col5, HIGH);

  pinMode(row1, INPUT_PULLUP);
  pinMode(row2, INPUT_PULLUP);
  pinMode(row3, INPUT_PULLUP);
  pinMode(row4, INPUT_PULLUP);
  pinMode(row5, INPUT_PULLUP);
  
  Keyboard.begin();
}

void loop(){
    if (kpd.getKeys())
    {
        for (int i=0; i<23; i++)   // Scan the whole key list.
        {
            if(kpd.key[i].kstate == PRESSED || kpd.key[i].kstate == HOLD) {
              Keyboard.press(kpd.key[i].kchar);
            }

            if(kpd.key[i].kstate == RELEASED) {
              Keyboard.release(kpd.key[i].kchar);
            }
        }
    }
}
