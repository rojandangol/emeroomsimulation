#include "nurse.h"
#include "patient.h"
#include "caregiver.h"

#include <iostream>



std::string Nurse::get_PatientName()
{
    // return person->getName();
    return prosopon->getName();
}

void Nurse::assign_Patient(patient *p)
{
    prosopon = p;
}

bool Nurse::check_IsBusy()
{
    if (this->prosopon == nullptr)
    {
        
        // cout << "This Nurse is not busy" << endl;
        isBusy = false;
        return false;

    
    }
    else
    {
        // cout << "This Nurse is currently tending to: " << person->getName() << endl;
        isBusy = true;
        return true;
    }
}

patient* Nurse::get_Patient(){
    return prosopon;
}

// void Nurse::treatPatients()
// {

//     cout<< "lol"<< endl;
// }
