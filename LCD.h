#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"
#include "LCD_Config.h"
// most used cmd
#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAN_ON 0x0e
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#if defined FOUR_BITSMODE
#define EN 0
#define RS 1
#define RW 2
#define FOUR_BITS 0x28
#elif defined EIGHT_BITSMODE
#define EN 0 //no of pin
#define RS 1 //no of pin
#define RW 2 //no of pin
#define EIGHT_BITS 0x38
#endif

void LCD_Init(void);
static void Send_FailingEdge(void);
void LCD_Sendcmd(char cmd);
void LCD_Sendchar(char data);
void LCD_Sendstring(char *data);
void LCD_CLRScreen();
void LCD_Movecurser(char row,char coloumn);

#endif