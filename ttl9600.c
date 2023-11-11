#include "ttl9600.h"
#include <STC15F2K60S2.H>
#include "one_wire.h"


void writerTll(unsigned int tsts){
	char i;
	ttlswriter = 1;			
			i = 45;
			while (--i);
	ttlswriter = 0;
	i = 45;
			while (--i);
	for(i=0;i<8;i++){
		ttlswriter = 0x8000&(tsts<<(16-i));
		i = 45;
			while (--i);
	}
	ttlswriter = 1;
	i = 45;
			while (--i);
	ttlswriter = 0;
		i = 45;
			while (--i);
	for(i=8;i<16;i++){
		ttlswriter = 0x8000&(tsts<<(16-i));
		i = 45;
			while (--i);
	}
	ttlswriter = 1;
	i = 45;
			while (--i);
	
}
