#ifndef DIO_H_
#define DIO_H_

void DIO_SETPINDir(unsigned char port,unsigned char pin,unsigned char direction);
void DIO_Write(unsigned char port,unsigned char pin,unsigned char outputvalue);
unsigned char DIO_Read(unsigned char port,unsigned char pin);
void DIO_Toggle(unsigned char port,unsigned char pin);
void DIO_SETPortDir(unsigned char port,unsigned char direction);
void DIO_WritePort(unsigned char port,unsigned char outputvalue);
unsigned char DIO_ReadPort(unsigned char port);
void DIO_ConnectPullup(char port,char pin,char connect_pullup);
void DIO_Write_Lownibble(unsigned char port,unsigned char outputvalue);
void DIO_Write_Highnibble(unsigned char port,unsigned char outputvalue);

#endif