#include "LCD.h"
#define  F_CPU 8000000UL
#include <util/delay.h>

void LCD_Init(void)
{
	_delay_ms(200); //for bushbutton
	#if defined EIGHT_BITSMODE
	DIO_SETPINDir('A',0,1);
	DIO_SETPINDir('A',1,1);
	DIO_SETPINDir('A',2,1);
	DIO_SETPINDir('A',3,1);
	DIO_SETPINDir('A',4,1);
	DIO_SETPINDir('A',5,1);
	DIO_SETPINDir('A',6,1);
	DIO_SETPINDir('A',7,1);
	DIO_SETPINDir('B',EN,1);
	DIO_SETPINDir('B',RW,1);
	DIO_SETPINDir('B',RS,1);
	DIO_Write('B',RW,0);
	LCD_Sendcmd(EIGHT_BITS); //8 bits mode
	_delay_ms(1);
	LCD_Sendcmd(CURSOR_ON_DISPLAN_ON);
	_delay_ms(1);
	LCD_Sendcmd(CLR_SCREEN);
	_delay_ms(10);
	LCD_Sendcmd(ENTRY_MODE);
	_delay_ms(1);
	
	#elif defined FOUR_BITSMODE
	DIO_SETPINDir('A',4,1);
	DIO_SETPINDir('A',5,1);
	DIO_SETPINDir('A',6,1);
	DIO_SETPINDir('A',7,1);
	DIO_SETPINDir('B',EN,1);
	DIO_SETPINDir('B',RW,1);
	DIO_SETPINDir('B',RS,1);
	DIO_Write('B',RW,0);
	LCD_Sendcmd(RETURN_HOME);
	_delay_ms(10);
	LCD_Sendcmd(FOUR_BITS); //4 bits mode
	_delay_ms(1);
	LCD_Sendcmd(CURSOR_ON_DISPLAN_ON);
	_delay_ms(1);
	LCD_Sendcmd(CLR_SCREEN);
	_delay_ms(10);
	LCD_Sendcmd(ENTRY_MODE);
	_delay_ms(1);
	
	#endif
}

static void Send_FailingEdge(void)
{
	DIO_Write('B',EN,1);
	_delay_ms(2);
	DIO_Write('B',EN,0);
	_delay_ms(2);
	
}

void LCD_Sendcmd(char cmd)
{
	#if defined EIGHT_BITSMODE
	DIO_WritePort('A',cmd);
	DIO_Write('B',RS,0);
	Send_FailingEdge();
	
	#elif defined FOUR_BITSMODE
	DIO_Write_Highnibble('A',cmd>>4);
	DIO_Write('B',RS,0);
	Send_FailingEdge();
	DIO_Write_Highnibble('A',cmd);
	DIO_Write('B',RS,0);
	Send_FailingEdge();
	#endif
	
	_delay_ms(1);
	
}


void LCD_Sendchar(char data)
{
	#if defined EIGHT_BITSMODE
	DIO_WritePort('A',data);
	DIO_Write('B',RS,1);
	Send_FailingEdge();
	
	#elif defined FOUR_BITSMODE
	DIO_Write_Highnibble('A',data>>4);
	DIO_Write('B',RS,1);
	Send_FailingEdge();
	DIO_Write_Highnibble('A',data);
	DIO_Write('B',RS,1);
	Send_FailingEdge();
	#endif
	
	_delay_ms(1);
}


void LCD_Sendstring(char *data)
{
	while((*data)!='\0')
	{
		LCD_Sendchar(*data);
		data++;
	}
}


void LCD_CLRScreen()
{
	LCD_Sendcmd(CLR_SCREEN);
	_delay_ms(10);
}


void LCD_Movecurser(char row,char coloumn)
{
	char data;
	if(row>2||row<1||coloumn>16||coloumn<1)
	{
		data=0x80;
	}
	else if(row==1)
	{
		data=0x80+coloumn-1 ;
	}
	else if (row==2)
	{
		data=0xc0+coloumn-1;
	}
	LCD_Sendcmd(data);
	_delay_ms(1);
}