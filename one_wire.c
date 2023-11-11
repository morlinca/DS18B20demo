#include <STC15F2K60S2.H>
#include "one_wire.H"

static unsigned int is;

void one_wireInit(){
	
		one_wire =0;
		is = 247;
		while(--is);
		one_wire = 1;
		is = 29;
		while(--is);
		if(one_wire == 0){
			led2 = ~led2;
		}
}
void oneWireWriterBit(unsigned char Bit){
	one_wire = 0;
	is = 2;
	while(--is);
	one_wire =Bit;
	is = 25;
	while(--is);
	one_wire = 1;
	}

unsigned char oneWireReadBit(){
	unsigned char Bit;
	one_wire = 1;
	one_wire = 0;
	is = 2;
	while(--is);
	one_wire = 1;
	is = 2;
	while(--is);
	Bit = one_wire;
	is = 25;
	while(--is);
	return Bit;
}

void writerByte(unsigned char Byte){
	unsigned char index;
	for(index = 0;index<8;index++){
		oneWireWriterBit(Byte&(0x01<<index));
	}
}
unsigned char readerByte(){
	unsigned char index;
	unsigned char Byte;
	Byte = 0x00;
	for(index = 0;index<8;index++){
		if(oneWireReadBit() == 1){
		Byte |= (0x01<<index);
		}
	}
	return Byte;
}
