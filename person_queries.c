#include "person_queries.h"
void status(person p)
{
    if (p.status == 0)
        printf("Negative\n");
    else if (p.status == 1)
        printf("Positive\n");
    else if (p.status == 2)
        printf("Primary Contact\n");
    else if (p.status == 3)
        printf("Secondary Contact\n");
}

int list_positive(person* p, int k, char func)
{
    vector v;
    init_vector(&v);
    int s = 0;

    for (int i = 0; i < k; k++) {
        if (p[i].status == 1) {
            pushback(&v, p[i].id);
            s++;
        }
    }
    if (func == 'P')
    {
        for (int i = 0; i < v.size; i++)
        {
            printf("%d", v.arr[i]);
        }
        printf("\n");
    }

    if (func == 'R')
        return s;
}

int list_primary(person* p, int k, char func)
{
    vector v;
    init_vector(&v);
    int s = 0;

    for (int i = 0; i < k; k++) {
        if (p[i].status == 2) {
            pushback(&v, p[i].id);
            s++;
        }
    }
    if (func == 'P')
    {
        for (int i = 0; i < v.size; i++)
        {
            printf("%d", v.arr[i]);
        }
        printf("\n");
    }

    if (func == 'R')
        return s;
}

int list_secondary(person* p, int k, char func)
{
    vector v;
    init_vector(&v);
    int s = 0;

    for (int i = 0; i < k; k++) {
        if (p[i].status == 3) {
            pushback(&v, p[i].id);
            s++;
        }
    }
    if (func == 'P')
    {
        for (int i = 0; i < v.size; i++)
        {
            printf("%d", v.arr[i]);
        }
        printf("\n");
    }

    if (func == 'R')
        return s;
}

int list_primary_at_s(station s, person* p, int k, char func)
{

    vector v;
    init_vector(&v);
    int sum = 0;

    for (int i = 0; i < k; k++) {
        if (s.array_people[i] == 1 && p[i].status == 2) {
            pushback(&v, p[i].id);
            sum++;
        }
    }
    if (func == 'P')
    {
        for (int i = 0; i < v.size; i++)
        {
            printf("%d", v.arr[i]);
        }
        printf("\n");
    }

    if (func == 'R')
        return sum;
}

int list_secondary_at_s(station s, person* p, int k, char func)
{

    vector v;
    init_vector(&v);
    int sum = 0;

    for (int i = 0; i < k; k++) {
        if (s.array_people[i] == 1 && p[i].status == 3) {
            pushback(&v, p[i].id);
            sum++;
        }
    }
    if (func == 'P')
    {
        for (int i = 0; i < v.size; i++)
        {
            printf("%d", v.arr[i]);
        }
        printf("\n");
    }

    if (func == 'R')
        return sum;
}

int list_postive_at_s(station s, person* p, int k, char func)
{
    vector v;
    init_vector(&v);
    int sum = 0;

    for (int i = 0; i < k; k++) {
        if (s.array_people[i] == 1 && p[i].status == 1) {
            pushback(&v, p[i].id);
            sum++;
        }
    }
    if (func == 'P')
    {
        for (int i = 0; i < v.size; i++)
        {
            printf("/%d", v.arr[i]);
        }
        printf("\n");
    }

    if (func == 'R')
        return sum;
}

int location(person p, int curr_day, char func)
{
    curr_day = curr_day % 15;
    vector v = p.stations_visited[curr_day];
    if (func == 'R')
        return v.arr[v.size - 1];
    if (func == 'P')
        printf("%d", v.arr[v.size - 1]);
}

double danger_value(station s, person* p, int K)
{
    int pos = list_positive_at_s(s, p, K, 'R');
    int prim = list_primary_at_s(s, p, K, 'R');
    int sec = list_secondary_at_s(s, p, K, 'R');
    double x = pos + prim / 5 + sec / 10;
    return x;
}