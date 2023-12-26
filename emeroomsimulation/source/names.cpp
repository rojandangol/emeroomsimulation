#include "names.h"
#include "patient.h"
#include <doctor.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <ctime>
#include "string"
#include "iterator"
#include <cstddef> // For nullptr, if not already included

// default
names::names()
{
    std::cout << "default" << std::endl;
    id_counter = 0;
}

void names::makecaregivers()
{

    int uPut;

    std::cout << "How Many doctors do you want? " << std::endl;
    std::cin >> uPut;

    createDoctors(uPut);

    std::cout << "How Many Nurse do you want? " << std::endl;
    std::cin >> uPut;
    createNurses(uPut);

    std::cout << "what rate do you want? (No more than 60)" << std::endl;

    std::cin >> uPut;
    rateybaby(uPut, 0);
}
int names::randi()
{

    int x = rand() % 99 + 1;

    // 70% of ppl have sickness 1-10
    if (x > 30)
    {
        int y = rand() % 9 + 1;

        return y;
    }
    // 20% of ppl have sickness 11-15

    if (x > 10 && x < 30)
    {
        int z = 11 + rand() % 4;
        return z;
    }
    // 10% of ppl have sickness 16-20
    if (x < 11)
    {
        int q = 16 + rand() % 4;
        return q;
    }
}

// sets id number for patients
int names::setnum()
{
    return id_counter++;
}

// opens the txt file and creates patients
void names::oopenfile()
{
    std::fstream file("names.txt", std::ios::in | std::ios::out | std::ios::binary);

    if (file.is_open())
    {
        // if the file is open correctly
        std::cout << "Opened correctly!!" << std::endl;

        std::string line;
        // pulls all the lines, one at a time
        while (getline(file, line))
        {

            pt.push_back((new patient(line, setnum(), randi(), 0, 0, 0, 0, 0)));
        }

        // close the file
        file.close();
    }
}

// for testing
// void names::printall()
// {

//     std::cout << "Printing" << std::endl;
//     std::cout << "size" << pt.size() << std::endl;
//     for (int i = 0; i < 10; i++)
//     {
//         // cout << i << "| " << pt.at(i) << endl;
//         std::cout << i << " " << pt[i]->getName() << "| ID: " << pt[i]->getIdNum() << "| Severity: " << pt[i]->getSeverity()
//                   << "|intime:  " << pt[i]->getintime() << " |outime: " << pt[i]->getoutime()
//                   << std::endl;
//     }
// }

void names::createDoctors(int num)
{
    // https://cplusplus.com/forum/beginner/6400/
    // Create pointer of doctors and push them to a vector

    for (int i = 0; i < num; i++)
    {
        dr.push_back(new Doctor(i));
    }
}

void names::createNurses(int num)
{
    // https://cplusplus.com/forum/beginner/6400/
    // Create pointer of nurses and push them to a vector

    for (int i = 0; i < num; i++)
    {
        nr.push_back(new Nurse(i));
    }
}

Doctor *names::returnDoctor(int num)
{
    return dr.at(num);
}

Nurse *names::returnNurse(int num)
{
    return nr.at(num);
}

void names::rateybaby(int nummy, int hour)
{
    // create a variable to hold a random number
    //  this variable will be used to know how many patients to
    //  push into the waiting room (pqueue)
    int num;

    totalArrivals += num;

    num = nummy / 60;

    // Push nummy amount of patients into pqueue
    for (int j = 0; j < num + 1; j++)
    {
        if (temp.size() > 0)
        {
            totalV++;
            int rundi = rand() % temp.size();
            pqueue.push(temp.at(rundi));
            temp.at(rundi)->setWaitingI(hour);
            temp.at(rundi)->addNumW();
            // temp.push_back(temp.at(rundi));
            temp.erase(temp.begin() + rundi);
        }
        else
        {
            return;
        }
    }
}

// copies content from pt vector to temp vector
void names ::putinqueus()
{
    for (int i = 0; i < pt.size(); i++)
    {

        temp.push_back(pt.at(i));
    }
}

patient *names::returnPatient(int num)
{
    return pt.at(num);
}

std::string names::returnPatientName()
{
    // if the queue is not empty
    if (!pqueue.empty())
    {
        return pqueue.top()->getName();
    }
    else
    {
        // Handle the case when the priority queue is empty
        return nullptr;
    }
}

