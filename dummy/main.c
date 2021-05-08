
#include "Persons.h"
#include "Stations.h"
typedef long long LL;
int main()
{
    /* INPUT */
    LL N, M, K;
    // Note: Person and Stations are indexed starting from 1
    scanf("%lld %lld %lld", &N, &M, &K);
    LL PersonCount[N+1];//No. of person in ith station.
    persons* PersonArr=(persons*)malloc(sizeof(persons)*(K+1));
    Station* StationArr=(Station*)malloc(sizeof(Station)*(N+1));
    for(LL i=1;i<N+1;i++)
    {
        StationArr[i]=InitStationNode(K,i);
    }

    double** StationMatrix=InitStation_Matrix(N);


    for (LL i = 0; i < M; ++i) {
        LL U, V; double W;
        scanf("%lld %lld %lld", &U, &V, &W);
        UpdateStation_Matrix(U,V,W,N);
    }


    for (LL i = 1; i < K+1; ++i) {
        LL StationNo;
        PersonArr[i]=InitPersonNode();
        scanf("%lld",&StationNo);
        PersonArr[i].CurrentStation=StationNo;
        StationArr[StationNo].PersonArr[PersonCount[StationNo]]=PersonArr[i];// maintaining person at jth station
        PersonCount[StationNo]++;        
    }
    printf("Enter the number of queries\n");
    int q;
    for(int i=0;i<q;i++)
    {
        //Part A
        LL l;
        printf("Enter the length of list\n");
        scanf("%lld",&l);
        LL list[l];
        for(int i=0;i<l;i++)
        scanf("%d",&list[i]);
        //Now use PersonArr[list[i]] to get access of the person
        //After getting the person use person.CurrentStation

        // ??After that no idea how to update the dates





        //Part B

        //Bellmond or djishtra on basis of length or danger value 
        printf("Enter the person who wants to move and path(1,2,3) he wisher\n");
        LL p;int path;
        scanf("%lld %d",&p,&path);
        //Use PersonArr[i] to access the person 
        
        //Now update that person Node(status) and the two station node





        //PartC
        
        /*In this part we use
        a)person.status to get the status
        b)person.currentStation to get the currrent location
        c.)Iterate through person arr to get total no. of covid +ve person,primary ,secondary
        d.) Use PersonCount to get the number of the person on a station
        */




    }
}
