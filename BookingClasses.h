#ifndef _BOOKINGCLASSES_H
#define _BOOKINGCLASSES_H

#include <iostream>
#include <string>

using namespace std;

class BookingClasses // Abstract Base Class
{
    protected:
    float loadFactor_;
    string name_;
    bool isAC_, isLuxury_, isSitting_;
    int numTiers_;
    BookingClasses(const string name, const bool isAC, const bool isLuxury, const float loadFactor); // Constructor
    BookingClasses(const BookingClasses& b); // Copy Constructor
    virtual ~BookingClasses(); // Destructor

    public:
    BookingClasses &operator=(const BookingClasses &b); // Copy Assignment Operator
    virtual bool IsSitting() const = 0;
    virtual int GetNumberOfTiers() const = 0;

    inline float GetLoadFactor() const
    {
        return loadFactor_;
    }

    inline string GetName() const
    {
        return name_;
    }
    
    inline bool IsAC() const
    {
        return isAC_;
    }

    inline bool IsLuxury() const
    {
        return isLuxury_;
    }

    friend ostream& operator<<(ostream &output, const BookingClasses &b); // Output Streaming Operator
};

class Berth: public BookingClasses
{
    protected:
    Berth(const string name, const bool isAC, const bool isLuxury, const float loadFactor); //Constructor
    ~Berth();

    public:
    inline bool IsSitting() const
    {
        return isSitting_;
    }
};

class Seat: public BookingClasses
{
    protected:
    Seat(const string name, const bool isAC, const bool isLuxury, const float loadFactor); //Constructor
    ~Seat();

    public:
    inline bool IsSitting() const
    {
        return isSitting_;
    }

    inline int GetNumberOfTiers() const
    {
        return numTiers_;
    }
};

class SecondTier: public Berth
{
    protected:
    SecondTier(const string name, const bool isAC, const bool isLuxury, const float loadFactor); //Constructor
    ~SecondTier();

    public:
    inline int GetNumberOfTiers() const
    {
        return numTiers_;
    }
};

class ThirdTier: public Berth
{
    protected:
    ThirdTier(const string name, const bool isAC, const bool isLuxury, const float loadFactor); //Constructor
    ~ThirdTier();

    public:
    inline int GetNumberOfTiers() const
    {
        return numTiers_;
    }
};

// Concrete Classes begin now
class ACChairCar: public Seat
{
    static const string sName;
    static const bool sIsAC, sIsLuxury;
    static const float sLoadFactor;
    ACChairCar();
    ~ACChairCar();

    public:
    static const ACChairCar &Type(); // Implementation for a singleton class
};

class SecondSitting: public Seat
{
    static const string sName;
    static const bool sIsAC, sIsLuxury;
    static const float sLoadFactor;
    SecondSitting();
    ~SecondSitting();

    public:
    static const SecondSitting &Type(); // Implementation for a singleton class
};

class ACFirstClass: public SecondTier
{
    static const string sName;
    static const bool sIsAC, sIsLuxury;
    static const float sLoadFactor;
    ACFirstClass();
    ~ACFirstClass();

    public:
    static const ACFirstClass &Type(); // Implementation for a singleton class
};

class AC2Tier: public SecondTier
{
    static const string sName;
    static const bool sIsAC, sIsLuxury;
    static const float sLoadFactor;
    AC2Tier();
    ~AC2Tier();

    public:
    static const AC2Tier &Type(); // Implementation for a singleton class
};

class FirstClass: public SecondTier
{
    static const string sName;
    static const bool sIsAC, sIsLuxury;
    static const float sLoadFactor;
    FirstClass();
    ~FirstClass();

    public:
    static const FirstClass &Type(); // Implementation for a singleton class
};

class AC3Tier: public ThirdTier
{
    static const string sName;
    static const bool sIsAC, sIsLuxury;
    static const float sLoadFactor;
    AC3Tier();
    ~AC3Tier();

    public:
    static const AC3Tier &Type(); // Implementation for a singleton class
};

class Sleeper: public ThirdTier
{
    static const string sName;
    static const bool sIsAC, sIsLuxury;
    static const float sLoadFactor;
    Sleeper();
    ~Sleeper();

    public:
    static const Sleeper &Type(); // Implementation for a singleton class
};

#endif