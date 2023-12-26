#ifndef CAREGIVER_H
#define CAREGIVER_H
#include "patient.h"


class Caregiver
{
private:
    bool isBusy;     // checks if the caregiver is busy or not
    patient *person; // The patient the person is assigned to

public:

    /// @brief check if the caregiver is assigned a pointer patient 
    /// @return true if assigned a pointer patient, false if assigned a null pointer
    virtual bool check_IsBusy() = 0;

    /// @brief to get the patient that 
    /// @return the pointer to the patient that is assigned to the doctor
    virtual patient* get_Patient() = 0;

    
};

#endif