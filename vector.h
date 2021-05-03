/* HOW TO USE
METHOD 1 (recommneded):
vector v;
init_vector(&v);
pushback(v, int ele); // to push back ele into v
popback(v) // to pop back from v

METHOD 2:
vector *v = init_vector_ptr(); // initialise v, preferably at the time of delaration
pushback(v, int ele); // to push back ele into v
popback(v) // to pop back from v
delete_vector(&v) // to delete v
*/
#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct vector vector;
struct vector {
    size_t size, capacity;
    int* arr;
};

void init_vector(vector* v);
vector* init_vector_ptr();
void pushback(vector* v, int ele);
void print_vector(vector* v);
void delete_vector(vector** v);
void popback(vector* v);

#endif