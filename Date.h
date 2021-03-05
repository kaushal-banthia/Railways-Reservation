#ifndef _DATE_H
#define _DATE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Date
{
    // Vector to store the month names
    static const vector<string> sMonthName;

    // Integers to store the day, month and year respectively
    const int d_, m_, y_;
    
    // Store the formatted date
    const string date_;

    // Copy Assignment Operator
    Date& operator=(const Date& d);

    public:
    // Constructor
    Date(const int d, const int m, const int y);

    // Copy Constructor
    Date(const Date& d);

    // Destructor
    ~Date();

    // Output Streaming Operator
    friend ostream& operator<<(ostream &output, Date d);
};

#endif