#include "vector.h"
#include "person.h"
#include "header.h"
#include "station.h"



//In all give function 'char func' tells how the user wants to use the function 
//func=='P' then the function prints the list
//func=='R' returns the no. of person in that list.   



//Takes the person node and prints the status
void status(person p);
//O(1)

//Takes an array of all person and total number of person and print the list of all positive ones
int list_positive(person* p,int k, char func);//
//O(n)

//Takes an array of all person and total number of person and print the list of all primary contacts
int list_primary(person* p,int k,char func);
//O(n)

//Takes an array of all person and total number of person and print the list of all secondary contacts
int list_positive(person* p,int k,char func);
//O(n)

//Takes station node,array of all person node and total number of person  and print the list of all primary contacts at that station
int list_primary_at_s(station s,person* p,int n,char func); 
//O(n)

//Takes station node, array of all person node and total number of person and print the list of all secondary contacts at that station
int list_secondary_at_s(station s,person* p,int n,char func);
//O(n)

//Takes station node, array of all person node and total number of person and print the list of all positive at that station
int list_positive_at_s(station s,person* p,int n,char func);
//O(n) 

//takes in person node and current date and print its location
void location(person p,int curr_day);
//O(1)

// gives danger value of a station s and the array of person and the total numberr of person
double danger_value(station s,person* p,int n);
//O(n)
