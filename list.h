#ifndef DSA_MINI_PROJECT_LIST_H
#define DSA_MINI_PROJECT_LIST_H
#include "header.h"
#include "person.h"
#include "station.h"
#include "common.h"
#include "dijkstra.h"
#include "list1.h"
#include "person_queries.h"
#include "vector.h"


//The assumption taken here is that if a positive person enters the station in the any point of the day the station, the station is considered effected.

void updatePeople(person* persons[],int day,LL station_Number,int personNumber);//This has array of persons with each having vectors and has time complexity of O(1) if size<capacity else if is size = capacity then it is O(size)
//The purpose of updatePeople is that it updates the stations that person visited on that day.
//It pushes the station the person is going to visit into the vector

vector getPrimaryContacts(int Day,person* persons[],station* stations[],LL positive[],int positiveVal,int totalPeople,int X);//the time complexity is O(X*X*K*stationsVisited by the person)
//This takes the input from the user as and calls the function getStationContacts_primary
//The purpose of this function is that it takes a list of stations, people, positive people, present day and the days till the user want the primary contacts and the total number of primary contacts
//The function first iterates through all the positive people and for each positive person, it gives the stations visited.
//Now we use this station visited to call other function named getStationContacts_primary which returns the vector of all the primary contacts

vector getPrimaryContacts_print(int Day,person* persons[],station* stations[],LL positive[],int positiveVal,int totalPeople,int X);//the time complexity is O(X*X*K*stationsVisited by the person)
//This function getStationsContact_primary gives us the primary contacts.
//Since it is called for a station of a positive person, it checks for all the people present in that day on that station
//If that person is not primary or positive person or a quarantined person, he is considered a primary contact and his value is pushed into
// the vector of primary contacts

void updateStations(int Day,station* stations[],int stationVisit,int stationLeft,int personNumber);//time complexity of this is O(1)
//The purpose of UpdateStations is that it updates the stations array_people and Arraytotal
//array_people will tell the presence of the person in the visiting station and his absence in the left station
//Arraytotal will keep a check whether that person entered that station or not in that particular day

vector getStationContacts_primary(int stationVal, station *stations[], int Day, person *persons[], int totalPeople,LL positivePerson, int X);//the time complexity is O(X*X*K*stationsVisited by the person)
//This is the same function as getPrimaryContacts but is needed for the printing purpose

vector getStationContacts_primary_print(int stationVal,station* stations[],int Day,person* persons[],int totalPeople,LL positivePerson,int X);//the time complexity is O(X*X*K*stationsVisited by the person)
//This is same as the getStationContacts_primary but is needed for the printing purpose

#endif



