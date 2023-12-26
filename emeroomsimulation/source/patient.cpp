#include "patient.h"
#include <fstream>
#include <iostream>
#include "string"


std::string patient::getName()
{
    return name;
}

int patient::getIdNum()
{
    return id_num;
}

int patient::getSeverity()
{
    return severity_lvl;
}

int patient::getOldSeverity()
{
    return old_severitylvl;
}

void patient::setSeverity(int a)
{
    this->severity_lvl -= a;
}

int patient::getintime()
{
    return intime;
}

int patient::getoutime()
{
    return outime;
}

int patient::getoldseveritylvl()
{

    return old_severitylvl;
}

void patient::setintime(int x)
{
    this->intime = x;
}

void patient::setoutime(int y)
{
    this->outime = y;
}

void patient::setWaitingI(int x)
{
    this->wIn = x;
}

void patient::setWaitingO(int x)
{
    this->wOut = x;
}

int patient::getWaitingI()
{
    return wIn;
}

int patient::getWaitingO()
{
    return wOut;
}