// Keep track of the currentDay here
#include "header.h"
#include "person.h"
#include "station.h"
#include "common.h"
#include "dijkstra.h"
#include "list.h"
#include "list1.h"
#include "person_queries.h"
#include "vector.h"

#define clearScreen printf("\e[1;1H\e[2J")

int main()
{
    /* INPUT */
    LL N, M, K;
    scanf("%lld %lld %lld", &N, &M, &K);
    int** a = (int**)malloc(sizeof(int*) * N);
    if (a == NULL) {
        printf("Failed to allocate memory to a\n");
        assert(0);
    }
    for (LL i = 0; i < N; ++i) {
        a[i] = (int*)malloc(sizeof(double) * N);
        if (a[i] == NULL) {
            printf("Failed to allocate memory to a[%lld]\n", i);
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


    for (int i = 0; i < M; ++i) {
        LL U, V;
        double W;
        scanf("%lld%lld%lf", &U, &V, &W);
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
    station* s = (station*)malloc(sizeof(station) * N);
    if (p == NULL || s == NULL) {
        printf("Failed to allocate memory!\n");
        assert(0);
    }
    for (int i = 0; i < K; ++i)
        init_person(&p[i]);

    for (int i = 0; i < N; ++i)
        init_station(&s[i], i, N);

    int day = 0;
    for (int i = 0; i < K; ++i) {
        init_person(&p[i]);
        int station_no;
        scanf("%d", &station_no);
        add_travel(&p[i], &s[i], day, station_no, i);
    }

    /* QUERIES */
    while (1) {
        int choice;
        printf("WELCOME!\n\n");
        printf("Enter 1 to enter a list of COVID positive people.\n");
        printf("Enter 2 to find the top 3 shortest and safest paths.\n");
        printf("Enter 3 to inquire about a person.\n");
        printf("Enter 4 to move forward by one day\n");
        printf("Enter 9 to quit.\n");
        printf("Your choice: ");
        scanf("%d", &choice);


        /* Here choice 1 is the function for getting primary and secondary contacts.
        For more info on how each of the function works:
        (a) go to list.h and list.c for primary contacts
        (b) visit list1.h and list1.c for info about secondary contacts. */
        if (choice == 1) {
            int positiveVal;
            vector primaryContacts_vector;
            init_vector(&primaryContacts_vector);
            vector primaryContacts_vector_print;
            init_vector(&primaryContacts_vector_print);

            vector secondaryContacts_vector_print;
            init_vector(&secondaryContacts_vector_print);

            scanf("%d", &positiveVal);

            LL A[positiveVal];
            for (int i = 0; i < positiveVal; i++) {
                scanf("%lld", &A[i]);
            }

            int X;
            scanf("%d", &X);

            primaryContacts_vector_print = getPrimaryContacts_print(day, &p, &s, A, positiveVal, K, X);
            secondaryContacts_vector_print = getSecondaryContacts_print(day, &p, &s, primaryContacts_vector, X, K);

            primaryContacts_vector = getPrimaryContacts(day, &p, &s, A, positiveVal, K, X);
            getSecondaryContacts(day, &p, &s, primaryContacts_vector, X, K);


            printf("Do you want to take the output into a file for plotting the number of primary contacts on each day (0/1)  ??\n");
            int val;
            scanf("%d", &val);
            if (val == 1) {
                for (int i = day, j = 0; j < X || i == 0; i--, j++) {
                    //printf("%d %d\n",day,primaryContacts_vector_print.arr[j]);
                    FILE* fptr;
                    fptr = fopen("primary_contacts.txt", "w");
                    fprintf(fptr, "%d %d\n", day, primaryContacts_vector_print.arr[j]);
                    fclose(fptr);
                }
            }

            printf("Do you want to take the output into a file for plotting the number of secondary contacts on each day (0/1)  ??\n");

            scanf("%d", &val);
            if (val == 1) {
                for (int i = day, j = 0; j < X || i == 0; i--, j++) {
                    FILE* fptr;
                    fptr = fopen("secondary_contacts.txt", "w");
                    fprintf(fptr, "%d %d\n", day, secondaryContacts_vector_print.arr[j]);
                    fclose(fptr);
                }
            }


            for (int i = 0;i < positiveVal;i++) {
                p[A[i]].status = QUARANTINED;
            }

        }
        else if (choice == 2) {
            printf("Enter person number: ");
            int id;
            scanf("%d", &id);
            if (id < 0 || id >= K) {
                printf("Person ID has be >= 0 and < K!");
                assert(0);
            }
            printf("Enter the destination: ");
            int dest;
            scanf("%d", &dest);
            if (dest < 0 || dest >= N) {
                printf("Station ID has be >= 0 and < K!");
                assert(0);
            }

            int currLocation = location(p[id], day, 'R');
            vector* path;
            path = get_safest_shortest(currLocation, dest, N, a, s);
            for (int i = 0; i < (path->size) - 1; i++) {
                updatePeople(&p, day, path->arr[i + 1], id);
                updateStations(day, &s, path->arr[i + 1], path->arr[i], id);
            }

            s[path->arr[0]].dangerValue= danger_value(s[path->arr[0]],p,K);
            s[path->arr[path->size]].dangerValue=danger_value(s[path->arr[path->size]],p,K);

        }
        else if (choice == 3) {
            printf("Enter 1 to access the status of a person.\n");
            printf("Enter 2 to access the location of a person.\n\n");

            printf("Enter 3 to access the list of COVID-positive people at a particular station.\n");
            printf("Enter 4 to access the list of primary contacts at a particular station.\n");
            printf("Enter 5 to access the list of secondary contacts at a particular station.\n\n");

            printf("Enter 6 to access the list of all COVID-positive people.\n");
            printf("Enter 7 to access the list of all primary contacts.\n");
            printf("Enter 8 to access the list of all secondary contacts.\n\n");

            printf("Enter 9 to access the danger value of a station.\n");

            int choice3;
            printf("\nEnter your choice: ");
            scanf("%d", &choice3);

            int id;
            switch (choice3) {
            case 1:
            case 2: // status and location respectively
                printf("Enter the ID of the person: ");

                scanf("%d", &id);
                if (id < 0 || id >= K) {
                    printf("Invalid ID");
                    continue;
                }
                if (choice3 == 1) status(p[id]);
                else location(p[id], day, 'P');

                break;

            case 3: // list of +ve people at a particular station
            case 4: // list of primary contacts at a particular station
            case 5: // list of secondary contacts at a particular station
                printf("Enter the station ID: ");
                scanf("%d", &id);
                if (id < 0 || id >= N) {
                    printf("Station ID out of bounds!\n");
                    continue;
                }

                if (choice3 == 3) list_positive_at_s(s[id], p, K, 'P');
                else if (choice3 == 4) list_primary_at_s(s[id], p, K, 'P');
                else list_secondary_at_s(s[id], p, K, 'P');

                break;

            case 6: // list of all +ve people
                list_positive(p, K, 'P');
                break;
            case 7: // list of all primary contacts
                list_primary(p, K, 'P');
                break;
            case 8: // list of all secondary contacts
                list_secondary(p, K, 'P');
                break;

            case 9:
                printf("Enter the station ID: ");
                scanf("%d", &id);
                if (id < 0 || id >= N) {
                    printf("Station ID out of bounds!\n");
                    continue;
                }

                // Use this if the dangerValue data member is being updated:
                printf("Danger value of station %d is %lf.\n", id, s[id].dangerValue);

                // Else use this:
                // printf("Danger value of station %d is %Lf.\n", id, danger_value(s[id], p, K));

            default:
                printf("Invalid choice!\n");
            }
        }
        else if (choice == 4) {
            move_forward_one_day(p, s, &day, K, N);//The function's purpose is to increase day by 1 and some other things that are needed for the program to work
                                                //Visit common.c for more info on the purpose of this function
        }
        else if (choice == 9) {
            printf("\nGoodbye!\n");
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
