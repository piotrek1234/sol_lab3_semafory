#include <unistd.h>
#include <cstdlib>
#include <ctime>

void delay()
{
	//rlosowe czekanie 1-2 sekundy

	int czas;
	srand(time(0));
	czas = (std::rand() % 1000)+1000;

	usleep(1000*czas);
}