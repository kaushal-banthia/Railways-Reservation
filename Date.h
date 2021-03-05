#ifndef _DATE_H
#define _DATE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Date
{
    static const vector<string> sMonthName;
    int d_, m_, y_;
    string date_;

    public:
    Date(int d, int m, int y); // Constructor
    Date(const Date& d); // Copy Constructor
    Date& operator=(const Date& d); // Copy Assignment Operator

    friend ostream& operator<<(ostream &output, Date d); // Output Streaming Operator
};

#endif