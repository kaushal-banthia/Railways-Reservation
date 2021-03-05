#ifndef _PASSENGER_H
#define _PASSENGER_H

#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

class Passenger
{
    string name_;
    long aadharNumber_;
    Date dateOfBirth_;
    string gender_;
    long mobileNumber_;
    string category_;

    public:

    // Constructor
    Passenger(string name, long aadharNumber, Date dateOfBirth, string gender, long mobileNumber, string category);

    // Copy Constructor
    Passenger(const Passenger& p);

    // Copy Assignment Operator
    Passenger& operator=(const Passenger& p);

    // Destructor
    ~Passenger();
};

#endif