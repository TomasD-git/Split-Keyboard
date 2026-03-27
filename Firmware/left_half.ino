// Left half firmware
#include "USB.h"
#include "USBHIDKeyboard.h"

USBHIDKeyboard Keyboard;
const uint8_t COL_PINS[] = { 1,  2,  4,  5,  6,  7,  8 };
const uint8_t ROW_PINS[] = { 11,  12,  13,  14,  15 };


#define NUM_COLS   7
#define NUM_ROWS   5
#define DEBOUNCE   5   

const uint8_t KEYMAP[NUM_ROWS][NUM_COLS] = {
        { KEY_ESC,        '1',   '2',   '3',   '4',   '5',   '6'          },
        { KEY_TAB,        'q',   'w',   'e',   'r',   't',   0x00         },
        { KEY_CAPS_LOCK,  'a',   's',   'd',   'f',   'g',   0x00         },
        { KEY_LEFT_SHIFT, 'z',   'x',   'c',   'v',   'b',   0x00         },
        { KEY_LEFT_CTRL,  KEY_LEFT_GUI, KEY_LEFT_ALT, ' ', 0x00, 0x00, 0x00 },
};

uint8_t debounce[NUM_ROWS][NUM_COLS];
bool    keyState[NUM_ROWS][NUM_COLS];

void setup() {
    for (int c = 0; c < NUM_COLS; c++) {
        pinMode(COL_PINS[c], OUTPUT);
        digitalWrite(COL_PINS[c], HIGH);
    }
    for (int r = 0; r < NUM_ROWS; r++) {
        pinMode(ROW_PINS[r], INPUT_PULLUP);
    }

    USB.manufacturerName("DIY");
    USB.productName("Split KB Left");
    USB.begin();
    Keyboard.begin();
    delay(1000);  
}
void loop() {
    for (int col = 0; col < NUM_COLS; col++) {
        digitalWrite(COL_PINS[col], LOW);
        delayMicroseconds(10);  

        for (int row = 0; row < NUM_ROWS; row++) {
            bool raw = (digitalRead(ROW_PINS[row]) == LOW);

            if (raw == keyState[row][col]) {
                debounce[row][col] = 0;
            } else if (++debounce[row][col] >= DEBOUNCE) {
                debounce[row][col] = 0;
                keyState[row][col] = raw;

                uint8_t k = KEYMAP[row][col];
                if (k) {
                    raw ? Keyboard.press(k) : Keyboard.release(k);
                }
            }
        }

        digitalWrite(COL_PINS[col], HIGH);
    }
    delay(1);   
}
