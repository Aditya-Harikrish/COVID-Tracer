#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "vector.h"

//TODO

/*
compare that any 2 shortest paths are not same
if not same, compare danger values
if same danger value then compare using length of path
try to improve on time complexity
*/

//DONE

/*
implement basic Dijkstra
way to keep track of path
find algo for next shortest
manipulating the adj matrix according to our need
*/


typedef struct station st_info;

struct station
{
    int danger_val;
};

int num_stations;
int src;
int dest;
void get_path(int parent[], vector* P, int tmp_src);
int dijkstra_safety(int graph[num_stations][num_stations], st_info arr[], vector* P);
int safest_station(int danger_path[], bool traversed[]);
void second_shortest(int matrix[][num_stations], vector* P1, vector* P2, st_info arr[]);
void third_shortest(int matrix[][num_stations], vector* P1, vector* P2, st_info arr[]);

int main()
{
    scanf("%d", &num_stations);
    int adj_matrix[num_stations][num_stations];

    for(int i = 0; i < num_stations; i++)
    {
        for(int j = 0; j < num_stations; j++)
        {
            scanf("%d", &adj_matrix[i][j]);
        }
    }

    st_info arr[num_stations];

    for(int i = 0; i < num_stations; i++)
    {
        scanf("%d", &arr[i].danger_val);
    }

    scanf("%d %d", &src, &dest);

    vector* path_1 = init_vector();
    vector* path_2 = init_vector();
    vector* path_3 = init_vector();

    int danger_1 = dijkstra_safety(adj_matrix, arr, path_1);

    printf("%d(danger_val) ", danger_1);
    print_vector(path_1);

    //int danger_2 = second_shortest(adj_matrix, path_1, path_2, arr);
    //printf("%d(danger_val) ", danger_2);

    second_shortest(adj_matrix, path_1, path_2, arr);
    print_vector(path_2);

    //int danger_3 = third_shortest(adj_matrix, path_2, path_3, arr);
    //printf("%d(danger_val) ", danger_3);

    third_shortest(adj_matrix, path_2, path_3, arr);
    print_vector(path_3);

    return 0;
}

int safest_station(int danger_path[], bool traversed[])
{
    int min = INT_MAX;
    int station_with_min_danger;

    for(int i = 0; i < num_stations; i++)
    {
        if(traversed[i] == false && danger_path[i] <= min)
        {
            min = danger_path[i];
            station_with_min_danger = i;
        }
    }

    return station_with_min_danger;
}

int dijkstra_safety(int graph[num_stations][num_stations], st_info arr[], vector* P)
{
    int danger_val_path[num_stations];
    bool traversed[num_stations];
    int parent[num_stations];

    for(int i = 0; i < num_stations; i++)
    {
        danger_val_path[i] = INT_MAX;
        traversed[i] = false;
        parent[i] = -1;
    }

    danger_val_path[src] = 0;

    for(int i = 0; i < num_stations - 1; i++)
    {
        int u = safest_station(danger_val_path, traversed);
        traversed[u] = true;

        if(danger_val_path[u] != INT_MAX)
        {
            for(int j = 0; j < num_stations; j++)
            {
                if(traversed[j] == false && graph[u][j] > 0 && danger_val_path[u] + arr[j].danger_val < danger_val_path[j])
                {
                    parent[j] = u;
                    danger_val_path[j] = danger_val_path[u] + arr[j].danger_val;
                }
            }
        }
    }
    get_path(parent, P, dest);

    return danger_val_path[dest];
}

void get_path(int parent[], vector* P, int tmp_src)
{
    if(parent[tmp_src] == -1)
    {
        pushback(P, tmp_src);
        return;
    }
    get_path(parent, P, parent[tmp_src]);
    pushback(P, tmp_src);

}

void second_shortest(int matrix[][num_stations], vector* P1, vector* P2, st_info arr[])
{
    vector* all_paths[P1->size - 1];

    int total_danger_val[P1->size -1];

    for(int i = 0; i < P1->size - 1; i++)
    {
        int r = P1->arr[i];
        int s = P1->arr[i+1];

        all_paths[i] = init_vector();

        int tmp = matrix[r][s];
        matrix[r][s] = 0;

        int danger_of_dest = dijkstra_safety(matrix, arr, all_paths[i]);

        matrix[r][s] = tmp;

        total_danger_val[i] = danger_of_dest;

        //print_vector(all_paths[i]);
    }    

    int min = INT_MAX;
    int index = 0;

    for(int i = 0; i < P1->size - 1; i++)
    {
        if(total_danger_val[i] < min)
        {
            index = i;
            min = total_danger_val[i];
        }
    }

    printf("%d(danger_val) ", min);
    //print_vector(all_paths[index]);

    for(int i = 0; i < all_paths[index]->size; i++)
    {
        pushback(P2, all_paths[index]->arr[i]);
    }
}

void third_shortest(int matrix[][num_stations], vector* P1, vector* P2, st_info arr[])
{
    second_shortest(matrix, P1, P2, arr);
}

