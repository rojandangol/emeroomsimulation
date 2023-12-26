#ifndef NAMES_H
#define NAMES_H

#include "patient.h"
#include <nurse.h>
#include <doctor.h>
#include <ostream>
#include <iostream>
#include <string>
#include <stdlib.h> /* srand, rand */
#include <time.h>
#include <vector>
#include <queue>

// Creating the CSV File: Doctors, Nurses, Average wait time
#include <fstream>
#include <string>

class names
{
private:
    int totalArrivals;
    float avgArrivals;

protected:
    std::vector<patient *> pt;
    int id_counter;
    std::vector<Doctor *> dr;
    std::priority_queue<patient *> pqueue;
    std::vector<Nurse *> nr;
    std::vector<patient *> allPatients;
    std::vector<patient *> temp;
    int totalV; // The total amount of visits to the emergency room
    float avgTim;
    // int hour =0;

public:
    // Defalut constructor
    names();


    void makecaregivers();

    /// @brief Returns a random number for the severity level
    /// @return Returns a random number for the severity level
    int randi();

    /// @brief opens txt file with patients name
    void oopenfile();

    /// @brief prints name/ details of patients
    void printall();
    /// @brief setting id number for patients
    /// @return the id_counter++
    int setnum();

    /// @brief Will create the a certain number of Doctors based on the integer
    /// @brief the user inputs
    /// @param num the number of Doctors the user wants
    void createDoctors(int num);

    /// @brief Will create a certain number of nurses based on the integer the user inputs
    /// @param num the number of nurses the user wants
    void createNurses(int num); // 91-100

    /// @brief Will return the doctor at the location entered
    /// @param num The index of the array holding the doctor
    /// @return the object doctor
    Doctor *returnDoctor(int num);

    /// @brief Will return the nurse at the location entered
    /// @param num The index of the array holding the doctor
    /// @return the object nurse
    Nurse *returnNurse(int num); // 108-112

    /// @brief returns a patient at a given index
    /// @param num the index that you want to get the patient from
    /// @return the patient at the given index
    patient *returnPatient(int num);

    /// @brief returns patient's name from the queue
    /// @return the patients name :)
    std::string returnPatientName();

    /// @brief checks the availability of doctors
    /// @return the counter of how many doctors are busy
    int checkavailability();

    /// @brief Checks the availability of the nurses
    /// @return the counter of how many nurses are busy
    int checkavailability_n();

    /// @brief inserts patients in vector pt to a queue
    void putinqueus();

    /// @brief pulls patients from queues and put in a vector. Where no. of patients = no.of doctor available
    /// @param num the number of how many doctors are not busy
    /// @param num_n the number of how many nurses are not busy
    /// @param hour the time stamp
    void putinsecvector(int num, int num_n, int &hour);

    /// @brief The main simulation
    void treatpatients();

    /// @brief Function to check what is in the patient queues
    void printPatientVector();

    /// @brief Function to check what is in the priority queue
    void printPriorityQueue();

    // Testing removing patients
    void removePatients(int hour);

    /// @brief Prints all the patients and their severity levels
    void printPatients();

    /// @brief Will decrease the severity of all the patients that are currently assigned to doctors
    /// @brief if the patients severity reaches 0, then set the doctor's status to not busy and
    /// @brief the doctor's patient to a null pointer
    /// @param hour the time stamp
    void treatment(int hour);

    /// @brief Will create a random number of patients to be put into the priority queue
    void rateybaby(int nummy, int hour);

    /// @brief Calculates the average of how many arrivals there are in the waiting room per hour
    void averageArrivalRate();

    ///@brief gets the average time (from waiting room in time to treatment out time)
    ///@brief of every patient of the entire simulation
    float getAvgTime()
    {
        int totalTime = 0;

        for (int i = 0; i < allPatients.size(); i++)
        {
            totalTime += allPatients.at(i)->totalTime();
        }
        avgTim = totalTime / allPatients.size();
        return totalTime / allPatients.size();
    }

    /// @brief Will create a CSV file containing: Doctors, Nurses, and Average wait time for patient
    bool reportFile(std::string file_name);

    /// @brief search and print out a speicfic patient's records
    void searchPatient(std::string userInput);

    void front();


};

#endif
