CC = g++ -g

all: insertsort mergesort

insersion: insertsort.o
		$(CC) insertsort.o -o insertsort

merge: mergesort.o
		$(CC) mergesort.o -o mergesort

insersion.o: insertsort.cpp
	$(CC) -c insertsort.cpp

merge.o: mergesort.cpp
	$(CC) -c mergesort.cpp



clean:
	rm -f *.o insertsort mergesort
