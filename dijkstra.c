#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "vector.h"
#include "dijkstra.h"

int num_stations;
int src;
int dest;

// keeps the src whose edge has to be removed for the third path
int edge_to_rem_in_third;

vector* get_safest_shortest(int s, int d, int num_st, int** adj_matrix, station arr[])
{
    num_stations = num_st;
    src = s;
    dest = d;

    // initialising the 3 paths as vectors
    vector* path_1 = init_vector_ptr();
    vector* path_2 = init_vector_ptr();
    vector* path_3 = init_vector_ptr();

    // finding the safest path
    double danger_1 = first_safest(adj_matrix, path_1, arr);

    // finding the second safest path
    double danger_2 = second_safest(adj_matrix, path_1, path_2, arr);

    // finding the third safest path
    double danger_3 = third_safest(adj_matrix, path_1, path_2, path_3, arr);

    // getting the shortest paths if 2 paths have the same danger value
    if(danger_2 == danger_3)
    {
        // returns 1 if the 2nd pointer corresponds to shorter path
        if(give_shortest_path(path_2, path_3, adj_matrix) == 1)
        {
            //swapping the pointers to the paths
            vector* tmp = path_2;
            path_2= path_3;
            path_3 = tmp;
        }
    }
    
    // getting the shortest paths if 2 paths have the same danger value
    if(danger_1 == danger_2)
    {
        // returns 1 if the 2nd pointer corresponds to shorter path
        if(give_shortest_path(path_1, path_2, adj_matrix) == 1)
        {
            //swapping the pointers to the paths
            vector* tmp = path_1;
            path_1= path_2;
            path_2 = tmp;
        }
    }

    // printing the paths along with the danger value
    printf("Path-1 with danger_val = %.2lf is ", danger_1);
    print_vector(path_1);

    printf("Path-2 with danger_val = %.2lf is ", danger_2);
    print_vector(path_2);

    printf("Path-3 with danger_val = %.2lf is ", danger_3);
    print_vector(path_3);

    char ch;
    int path_num;
<<<<<<< HEAD
=======

    // asking the user if they want to traverse the path
>>>>>>> cb1d3ad7a2b58d3055c530972ce9478af1d49fd5
    printf("Do you want to traverse? (y/n): ");
    scanf(" %c", &ch);

    // asking for path only if the user says Yes
    if(ch == 'Y' || ch == 'y')
    {
        printf("Which path do you want to go with (1/ 2/ 3): ");
        scanf(" %d", &path_num);

        if(path_num == 1)
        {
            //free the malloc'ed memory and return ptr to required path
            delete_vector_ptr(&path_2);
            delete_vector_ptr(&path_3);
            return path_1;
        }
        else if(path_num == 2)
        {
            //free the malloc'ed memory and return ptr to required path
            delete_vector_ptr(&path_1);
            delete_vector_ptr(&path_3);
            return path_2;
        }
        else
        {
            //free the malloc'ed memory and return ptr to required path
            delete_vector_ptr(&path_1);
            delete_vector_ptr(&path_2);
            return path_3;
        }
    }
    else
    {
        // freeing the malloc'ed memory
        delete_vector_ptr(&path_1);
        delete_vector_ptr(&path_2);
        delete_vector_ptr(&path_3);
        return NULL;
    }    

}

// gives the shortest path according to the total distance
int give_shortest_path(vector* S, vector* T, int** matrix)
{
    // total_distance for both parts
    int total_dist_1 = 0;
    int total_dist_2 = 0;

    // 'r' acts as the source and 's' as the destination
    int r,s;

    //calculating the path length of path S
    //the distance will be given from the graph
    for(int i = 0 ; i < S->size - 1; i++)
    {
        r = S->arr[i];
        s = S->arr[i+1];
        total_dist_1 += matrix[r][s];
    }

    // calculating the path length of T
    //the distance will be given from the graph
    for(int i = 0 ; i < T->size - 1; i++)
    {
        r = T->arr[i];
        s = T->arr[i+1];
        total_dist_2 += matrix[r][s];
    }

    // if path T turns out to be shorter, we return 1 to swap the paths
    if(total_dist_2 < total_dist_1)
    {
        return 1;
    }

    //else we return 0
    return 0;
}

// getting the safest path among all
double first_safest(int** matrix, vector* P1, station arr[])
{
    // for Yen's algorithm, the first path is given by simply dijkstra
    double danger_1 =  dijkstra_safety(matrix, arr, P1);
    return danger_1;
}

