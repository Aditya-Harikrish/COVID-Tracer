#include "header.h"
#include "vector.h"
#ifndef _STATION_H
#define _STATION_H

typedef struct station station;
struct station {
    int id;
    double dangerValue;
    //vector persons_visited[15];
    int* array_people;
    vector* array_time_personVisit;
    vector* array_time_personLeft;
};
void init_station(station* station_object, int id, int N);


#endif