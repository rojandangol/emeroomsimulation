# help from: https://python.plainenglish.io/python-csv-module-how-to-read-and-write-csv-files-in-python-ca6e30c2da4f 
#and https://www.geeksforgeeks.org/working-csv-files-python/# 

import pandas as pd
import matplotlib.pyplot as plt
import csv

# Reads csv file, since we have 3 parameter/ values being, number of doctors, nurses and the average time
doctors = []
nurses = []
average_time = []
total =[]

#opens the csv file and reads it in the system
with open('text.csv', 'r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')

#goes to every row and assigns the value to doctors, then nurses and then the average time
    for row in plots:
        doctors.append(int(row[0]))
        nurses.append(int(row[1]))
        total.append(int(row[2]))
        average_time.append(int(row[3]))

# Plotting the graph
# # plt.scatter(nurses, label='Nurses', marker='o')    
#this will plot average time and the number of doctors + nurses
plt.scatter(total ,average_time, label='Average Time', color="green", marker='o')


# Add labels and title
plt.title('Graph from the csv file ')
plt.xlabel('Doctors and nurses')
plt.ylabel('Average treatement time')

# Adds a legend so, makes it easier to identify which line corresponds to which set of data
plt.legend()

# Add grid lines, makes it look nicer
plt.grid(True)

# Shows the plot
plt.show()
