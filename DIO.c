#include <avr/io.h>
#include "Std_Macros.h"

void DIO_SETPINDir(unsigned char port,unsigned char pin,unsigned char direction)
{
	switch(port)
	{
		case 'A':
		if(direction==1)
		{
			SET_BIT(DDRA,pin);  //outputpin
		}
		else
		{
			CLR_BIT(DDRA,pin);  //inputpin
		}
		break;
		case 'B':
		if(direction==1)
		{
			SET_BIT(DDRB,pin);  //outputpin
		}
		else
		{
			CLR_BIT(DDRB,pin);  //inputpin
		}
		break;
		case 'C':
		if(direction==1)
		{
			SET_BIT(DDRC,pin);  //outputpin
		}
		else
		{
			CLR_BIT(DDRC,pin);  //inputpin
		}
		break;
		case 'D':
		if(direction==1)
		{
			SET_BIT(DDRD,pin);  //outputpin
		}
		else
		{
			CLR_BIT(DDRD,pin);  //inputpin
		}
		break;
		default:
		break;
	}
	
	
}


void DIO_Write(unsigned char port,unsigned char pin,unsigned char outputvalue)
{
	switch(port)
	{
		case 'A':
		if(outputvalue==1)
		{
			SET_BIT(PORTA,pin);  //high
		}
		else
		{
			CLR_BIT(PORTA,pin);  //low
		}
		break;
		case 'B':
		if(outputvalue==1)
		{
			SET_BIT(PORTB,pin);  //high
		}
		else
		{
			CLR_BIT(PORTB,pin);  //low
		}
		break;
		case 'C':
		if(outputvalue==1)
		{
			SET_BIT(PORTC,pin);  //high
		}
		else
		{
			CLR_BIT(PORTC,pin);  //low
		}
		break;
		case 'D':
		if(outputvalue==1)
		{
			SET_BIT(PORTD,pin);  //high
		}
		else
		{
			CLR_BIT(PORTD,pin);  //low
		}
		break;
		default:
		break;
	}
}


unsigned char DIO_Read(unsigned char port,unsigned char pin)
{
	unsigned char return_val=0;
	switch(port)
	{
		case 'A':
		return_val=READ_BIT(PINA,pin);
		break;
		case 'B':
		return_val=READ_BIT(PINB,pin);
		break;
		case 'C':
		return_val=READ_BIT(PINC,pin);
		break;
		case 'D':
		return_val=READ_BIT(PIND,pin);
		break;
		default:
		break;
		
	}
	return return_val;
}


void DIO_Toggle(unsigned char port,unsigned char pin)
{
	switch(port)
	{
		case 'A':
		TOGG_BIT(PORTA,pin);
		break;
		case 'B':
		TOGG_BIT(PORTB,pin);
		break;
		case 'C':
		TOGG_BIT(PORTC,pin);
		break;
		case 'D':
		TOGG_BIT(PORTD,pin);
		break;
		default:
		break;
	}
}


void DIO_SETPortDir(unsigned char port,unsigned char direction)
{
	switch(port)
	{
		case 'A':
		DDRA=direction;
		break;
		case 'B':
		DDRB=direction;
		break;
		case 'C':
		DDRC=direction;
		break;
		case 'D':
		DDRD=direction;
		break;
		default:
		break;
	}
}


void DIO_WritePort(unsigned char port,unsigned char outputvalue)
{
	switch(port)
	{
		case 'A':
		PORTA=outputvalue;
		break;
		case 'B':
		PORTB=outputvalue;
		break;
		case 'C':
		PORTC=outputvalue;
		break;
		case 'D':
		PORTD=outputvalue;
		break;
		default:
		break;
	}
}

unsigned char DIO_ReadPort(unsigned char port)
{
	unsigned char return_val=0;
	switch(port)
	{
		case 'A':
		return_val=PINA;
		break;
		case 'B':
		return_val=PINB;
		break;
		case 'C':
		return_val=PINC;
		break;
		case 'D':
		return_val=PIND;
		break;
		default:
		break;
	}
	return return_val;
}


void DIO_ConnectPullup(char port,char pin,char connect_pullup)
{
	switch(port)
	{
		case 'A':
	if(connect_pullup==1)
	{
		SET_BIT(PORTA,pin); //internaL PULLup
	}
	else
	{
		CLR_BIT(PORTA,pin);
	}
	break;
	case 'B':
	if(connect_pullup==1)
	{
		SET_BIT(PORTB,pin); //internaL PULLup
	}
	else
	{
		CLR_BIT(PORTB,pin);
	}
	break;
	case 'C':
	if(connect_pullup==1)
	{
		SET_BIT(PORTC,pin); //internaL PULLup
	}
	else
	{
		CLR_BIT(PORTC,pin);
	}
	break;
	case 'D':
	if(connect_pullup==1)
	{
		SET_BIT(PORTD,pin); //internaL PULLup
	}
	else
	{
		CLR_BIT(PORTD,pin);
	}
	break;
	default:
	break;
	}	
}


void DIO_Write_Lownibble(unsigned char port,unsigned char outputvalue)
{
		outputvalue&=0x0f;
		switch(port)
		{
			case 'A':
			PORTA&=0xf0;
			PORTA|=outputvalue;
			case 'B':
			PORTB&=0xf0;
			PORTB|=outputvalue;
			case 'C':
			PORTC&=0xf0;
			PORTC|=outputvalue;
			case 'D':
			PORTD&=0xf0;
			PORTD|=outputvalue;
		}
	
}


void DIO_Write_Highnibble(unsigned char port,unsigned char outputvalue)
{
	outputvalue<<=4;
	switch(port)
	{
		case 'A':
		PORTA&=0x0f;
		PORTA|=outputvalue;
		case 'B':
		PORTB&=0x0f;
		PORTB|=outputvalue;
		case 'C':
		PORTC&=0x0f;
		PORTC|=outputvalue;
		case 'D':
		PORTD&=0x0f;
		PORTD|=outputvalue;
	}
}