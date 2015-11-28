CC=g++
CFLAGS=-Wall

all: alokacja prodA prodB kons1 dealokacja
	$(CC) $(CFLAGS) alokacja.cpp -o alokacja
	$(CC) $(CFLAGS) dealokacja.cpp -o dealokacja
	$(CC) $(CFLAGS) prodA.cpp -o prodA
	$(CC) $(CFLAGS) prodB.cpp -o prodB
	$(CC) $(CFLAGS) kons1.cpp -o kons1

clean:
	rm -f alokacja dealokacja prodA prodB kons1