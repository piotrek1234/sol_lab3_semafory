/* dealokator semaforów */

#include <iostream>
#include "fifo.h"
#include "sem.h"

using namespace std;

Sem mutex(1234);
Sem min3(1235);
Sem puste(1236);
Sem info(1237);

int main (void)
{
	mutex.deallocate();
	min3.deallocate();
	puste.deallocate();
	info.deallocate();

	cout << "Dealokacja gotowa" << endl;
	return 0;
}