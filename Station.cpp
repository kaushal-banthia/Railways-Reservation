# include "Station.h"
# include "Railways.h"

Station::Station(string name): name_(name) {} // Constructor
Station::Station(const Station& s):name_(s.name_) {} // Copy Constructor
Station& Station::operator=(const Station& s) // Copy Assignment Operator
{
    name_ = s.name_;
    return *this;
}

int Station::GetDistance(const Station& s)
{
    Station other_ = s;
    const Railways& IndianRailways = Railways::Type();
    return IndianRailways.GetDistance(*this, other_);
}

ostream& operator<<(ostream &output, Station s) // Output Streaming Operator
{
    output<<s.name_<<endl;
    return output;
}

