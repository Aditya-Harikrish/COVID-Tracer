#include "list.h"

void updatePeople(person* persons[],int day,LL station_Number,int personNumber)//This has array of persons with each having vectors
{
        pushback(&(persons[personNumber]->stations_visited[day%15]),personNumber);//this adds the station to the visited vector on that day
}


void getPrimaryContacts(int Day,person* persons[],station* stations[],LL positive[],int positiveVal,int totalPeople)//positiveVal is the total number of positive people
{

    for(int i=0;i<positiveVal;i++)//this loop is for iterating through all the positive people
    {
        for(int j=0;j<15;j++)//this is for keeping a track of all the past 15 days
        {
            for(int k = 0; k < persons[positiveVal]->stations_visited[j].size; k++) //this gives the stations which the person visited
            {
               int stationNum = persons[positive[k]]->stations_visited[j].arr[k]; //this gives the station numbers( type int )
               getStationContacts_primary(stationNum,stations,Day,persons,totalPeople,positive[k]);
            }
        }
    }
}


void updateStations(int Day,station* stations[],int stationVisit,int stationLeft,int personNumber)
{
    stations[stationVisit]->array_people[personNumber]=1;//this is a int array which is 1 if the person is present and 0 if that person is not there in that station
    stations[stationLeft]->array_people[personNumber]=0;
    stations[stationVisit]->transitNum++;//this is useful for keeping a track of time for which the person visited the station and the person left the station.
    pushback(stations[stationVisit]->array_time_personVisit[personNumber],stations[stationVisit]->transitNum);//=stations[stationVisit]->transitNum;//the above line is implemented here
    stations[stationLeft]->transitNum++;//at the end of each day transit num of each station should become 0
    pushback(stations[stationLeft]->array_time_personLeft[personNumber],stations[stationLeft]->transitNum);
}

void getStationContacts_primary(int stationVal,station* stations[],int Day,person* persons[],int totalPeople,LL positivePerson)//this day is the present day running
{
    for(int i=Day,j=0;j<15;i--,j++)
    {
        printf("Primary contacts on Day %d:\n",i);
        for(int k=0;k<totalPeople;k++)
        {
            if(stations[stationVal]->array_People[k]==1)//checking if that person is there in that station.
            {
                if(persons[k]->status!=POSITIVE)
                {
//                    if(stations[stationVal]->array_time_personVisit[k]<stations[stationVal]->array_time_personLeft[positivePerson])
//                    {
//                        printf("%d ",k);
//                        persons[k]->status=PRIMARY_CONTACT;
//                    }
                }
            }
            printf("/n");
        }

        printf("\n");
    }
}

void getSecondaryContacts(int Day,person* persons[],station* stations[],LL positive[],LL primary[])
{
    ;
}

void getStationContacts_secondary(int stationVal,station* stations[],int Day,person* persons[])
{

}