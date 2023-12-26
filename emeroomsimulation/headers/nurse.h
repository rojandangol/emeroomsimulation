#ifndef Nurse_H
#define Nurse_H

#include "patient.h"
#include "caregiver.h"
#include <string>

class Nurse : public Caregiver
{
private:
    // one method and one attribute unique to it
    /* data */
    std::string name;
    int num;
    bool isBusy;
    patient* prosopon;

public:

    /// @brief The Nurse with an Id number
    /// @param id the id number of the nurse
    Nurse(int id) : num(id){};

    /// @brief The default constructor for Nurse
    Nurse() : name("Ms. Default"), isBusy(false), prosopon(nullptr){};

    /// @brief The constructor for the Doctor when
    /// @param name the name of the Doctor (string)
    /// @param isBusy if the Doctor is busy or not (bool)
    Nurse(std::string n, bool iB) : name(n), isBusy(iB), prosopon(nullptr){};

    ///@brief Returns the patient that the Doctor is working on
    ///@return the name of the patient 
    std::string get_PatientName();

    bool check_IsBusy();

    /// @brief Assignes a patient pointer to the doctor object
    /// @param p the pointer to an assigned patient
    void assign_Patient(patient* p);

    /// @brief Changes the name of the nurse
    /// @param newName the new name for the nurse
    void change_Name(std::string newName);

    /// @brief to get the patient that 
    /// @return the pointer to the patient that is assigned to the doctor
    patient* get_Patient();
};

#endif
