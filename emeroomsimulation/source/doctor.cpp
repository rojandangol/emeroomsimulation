#include "doctor.h"
#include "patient.h"


#include <iostream>


std::string Doctor::getPatientName()
{
    return person->getName();
}

void Doctor::assignPatient(patient *p)
{
    person = p;
}

bool Doctor::check_IsBusy()
{
    if (this->person == nullptr)
    {

        // cout << "This doctor is not busy" << endl;
        isBusy = false;
        return false;
    }
    else
    {
        // cout << "This doctor is currently tending to: " << person->getName() << endl;
        isBusy = true;
        return true;
    }
}

patient *Doctor::get_Patient()
{
    if (person != nullptr)
    {
        return person;
    } 
}
