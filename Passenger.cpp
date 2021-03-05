#include "Passenger.h"
#include "Date.h"

// Constructor
Passenger::Passenger(string name, long aadharNumber, Date dateOfBirth, string gender, long mobileNumber, string category):
    name_(name), aadharNumber_(aadharNumber), dateOfBirth_(dateOfBirth_), gender_(gender), mobileNumber_(mobileNumber), category_(category)
{}

// Copy Constructor
Passenger::Passenger(const Passenger& p): 
    name_(p.name_), aadharNumber_(p.aadharNumber_), dateOfBirth_(p.dateOfBirth_), gender_(p.gender_), mobileNumber_(p.mobileNumber_), category_(p.category_)
{}

// Copy Assignment Operator
Passenger& Passenger::operator=(const Passenger& p)
{
    name_ = p.name_;
    aadharNumber_ = p.aadharNumber_;
    dateOfBirth_ = p.dateOfBirth_;
    gender_ = p.gender_;
    mobileNumber_ = p.mobileNumber_;
    category_ = p.category_;

    return *this;
}

// Destructor
Passenger::~Passenger()
{}