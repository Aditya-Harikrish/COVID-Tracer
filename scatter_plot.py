import matplotlib.pyplot as plot
  
days = []
num_cases = []
f = open('output.txt', 'r')
for row in f:
    row = row.split(' ')
    days.append(row[0])
    num_cases.append(int(row[1]))
      
plot.title("Cases Vs Days")
plot.xlabel('Days')
plot.ylabel('Number of Cases')
plot.scatter(days, num_cases)
  
plot.show()