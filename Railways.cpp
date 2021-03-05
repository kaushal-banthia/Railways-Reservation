#include "Railways.h"
#include "Station.h"

vector<string> Railways::sStations = {"Mumbai", "Delhi", "Bangalore", "Kolkata", "Chennai"};
map<vector<string>, int> Railways::sDistStations = {{{"Delhi", "Mumbai"}, 1447},
{{"Bangalore", "Mumbai"}, 981},
{{"Kolkata", "Mumbai"}, 2014},
{{"Chennai", "Mumbai"}, 1338},
{{"Bangalore", "Delhi"}, 2150},
{{"Delhi", "Kolkata"}, 1472},
{{"Chennai", "Delhi"}, 2180},
{{"Bangalore", "Kolkata"}, 1871},
{{"Bangalore", "Chennai"}, 350},
{{"Chennai", "Kolkata"}, 1659}};

int Railways::GetDistance(Station& one, Station& two) const
{
    string firstStationName = one.GetName()<two.GetName() ? one.GetName() : two.GetName();
    string secondStationName = one.GetName()>two.GetName() ? one.GetName() : two.GetName();;

    return sDistStations[{firstStationName, secondStationName}];
}

const Railways& Railways::Type() // Implementation for a singleton class
{
    static const Railways sRailwaysObj;
    return sRailwaysObj;
}


ostream& operator<<(ostream &output, Railways r) // Output Streaming Operator
{
    output<<"List of Stations:"<<endl;
    for (auto i = r.sStations.begin(); i != r.sStations.end(); i++)
    {
        output<<*i<<endl;
    }
    output<<endl;
    
    output<<"Distance Between 2 Stations is listed below:"<<endl;
    for (auto i = r.sDistStations.begin(); i != r.sDistStations.end(); i++)
    {
        output<<i->first[0]<<", "<<i->first[1]<<": "<<i->second<<endl;
    }

    return output;
}