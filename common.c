#include "common.h"
#include "person_queries.h"
void move_forward_one_day(person* p, station* s, int* day, int totalPeople, int totalStations)
{
    int d = *day;
    ++(*day);
    //delete_vector(&(p->stations_visited[*day % 15]));
    for (int i = 0;i < totalPeople;i++) {
        vector v = p[i].stations_visited[*day % 15];
        vector v1 = p[i].stations_visited[d % 15];
        int l = location(p[i], d, 'R');
        while (v.size != 0)
            popback(&v);
        pushback(&p[i].stations_visited[*day % 15], l);
    }
    for (int i = 0;i < totalStations;i++) {
        for (int j = 0;j < totalPeople;j++) {
            s[i].Arraytotal[j] = s[i].array_people[j];
        }
    }
}
//This function  increases the day by 1 and updates the Arraypeople to the person's last present station in a day.
//The purpose of doing this is since Arraypeople keeps a track of the person's presence in any point of time in that particular day,
// His presence will be same as that of the last present station on the previous day.
// This also removes the station history of stations visited by a particular person on the following day if it is present.