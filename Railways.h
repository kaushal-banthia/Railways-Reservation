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
    static vector<string> sStations;
    static map<vector<string>, int> sDistStations;
    Railways(){}

    public:
    static const Railways& Type(); // Implementation for a singleton class

    int GetDistance(Station& one, Station& two) const; // Function to get distance between two cities
    
    friend ostream& operator<<(ostream &output, Railways r); // Output Streaming Operator
};

#endif