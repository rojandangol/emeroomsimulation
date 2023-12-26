#ifndef PATIENT_H
#define PATIENT_H
#include <ostream>
#include <string>
#include <stdlib.h> /* srand, rand */
#include <time.h>


class patient
{
private:
    std::string name;         // the name of the patient
    int id_num;          // the identification number of the patient
    int old_severitylvl; // the begining severity level of the patient
    int severity_lvl;    // the severity level of the patient that the docter will be treating
    int intime;          // the time when the doctor is assigned to the patient
    int outime;          // the time when the patients severity level hits 0
    int wIn;             // the time when the patient is in the prioity queue (waiting room)
    int wOut;            // the time when the patient leaves the prioty queue and is assigend to a doctor
    //int totalTime; // The total amount of time the patient is in the emergency room outime - wIn
    int numW; // Number of times the patient is in the waiting room 

public:
    patient(std::string name) : name("Null"){};

    /// @brief
    /// @param n name
    /// @param i id number
    /// @param s severity number
    /// @param ol old severity number
    /// @param In intime
    /// @param o outtime
    /// @param wI waiting in time
    /// @param wO waiting out time
    patient(std::string n, int i, int s, int ol, int In, int o, int wI, int wO) : name(n), id_num(i), severity_lvl(s), old_severitylvl(s), intime(In), outime(o), wIn(wI), wOut(wO){};

    /// @brief getter method for the patients name
    /// @return name of the patient 
    std::string getName();

    /// @brief getter method for the id number of the patient 
    /// @return the id number
    int getIdNum();

    /// @brief getter metod for the changing severity number of the patient
    /// @brief decreases by 1 every tick 
    /// @return severity number of the patient 
    int getSeverity();

    /// @brief Gets the beginning severity number of the patient
    /// @return the severity level
    int getOldSeverity();

    /// @brief changes the severity level. Should decrease by 1
    /// @param a the amount the severity level decreases by
    void setSeverity(int a);

    /// @brief getter method for getting the in time of the patient during the treatment phase
    /// @return the intime of the patient
    int getintime();

    /// @brief getter method for getting the out time of the patient during the treatment phase
    /// @return the out time of the patient 
    int getoutime();

    /// @brief set's the in time of the patient during the treatment phase
    /// @param x the intime
    void setintime(int x);

    /// @brief set's the out time of the patient during the treatment phase
    /// @param y the out time
    void setoutime(int y);

    /// @brief sets the in time of the patient during the waiting phase
    /// @param x the in time of the patient during the waiting phase
    void setWaitingI(int x);

    /// @brief sets the out time of the patient during the waiting phase
    /// @param y the out time of the patient during the waiting phase
    void setWaitingO(int y);

    /// @brief getter method for getting the in time of the patient during the waiting room phase
    /// @return the in time for the waitroom phase
    int getWaitingI();

     /// @brief getter method for getting the out time of the patient during the waiting room phase
    /// @return the out time for the waitroom phase
    int getWaitingO();

    /// @brief getter method for getting the original severity level of the patient
    /// @return the original severity level of the patient 
    int getoldseveritylvl();

    //The operators are set so that the prioity queue works 

    bool operator<(const patient &other) 
    {
        return this->severity_lvl < other.severity_lvl;
    }
    bool operator=(const patient &other) 
    {
        return this->severity_lvl == other.severity_lvl;
    }
    bool operator>(const patient &other) 
    {
        return this->severity_lvl > other.severity_lvl;
    }

    /// @brief Gets the total time from when the patient enters the waiting room to when the patient exits the treatment
    /// @return outime - wIn
    int totalTime(){
        return (outime - wIn);
    }

    /// @brief gettter method for the times that the patient has entered the waiting room
    /// @return numW
    int getNumW() {
        return numW;
    }

    /// @brief Adds +1 to the amount of times this patient has entered the waiting room 
    void addNumW() {
        numW++;
    }
};
#endif