// picks out the safest station not yet traversed
int safest_station(double danger_path[], bool traversed[], int dist[])
{
    double min = INT_MAX;
    int station_with_min_danger;
    int min_dist = INT_MAX;

    // traversing over the all stations to check them
    for(int i = 0; i < num_stations; i++)
    {
        // we need the next safest station which is not traversed, has the least danger value and is the shortest
        if(traversed[i] == false && danger_path[i] <= min && dist[i] < min_dist)
        {
            min_dist = dist[i];
            min = danger_path[i];
            station_with_min_danger = i;
        }
    }

    //returns the index of station with minimum danger value
    return station_with_min_danger;
}

// dijkstra implementation using the danger value as the cost
double dijkstra_safety(int** graph, station arr[], vector* P)
{
    // to take account of the danger val of each station
    double danger_val_path[num_stations];

    // checks if a station has been included in the shortest tree, that is if it has been traversed or not
    bool traversed[num_stations];

    // keeps the parent of each station corresponding to its smallest path
    int parent[num_stations];

    // keeps the total distance to reach that station
    int dist[num_stations];

    // initially all stations have infinite distance and are not traversed
    for(int i = 0; i < num_stations; i++)
    {
        danger_val_path[i] = INT_MAX;
        traversed[i] = false;
        parent[i] = -1;
        dist[i] = INT_MAX;
    }

    // the src is given 0, to select it as the smallest during first iteration of safest station
    danger_val_path[src] = 0;
    dist[src] = 0;

    for(int i = 0; i < num_stations - 1; i++)
    {
        // gives the safest station which hasnt been traversed yet
        int u = safest_station(danger_val_path, traversed, dist);

        // the safest station is now included in the shortest path tree
        traversed[u] = true;

        if(danger_val_path[u] != INT_MAX)
        {
            // traversing all the vertices 'u' is connected to and updting the danger values and path distances
            for(int j = 0; j < num_stations; j++)
            {
                // the distance, danger_val, parent are updated only if the vertex is not yet traversed and has
                // danger value of new path less than its current danger value
                if(traversed[j] == false && graph[u][j] > 0 && danger_val_path[u] + arr[j].dangerValue < danger_val_path[j])
                {
                    parent[j] = u;
                    danger_val_path[j] = danger_val_path[u] + arr[j].dangerValue;
                    dist[j] = dist[u] + graph[u][j];
                }
            }
        }
    }

    // getting the path using the parent array
    get_path(parent, P, dest);

    // returning the danger value corresponding to the destination
    return danger_val_path[dest];
}

// recursive function which gets the path using parent array
void get_path(int parent[], vector* P, int tmp_src)
{
    // we have reached the src if its parent it -1
    if(parent[tmp_src] == -1)
    {
        pushback(P, tmp_src);
        return;
    }
    get_path(parent, P, parent[tmp_src]);
    pushback(P, tmp_src);
}

// We use Yen's Algorithm to find the next shortest paths
double second_safest(int** matrix, vector* P1, vector* P2, station arr[])
{
    // creating an array of vectors of size being the number of edges in P1
    vector* all_paths[P1->size - 1];

    // keeps track of the danger value of each path
    double total_danger_val[P1->size -1];

    // keeps distance of all paths
    int dist_all_paths[P1->size-1];

    // to iterate over all edges and removing them one by one
    for(int i = 0; i < P1->size - 1; i++)
    {
        // gives the start of edge
        int r = P1->arr[i];

        // gives the end of that edge
        int s = P1->arr[i+1];

        // initialising to 0, to remove any garbage value
        dist_all_paths[i] = 0;

        // initialising the vector which keeps this new path
        all_paths[i] = init_vector_ptr();

        // removing the edge from the matrix
        int tmp = matrix[r][s];
        matrix[r][s] = 0;

        // finding the shortest path in this modified graph
        double danger_of_dest = dijkstra_safety(matrix, arr, all_paths[i]);

        // restoring the value of the cost in that cell
        matrix[r][s] = tmp;

        // value updated in the array
        total_danger_val[i] = danger_of_dest; 

        //updating the total distance in the array
        for(int j = 0; j < all_paths[i]->size - 1; j++)
        {
            dist_all_paths[i] += matrix[all_paths[i]->arr[j]][all_paths[i]->arr[j+1]];
        }
    }    

    double min = INT_MAX;
    int index = 0;
    int min_dist = INT_MAX;

    // getting the path with the least danger value
    for(int i = 0; i < P1->size - 1; i++)
    {
        if(total_danger_val[i] <= min && min_dist > dist_all_paths[i])
        {
            index = i;
            min = total_danger_val[i];
            min_dist = dist_all_paths[i];
        }
    }

    // Putting the safest path achieved in P2
    for(int i = 0; i < all_paths[index]->size; i++)
    {
        pushback(P2, all_paths[index]->arr[i]);
    }

    // this takes account of the extra edge which will removed for third path
    // this extra edge is the one which gave the second path
    edge_to_rem_in_third = index;

    // freeing the memory allocated for each path
    for(int i = 0; i < P1->size - 1; i++)
    {
        delete_vector_ptr(&all_paths[i]);
    }

    //returning the minimum danger value
    return min;
}

