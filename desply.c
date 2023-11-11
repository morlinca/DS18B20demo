#include "desply.h"
#include <STC15F2K60S2.H>

void Delay500ms(){
	unsigned char i, j, k;
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
