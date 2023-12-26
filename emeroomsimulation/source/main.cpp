#include <iostream>
#include "patient.h"
#include "names.h"
#include "doctor.h"
#include <vector>
#include <stdlib.h> /* srand, rand */
#include <time.h>
#include <ctime>

int main()
{
    srand(time(NULL));

    names n1;
    
    //create the user desired doctors and nurses and the hourly rate
    n1.makecaregivers();

    // Opens the file to get the naims
    n1.oopenfile();

    // n1.printall();

    // assigns the names into the queues
    n1.putinqueus();

    std::cout << std::endl;

    // runs the simulation
    n1.treatpatients();

    // Prints the menu
    n1.front();

    n1.reportFile("text.csv");

  

    return 0;
}