#include "fifo.h"
#include "sem.h"
#include <iostream>

using namespace std;

int main (void)
{
	Fifo fifo;
	fifo.reset();

	Sem mutex(1, 1234);
	Sem min3(0, 1235);
	Sem puste(9, 1236);
	Sem czytA(0, 1237);
	Sem czytB(0, 1238);
	Sem nCzytA(1, 1239);
	Sem nCzytB(1, 1240);

	cout << "Alokacja gotowa" << endl;
	return 0;
}