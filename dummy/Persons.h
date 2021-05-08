#ifndef _PERSON_H
#define _PERSON_H

#include "Stations.h"

typedef struct persons {
    int status;//-1 for positive, 0 for neutral, 1 for primary 2 for secondary
    LL CurrentStation ;
    int** stations_visited[15];
} persons;

persons InitPersonNode();


#endif