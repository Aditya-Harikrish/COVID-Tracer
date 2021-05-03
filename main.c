// Keep track of the currentDay here
#include "header.h"
#include "person.h"
int main()
{
    /* INPUT */
    LL N, M, K;
    scanf("%lld%lld%lld", &N, &M, &K);
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

    /* INITIALISE ALL ELEMENTS OF A TO -1 */
    for (LL i = 0; i < N; ++i) {
        for (LL j = 0; j < N; ++j) {
            if (i == j)
                a[i][j] = 0;
            else
                a[i][j] = -1;
        }
    }


    for (LL i = 0; i < M; ++i) {
        LL U, V; double W;
        scanf("%lld%lld%lld", &U, &V, &W);
        if (U < 0 || U >= N) {
            printf("U is out of bounds\n");
            printf("Assert failed for i = %d\n", i);
            assert(0);
        }
        if (V < 0 || V >= N) {
            printf("V is out of bounds\n");
            printf("Assert failed for i = %d\n", i);
            assert(0);
        }
        if (W <= 0) {
            printf("W has to be positive");
            printf("Assert failed for i = %d\n", i);
            assert(0);
        }
        if (U == V && W != 0) {
            printf("Length from a station to itself should be 0\n");
            printf("Assert failed for i = %d\n", i);
            assert(0);
        }
        a[U][V] = W;
        a[V][U] = W;
    }
    person* p = (person*)malloc(sizeof(person) * K);
    int day = 0;
    for (LL i = 0; i < K; ++i) {
        init_person(&p[i]);
        int station_no;
        scanf("%d", station_no);
        add_travel(&p[i], day, station_no);
    }





    /* DELELTE a */
    for (LL i = 0; i < M; ++i) {
        free(a[i]);
    }
    free(a);
    return 0;
}