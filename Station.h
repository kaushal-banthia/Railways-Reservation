#ifndef _STATION_H
#define _STATION_H

#include <iostream>
#include <string>
class Railways;

using namespace std;

class Station
{
    // Name of the Station
    const string name_;
    Station& operator=(const Station& s);

    public:
    // Constructor
    Station(const string name);

    // Copy Constructor
    Station(const Station& s);

    // Destructor
    ~Station();
    
    // Getter function for getting the Name of the Station
    inline string GetName() const
    {
        return name_;
    }

    // Function for finding out the distance between two Stations
    int GetDistance(const Station& s) const;

    // Output Streaming Operator
    friend ostream& operator<<(ostream &output, Station s);
};

#endif