/* konsument dojadający resztki (3) */

#include <iostream>
#include "fifo.h"
#include "sem.h"

using namespace std;

Sem mutex(1234);
Sem min3(1235);
Sem puste(1236);
Sem info(1237);

Fifo fifo;

void czytaj()
{
	cout << "[d czeka na dane]" << endl;
	min3.down();
	cout << "[d chce czytac]" << endl;
	mutex.down();
	cout << "[d czyta:";
	cout << fifo.pop() << "]";
	fifo.de();
	puste.up();
	mutex.up();
}

int main (void)
{
	for(int i=0; i<3; i++)
		czytaj();
}