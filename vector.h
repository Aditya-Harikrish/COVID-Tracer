/* HOW TO USE
METHOD 1 (recommended):
vector v;
init_vector(&v);
pushback(&v, int ele); // to push back ele into v
popback(v) // to pop back from v

v.size is the the number of elements currently is the vector
v.capacity is the capacity of the vector
DO NOT MODIFY v.size AND v.capacity UNLESS YOU KNOW WHAT YOU'RE DOING.
The functions mentioned above handle that. 

delete_vector(&v); // to clear the contents of the vector

METHOD 2:
vector *v = init_vector_ptr(); // initialise v, preferably at the time of delaration
pushback(v, int ele); // to push back ele into v
popback(v) // to pop back from v
delete_vector_ptr(&v) // to delete v
*/
#include "header.h"

#ifndef VECTOR_H
#define VECTOR_H

typedef struct vector vector;
struct vector {
    size_t size, capacity;
    int* arr;
};

void init_vector(vector* v);
vector* init_vector_ptr();
void pushback(vector* v, int ele);
void print_vector(vector* v);
void delete_vector(vector *v);
void delete_vector_ptr(vector** v);
void popback(vector* v);

#endif