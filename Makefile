CC=g++
CFLAGS=-Wall

all: alokacja prodA prodB kons1
	$(CC) $(CFLAGS) alokacja.cpp -o alokacja
	$(CC) $(CFLAGS) prodA.cpp -o prodA
	$(CC) $(CFLAGS) prodB.cpp -o prodB
	$(CC) $(CFLAGS) kons1.cpp -o kons1

clean:
	rm -f alokacja prodA prodB kons1