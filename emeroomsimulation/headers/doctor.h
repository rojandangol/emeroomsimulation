#ifndef Doctor_H
#define Doctor_H

#include "patient.h"
#include "caregiver.h"
#include <string>

class Doctor : public Caregiver
{
private:
    // one method and one attribute unique to it
    /* data */
    std::string name;
    int num;
    bool isBusy;
    patient *person;

public:
    /// @brief The default constructor of the nurse
    Doctor() : name("Dr. Default"), isBusy(false), person(nullptr){};

    /// @brief The Doctor with an Id number
    /// @param id the id number of the nurse
    Doctor(int id) : num(id){};

    /// @brief The constructor for the Doctor when
    /// @param name the name of the Doctor (string)
    /// @param isBusy if the Doctor is busy or not (bool)
    Doctor(std::string n, bool iB) : name(n), isBusy(iB), person(nullptr){};

    // Returns the patient that the Doctor is working on
    std::string getPatientName();

    /// @brief check if the doctor is assigned a pointer patient
    /// @return true if assigned a pointer patient, false if assigned a null pointer
    bool check_IsBusy();

    /// @brief Assigns a patient pointer to the doctor object
    /// @param p the pointer to an assigned patient
    void assignPatient(patient *p);

    /// @brief Changes the name of the doctor
    /// @param newName the new name for the doctor
    void changeName(std::string newName);

    /// @brief to get the patient that
    /// @return the pointer to the patient that is assigned to the doctor
    patient *get_Patient();
};

#endif
