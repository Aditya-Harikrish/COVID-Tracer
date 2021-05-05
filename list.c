#include "list.h"


void updatePeople(person* persons[],int day,LL station_Number,int personNumber)//This has array of persons with each having vectors
{
        pushback(&(persons[personNumber]->stations_visited[day%15]),personNumber);
}


LL* getPrimaryContacts(int Day,person* persons[],station* stations[],LL positive[])
{
    ;
}


void updateStations(int Day,station* stations[],int priorityVal)
{
    ;
}

void getStationContacts(int stationVal,station* stations[],int Day,LL positive[])
{
    ;
}

void getSecondaryContacts(int Day,person* persons[],station* stations[],LL positive[],LL primary[])
{
    ;
}