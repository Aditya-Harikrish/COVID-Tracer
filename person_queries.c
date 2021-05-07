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

void list_positive(person* p,int k)
{
    for(int i=0;i<k;k++)
    {
        if(p[i].status==1)
            printf("%d ",p[i].id);
    }
    printf("\n");
}

void list_primary(person* p,int k)
{
    for(int i=0;i<k;k++)
    {
        if(p[i].status==2)
            printf("%d ",p[i].id);
    }
    printf("\n");
}

void list_secondary(person* p,int k)
{
    for(int i=0;i<k;k++)
    {
        if(p[i].status==3)
            printf("%d ",p[i].id);
    }
    printf("\n");
}

void list_primary_at_s(station s,person* p,int n)
{
    
    for(int i=0;i<n;i++)
    {
        if(s.array_people[i]==1 && p[i].status==2)
        {
            printf("%d",p[i].id);        
        }
    }
    printf("\n");
}


void list_secondary_at_s(station s,person* p,int n)
{
    
    for(int i=0;i<n;i++)
    {
        if(s.array_people[i]==1 && p[i].status==3)
        {
            printf("%d",p[i].id);        
        }
    
    }
    printf("\n");
}

void list_postive_at_s(station s,person* p,int n)
{
    
    for(int i=0;i<n;i++)
    {
        if(s.array_people[i]==1 && p[i].status==1)
        {
            printf("%d",p[i].id);        
        }
    }
    printf("\n");
}

void location(person p,int curr_day)
{
    curr_day=curr_day%15;
    vector v=p.stations_visited[curr_day];
    printf("%d\n",v.arr[v.size]);
}