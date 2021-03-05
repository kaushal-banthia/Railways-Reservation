#ifndef _BOOKINGCLASSES_H
#define _BOOKINGCLASSES_H

#include <iostream>
#include <string>

using namespace std;

// Abstract Base Class
class BookingClasses
{
    // Copy Assignment Operator
    BookingClasses &operator=(const BookingClasses &b);

    protected:
    // Fare Load Factor of the Booking Class
    const float loadFactor_;

    // Name of the Booking Class
    const string name_;

    // Booleans for keeping record if the Booking Class is AC or Non-AC and if it is Luxury or Ordinary
    const bool isAC_, isLuxury_;

    // Boolean for keeping record if the Booking Class is Sitting or Sleeping
    bool isSitting_;

    // Number of Tier in the Booking Class
    int numTiers_;

    // Constructor
    BookingClasses(const string name, const bool isAC, const bool isLuxury, const float loadFactor);
    
    // Copy Constructor
    BookingClasses(const BookingClasses& b);

    // Virtual Destructor for Polymorphism
    virtual ~BookingClasses();

    public:
    // Pure Virtual Function for determing if the Booking Class is sitting or sleeping
    virtual bool IsSitting() const = 0;

    // Pure Virtual Function for getting the number of tiers in the Booking Class
    virtual int GetNumberOfTiers() const = 0;

    // Getter Function for getting the Fare Load Factor of the Booking Class
    inline float GetLoadFactor() const
    {
        return loadFactor_;
    }

    // Getter Function for getting the Name of the Booking Class
    inline string GetName() const
    {
        return name_;
    }
    
    // Function that tells if the Booking Class is AC or Non-AC
    inline bool IsAC() const
    {
        return isAC_;
    }

    // Function that tells if the Booking Class is Luxury or Ordinary
    inline bool IsLuxury() const
    {
        return isLuxury_;
    }

    // Output Streaming Operator
    friend ostream& operator<<(ostream &output, const BookingClasses &b);
};

// Berth Class (Derived from BookingClasses)
class Berth: public BookingClasses
{
    protected:
    //Constructor
    Berth(const string name, const bool isAC, const bool isLuxury, const float loadFactor);
    
    // Destructor for Berth
    ~Berth();

    public:
    // Function that tells if the Booking Class is Sitting or Sleeping
    inline bool IsSitting() const
    {
        return isSitting_;
    }
};

// Seat Class (Derived from BookingClasses)
class Seat: public BookingClasses
{
    protected:
    //Constructor
    Seat(const string name, const bool isAC, const bool isLuxury, const float loadFactor);
    
    // Destructor for Seat
    ~Seat();

    public:
    // Function that tells if the Booking Class is Sitting or Sleeping
    inline bool IsSitting() const
    {
        return isSitting_;
    }

    // Function that returns the number of tiers in the Booking Class
    inline int GetNumberOfTiers() const
    {
        return numTiers_;
    }
};

// SecondTier Class (Derived from Berth (Derived from BookingClasses))
class SecondTier: public Berth
{
    protected:
    //Constructor
    SecondTier(const string name, const bool isAC, const bool isLuxury, const float loadFactor);
    
    // Destructor for SecondTier
    ~SecondTier();

    public:
    // Function that returns the number of tiers in the Booking Class
    inline int GetNumberOfTiers() const
    {
        return numTiers_;
    }
};

// ThirdTier Class (Derived from Berth (Derived from BookingClasses))
class ThirdTier: public Berth
{
    protected:
    //Constructor
    ThirdTier(const string name, const bool isAC, const bool isLuxury, const float loadFactor);
    
    // Destructor for ThirdTier
    ~ThirdTier();

    public:
    // Function that returns the number of tiers in the Booking Class
    inline int GetNumberOfTiers() const
    {
        return numTiers_;
    }
};

// Concrete Classes begin now

// ACChairCar Class (Derived from Seat (Derived from BookingClasses))
class ACChairCar: public Seat
{
    static const string sName;
    static const bool sIsAC, sIsLuxury;
    static const float sLoadFactor;
 
    // Constructor
    ACChairCar();

    // Destructor for ACChairCar
    ~ACChairCar();

    public:
    // Implementation for a singleton class
    static const ACChairCar &Type();
};

// SecondSitting Class (Derived from Seat (Derived from BookingClasses))
class SecondSitting: public Seat
{
    static const string sName;
    static const bool sIsAC, sIsLuxury;
    static const float sLoadFactor;

    // Constructor
    SecondSitting();

    // Destructor for SecondSitting
    ~SecondSitting();

    public:
    // Implementation for a singleton class
    static const SecondSitting &Type();
};

// ACFirstClass Class (Derived from SecondTier (Derived from Berth (Derived from BookingClasses)))
class ACFirstClass: public SecondTier
{
    static const string sName;
    static const bool sIsAC, sIsLuxury;
    static const float sLoadFactor;

    // Constructor
    ACFirstClass();

    // Destructor for ACFirstClass
    ~ACFirstClass();

    public:
    // Implementation for a singleton class
    static const ACFirstClass &Type();
};

// AC2Tier Class (Derived from SecondTier (Derived from Berth (Derived from BookingClasses)))
class AC2Tier: public SecondTier
{
    static const string sName;
    static const bool sIsAC, sIsLuxury;
    static const float sLoadFactor;

    // Constructor
    AC2Tier();

    // Destructor for AC2Tier
    ~AC2Tier();

    public:
    // Implementation for a singleton class
    static const AC2Tier &Type();
};

// FirstClass Class (Derived from SecondTier (Derived from Berth (Derived from BookingClasses)))
class FirstClass: public SecondTier
{
    static const string sName;
    static const bool sIsAC, sIsLuxury;
    static const float sLoadFactor;

    // Constructor
    FirstClass();

    // Destructor for FirstClass
    ~FirstClass();

    public:
    // Implementation for a singleton class
    static const FirstClass &Type();
};

// AC3Tier Class (Derived from ThirdTier (Derived from Berth (Derived from BookingClasses)))
class AC3Tier: public ThirdTier
{
    static const string sName;
    static const bool sIsAC, sIsLuxury;
    static const float sLoadFactor;

    // Constructor
    AC3Tier();

    // Destructor for AC3Tier
    ~AC3Tier();

    public:
    // Implementation for a singleton class
    static const AC3Tier &Type();
};

// Sleeper Class (Derived from ThirdTier (Derived from Berth (Derived from BookingClasses)))
class Sleeper: public ThirdTier
{
    static const string sName;
    static const bool sIsAC, sIsLuxury;
    static const float sLoadFactor;

    // Constructor
    Sleeper();

    // Destructor for Sleeper
    ~Sleeper();

    public:
    // Implementation for a singleton class
    static const Sleeper &Type(); 
};

#endif