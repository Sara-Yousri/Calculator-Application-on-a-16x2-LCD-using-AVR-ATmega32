#include "Keypad.h"

void Keypad_Init()
{
	//set 1st 4 pins of portD as output pins
	DIO_SETPINDir('D',0,1);
	DIO_SETPINDir('D',1,1);
	DIO_SETPINDir('D',2,1);
	DIO_SETPINDir('D',3,1);
	//set last pins as input pins
	DIO_SETPINDir('D',4,0);
	DIO_SETPINDir('D',5,0);
	DIO_SETPINDir('D',6,0);
	DIO_SETPINDir('D',7,0);
	//connect pullup for input pins
	DIO_ConnectPullup('D',4,1);
	DIO_ConnectPullup('D',5,1);
	DIO_ConnectPullup('D',6,1);
	DIO_ConnectPullup('D',7,1);
}

char Keypad_CheckPress()
{
  char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
  char row,coloumn,x;
  char returnval=NOTPRESSED;
  for(row=0;row<4;row++)
  {
	   DIO_Write('D',0,1);
	   DIO_Write('D',1,1);
	   DIO_Write('D',2,1);
	   DIO_Write('D',3,1);
	   DIO_Write('D',row,0);
	   
	   for(coloumn=0;coloumn<4;coloumn++)
	   { x=DIO_Read('D',(coloumn+4));
		   if (x==0)
		   {
			   returnval=arr[row][coloumn];
			   break;
		   }
	   }
	   if (x==0)
	   {
		   break;
	   }
	   		   
  }
  return returnval;
}