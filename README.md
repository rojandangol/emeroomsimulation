Introduction

The Emergency Room Simulator aims to replicate the functioning of a hospital emergency room in the town of 273ville, with a population of 2000. The simulation will focus on patient triaging, treatment by doctors and nurses, record-keeping, and user interactions. The simulation will cover a week in the life of the emergency room, examining each minute to capture the dynamics of patient arrivals, triaging, treatment, and record-keeping. 

Users can input the average hourly patient arrival rate (patients/hour), Number of doctors in the emergency room, and Number of nurses in the emergency room. The simulation will run for at least 7 days and go on a minute-per-minute basis (7 x 24 x 60 minutes). Patients are assigned a priority number (1 to 20) based on the severity of their illness.
The probability distribution for priority:
70% for priority 1 to 10.
20% for priority 11 to 15.
10% for priority 16 to 20

Nurses can treat patients with priority 1 to 10. Doctors can treat patients with priority 1 to 20. Treatment time for Nurses: 1 to 10 minutes. Treatment time for Doctors: 1 to 20 minutes. We also display the Average visit time (arrival to discharge time) for emergency room patients. Display a menu at the end of the simulation with options to: List the names of all treated residents and Retrieve the record of a resident by name. The simulation also displays a menu for user interaction at the end of the simulation. The two options provided for the user include a full report of patients treated at the hospital and another option to search for a specific patient name  Both options will print out patient records

The Code:

We used both Inheritance and Polymorphism to tackle this simulation. To begin with, we have the main (parent)class, Names.h which includes the sub-classes Caregiver.h and Patient.h. Caregiver class contains polymorphic subclasses, Doctor.h and Patient.h. The patient class has the getters and setters for the patient. Doctors and Nurses are arguably the same class. The key difference is that Nurses cannot treat patients with a severity of more than 10. The Doctor and Nurse consist of getters and setters.
The names class is our main class and majority of the functions. The names class acts as a simulation containing the code functionality that addresses the simulation issues. The main functions are, `treatment()` and  `putinsecvector()`. The `putinsecvector()` goes through the vectors of doctors and nurses and assigns them with patients if they are available. Additionally,  sets in time (check in time stamp) and waiting time (total time spent waiting for treatment) for the patients. The `treatment()` function is where the treatment of the assigned patients takes place. If a patient has a severity level of 10, the severity decreases as every minute passes by. So in theory, it would take the caregiver 10 minutes to treat the patient. If the severity level is zero, we set the out time for the patient – the patient is allowed to check out. From there, the doctor points to a null and the status of the caregiver changes to not busy meaning they can treat another patient. This process will iterate through until the time runs out (simulation requirements states that it will go on for a week)

The Algorithm

Creates a new Patient by pulling name from the txt file and assigns ID, Severity Level…..
Copies it to another Vector called temp vector
User inserts a rate which can’t be more than 60/hour.
According to the rate, randomly selected Patient gets selected and pushed into a queue. Once in the queue, the patient is removed from the temp vector.
Then according to the Severity lvl a Doctor or Nurse is assigned to the patient and is pushed to another vector. 
And once they’re treated, the doctor or nurse will look for another patient to treat while other patients wait.
And the loop repeats until time runs out.

CSV File

When we run the code, press 3 on the menu, and end the terminal, the csv file gets updated. It holds the number of doctors, the number of nurses, the total number of caretakers, and the average treatment time. The third parameter exists to make it easier to graph. 

Graph using python

We used Python to simplify the graphing process. Previously, when the CSV file was made, we had to go into the csv file, open it with Excel, and input the graph but now, after the data is in the CSV file, we can just click the play button that shows up in the top right corner (if you have code runner installed), click it, then a graph automatically appears. The graph has Doctors and nurses on the x-axis, and average treatment time on the y-axis. A common trend that can be seen is that, when there are 2 doctors and 1 nurse, the treatment time is the lowest whereas having 1 doctor and 1 nurse as well as having 1 doctor and 2 nurses results in a similar average waiting time which is higher than when there were 2 doctors and 1 nurse. 

Unit Testing
 
unitTesting.cpp holds the unit tests that we wrote for the simulation to make sure that the functions are working correctly. We made two unit tests. One of them checks if the randi function that is used to return a number from 1-100 which helps us to determine the severity level of patients works or not. The other checks if one of the functions which allow us to set patients name works or not. Due to a lack of time, we were only able to write two unit tests, but in the future we will make sure to write multiple more. 

