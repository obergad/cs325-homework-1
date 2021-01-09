CC = g++ -g

all: insersion merge

insersion: insersion.o
		$(CC) insersion.o -o insersion

merge: merge.o
		$(CC) merge.o -o merge

insersion.o: insersion.cpp
	$(CC) -c insersion.cpp

merge.o: merge.cpp
	$(CC) -c merge.cpp



clean:
	rm -f *.o insersion merge 
