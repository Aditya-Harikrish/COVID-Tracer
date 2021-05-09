# DSA Mini Project - COVID Tracing

## Instructions to Compile
 1.  Command: `make init`    or   `make`  
         This command compiles all subfunctions and make their object file and  the final executable named CovidTracing
<!-- 2.  Command:    make common.o
         This command compiles common.c and builds its object file common.o
 3.  Command:    make dijkstra.o
         This command compiles dijkstra.c and builds its object file dijkstra.o
 4.  Command:    make list.o
         This command compiles list.c and builds its object file list.o
 5.  Command:    make list1.o
         This command compiles list1.c and builds its object file list1.o
 6.  Command:    make person_queries.o
         This command compiles person_queries.c and builds its object file person_queries.o
 7.  Command:    make person.o
         This command compiles person.c and builds its object file person.o
 8.  Command:    make station.o
         This command compiles station.c and builds its object file station.o
 9.  Command:    make vector.o
         This command compiles vector.c and builds its object file vector.o -->
 2. Command:    `make clean`  
         This command removes all the object files and the final executable file.

## Assumptions:

1. The time taken to travel from one station to another is 0s.

The following two assumptios were actually not taken initially but the complexity of the program for finding primary and secondary contacts was a lot as we need to take care of all the cases if the person remains in the station for the whole time, leaves for more number of times than he visits, visits for more number of times than he leaves and the same with the person we are comparing with and also we have to make sure when the positive person or primary person came and left and the presence of negative person when he was present. In total they were becoming  20+ cases which were difficult to handle. So given the difficulty of handling and time constraints the following assumptions were made.

2. The stations are sanitized at the start of the day and if a positive person enters that station, it is effected and all the people who come to the station for the rest of the day are considered primary contacts.
3. Similarly if a primary contact enters a station that staion is effected and any person who enters the station thereafter becomes a secondary contact.
4. If a person becomes a primary contact, he remains a primary contact for the rest of the time the code is running till he gets tested positive.
5. If a person becomes a secondary contact, he remains a secondary contact for the rest of the time until he becomes a primary contact or he gets tested positive.



## Instructions for input format:

1. The input for the code has 2 parts. Part-1 is the general user input that the user has to provide with for the structure of the stations, people their positions, and distance between the stations. Part-2 handles different queries of the people like if the user wants the list of primary and secondary contacts and the total no of primary contacts on that day (for graph purposes), if he wants to move a certain person from one station to other station, the route he wants to choose, the status of that person.
2. Input format 1:
    - In the first line you will be given three integers
    N, M, K, denoting number of stations, number of
    roads, number of people respectively.
    - Then M lines follow, the ith of them contains three
    integers U, V , W, meaning there is a bidirectional
    road between Uth station and Vth station of length W.
    - The next line contains K space separated integers where 
    ith integer represents the initial station number of the 
    ith person.
3. Input format 2:
    - In the first line you will be entering one of the 5 integers i.e.
    Enter 1 to enter a list of COVID positive people.
    Enter 2 to find the top 3 shortest and safest paths.
    Enter 3 to inquire about a person.
    Enter 4 to move forward by one day
    Enter 9 to quit.
    - If 1 is entered, then enter an integer H for the number of people tested positive on that day and the next H integers for the id of the person tested positive.The next line contains an integer X for the number primary and secondary contacts for the last X days. Next the input can be 1 or 0 whether the person wants a to take the output for plotting primary contacts to the graph or not respectively.Next the input can be 1 or 0 whether the person wants a to take the output for plotting secondary contacts to the graph or not respectively.
    - If 2 is entered first line contains an integer A which is the person number and the next line follows an integer B which is the destination station which the person is going to. Next press Y to move to destination and N else. If Y is entered, press 1/2/3 depending on the path to be chosen. 
    - If 3 is entered, enter the following for specific actions
        1. Enter 1 to access the status of a person.
        2. Enter 2 to access the location of a person.
        3. Enter 3 to access the list of COVID-positive people at a particular station.
        4. Enter 4 to access the list of primary contacts at a particular station.
        5. Enter 5 to access the list of secondary contacts at a particular station.
        6. Enter 6 to access the list of all COVID-positive people.
        7. Enter 7 to access the list of all primary contacts.
        8. Enter 8 to access the list of all secondary contacts.
        9. Enter 9 to access the danger value of a station.
   
        - If 1 or 2 is entered, in the next line the person ID is to be entered.
        - If 3, 4 or 5 is entered in the next line the station ID is to be entered.
        - if 9 is entered in the next line the station ID is to be entered.

## External Applications That Are To Be Installed

1. pip
2. numpy
3. matplotlib


<!--2. A person, if declared a primary contact, will maintain the said status for 15 days from the time of contact with >
