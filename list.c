#include "list.h"

void updatePeople(person* persons[],int day,LL station_Number,int personNumber)//This has array of persons with each having vectors
{
        pushback(&(persons[personNumber]->stations_visited[day%15]),personNumber);//this adds the station to the visited vector on that day
}
//The purpose of updatePeople is that it updates the stations that person visited on that day.
//It pushes the station the person is goiing into the vector

vector getPrimaryContacts(int Day,person* persons[],station* stations[],LL positive[],int positiveVal,int totalPeople,int X)//positiveVal is the total number of positive people
{
    vector* v;
    init_vector(v);
    for(int i=0;i<positiveVal;i++)//this loop is for iterating through all the positive people
    {
        for(int j=0,l=Day;j<X||l==0;j++,l--)//this is for keeping a track of all the past 15 days
        {
            for(int k = 0; k < persons[positiveVal]->stations_visited[l%15].size; k++) //this gives the stations which the person visited
            {
               int stationNum = persons[positive[k]]->stations_visited[l%15].arr[k]; //this gives the station numbers( type int )
               v=getStationContacts_primary(stationNum,stations,Day,persons,totalPeople,positive[k],X);//the person surely visited that station

            }
        }
    }
    return *v;
}



void updateStations(int Day,station* stations[],int stationVisit,int stationLeft,int personNumber)
{
    stations[stationVisit]->array_people[personNumber]=1;
    stations[stationLeft]->array_people[personNumber]=0;
    stations[stationVisit]->Arraytotal[personNumber]=1;
}
//The purpose of UpdateStations is that it updates the stations with the people


vector getStationContacts_primary(int stationVal,station* stations[],int Day,person* persons[],int totalPeople,LL positivePerson,int X)//this day is the present day running
{
    vector* v;
    init_vector(v);
    for(int i=Day,j=0;j<X||i==0;i--,j++)
    {
        printf("Primary contacts on day: %d\n",i);
        for(int k=0;<totalPeople;k++)
        {
            if(station[stationVal]->Arraytotal[k]==1)
            {
                if(persons[k]->status!=PRIMARY_CONTACT||persons[k]->status!=POSITIVE||persons[k]->status!=QUARANTINED)
                {
                    printf("%d ",k);
                    persons[k]->status=PRIMARY_CONTACT;
                    persons[k]->statusChangeDay=Day;
                    pushback(v,k);
                }
            }
        }
    }
    printf("\n");
    return *v;
}



void getSecondaryContacts(int Day,person* persons[],station* stations[],LL positive[],LL primary[])
{
    ;
}



void getStationContacts_secondary(int stationVal,station* stations[],int Day,person* persons[])
{

}