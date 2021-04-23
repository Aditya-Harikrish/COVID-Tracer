#include "Stations.h"
#include "Persons.h"


Station InitStationNode(int max_no_of_Persorns,int id)
{
    Station x;
    x.DangerValue=0;
    x.StationID=id;
    x.PersonArr=(persons*)malloc(sizeof(persons)*max_no_of_Persorns);
    for(int i=0;i<max_no_of_Persorns;i++)
    x.PersonArr[i]=InitPersonNode();
}

double** InitStation_Matrix(LL N)
{
    double** a = (double**)malloc(sizeof(double*) * N);
    if (a == NULL) {
        printf("Failed to allocate memory to a\n");
        assert(0);
    }
    for (LL i = 0; i < N; ++i) {
        a[i] = (double*)malloc(sizeof(double) * N);
        if (a[i] == NULL) {
            printf("Failed to allocate memort to a[%d]\n", i);
            assert(0);
        }
    }

    // a[i][j] = -1 iff i is not connected to j 
    // If i is connected to j, a[i][j] = length of edge from i to j
    /* Initialise all elements of a to -1 */
    for (LL i = 0; i < N; ++i) {
        for (LL j = 0; j < N; ++j) {
            if (i == j)
                a[i][j] = 0;
            else
                a[i][j] = -1;
        }
    }
    return a;
}

void UpdateStation_Matrix(double ** matrix,LL U,LL V,double W,LL N)
{
     if (U < 0 || U >= N) {
            printf("U is out of bounds\n");
            assert(0);
        }
        if (V < 0 || V >= N) {
            printf("V is out of bounds\n");
            assert(0);
        }
        if (W <= 0) {
            printf("W has to be positive");
            assert(0);
        }
        if (U == V && W != 0) {
            printf("Length from a station to itself should be 0\n");
            assert(0);
        }
        matrix[U][V] = W;
        matrix[V][U] = W;
}