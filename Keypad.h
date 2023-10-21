#ifndef Keypad_H_
#define Keypad_H_
#define NOTPRESSED 0xff
#include "DIO.h"
void Keypad_Init();
char Keypad_CheckPress();
#endif