// check how many doctors are available
int names::checkavailability()
{

    int counter = 0; // for doctor

    for (int i = 0; i < dr.size(); i++)
    {
        if (dr.at(i)->check_IsBusy() == false)
        {
            counter++;
        }
    }
    return counter;
}

// check how many nurses are available
int names::checkavailability_n()
{
    int counter2 = 0; // for nurses
    for (int i = 0; i < nr.size(); i++)
    {
        if (nr.at(i)->check_IsBusy() == false)
        {
            counter2++;
        }
    }
    return counter2;
}

void names::putinsecvector(int num, int num_n, int &hour)
{
    int prIterato = 0; // iterate through the nurse vector
    int drIterato = 0; // iterate through the doctor vector

    // if there are doctors available and the severity lvl of patients is greater than 10
    if (num > 0 && pqueue.top()->getoldseveritylvl() > 10)
    {
        for (int i = 0; i < dr.size(); i++)
        {
            // if the doctor is free. This also finds the doctor that is free and assigns a patient
            if (dr.at(drIterato)->check_IsBusy() == false)
            {
                // pushes the person on top of the queue to the vector that will hold all info about patients
                allPatients.push_back(pqueue.top());
                // assign patient to doctor
                dr.at(drIterato)->assignPatient(pqueue.top());
                // change status to busy
                dr.at(drIterato)->check_IsBusy();
                // sets intime
                dr.at(drIterato)->get_Patient()->setintime(hour);
                // sets waiting time
                dr.at(drIterato)->get_Patient()->setWaitingO(hour);
                // remove the person from the queue
                pqueue.pop();
                // increase the operator
                drIterato++;
            }
        }
    }
    // for nurses as nurses can only treat patients w severity lvl 1-10
    else if (num_n > 0 && pqueue.top()->getoldseveritylvl() < 11)
    {
        for (int i = 0; i < nr.size(); i++)
        {
            if (nr.at(drIterato)->check_IsBusy() == false)
            {
                if (pqueue.top()->getoldseveritylvl() < 11)
                {
                    // pushes the person on top of the queue to the vector that will hold all info about patients
                    allPatients.push_back(pqueue.top());
                    // assign patient to nurse
                    nr.at(prIterato)->assign_Patient(pqueue.top());
                    // change status to busy
                    nr.at(prIterato)->check_IsBusy();
                    // sets intime
                    nr.at(prIterato)->get_Patient()->setintime(hour);
                    // sets waiting time
                    nr.at(prIterato)->get_Patient()->setWaitingO(hour);
                    // remove the person from the queue

                    pqueue.pop();
                    // increase the operator

                    prIterato++;
                }
            }
        }
    }

    // if there is a patient w severity < 11 and no nurses are available but doctors are, the patients get assigned to the doctors
    else if (num > num_n && num_n == 0 && pqueue.top()->getoldseveritylvl() < 11)
    {
        for (int i = 0; i < dr.size(); i++)
        {
            allPatients.push_back(pqueue.top());
            dr.at(drIterato)->assignPatient(pqueue.top());
            dr.at(drIterato)->check_IsBusy();
            dr.at(drIterato)->get_Patient()->setintime(hour);
            pqueue.pop(); // this also works
            drIterato++;
        }
    }
    // if there are no doctor available
    else
    {
        return;
    }
}

void names::treatpatients()
{
    // Resetting the total visists
    totalV = 0;
    // making a simulation for an hour
    for (int i = 1; i < 7 * 24 * 60; i++)
    {
        rateybaby(1, i); // gets a rate at which the patients come in / minute

        putinsecvector(checkavailability(), checkavailability_n(), i); // checks the number of doctors and patients available and assign them a patient

        treatment(i); // treats patients
    }
}

void names::treatment(int hour)
{
    // for doctors
    // checks if doctor have a patient and if it does, treats them by decreasing the severity lvl
    for (int i = 0; i < dr.size(); i++)
    {
        if (dr.at(i)->check_IsBusy() == true)
        {
            dr.at(i)->get_Patient()->setSeverity(1);
            // if the patient is treated, sets out time and doctor points to null
            if (dr.at(i)->get_Patient()->getSeverity() == 0)
            {
                dr.at(i)->get_Patient()->setoutime(hour + 1);
                // temp.push_back(dr.at(i) ->get_Patient());
                dr.at(i)->assignPatient(nullptr);
            }
        }
    }
    // for nurses
    // checks if nurses have a patient and if it does, treats them by decreasing the severity lvl
    for (int i = 0; i < nr.size(); i++)
    {
        if (nr.at(i)->check_IsBusy() == true)
        {
            nr.at(i)->get_Patient()->setSeverity(1);

            // if the patient is treated, sets out time and doctor points to null
            if (nr.at(i)->get_Patient()->getSeverity() == 0)
            {
                nr.at(i)->get_Patient()->setoutime(hour + 1);
                // temp.push_back(nr.at(i) ->get_Patient());
                nr.at(i)->assign_Patient(nullptr);
            }
        }
    }
}

