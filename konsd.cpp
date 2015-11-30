/* konsument dojadający resztki (3) */

#include <iostream>
#include "fifo.h"
#include "sem.h"

using namespace std;

Sem mutex(1234);
Sem min3(1235);
Sem puste(1236);
Sem czytA(0, 1237);
Sem czytB(0, 1238);
Sem nCzytA(1, 1239);
Sem nCzytB(1, 1240);

Fifo fifo;

void usuwaj()
{
	cout << "[Usuwacz: czekam na A]" << endl;
	czytA.down();
		cout << "[Usuwacz: czekam na B]" << endl;
		czytB.down();
			cout << "[Usuwacz: chce usuwac]" << endl;
			mutex.down();
				cout << "[Usuwacz usuwa]";
				fifo.pop();
				fifo.de();
			mutex.up();
		nCzytA.up();
		nCzytB.up();
}

int main (void)
{
	for(int i=0; i<20; i++)
		usuwaj();
}