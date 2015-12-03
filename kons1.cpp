/* konsument 1 */

#include <iostream>
#include "fifo.h"
#include "sem.h"
#include "delay.h"

using namespace std;

Sem mutex(1234);
Sem min3(1235);
Sem puste(1236);
Sem czytA(1237);
Sem czytB(1238);
Sem nCzytA(1239);
Sem nCzytB(1240);

Fifo fifo;

void czytaj()
{
	cout << "[1: nie czytalem?]" << endl;
	nCzytA.down();
		cout << "[1: kolejka>3?   ]" << endl;
		min3.down();
			cout << "[1 chce czytac   ]" << endl;
			mutex.down();
				cout << "[1 czyta: " << fifo.get() << "]";
				fifo.de();
			mutex.up();
		min3.up();
	czytA.up();
}

int main (void)
{
	for(int i=0; i<20; i++)
	{
		#ifdef DELAY
		delay();
		#endif
		czytaj();
	}
}