# DSA Mini Project - COVID Tracing

## Assumptions:

1. The time taken to travel from one station to another is 0s.
2. The following two assumptios were actually not taken initially but the complexity of the program for finding primary and secondary contacts was a lot as we need to take care of all the cases if the person remains in the station for the whole time, leaves for more number of times than he visits, visits for more number of times than he leaves and the same with the person we are comparing with and also we have to make sure when the positive person or primary person came and left and the presence of -ve person when he was present.In total they were becoming  20+ cases which were difficult to handle.So given the difficulty of handling and time constraints the following assumptions were made.
3. The stations are sanitized at the start of the day and if a positive person enters that station, it is effected and all the people who come to the station for the rest of the day are considered primary contacts.
4. Similarly if a primary contact enters a station that staion is effected and any person who enters the station thereafter becomes a secondary contact.
5. If a person becomes a primary contact, he remains a primary contact for the rest of the time the code is running till he gets tested positive.
6. If a person becomes a secondary contact, he remains a secondary contact for the rest of the time until he becomes a primary contact or he gets tested positive.



## Instructions for input format:

1. The input for the code has 2 parts. Part-1 is the general user input that the user has to provide with for the structure of the stations, people their positions, and distance between the stations. Part-2 handles different queries of the people like if the user wants the list of primary and secondary contacts and the total no of primary contacts on that day (for graph purposes), if he wants to move a certain person from one station to other station, the route he wants to choose, the status of that person.
2. Input format 1:
    1. In the first line you will be given three integers
    N, M, K, denoting number of stations, number of
    roads, number of people respectively.
    2. Then M lines follow, the ith of them contains three
    integers U, V , W, meaning there is a bidirectional
    road between Uth station and Vth station of length W.
    3. The next line contains K space separated integers where 
    ith integer represents the initial station number of the 
    ith person.
3. Input format 2:
    1. In the first line you will be entering one of the 5 integers i.e.
    Enter 1 to enter a list of COVID positive people.
    Enter 2 to find the top 3 shortest and safest paths.
    Enter 3 to inquire about a person.
    Enter 4 to move forward by one day
    Enter 9 to quit.
    2. If 1 is entered, then enter an integer H for the number of people tested positive on that day and the next H integers for the id of the person tested positive.The next line contains an integer X for the number primary and secondary contacts for the last X days.Next the input can be 1 or 0 whether the person wants a to take the output for plotting the graph or not respectively.
    3. If 2 is entered



[//]: <2. A person, if declared a primary contact, will maintain the said status for 15 days from the time of contact with >