#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

using namespace std;

class Fifo{
	// buf[0] - indeks front
	// buf[1] - indeks back
public:
	Fifo()
	{
		int shmid;
		shmid = shmget(98765, 500*sizeof(int), IPC_CREAT|0666);
		if(shmid == -1)
			cout << "problem z shmget\n";
		buf = (int*)shmat(shmid, NULL, 0);
		if(buf == NULL)
			cout << "problem z shmat\n";
	}
	~Fifo(){}
	void push(int val)
	{
		buf[buf[1]] = val;
		buf[1]++;
	}
	int get() const { return buf[buf[0]]; }
	char pop()
	{
		buf[0]++;
		return buf[buf[0]-1];
	}
	int size() const { return buf[1]-buf[0]; }
	void reset()
	{
		buf[0] = 2;
		buf[1] = 2;
	}
	void de()
	{
		int i;
		for(i=buf[0]; i<buf[1]; i++)
			cout << "[" << (char)buf[i] << "]";
		cout << "<" << size() << ">" << endl;
		/*for(;i-front<9; i++)
			cout << "[ ]";*/
		//cout << endl;
	}
private:
	int* buf;
};
