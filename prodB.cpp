/* producent B */

#include <iostream>
#include "delay.h"
#include "fifo.h"
#include "sem.h"

using namespace std;

Sem mutex(1234);
Sem min3(1235);
Sem puste(1236);

Fifo fifo;

void produkuj()
{
	cout << "[B czeka na miejsce]" << endl;
	puste.down();

	cout << "[B chce wstawiac]" << endl;
	mutex.down();
		cout << "[B wstawia]";
		fifo.push('B');
		fifo.de();
		if(fifo.size() > 3)
		{
			min3.up();
		}
	mutex.up();
}

int main (void)
{
	for(int i=0; i<10; i++)
	{
		#ifdef DELAY
		delay();
		#endif
		produkuj();
	}
	cout << "            [B konczy]" << endl;
}