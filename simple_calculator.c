#include "LCD.h"
#include "keypad.h"
#define  F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	label:	
	LCD_Init();
	Keypad_Init();
unsigned char arr[6]={NOTPRESSED,NOTPRESSED,NOTPRESSED,NOTPRESSED,NOTPRESSED,NOTPRESSED} ;
unsigned short result ;
unsigned char counter=0 ;
while(1)
{
	do
	{
		arr[counter]=Keypad_CheckPress();
		
	} while(arr[counter]==NOTPRESSED);
	if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
	{
		LCD_CLRScreen();
		goto label ;
	}
	else
	{
		LCD_Sendchar(arr[counter]);
	}
	counter++;
	_delay_ms(300);
	do
	{
		arr[counter]=Keypad_CheckPress();
		
	}while(arr[counter]==NOTPRESSED);
	if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
	{
		LCD_CLRScreen();
		goto label ;
	}
	else
	{
		LCD_Sendchar(arr[counter]);
	}
	counter++;
	_delay_ms(300);
	
	do
	{
		arr[counter]=Keypad_CheckPress();
		
	}while(arr[counter]==NOTPRESSED);
	
	if(arr[counter]=='A'||arr[counter]=='=')
	{
		LCD_CLRScreen();
		goto label ;
	}
	else
	{
		LCD_Sendchar(arr[counter]);
	}
	counter++;
	_delay_ms(300);
	do
	{
		arr[counter]=Keypad_CheckPress();
		
	}while(arr[counter]==NOTPRESSED);
	
	if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
	{
		LCD_CLRScreen();
		goto label ;
	}
	else
	{
		LCD_Sendchar(arr[counter]);
	}
	counter++;
	_delay_ms(300);
	do
	{
		arr[counter]=Keypad_CheckPress();
		
	}while(arr[counter]==NOTPRESSED);
	
	if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
	{
		LCD_CLRScreen();
		goto label ;
	}
	else
	{
		LCD_Sendchar(arr[counter]);
	}
	counter++;
	_delay_ms(300);
	
	
	do
	{
		arr[counter]=Keypad_CheckPress();
		
	}while(arr[counter]==NOTPRESSED);
	
	if(arr[counter]=='=')
	{
		LCD_Sendchar(arr[counter]);
		
		
		
		switch(arr[counter-3])
		{
			case '+':
			result=(arr[counter-4]-48)+((arr[counter-5]-48)*10)+((arr[counter-2]-48)*10)+(arr[counter-1]-48);
			if(result>=100&&result<1000)
			{
				LCD_Sendchar((result/100)+48);
				LCD_Sendchar(((result/10)%10)+48);
				LCD_Sendchar((result%10)+48);
			}
			else if (result>=10&&result<100)
			{
				LCD_Sendchar((result/10)+48);
				LCD_Sendchar((result%10)+48);
			}
			else if(result<10)
			{
				LCD_Sendchar(result+48);
			}
			break;
			case '-' :
			result=((arr[counter-4]-48)+((arr[counter-5]-48)*10))-(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
			if(result>=100&&result<1000)
			{
				LCD_Sendchar((result/100)+48);
				LCD_Sendchar(((result/10)%10)+48);
				LCD_Sendchar((result%10)+48);
			}
			else if (result>=10&&result<100)
			{
				LCD_Sendchar((result/10)+48);
				LCD_Sendchar((result%10)+48);
			}
			else if(result<10)
			{
				LCD_Sendchar(result+48);
			}
			break;
			case '*':
			result=((arr[counter-4]-48)+((arr[counter-5]-48)*10))*(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
			if(result>=1000&&result<10000)
			{
				LCD_Sendchar((result/1000)+48);
				LCD_Sendchar(((result/100)%10)+48);
				LCD_Sendchar(((result/10)%10)+48);
				LCD_Sendchar((result%10)+48);
				
			}
			else if(result>=100&&result<1000)
			{
				LCD_Sendchar((result/100)+48);
				LCD_Sendchar(((result/10)%10)+48);
				LCD_Sendchar((result%10)+48);
			}
			else if (result>=10&&result<100)
			{
				LCD_Sendchar((result/10)+48);
				LCD_Sendchar((result%10)+48);
			}
			else if(result<10)
			{
				LCD_Sendchar(result+48);
			}
			break;
			case '/':
			result=((arr[counter-4]-48)+((arr[counter-5]-48)*10))/(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
			if(result>=100&&result<1000)
			{
				LCD_Sendchar((result/100)+48);
				LCD_Sendchar(((result/10)%10)+48);
				LCD_Sendchar((result%10)+48);
			}
			else if (result>=10&&result<100)
			{
				LCD_Sendchar((result/10)+48);
				LCD_Sendchar((result%10)+48);
			}
			else if(result<10)
			{
				LCD_Sendchar(result+48);
			}
			break;
			default : break;
			
		}
	}
	else
	{
		LCD_CLRScreen();
		goto label ;
	}
	_delay_ms(2000);
}
	}
			
