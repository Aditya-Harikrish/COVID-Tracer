#include "common.h"
void move_forward_one_day(person* p, station* s, int *day)
{
    ++(*day);
    delete_vector(&(p->stations_visited[*day % 15]));
    delete_vector(&(s->persons_visited[*day % 15]));
}