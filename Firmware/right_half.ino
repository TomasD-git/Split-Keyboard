// right half firmware
#include "USB.h"
#include "USBHIDKeyboard.h"

USBHIDKeyboard Keyboard;

const uint8_t COL_PINS[] = { 1,  2,  4,  5,  6,  7,  8,  9, 10 };
const uint8_t ROW_PINS[] = { 11,  12,  13,  14,  15 };

#define NUM_COLS   9
#define NUM_ROWS   5
#define DEBOUNCE   5


#define FN_ROW  4  
#define FN_COL  2   
bool fnActive = false;

const uint8_t KEYMAP[NUM_ROWS][NUM_COLS] = {
        { '7',   '8',   '9',   '0',   '-',   '=',   KEY_BACKSPACE, KEY_PRINT_SCREEN, 0x00            },
        { 'y',   'u',   'i',   'o',   'p',   '[',   ']',           '\\',             KEY_LEFT_ARROW  },
        { 'h',   'j',   'k',   'l',   ';',   '\'',  KEY_RETURN,    KEY_DOWN_ARROW,   0x00            },
        { 'n',   'm',   ',',   '.',   '/',   KEY_RIGHT_SHIFT, KEY_UP_ARROW, 0x00,   0x00             },
        { ' ',   KEY_RIGHT_ALT, 0x00, KEY_RIGHT_GUI, KEY_RIGHT_CTRL, KEY_RIGHT_ARROW, 0x00, 0x00, 0x00 },
};


uint8_t debounce[NUM_ROWS][NUM_COLS];
bool    keyState[NUM_ROWS][NUM_COLS];


void processKey(int row, int col, bool pressed) {
    if (row == FN_ROW && col == FN_COL) {
        fnActive = pressed;
        return;
    }

    uint8_t k = fnActive ? FN_MAP[row][col] : KEYMAP[row][col];
    if (k == 0x00) return;

    pressed ? Keyboard.press(k) : Keyboard.release(k);
}

void setup() {
    for (int c = 0; c < NUM_COLS; c++) {
        pinMode(COL_PINS[c], OUTPUT);
        digitalWrite(COL_PINS[c], HIGH);
    }
    for (int r = 0; r < NUM_ROWS; r++) {
        pinMode(ROW_PINS[r], INPUT_PULLUP);
    }

    USB.manufacturerName("DIY");
    USB.productName("Split KB Right");
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
                processKey(row, col, raw);
            }
        }

        digitalWrite(COL_PINS[col], HIGH);
    }
    delay(1);
}
