#include "BookingClasses.h"

// Constructor
BookingClasses::BookingClasses(string name, bool isAC, bool IsLuxury, float loadFactor):
    name_(name), isAC_(isAC), isLuxury_(IsLuxury), loadFactor_(loadFactor)
{}

// Copy Constructor
BookingClasses::BookingClasses(const BookingClasses &b):
    name_(b.name_), isAC_(b.isAC_), isLuxury_(b.isLuxury_), loadFactor_(b.loadFactor_)
{}

// Copy Assignment Operator
BookingClasses& BookingClasses::operator=(const BookingClasses &b)
{
    name_ = b.name_;
    isAC_ = b.isAC_;
    isLuxury_ = b.isLuxury_;
    loadFactor_ = b.loadFactor_;
    return *this;
}

// Destructor
BookingClasses::~BookingClasses()
{}

// Output Streaming Operator
ostream& operator<<(ostream &output, const BookingClasses &b)
{
    output<<b.name_<<endl;
    output<<"Fare Load Factor: "<<b.loadFactor_<<endl;
    output<<"Seat / Berth: "<<(b.IsSitting() ? "Seat" : "Berth")<<endl;
    output<<"AC: "<<(b.isAC_ ? "Yes" : "No")<<endl;
    output<<"# of Tiers: "<<b.GetNumberOfTiers()<<endl;
    output<<"Luxury / Ordinary: "<<(b.isLuxury_ ? "Luxury" : "Ordinary")<<endl;
    
    return output;
}

Seat::Seat(const string name, const bool isAC, const bool isLuxury, const float loadFactor):
    BookingClasses(name, isAC, isLuxury, loadFactor)
{
    isSitting_ = true;
    numTiers_ = 0;
}
Seat::~Seat(){}

Berth::Berth(const string name, const bool isAC, const bool isLuxury, const float loadFactor):
    BookingClasses(name, isAC, isLuxury, loadFactor)
{
    isSitting_ = false;
}
Berth::~Berth(){}

SecondTier::SecondTier(const string name, const bool isAC, const bool isLuxury, const float loadFactor):
    Berth(name, isAC, isLuxury, loadFactor)
{
    numTiers_ = 2;
}

SecondTier::~SecondTier(){}

ThirdTier::ThirdTier(const string name, const bool isAC, const bool isLuxury, const float loadFactor):
    Berth(name, isAC, isLuxury, loadFactor)
{
    numTiers_ = 3;
}

ThirdTier::~ThirdTier(){}

// Concrete Classes begin now

// AC Chair Car
const string ACChairCar::sName = "AC Chair Car";
const bool ACChairCar::sIsAC = true;
const bool ACChairCar::sIsLuxury = false;
const float ACChairCar::sLoadFactor = 1.25;
ACChairCar::ACChairCar(): Seat(sName, sIsAC, sIsLuxury, sLoadFactor){}
ACChairCar::~ACChairCar(){};
const ACChairCar &ACChairCar::Type() // Implementation for a singleton class
{
    static const ACChairCar sACChairCarObj;
    return sACChairCarObj;
}

// Second Sitting
const string SecondSitting::sName = "Second Sitting";
const bool SecondSitting::sIsAC = false;
const bool SecondSitting::sIsLuxury = false;
const float SecondSitting::sLoadFactor = 0.5;
SecondSitting::SecondSitting(): Seat(sName, sIsAC, sIsLuxury, sLoadFactor){}
SecondSitting::~SecondSitting(){};
const SecondSitting &SecondSitting::Type() // Implementation for a singleton class
{
    static const SecondSitting sSecondSittingObj;
    return sSecondSittingObj;
}

// AC First Class
const string ACFirstClass::sName = "AC First Class";
const bool ACFirstClass::sIsAC = true;
const bool ACFirstClass::sIsLuxury = true;
const float ACFirstClass::sLoadFactor = 3;
ACFirstClass::ACFirstClass(): SecondTier(sName, sIsAC, sIsLuxury, sLoadFactor){}
ACFirstClass::~ACFirstClass(){};
const ACFirstClass &ACFirstClass::Type() // Implementation for a singleton class
{
    static const ACFirstClass sACFirstClassObj;
    return sACFirstClassObj;
}

// AC 2 Tier
const string AC2Tier::sName = "AC 2 Tier";
const bool AC2Tier::sIsAC = true;
const bool AC2Tier::sIsLuxury = false;
const float AC2Tier::sLoadFactor = 2;
AC2Tier::AC2Tier(): SecondTier(sName, sIsAC, sIsLuxury, sLoadFactor){}
AC2Tier::~AC2Tier(){};
const AC2Tier &AC2Tier::Type() // Implementation for a singleton class
{
    static const AC2Tier sAC2TierObj;
    return sAC2TierObj;
}

// First Class
const string FirstClass::sName = "First Class";
const bool FirstClass::sIsAC = false;
const bool FirstClass::sIsLuxury = true;
const float FirstClass::sLoadFactor = 2;
FirstClass::FirstClass(): SecondTier(sName, sIsAC, sIsLuxury, sLoadFactor){}
FirstClass::~FirstClass(){};
const FirstClass &FirstClass::Type() // Implementation for a singleton class
{
    static const FirstClass sFirstClassObj;
    return sFirstClassObj;
}

// AC 3 Tier
const string AC3Tier::sName = "AC 3 Tier";
const bool AC3Tier::sIsAC = true;
const bool AC3Tier::sIsLuxury = false;
const float AC3Tier::sLoadFactor = 1.75;
AC3Tier::AC3Tier(): ThirdTier(sName, sIsAC, sIsLuxury, sLoadFactor){}
AC3Tier::~AC3Tier(){};
const AC3Tier &AC3Tier::Type() // Implementation for a singleton class
{
    static const AC3Tier sAC3TierObj;
    return sAC3TierObj;
}

// Sleeper
const string Sleeper::sName = "Sleeper";
const bool Sleeper::sIsAC = false;
const bool Sleeper::sIsLuxury = false;
const float Sleeper::sLoadFactor = 1;
Sleeper::Sleeper(): ThirdTier(sName, sIsAC, sIsLuxury, sLoadFactor){}
Sleeper::~Sleeper(){};
const Sleeper &Sleeper::Type() // Implementation for a singleton class
{
    static const Sleeper sSleeperObj;
    return sSleeperObj;
}