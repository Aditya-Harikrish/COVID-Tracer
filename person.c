#include "person.h"
#include "station.h"
#include "header.h"
void init_person(person* p)
{
    p->status = NEGATIVE;
    for (int i = 0; i < 15; ++i) {
        init_vector(&(p->stations_visited[i]));
    }
}
void add_travel(person* p, station* s, int day, int destination,int i)
{
    pushback(&(p->stations_visited[day % 15]), destination);
    s[destination].array_people[i]=1;
    s[destination].Arraytotal[i]=1;
}
// void move
