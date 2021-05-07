#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "vector.h"

//Check this out
// https://github.com/AnimeshSinha1309/algorithms-notebook/blob/master/others/berkeley.pdf


//TODO

/*
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
compare that any 2 shortest paths are not same
*/


typedef struct station st_info;

struct station
{
    int danger_val;
};

int num_stations;
int src;
int dest;

int danger_1;
int danger_2;
int danger_3;

int comp(vector* P1, vector* P3);
void get_path(int parent[], vector* P, int tmp_src);
int safest_station(int danger_path[], bool traversed[]);
int give_shortest_path(vector* S, vector* T, int matrix[][num_stations]);
int dijkstra_safety(int graph[num_stations][num_stations], st_info arr[], vector* P);
int first_safest(int matrix[][num_stations], vector* P1, st_info arr[]);
int second_safest(int matrix[][num_stations], vector* P1, vector* P2, st_info arr[]);
int third_safest(int matrix[][num_stations], vector* P1, vector* P2, vector* P3, st_info arr[]);

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

    // initialising the 3 paths as vectors
    vector* path_1 = init_vector();
    vector* path_2 = init_vector();
    vector* path_3 = init_vector();

    // finding the safest path
    int danger_1 = first_safest(adj_matrix, path_1, arr);
    print_vector(path_1);

    // finding the second safest path
    int danger_2 = second_safest(adj_matrix, path_1, path_2, arr);
    print_vector(path_2);

    // finding the thirs safest path
    int danger_3 = third_safest(adj_matrix, path_1, path_2, path_3, arr);
    print_vector(path_3);

    // getting the shortest paths if 2 paths have the same danger value
    if(danger_1 == danger_2)
    {
        if(give_shortest_path(path_1, path_2, adj_matrix) == 1)
        {
            int tmp = danger_1;
            danger_1 = danger_2;
            danger_2 = tmp;
        }
    }

    if(danger_2 == danger_3)
    {
        if(give_shortest_path(path_2, path_3, adj_matrix) == 1)
        {
            int tmp = danger_2;
            danger_2 = danger_3;
            danger_3 = tmp;
        }
    }

    // printing the paths along with the danger value
    printf("Path-1 with danger_val = %d is ", danger_1);
    print_vector(path_1);

    printf("Path-2 with danger_val = %d is ", danger_2);
    print_vector(path_2);

    printf("Path-3 with danger_val = %d is ", danger_3);
    print_vector(path_3);

    // freeing the malloc'ed memory
    delete_vector(&path_1);
    delete_vector(&path_2);
    delete_vector(&path_3);

    return 0;
}

// gives the shortest path according to the total distance
int give_shortest_path(vector* S, vector* T, int matrix[][num_stations])
{
    int total_dist_1 = 0;
    int total_dist_2 = 0;

    // 'r' acts as the source and 's' as the destination
    int r,s;

    for(int i = 0 ; i < S->size - 1; i++)
    {
        r = S->arr[i];
        s = S->arr[i+1];

        total_dist_1 += matrix[r][s];
    }

    for(int i = 0 ; i < T->size - 1; i++)
    {
        r = T->arr[i];
        s = T->arr[i+1];

        total_dist_2 += matrix[r][s];
    }

    if(total_dist_2 < total_dist_1)
    {
        // swapping the pointers to the paths if second path is shorter than the first
        vector* tmp = init_vector();
        *tmp = *S;
        *S = *T;
        *T = *tmp;

        delete_vector(&tmp);

        return 1;
    }

    return 0;
}

// getting the safest path among all
int first_safest(int matrix[][num_stations], vector* P1, st_info arr[])
{
    int danger_1 =  dijkstra_safety(matrix, arr, P1);
    printf("%d(danger_val) ", danger_1);
    return danger_1;
}

// picks out the safest station not yet traversed
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

// dijkstra implementation using the danger value as the cost
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

    // getting the path using the parent array
    get_path(parent, P, dest);

    return danger_val_path[dest];
}

// gets the path using parent array
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

// We use Yen's Algorithm to find the next shortest paths
int second_safest(int matrix[][num_stations], vector* P1, vector* P2, st_info arr[])
{
    // creating an array of vectors of size being the number of edges in P1
    vector* all_paths[P1->size - 1];

    // keeps track of the danger value of each path
    int total_danger_val[P1->size -1];

    for(int i = 0; i < P1->size - 1; i++)
    {
        int r = P1->arr[i];
        int s = P1->arr[i+1];

        all_paths[i] = init_vector();

        // removing the edge from the matrix
        int tmp = matrix[r][s];
        matrix[r][s] = 0;

        // finding the shortest path in this modified graph
        int danger_of_dest = dijkstra_safety(matrix, arr, all_paths[i]);

        matrix[r][s] = tmp;

        total_danger_val[i] = danger_of_dest; 
    }    

    int min = INT_MAX;
    int index = 0;

    // getting the path with the least danger value
    for(int i = 0; i < P1->size - 1; i++)
    {
        if(total_danger_val[i] < min)
        {
            index = i;
            min = total_danger_val[i];
        }
    }

    printf("%d(danger_val) ", min);

    // Putting the safest path achieved in P2
    for(int i = 0; i < all_paths[index]->size; i++)
    {
        pushback(P2, all_paths[index]->arr[i]);
    }

    // freeing the memory allocated for each path
    for(int i = 0; i < P1->size - 1; i++)
    {
        delete_vector(&all_paths[i]);
    }

    return min;
}

int third_safest(int matrix[][num_stations], vector* P1, vector* P2, vector* P3, st_info arr[])
{
    // creating an array of vectors of size being the number of edges in P2
    vector* all_paths[P2->size - 1];

    // keeps track of the danger value of each path
    int total_danger_val[P2->size -1];

    for(int i = 0; i < P2->size - 1; i++)
    {
        int r = P2->arr[i];
        int s = P2->arr[i+1];

        all_paths[i] = init_vector();

        // removing the edge from the matrix
        int tmp = matrix[r][s];
        matrix[r][s] = 0;

        // finding the shortest path in this modified graph
        int danger_of_dest = dijkstra_safety(matrix, arr, all_paths[i]);

        // to remove the cases in which the 1st and 3rd paths are identical
        if(comp(P1, all_paths[i]) == 1)
        {
            danger_of_dest = INT_MAX;
        }
        
        matrix[r][s] = tmp;

        total_danger_val[i] = danger_of_dest;
    }    

    int min = INT_MAX;
    int index = 0;

    // getting the path with the least danger value
    for(int i = 0; i < P2->size - 1; i++)
    {
        if(total_danger_val[i] < min)
        {
            index = i;
            min = total_danger_val[i];
        }
    }

    printf("%d(danger_val) ", min);

    // Putting the safest path achieved in P3
    for(int i = 0; i < all_paths[index]->size; i++)
    {
        pushback(P3, all_paths[index]->arr[i]);
    }

    // freeing the memory allocated for each path
    for(int i = 0; i < P2->size - 1; i++)
    {
        delete_vector(&all_paths[i]);
    }

    return min;
}

int comp(vector* P1, vector* P3)
{
    if(P1->size != P3->size)
    {
        return 0;
    }
    else
    {
        for(int i = 0; i < P1->size; i++)
        {
            if(P1->arr[i] != P3->arr[i])
            {
    // freeing the memory allocated for each path
                return 0;
            }
        }
    }
    return 1;
}
