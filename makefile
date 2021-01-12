CC = g++ -g

all: insertsort mergesort generatetxt

insersion: insertsort.o
		$(CC) insertsort.o -o insertsort

merge: mergesort.o
		$(CC) mergesort.o -o mergesort

insersion.o: insertsort.cpp
	$(CC) -c insertsort.cpp

merge.o: mergesort.cpp
	$(CC) -c mergesort.cpp

generatetxt: generatetxt.o
		$(CC) generatetxt.o -o generatetxt

generatetxt.o: generatetxt.cpp
	$(CC) -c generatetxt.cpp

insertTime: insertTime.o
		$(CC) insertTime.o -o insertTime

insertTime.o: insertTime.cpp
	$(CC) -c insertTime.cpp

mergeTime: mergeTime.o
		$(CC) mergeTime.o -o mergeTime

mergeTime.o: mergeTime.cpp
	$(CC) -c mergeTime.cpp

clean:
	rm -f *.o insertsort mergesort generatetxt mergeTime insertTime
