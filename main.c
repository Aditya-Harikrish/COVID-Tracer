// Keep track of the currentDay here
#include "header.h"
#include "person.h"
#include "station.h"
#include "common.h"
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
            printf("Failed to allocate memory to a[%d]\n", i);
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

    /* QUERIES */
    while(1) {
        int choice;
        printf("WELCOME!\n\n");
        printf("Enter 1 to enter a list of COVID positive people.\n");
        printf("Enter 2 to find the top 3 shortest and safest paths.\n");
        printf("Enter 3 to inquire about a person.\n");
        printf("Enter 4 to move forward by one day\n");
        printf("Enter 9 to quit.\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {

        }
        else if(choice == 2) {

        }
        else if (choice == 3) {

        }
        else if(choice == 4) {
            // move_forward_one_day(p, )
        }
        else if(choice == 9) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid output. Please try again.");
        }
    }

    /* DELELTE a */
    for (LL i = 0; i < M; ++i) {
        free(a[i]);
    }
    free(a);
    return 0;
}