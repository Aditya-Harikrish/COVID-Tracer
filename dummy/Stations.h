#ifndef _STATIONS_H
#define _STATIONS_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "Persons.h"

typedef long long int LL;
typedef struct station
{
    LL StationID;
    double DangerValue;
    persons* PersonArr; //maintaing person arr in a particular station
}Station;

Station InitStationNode(LL max_no_of_Persorns,int id);
void InitStation_Matraix(Station* StationArr);
double CalcDangerValue(Station s);
void UpdateStation_Matrix();

#endif