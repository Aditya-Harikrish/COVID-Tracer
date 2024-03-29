CC=gcc

## If unable to use Makefile ,Use following command

## gcc -g main.c common.c list.c person_queries.c person.c station.c vector.c dijkstra.c list1.c -o CovidTracing 

init: main.o common.o list.o person_queries.o person.o station.o vector.o dijkstra.o list1.o
	$(CC) -g main.o common.o list.o person_queries.o person.o station.o vector.o dijkstra.o list1.o -o CovidTracing

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

dijkstra.o: dijkstra.c
	$(CC) -c dijkstra.c

list1.o: list1.c
	$(CC) -c list1.c

vector.o: vector.c
	$(CC) -c vector.c

clean:
	rm -rf *.o CovidTracing