// for testing
void names::printPriorityQueue()
{

    // printing priority queue
    std::cout << "Priority Queue: ";
    while (!pqueue.empty())
    {
        std::cout << pqueue.top()->getName() << ' ';
        // pqueue.pop();
    }
}

// prints all the patients being treated
void names::printPatients()
{
    std::cout << "All p size: " << allPatients.size() << std::endl;
    for (int i = 0; i < allPatients.size(); i++)
    {
        std::cout << allPatients.at(i)->getName() << "| Severity Level: " << allPatients.at(i)->getoldseveritylvl() << " | Waiting Time: " << allPatients.at(i)->getWaitingI() << ":" << allPatients.at(i)->getWaitingO() << "| Treatment Time: " << allPatients.at(i)->getintime() << ":" << allPatients.at(i)->getoutime() << " | Total time: " << allPatients.at(i)->totalTime() << " | Number of times in the waiting room: " << allPatients.at(i)->getNumW() << std::endl;
        // cout << allPatients.at(i)->getName() << " Slvl: " << allPatients.at(i)->getoldseveritylvl() << " | Wait Time: " << allPatients.at(i)->getWaitingO() - allPatients.at(i)->getWaitingI() << "minutes | Treatment Time: " << allPatients.at(i)->getoutime() - allPatients.at(i)->getintime() << " | Number of times in the waiting room " << allPatients.at(i)->addNumW() << endl;
    }
    std::cout << "Total Visits to the Emergency room: " << totalV << std::endl;

    // reportFile("test");
}

// to open a csv file for a graph
bool names::reportFile(std::string file_name)
{
    std::ofstream file;
    file.open(file_name, std::ios_base::app);
    file << dr.size() << "," << nr.size() << "," << dr.size() + nr.size() << "," << getAvgTime() << std::endl; // prints out (Doctors, Nurses, Average Wait Time)
    file.close();

    return true;
}

// for the menu option in main.cpp
void names::searchPatient(std::string userInput)
{
    bool found = false;
    // std::cout << "\nSize: " << allPatients.size() << std::endl;

    // if(allPatients.find(userInput)) == true;

    // std::cout << userInput << std::endl;

    // check to see if there is a patient named present in the vector
    for (int i = 0; i < allPatients.size(); i++)
    {
        if (allPatients.at(i)->getName() == userInput)
        {
            found = true;
            std::cout << allPatients.at(i)->getName() << "| Severity Level: " << allPatients.at(i)->getoldseveritylvl() << " | Waiting Time: " << allPatients.at(i)->getWaitingI() << ":" << allPatients.at(i)->getWaitingO() << "| Treatment Time: " << allPatients.at(i)->getintime() << ":" << allPatients.at(i)->getoutime() << " | Total time: " << allPatients.at(i)->totalTime() << " | Number of times in the waiting room: " << allPatients.at(i)->getNumW() << std::endl;
        }
    }

    if (found == false)
    {
        std::cout << "Sorry, we could not find that patient" << std::endl;
    }
}

// for the menu aswell
void names::front()
{
    std::string userInput = "0";

    while (userInput != "3")
    {

        std::cout << " Please enter your request: " << std::endl;
        std::cout << "1 - Entire Record of All Patients " << std::endl;
        std::cout << "2 - Search for a specific patient's records " << std::endl;
        std::cout << "3 - exit the program" << std::endl;

        std::cin >> userInput;

        if (userInput == "1")
        {
            printPatients();
        }
        else if (userInput == "2")
        {
            std::string nameInput;
            std::cout << "Enter first name and last name" << std::endl;
            // std::getline(std::cin, nameInput);// testing but did not work
            std::cin >> nameInput;
            searchPatient(nameInput);
        }
        else if (userInput == "3")
        {
            return;
        }
        else
        {
            std::cout << "That is not one of the options. Please try again" << std::endl;
        }
        std::cout << std::endl;
    }
}
