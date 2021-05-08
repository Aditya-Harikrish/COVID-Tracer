#ifndef __SAFEST_PATH_H
#define __SAFEST_PATH_H
#include "station.h"

extern int num_stations;

// main function to call all the other functions
vector* get_safest_shortest(int s, int d, int num_st, int** adj_matrix, station arr[]);

// to compare two paths if they are identical
int comp(vector* P1, vector* P3);

// to get the path from a src to dest in a vector
void get_path(int parent[], vector* P, int tmp_src);

// to get the safest station not yet traversed
int safest_station(double danger_path[], bool traversed[]);

// decides which path is shortest if they have same danger value
int give_shortest_path(vector* S, vector* T, int matrix[][num_stations]);

// gives shortest path taking the danger val as the cost/weight
double dijkstra_safety(int graph[][num_stations], station arr[], vector* P);

// for the safest path with least danger value
double first_safest(int matrix[][num_stations], vector* P1, station arr[]);

// for the second safest path
double second_safest(int matrix[][num_stations], vector* P1, vector* P2, station arr[]);

// for the third safest path
double third_safest(int matrix[][num_stations], vector* P1, vector* P2, vector* P3, station arr[]);

#endif