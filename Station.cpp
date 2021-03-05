# include "Station.h"
# include "Railways.h"

// Constructor
Station::Station(const string name): name_(name) {}

// Copy Constructor
Station::Station(const Station& s):name_(s.name_) {}

// Destructor
Station::~Station() {} 

// Copy Assignment Operator
Station& Station::operator=(const Station& s)
{
    return *this;
}

// Function for finding out the distance between two Stations
int Station::GetDistance(const Station& s) const
{
    Station other_ = s;
    const Railways& IndianRailways = Railways::Type();
    return IndianRailways.GetDistance(*this, other_); // Gets the distance from IndianRailways
}

// Output Streaming Operator
ostream& operator<<(ostream &output, Station s)
{
    output<<s.name_<<endl;
    return output;
}

