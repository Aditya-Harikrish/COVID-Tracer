


#include "list1.h"

//Now we find the Secondary contacts from the list of primary contacts we received from the day a person became a primary contact to the present day.
// if the person is not positive, primary and quarantined and was present at a particular station on a particular day then he is said to be a secondary 
// contact if a primary contact was also on the same station on that day.
                



void getSecondaryContacts(int Day,person* persons[],station* stations[],vector v,int X)
{
    for (int i=0;i< v.size;i++) // To check all the Primary Contacts in the given list.
    {
        int k=0; 
        for (int Daycount=Day ,j=0; j<X ||Daycount>=0;j++,Daycount--) //Keeps track of all the days from the day the person is a Primary Contact to the Present Day.   
        {   
            while(k < persons[v.size]->stations_visited[Daycount%15].size) // Checks all the Stations that a Primary Contact has visited from the day he 
            {                                                               //became a Primary contact  to the Present Day
                int stationNum = persons[v.arr[k]]->stations_visited[Daycount%15].arr[k]; // the station that a Primary contact visited on a particular day 
                getStationContacts_secondary(stationNum,stations,Day,persons,totalPeople, v.arr[k]);
                //getStationContacts_secondary computes all the Secondary Contacts in a particular station on a particular day
                
            }
            k++;
        }
    }
}

// Now we iterate over all the people and check who have been in contact with the Primary contact on a particular day in a given station.


void getStationContacts_secondary(int stationVal,station* stations[],int Day, person* persons[], int totalPeople, int X)
{

    int k=0;

    while( k<totalPeople) // For all the people we need to check whether they are Secondary People
    {
        for (int i=Day, j=0;j<X|| i>=persons[k]->statusChangeDay, i--,j++) // We need to keep track of all the people the Primary Contact was in contact with from the day he bacame a primary contact to the Present Day.
        {

            if (station[stationVal]->Arraytotal[k]==1)  // if the station is visited by the primary contact.
            {
                if (persons[k]->status!= POSITIVE && persons[k]->status!=PRIMARY_CONTACT && persons[k]->status!=QUARANTINED && persons[k]->status!=SECONDARY_CONTACT) 
                {
                    printf("%d",k);
                    persons[k]->status=SECONDARY_CONTACT; //we update the status of the person
                    persons[k]->statusChangeDay=Day; //we update the day when the status has been changed.
                }
            }
        
        }
        k++;
    }
    printf("\n");



}

