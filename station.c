#include "header.h"
#include "station.h"
void init_station(station* station_object, int id, int N)
{
    (*station_object).id = id;
    (*station_object).dangerValue = 0;
    (*station_object).array_people = (int*)malloc(sizeof(int) * N);
    (*station_object).array_time_personLeft = (vector*)malloc(sizeof(vector) * N);
    (*station_object).array_time_personVisit = (vector*)malloc(sizeof(vector) * N);

    if (station_object->array_people == NULL ||
        station_object->array_time_personLeft == NULL ||
        station_object->array_time_personVisit == NULL) {
        printf("Failed to allocate memory!\n");
        assert(0);
    }

    for (int i = 0; i < N; ++i) {
        init_vector(&(station_object->array_time_personLeft[i]));
        init_vector(&(station_object->array_time_personVisit[i]));
        station_object->array_people[i] = 0;
    }
}
