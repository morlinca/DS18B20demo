#include <STC15F2K60S2.H>
#include "ds18b20.h"
#include "one_wire.h"

static unsigned char reRomcmd;
static unsigned char Tstate;
static unsigned char readmamorry;
static  int tbyte;
static unsigned char TL;
static unsigned char TH;
static float ttl;

int ds18b20run(){
		
			reRomcmd = 0xcc;
			Tstate = 0x44;
			readmamorry = 0xBE;
			one_wireInit();
			writerByte(reRomcmd);
			writerByte(Tstate);
			one_wireInit();
//		oneWireWriterBit(reRomcmd);
//		oneWireWriterBit(readmamorry);
			writerByte(reRomcmd);
			writerByte(readmamorry);
			TL = readerByte();
			TH = readerByte();
			tbyte = (TL<<8)|TH;
		//ttl = tbyte/16.0;
		return tbyte;
		

			
}