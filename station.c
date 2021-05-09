#include "header.h"
#include "station.h"

void init_station(station *station_object, int id, int K) {
    (*station_object).id = id;
    (*station_object).dangerValue = 0;
    (*station_object).array_people = (int *) malloc(sizeof(int) * K);
    (*station_object).Arraytotal = (int *) malloc(sizeof(int) * K);
    (*station_object).array_time_personLeft = (vector **) malloc(sizeof(vector *) * 15);
    (*station_object).array_time_personVisit = (vector **) malloc(sizeof(vector *) * 15);


    if (((*station_object).array_people == NULL) ||
        ((*station_object).array_time_personLeft == NULL) ||
        ((*station_object).array_time_personVisit == NULL) ||
        ((*station_object).Arraytotal == NULL)) {
        printf("Failed to allocate memory\n");
        assert(0);
    }


    for (int i = 0; i < 15; ++i) {

        (*station_object).array_time_personLeft[i] = (vector *) malloc(sizeof(vector) * K);
        (*station_object).array_time_personVisit[i] = (vector *) malloc(sizeof(vector) * K);


        if ((*station_object).array_time_personLeft[i] == NULL ||
            (*station_object).array_time_personVisit[i] == NULL) {
            printf("Failed to allocate memory\n");
            assert(0);
        }

        for (int j = 0; j < K; j++) {

            station_object->array_people[i] = 0;
        }
    }
