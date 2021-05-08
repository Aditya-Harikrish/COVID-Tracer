#ifndef DSA_MINI_PROJECT_LIST_H
#define DSA_MINI_PROJECT_LIST_H
#include "vector.h"
#include "person.h"
#include "station.h"

// Primary contacts can be found using 4 functions, UpdatePeople, getPrimaryContacts, updateStation, getStationContacts.
// Here updatePeople and updateStations are called everytime a person moves from one station to other on a given day ( day will be incremented using the main function where we keep a track of days and send it as a parameter )
// now the getPrimaryContacts function is called when we want a list of all the primary contacts if we give the input parameters as the array of positive people ( a loop in which when we enter
// each person and take a list of all the stations he visited i.e getStationContacts is called here which takes the input as the stations array and number of that station which that person arrived
// on that particular day and prints them if they are not same as the positive people.
// Requirements:: for keeping track of which person came first and who came later, we are using priorityVal which is incremented depending on the transactions of people in that particular station.
// but the problem is that where do we store the visit and left values in that station?? ---> It should have a station and in that station we need the info of the person in which order he came
// can it just be done by adding other field to stations struct??


void updatePeople(person* persons[],int day,LL station_Number,int personNumber);//whenever the person is moving from one station to other station, this is used to update the
                                                                                //array of people->vector persons[] is used to update the travelling status of the person on a specific day
                                                              //stationNumber takes the station number that is to be added to the person's vector array

vector getPrimaryContacts(int Day,person* persons[],station* stations[],LL positive[],int positiveVal,int totalPeople,int X);


void updateStations(int Day,station* stations[],int stationVisit,int stationLeft,int personNumber);


vector getStationContacts_primary(int stationVal,station* stations[],int Day,person* persons[],int totalPeople,LL positivePerson);


void getSecondaryContacts(int Day,person* persons[],station* stations[],LL positive[],LL primary[]);


void getStationContacts_secondary(int stationVal,station* stations[],int Day,person* persons[]);

#endif



