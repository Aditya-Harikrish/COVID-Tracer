import matplotlib.pyplot as plot

days = []
num_cases = []

f = open('output.txt', 'r')
for row in f:
    row = row.split(' ')
    days.append(row[0])
    num_cases.append(int(row[1]))

plot.bar(days, num_cases, color = 'g', label = 'File Data')

plot.xlabel('Days', fontsize = 12)
plot.ylabel('Number of Covid Cases', fontsize = 12)

plot.title('Cases vs Days', fontsize =  20)
plot.legend()
plot.show()