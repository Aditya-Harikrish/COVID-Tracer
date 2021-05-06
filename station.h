#include "header.h"
#include "vector.h"
#ifndef _STATION_H
#define _STATION_H

typedef struct station station;
struct station {
    int id;
    double dangerValue;
    vector persons_visited[15];
};




#endif