#include "common.h"
void move_forward_one_day(person* p, station* s, int *day,int totalPeople,int totalStations)
{
    ++(*day);
    delete_vector(&(p->stations_visited[*day % 15]));
    for(int i=0;i<totalStations;i++)
    {
        for(int j=0;j<totalPeople;j++) {
            s[i].Arraytotal[j] = s[i].array_people[j];
        }
    }
}