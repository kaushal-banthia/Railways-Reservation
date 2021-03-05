#ifndef _RAILWAYS_H
#define _RAILWAYS_H

#include <iostream>
#include <vector>
#include <map>
#include <string>

class Station;
using namespace std;

class Railways
{
    // Vector of all the Stations
    static const vector<string> sStations;

    // Map that stores the mutual distance between 2 stations
    static map<vector<string>, int> sDistStations;

    // Constructor
    Railways();

    public:
    // Implementation for a singleton class
    static const Railways& Type();

    // Function to get distance between two cities
    int GetDistance(const Station& one, const Station& two) const;
    
    // Output Streaming Operator
    friend ostream& operator<<(ostream &output, Railways r);
};

#endif