double third_safest(int** matrix, vector* P1, vector* P2, vector* P3, station arr[])
{
    // creating an array of vectors of size being the number of edges in P2
    vector* all_paths[P2->size - 1];

    // keeps track of the danger value of each path
    double total_danger_val[P2->size -1];

    // keeps track of the distance for each node
    int dist_all_paths[P2->size-1];

    //removing that extra edge
    int t = matrix[P1->arr[edge_to_rem_in_third]][P1->arr[edge_to_rem_in_third+1]];
    matrix[P1->arr[edge_to_rem_in_third]][P1->arr[edge_to_rem_in_third+1]] = 0;

    // to iterate over all edges and removing them one by one
    for(int i = 0; i < P2->size - 1; i++)
    {
        // gives the start of edge
        int r = P2->arr[i];

        // gives the end of that edge
        int s = P2->arr[i+1];

        // initialising to 0, to remove any garbage value
        dist_all_paths[i] = 0;

        // initialising the vector which keeps this new path
        all_paths[i] = init_vector_ptr();

        // removing the edge from the matrix
        int tmp = matrix[r][s];
        matrix[r][s] = 0;

        // finding the shortest path in this modified graph
        double danger_of_dest = dijkstra_safety(matrix, arr, all_paths[i]);

        // to remove the cases in which the 1st and 3rd paths are identical
        if(comp(P1, all_paths[i]) == 1)
        {
            danger_of_dest = INT_MAX;
        }
        
        // restoring the value of deleted edge
        matrix[r][s] = tmp;

        // value updated in the array
        total_danger_val[i] = danger_of_dest;

        //updating the total distance in the array
        for(int j = 0; j < all_paths[i]->size - 1; j++)
        {
            dist_all_paths[i] += matrix[all_paths[i]->arr[j]][all_paths[i]->arr[j+1]];
        }
    }    

    double min = INT_MAX;
    int index = 0;
    int min_dist = INT_MAX;

    // getting the path with the least danger value
    for(int i = 0; i < P2->size - 1; i++)
    {   
        if(total_danger_val[i] <= min)
        {
            if(total_danger_val[i] == min && min_dist < dist_all_paths[i])
            {
                continue;
            }
            else
            {
                index = i;
                min = total_danger_val[i];
                min_dist = dist_all_paths[i];
            }
            
        }
    }

    //restoring that extra edge
    matrix[P1->arr[edge_to_rem_in_third]][P1->arr[edge_to_rem_in_third+1]] = t;

    // if the minimum path still has INT_MAX distance, we'll remove 2 vertices together and find the path
    if(min == INT_MAX )
    {
        int tmp_src_1 = P1->arr[P1->size - 2];
        int tmp_dist_1 = matrix[tmp_src_1][dest];
        matrix[tmp_src_1][dest] = 0;

        int tmp_src_2 = P2->arr[P2->size - 2];
        int tmp_dist_2 = matrix[tmp_src_2][dest];
        matrix[tmp_src_2][dest] = 0;  

        int new_danger_val = 0;  

        vector* tmp_path = init_vector_ptr();
        int tmp_danger = first_safest(matrix, tmp_path, arr);

        for(int i = 0; i < tmp_path->size; i++)
        {
            pushback(P3, tmp_path->arr[i]);
            min = tmp_danger;
        }

        //restoring the deleted value
        matrix[tmp_src_1][dest] = tmp_dist_1;
        matrix[tmp_src_2][dest] = tmp_dist_2; 

    }
    else
    {
        // Putting the safest path achieved in P3
        for(int i = 0; i < all_paths[index]->size; i++)
        {
            pushback(P3, all_paths[index]->arr[i]);
        }
    }

    // freeing the memory allocated for each path
    for(int i = 0; i < P2->size - 1; i++)
    {
        delete_vector_ptr(&all_paths[i]);
    }

    return min;
}

// comparing if two vectors are identical
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
            // we return 0 as the stations at this fail to be identical
            if(P1->arr[i] != P3->arr[i])
            {
                return 0;
            }
        }
    }
    return 1;
}
