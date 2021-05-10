#ifndef __SAFEST_PATH_H
#define __SAFEST_PATH_H
#include "station.h"

extern int num_stations;

// main function to call all the other functions
// the whole function has wort time complexity of O(n^3)
vector* get_safest_shortest(int s, int d, int num_st, int** adj_matrix, station arr[]);

// to compare two paths if they are identical
// has a worst time complexity of O(n) as the max edge in a path can be n-1
int comp(vector* P1, vector* P3);

// to get the path from a src to dest in a vector
// has a worst time complexity of O(n) as the max edges in a path can be n-1
void get_path(int parent[], vector* P, int tmp_src);

// to get the safest station not yet traversed
// has time complexity of O(n)
int safest_station(double danger_path[], bool traversed[], int dist[]);

// decides which path is shortest if they have same danger value
// has worst time complexity of O(n) as the max edges in a path is n-1
int give_shortest_path(vector* S, vector* T, int** matrix);

// gives shortest path taking the danger val as the cost/weight
// time complexity O(n^2)
double dijkstra_safety(int** graph, station arr[], vector* P);

// for the safest path with least danger value
// runs dijkstra so has time complexity O(n^2)
double first_safest(int** matrix, vector* P1, station arr[]);

// for the second safest path
// has worst time complexity of O(n^3)
double second_safest(int** matrix, vector* P1, vector* P2, station arr[]);

// for the third safest path
// has worst time complexity of O(n^3)
double third_safest(int** matrix, vector* P1, vector* P2, vector* P3, station arr[]);

#endif
