#include "vector.h"
#include "person.h"
#include "header.h"
#include "station.h"

//Takes the person node and prints the status
void status(person p);
//O(1)

//Takes an array of all person and total number of person and print the list of all positive ones
void list_positive(person* p,int k);
//O(n)

//Takes an array of all person and total number of person and print the list of all primary contacts
void list_primary(person* p,int k);
//O(n)

//Takes an array of all person and total number of person and print the list of all secondary contacts
void list_positive(person* p,int k);
//O(n)

//Takes station node,array of all person node and total number of person  and print the list of all primary contacts at that station
void list_primary_at_s(station s,person* p,int n); 
//O(n)

//Takes station node, array of all person node and total number of person and print the list of all secondary contacts at that station
void list_secondary_at_s(station s,person* p,int n);
//O(n)

//Takes station node, array of all person node and total number of person and print the list of all positive at that station
void list_positive_at_s(station s,person* p,int n);
//O(n) 

//takes in person node and current date and print its location
void location(person p,int curr_day);
//O(1)

