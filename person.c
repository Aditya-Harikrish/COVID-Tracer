#include "person.h"
#include "header.h"
void init_person(person* p)
{
    p->status = NEGATIVE;
    for (int i = 0; i < 15; ++i) {
        init_vector(&(p->stations_visited[i]));
    }
}
void add_travel(person* p, int day, int destination)
{
    pushback(&(p->stations_visited[day % 15]), destination);
}
// void move
