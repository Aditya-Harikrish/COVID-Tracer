#include "list.h"

void updatePeople(person *persons[], int day, LL station_Number,int personNumber)//This has array of persons with each having vectors
{
    pushback(&(persons[personNumber]->stations_visited[day % 15]),station_Number);//this adds the station to the visited vector on that day
}
//The purpose of updatePeople is that it updates the stations that person visited on that day.
//It pushes the station the person is going to visit into the vector



void updateStations(int Day, station *stations[], int stationVisit, int stationLeft, int personNumber) {
    stations[stationVisit]->array_people[personNumber] = 1;
    stations[stationLeft]->array_people[personNumber] = 0;
    stations[stationVisit]->Arraytotal[personNumber] = 1;
}
//The purpose of UpdateStations is that it updates the stations array_people and Arraytotal
//array_people will tell the presence of the person in the visiting station and his absence in the left station
//Arraytotal will keep a check whether that person entered that station or not in that particular day


//Here in getPrimaryContacts we go under the assumption that if a positive person enters the station, that station is effected and will make all the people who enter it primary contact.

//This assumption was first not considered and then we tried to keep a track of time but there were 20+ cases we had to take care of and due to time constraints it was not possible
//to code that up.



vector
getPrimaryContacts(int Day, person *persons[], station *stations[], LL positive[], int positiveVal, int totalPeople,
                   int X)//positiveVal is the total number of positive people
{
    vector *v;
    init_vector(v);
    for (int i = 0; i < positiveVal; i++)//this loop is for iterating through all the positive people
    {
        for (int j = 0, l = Day; j < X || l == 0; j++, l--)//this is for keeping a track of all the past 15 days
        {
            for (int k = 0; k < persons[positiveVal]->stations_visited[l %
                                                                       15].size; k++) //this gives the stations which the person visited
            {
                int stationNum = persons[positive[k]]->stations_visited[l %
                                                                        15].arr[k]; //this gives the station numbers( type int )
                v = getStationContacts_primary(stationNum, stations, Day, persons, totalPeople, positive[k],
                                               X);//the person surely visited that station

            }
        }
    }
    return *v;
}
//This takes the input from the user as and calls the function getStationContacts_primary
//The purpose of this function is that it takes a list of stations, people, positive people, present day and the days till the user want the primary contacts and the total number of primary contacts
//The function first iterates through all the positive people and for each positive person, it gives the stations visited.
//Now we use this station visited to call other function named getStationContacts_primary which returns the vector of all the primary contacts


vector getStationContacts_primary(int stationVal, station *stations[], int Day, person *persons[], int totalPeople,
                                  LL positivePerson, int X)//this day is the present day running
{
    vector *v;
    init_vector(v);
    for (int i = Day, j = 0; j < X || i == 0; i--, j++) {
        printf("Primary contacts on day: %d\n", i);
        for (int k = 0;<totalPeople;
        k++)
        {
            if (station[stationVal]->Arraytotal[k] == 1) {
                if (persons[k]->status != PRIMARY_CONTACT || persons[k]->status != POSITIVE ||
                    persons[k]->status != QUARANTINED) {
                    printf("%d ", k);
                    persons[k]->status = PRIMARY_CONTACT;
                    persons[k]->statusChangeDay = Day;
                    pushback(v, k);
                }
            }
        }
    }
    printf("\n");
    return *v;
}
//This function getStationsContact_primary gives us the primary contacts.
//Since it is called for a station of a positive person, it checks for all the people present in that day on that station
//If that person is not primary or positive person or a quarantined person, he is considered a primary contact and his value is pushed into
// the vector of primary contacts


vector getPrimaryContacts_print(int Day,person* persons[],station* stations[],LL positive[],int positiveVal,int totalPeople,int X)
{
    vector *v;
    init_vector(v);
    for (int i = 0; i < positiveVal; i++)//this loop is for iterating through all the positive people
    {
        for (int j = 0, l = Day; j < X || l == 0; j++, l--)//this is for keeping a track of all the past 15 days
        {
            for (int k = 0; k < persons[positiveVal]->stations_visited[l%15].size; k++) //this gives the stations which the person visited
            {
                int stationNum = persons[positive[k]]->stations_visited[l%15].arr[k]; //this gives the station numbers( type int )
                v = getStationContacts_primary_print(stationNum, stations, Day, persons, totalPeople, positive[k],X);//the person surely visited that station

            }
        }
    }
    return *v;
}
//This is the same function as getPrimaryContacts but is needed for the printing purpose

vector getStationContacts_primary_print(int stationVal,station* stations[],int Day,person* persons[],int totalPeople,LL positivePerson)
{
    vector *v;
    init_vector(v);
    for (int i = Day, j = 0; j < X || i == 0; i--, j++) {
        int num=0;
        printf("Primary contacts on day: %d\n", i);
        for (int k = 0;<totalPeople;k++)
        {
            if (station[stationVal]->Arraytotal[k] == 1) {
                if (persons[k]->status != PRIMARY_CONTACT ||
                    persons[k]->status != POSITIVE ||
                    persons[k]->status != QUARANTINED) {
                    num++;
                }
            }
        }
        pushback(v, num);
    }
    return *v;
}
//This is same as the getStationContacts_primary but is needed for the printing purpose