#ifndef _BOOKING_H
#define _BOOKING_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BookingClasses;
class Station;
class Date;
class Passenger;

class Booking
{
    static const float sBaseFarePerKM, sACSurcharge, sLuxuryTaxPercent;
    static int sBookingPNRSerial;
    vector<int> heelo;
    
    Station &fromStation_, &toStation_;
    Date &date_;
    BookingClasses &bookingClass_;
    Passenger *passenger_;
    float fare_;
    int PNR_;
    bool bookingStatus_ = true;
    string bookingMessage_ = "BOOKING SUCCEEDED";

    public:
    static vector<Booking*> sBookings;
    Booking(Station fromStation, Station toStation, Date date, const BookingClasses& bookingClass, Passenger* passenger = NULL); // Constructor
    Booking(const Booking& b); // Copy Constructor
    Booking& operator=(const Booking &b); //Copy Assignment Operator
    virtual int ComputeFare(); /*Should it be virtual?*/
    ~Booking(); // Destructor
    friend ostream& operator<<(ostream &output, const Booking &b); // Output Streaming Operator
};

#endif