#ifndef _STATION_H
#define _STATION_H

#include <iostream>
#include <string>
class Railways;

using namespace std;

class Station
{
    string name_; // Name of the Station

    public:
    Station(string name); // Constructor
    Station(const Station& s); // Copy Constructor
    Station& operator=(const Station& s); // Copy Assignment Operator
    
    inline string GetName() const // Getter function for getting the Name of the Station
    {
        return name_;
    }

    int GetDistance(const Station& s);

    friend ostream& operator<<(ostream &output, Station s); // Output Streaming Operator
};

#endif