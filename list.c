#include "list.h"


void updatePeople(person* persons[],int day,LL station_Number,int personNumber)//This has array of persons with each having vectors
{
        pushback(&(persons[personNumber]->stations_visited[day%15]),personNumber);//this adds the station to the visited vector on that day
}


LL* getPrimaryContacts(int Day,person* persons[],station* stations[],LL positive[])
{
    ;
}


void updateStations(int Day,station* stations[],int stationVisit,int stationLeft,int personNumber)
{
    stations[stationVisit]->array_people[personNumber]=1;//this is a bool array which is 1 if the person is present and 0 if that person is not there in that station
    stations[stationLeft]->array_people[personNumber]=0;
    stations[stationVisit]->transitNum++;//this is useful for keeping a track of time for which the person visited the station and the person left the station.
    stations[stationVisit]->array_time_personVisit[personNumber]=stations[stationVisit]->transitNum;//the above line is implemented here
    stations[stationLeft]->transitNum++;
    stations[stationLeft]->array_time_personLeft[personNumber]=stations[stationLeft]->transitNum;

}

void getStationContacts(int stationVal,station* stations[],int Day,LL positive[])
{
    ;
}

void getSecondaryContacts(int Day,person* persons[],station* stations[],LL positive[],LL primary[])
{
    ;
}