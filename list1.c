
#include "list.h"

//Now we find the Secondary contacts from the list of primary contacts we received from the day a person became a primary contact to the present day.




void getSecondaryContacts(int Day,person* persons[],station* stations[],vector v,int X)
{
    for (int i=0;i< v.size;i++) 
    {
        
        int k=0; 

        while(k < persons[v.size]->stations_visited[Daycount%15].size) // Now we check all the Stations that a Primary Contact has visited on a particular Day
        {
            for (int Daycount= Dayj=0; j<X ||Daycount>=persons[k]->statusChangeDay;j++,Daycount--) //Keeps track of all the days from the day the person is a Primary Contact
            {
                int stationNum = persons[v.arr[k]]->stations_visited[Daycount%15].arr[k]; // the station that a Primary contact visited on a particular day 
                getStationContacts_secondary(stationNum,stations,Day,persons,totalPeople, v.arr[k]);
                //getStationContacts_secondary computes all the Secondary Contacts in a particular station on a particular day
                
            }
            k++;
        }
    }
}



void getStationContacts_secondary(int stationVal,station* stations[],int Day, person* persons[], int totalPeople, int X)
{
    
    int k=0;
    while( k<totalPeople) // For all the people we need to check whether they are Secondary People
    {
        for (int i=Day, j=0;j<X|| i>=persons[k]->statusChangeDay, i--,j++) // We need to keep track of the people from the day a person became a primary contact.
        {

            if (station[stationVal]->Arraytotal[k]==1)  
            {
                if (persons[k]->status!= POSITIVE && persons[k]->status!=PRIMARY_CONTACT && persons[k]->status!=QUARANTINED)
                {
                    printf("%d",k);
                    persons[k]->status=SECONDARY_CONTACT; 
                    persons[k]->statusChangeDay=Day;
                }
            }
        
        }
        k++;
    }
    printf("\n");



}







