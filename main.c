#include <STC15F2K60S2.H>
#include "one_wire.h"
#include "desply.h"
#include "ds18b20.h"
#include "ttl9600.h"

//sbit one_wire = P3^1;
//sbit led0 = P3^0;
//sbit led2 = P3^2;

unsigned int i = 0;
unsigned int times;
int temp;
void tm0_isr() interrupt 1{
	i++;
	if(i>= 1000){
		times++;
		if(times>=100){
		times = 0;
			led0 = ~led0;
		}
		i=0;
	}
}
void time_init(){
	
		AUXR |= 0x80;                   
    TMOD &= 0x0F;  
		TL0 = 0xF5;				
		TH0 = 0xFF;				
    TR0 = 1;                        
    ET0 = 1;                        
    EA = 1;

}

void main(){
	led0 = 1;
	one_wire = 1;
	led2 = 1;
	ttlswriter = 1;
	time_init();
	
	while(1){
		led2 = ~led2;
		temp = ds18b20run();
		writerTll(temp);
		Delay500ms();
	}
}
