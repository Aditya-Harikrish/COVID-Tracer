#include "vector.h"
#include "station.h"
#ifndef PERSON_H
#define PERSON_H

#define NEGATIVE 0
#define POSITIVE 1
#define PRIMARY_CONTACT 2
#define SECONDARY_CONTACT 3
#define QUARANTINED 4

typedef struct person person;
struct person {
    int id; // starts from 0
    int status;
    vector stations_visited[15];
    int statusChangeDay;
    int changeVal;
};
void init_person(person* p); 
// O(1)

void add_travel(person* p, station* s, int day, int destination,int i);
// Same TC as pushback

int getStatus(person* p);
// O(1)


#endif