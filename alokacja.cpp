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
	Sem info(1, 1237);

	cout << "Alokacja gotowa" << endl;
	return 0;
}