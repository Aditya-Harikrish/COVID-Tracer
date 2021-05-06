#include "common.h"
void move_forward_one_day(person* p, station* s, int *day)
{
    ++(*day);
    p->stations_visited[*day % 15];
}