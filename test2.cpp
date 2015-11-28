#include <iostream>
#include "sem.h"

using namespace std;

int main(void)
{
	Sem mutex(1234);
	for(int i=0; i<20; i++)
	{
		mutex.down();
		cout << "test2: mutex = 0" << endl;
		mutex.up();
	}
}