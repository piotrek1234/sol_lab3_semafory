#include <iostream>
#include "sem.h"

using namespace std;

int main(void)
{
	Sem mutex(1, 1234);
	Sem dwa(2, 1345);
	for(int i=0; i<20; i++)
	{
		mutex.down();
		cout << "test: mutex = 0" << endl;
		mutex.up();
	}
	while(1);
}