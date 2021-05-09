

#ifndef DSA_MINI_PROJECT_LIST1_H
#define DSA_MINI_PROJECT_LIST1_H


#include "vector.h"
#include "person.h"
#include "station.h"


// The Secondary Contacts can be found by checking all the people who have visited a given station on a particular day when the Primary Contact has been present.
// We can compute the Secondary Contacts by 2 Functions getSecondaryContacts and getStationContacts_secondary.\
// The first function iterates over list of primary contacts and passes the station number that a primary contact has been to on a day.
// The second function iterates over the entire list of people and checks all the days from the day a person became a Primary Contact to the Present Day.
// If the person is not primary, secondary , quarantined , positive then he becomes a Secondary Contact.
// We check if a person is Secondary to remove duplicates.


void getSecondaryContacts(int Day,person* persons[],station* stations[],vector v,int X);


void getStationContacts_secondary(int stationVal,station* stations[],int Day, person* persons[], int totalPeople, int X);

#endif
