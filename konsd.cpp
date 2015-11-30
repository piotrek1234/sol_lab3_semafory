/* konsument dojadający resztki (3) */

#include <iostream>
#include "fifo.h"
#include "sem.h"

using namespace std;

Sem mutex(1234);
Sem min3(1235);
Sem puste(1236);
Sem czytA(1237);
Sem czytB(1238);
Sem nCzytA(1239);
Sem nCzytB(1240);

Fifo fifo;

void usuwaj()
{
	cout << "[Usuwacz: czekam na 1]" << endl;
	czytA.down();
		cout << "[Usuwacz: czekam na 2]" << endl;
		czytB.down();
			cout << "[Usuwacz: kolejka>3? ]" << endl;
			min3.down();
			cout << "[Usuwacz: chce usuwac]" << endl;
			mutex.down();
				cout << "[Usuwacz usuwa]";
				fifo.pop();
				fifo.de();
				puste.up();
			mutex.up();
		nCzytA.up();
		nCzytB.up();
}

int main (void)
{
	for(int i=0; i<20; i++)
		usuwaj();
}