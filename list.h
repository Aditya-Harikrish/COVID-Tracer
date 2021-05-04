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

void updatePeople(vector persons[],int day,LL station_Number);//whenever the person is moving from one station to other station, this is used to update the
                                                                                           //array of people->vector persons[] is used to update the travelling status of the person on a specefic day
                                                                                           //stationNumber takes the station number that is to be added to the person's vector array

void getPrimaryContacts(int Day,vector persons[],vector stations[],LL positive[]);


void updateStations(int Day,vector stations[],int priorityVal);


void getStationContacts(int stationVal,vector stations[],int Day,LL positive[]);


#endif
