CC=g++
CFLAGS=-Wall -DDELAY

all: alokacja prodA prodB kons1 kons2 dealokacja konsd
	$(CC) $(CFLAGS) alokacja.cpp -o alokacja
	$(CC) $(CFLAGS) dealokacja.cpp -o dealokacja
	$(CC) $(CFLAGS) prodA.cpp -o prodA
	$(CC) $(CFLAGS) prodB.cpp -o prodB
	$(CC) $(CFLAGS) kons1.cpp -o kons1
	$(CC) $(CFLAGS) kons2.cpp -o kons2
	$(CC) $(CFLAGS) konsd.cpp -o konsd

clean:
	rm -f alokacja dealokacja prodA prodB kons1 konsd