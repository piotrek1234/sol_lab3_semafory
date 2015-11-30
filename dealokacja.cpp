/* dealokator semaforów */

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

int main (void)
{
	mutex.deallocate();
	min3.deallocate();
	puste.deallocate();
	czytA.deallocate();
	czytB.deallocate();
	nCzytA.deallocate();
	nCzytB.deallocate();

	cout << "Dealokacja gotowa" << endl;
	return 0;
}