/* producent A */

#include <iostream>
#include "fifo.h"
#include "sem.h"

using namespace std;

Sem mutex(1234);
Sem min3(1235);
Sem puste(1236);
Sem info(1237);

Fifo fifo;

void produkuj()
{
	cout << "[A czeka na miejsce]" << endl;
	puste.down();
	
	cout << "[A chce wstawiac]" << endl;
	mutex.down();
		cout << "[A wstawia]";
		cout << endl;
		fifo.push('A');
		fifo.de();
		if(fifo.size() > 3)
			min3.up();
	mutex.up();
}

int main (void)
{
	for(int i=0; i<10; i++)
		produkuj();
}