#include "Date.h"

const vector<string> Date::sMonthName = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

Date::Date(int d, int m, int y): d_(d), m_(m), y_(y) // Constructor
{
    string month_ = sMonthName[m_-1];
    date_ = to_string(d_) + '/' + month_ + '/' + to_string(y_);
}

Date::Date(const Date& d): d_(d.d_), m_(d.m_), y_(d.y_), date_(d.date_) // Copy Constructor
{}

Date& Date::operator=(const Date& d) // Copy Assignment Operator
{
    d_ = d.d_;
    m_ = d.m_;
    y_ = d.y_;
    date_ = d.date_;
    return *this;
}

ostream& operator<<(ostream &output, Date d) // Output Streaming Operator
{
    output<<d.date_<<endl;
    return output;
}