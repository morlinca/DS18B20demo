#ifndef __ONE_WIRE_H__
#define __ONE_WIRE_H__

#define uint unsigned int
sbit one_wire = P3^1;
sbit led0 = P3^0;
sbit led2 = P3^2;
sbit ttlswriter = P3^3;
void one_wireInit();

void writerByte(unsigned char Byte);
unsigned char readerByte();



#endif



