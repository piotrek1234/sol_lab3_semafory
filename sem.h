#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <iostream>

using namespace std;

union semun {
int val;
struct semid_ds *buf;
unsigned short int *array;
struct seminfo *__buf;
};

class Sem{
private:
	int semaphore_initialize (int init_val)
	{
		union semun argument;
		unsigned short values[1];
		values[0] = init_val;
		argument.array = values;
		return semctl (semid, 0, SETALL, argument);
	}

public:
	Sem(int init_val, int klucz) : key(klucz)
	{
		semid = semget(key, 1, IPC_CREAT|0666);
		semaphore_initialize(init_val);
		cout << "Nowy semafor, id: " << semid << endl;
	}

	Sem(int klucz) : key(klucz)
	{
		semid = semget(key, 1, IPC_CREAT|0666);
		cout << "Podpięto pod semafor, id: " << semid << endl;
	}

	~Sem(){}

	int deallocate ()
	{
		union semun ignored_argument;
		cout << "Dealokowanie semafora, id: " << semid << endl;
		return semctl (semid, 1, IPC_RMID, ignored_argument);
	}

	int down ()
	{
		struct sembuf operations[1];
		/* Use the first (and only) semaphore. */
		operations[0].sem_num = 0;
		/* Decrement by 1. */
		operations[0].sem_op = -1;
		return semop (semid, operations, 1);
	}
	
	int up ()
	{
		struct sembuf operations[1];
		/* Use the first (and only) semaphore. */
		operations[0].sem_num = 0;
		/* Increment by 1. */
		operations[0].sem_op = 1;
		return semop (semid, operations, 1);
	}
private:
	int key;
	int semid;
};

