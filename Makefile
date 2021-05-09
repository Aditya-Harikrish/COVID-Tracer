CC=gcc


init: main.o common.o list.o person_queries.o person.o station.o vector.o dijkshtra.o list1.o
	$(CC) -g main.o common.o list.o person_queries.o person.o station.o vector.o dijkshtra.o list1.o -o CovidTracing

main.o: main.c
	$(CC) -c main.c

common.o: common.c
	$(CC) -c common.c

list.o: list.c
	$(CC) -c list.c

person_queries.o: person_queries.c
	$(CC) -c person_queries.c

person.o: person.c
	$(CC) -c person.c

station.o: station.c
	$(CC) -c station.c

dijkshtra.o: dijkshtra.c
	$(CC) -c dijkshtra.c

list1.o: list1.c
	$(CC) -c list1.c

clean:
	rm -rf *.o CovidTracing

