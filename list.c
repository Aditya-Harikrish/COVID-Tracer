#include "list.h"

void updatePeople(person* persons[],int day,LL station_Number,int personNumber)//This has array of persons with each having vectors
{
        pushback(&(persons[personNumber]->stations_visited[day%15]),personNumber);//this adds the station to the visited vector on that day
}


void getPrimaryContacts(int Day,person* persons[],station* stations[],LL positive[],int positiveVal,int totalPeople,int X)//positiveVal is the total number of positive people
{
    for(int i=0;i<positiveVal;i++)//this loop is for iterating through all the positive people
    {
        for(int j=0,l=Day;j<X||l==0;j++,l--)//this is for keeping a track of all the past 15 days
        {
            for(int k = 0; k < persons[positiveVal]->stations_visited[l%15].size; k++) //this gives the stations which the person visited
            {
               int stationNum = persons[positive[k]]->stations_visited[l%15].arr[k]; //this gives the station numbers( type int )
               getStationContacts_primary(stationNum,stations,Day,persons,totalPeople,positive[k],X);//the person surely visited that station
            }
        }
    }
}



void updateStations(int Day,station* stations[],int stationVisit,int stationLeft,int personNumber)
{
    stations[stationVisit]->array_people[personNumber]=1;//this is a int array which is 1 if the person is present at some point of time
    stations[stationLeft]->array_people[personNumber]=0;
    stations[stationVisit]->transitNum++;//this is useful for keeping a track of time for which the person visited the station and the person left the station.
    pushback(stations[stationVisit]->array_time_personVisit[Day%15][personNumber],stations[stationVisit]->transitNum);//=stations[stationVisit]->transitNum;//the above line is implemented here
    stations[stationLeft]->transitNum++;//at the end of each day transit num of each station should become 0
    pushback(stations[stationLeft]->array_time_personLeft[Day%15][personNumber],stations[stationLeft]->transitNum);
}



void getStationContacts_primary(int stationVal,station* stations[],int Day,person* persons[],int totalPeople,LL positivePerson,int X)//this day is the present day running
{
    printf("Primary contacts in last 15 days:\n");
    for(int i=Day,j=0;j<X||i==0;i--,j++)
    {
        if((stations[stationVal]->array_time_personLeft[Day%15][positivePerson]).size==0&&stations[stationVal]->array_time_personVisit[Day%15][positivePerson]).size==0)//the positive person has not moved at all from that station on that day
        {
            if(stations[stationVal]->array_people[positivePerson]==1)
            {
                for(int k=0;k<totalPeople;k++)
                {
                    if(stations[stationVal]->array_time_personVisit[Day%15][k]).size==0)
                    {
                        if(persons[k]->status!=PRIMARY_CONTACT||persons[k]->status!=POSITIVE||persons[k]->status!=QUARANTINED)
                        {
                            printf("%d ",k);
                            persons[k]->status=PRIMARY_CONTACT;
                        }
                    }
                }
            }
        }

        else if((stations[stationVal]->array_time_personLeft[Day%15][positivePerson]).size>stations[stationVal]->array_time_personVisit[Day%15][positivePerson]).size)
        {
            for(int k=0;k<totalPeople;k++)
            {
                if((stations[stationVal]->array_time_personVisit[Day%15][positivePerson]).size==0)
                {

                }
            }
        }

        else if((stations[stationVal]->array_time_personLeft[Day%15][positivePerson]).size<stations[stationVal]->array_time_personVisit[Day%15][positivePerson]).size)
        {

        }
        else if((stations[stationVal]->array_time_personLeft[Day%15][positivePerson]).size<stations[stationVal]->array_time_personVisit[Day%15][positivePerson]).size)
        {
            if(stations[stationVal]->array_people[positivePerson]==1)
            {

            }
            if(stations[stationVal]->array_people[positivePerson]==0)
            {

            }
        }

    }
    printf("\n");
}



void getSecondaryContacts(int Day,person* persons[],station* stations[],LL positive[],LL primary[])
{
    ;
}



void getStationContacts_secondary(int stationVal,station* stations[],int Day,person* persons[])
{

}