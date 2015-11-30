/* konsument 2 */

#include <iostream>
#include "fifo.h"
#include "sem.h"
#include "delay.h"

using namespace std;

Sem mutex(1234);
Sem min3(1235);
Sem puste(1236);
Sem czytA(0, 1237);
Sem czytB(0, 1238);
Sem nCzytA(1, 1239);
Sem nCzytB(1, 1240);

Fifo fifo;

void czytaj()
{
	cout << "[2: nie czytalem?]" << endl;
	nCzytB.down();
		cout << "[2: kolejka>3?   ]" << endl;
		min3.down();
			cout << "[2 chce czytac   ]" << endl;
			mutex.down();
				cout << "[2 czyta: " << fifo.get() << "]";
				fifo.de();
			mutex.up();
		min3.up();
	czytB.up();
}

int main (void)
{
	for(int i=0; i<20; i++)
	{
		#ifdef DELAY
		czytaj();
		#endif
	}
}