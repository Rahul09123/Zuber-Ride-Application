#ifndef RIDE_H
#define RIDE_H

#include <iostream>

using namespace std;

class Ride
{
public:
    virtual void bookRide() = 0;
};
class BikeRide : public Ride
{
public:
    void bookRide() override
    {
        cout << "Bike Ride is on the way.." << endl;
    }
};
class CarPool : public Ride
{
public:
    void bookRide() override
    {
        cout << "Car pool Ride is on the way.." << endl;
    }
};
class SuvRide : public Ride
{
public:
    void bookRide() override
    {
        cout << "Suv Ride is on the way.." << endl;
    }
};
class SedanRide : public Ride
{
public:
    void bookRide() override
    {
        cout << "Sedan Ride is on the way.." << endl;
    }
};
class RideFactory
{
public:
    Ride* createRide(string type)
    {
        if (type == "bike")
        {
            return new BikeRide();
        }
        else if (type == "carpool")
        {
            return new CarPool();
        }
        else if (type == "suv")
        {
            return new SuvRide();
        }
        else if (type == "sedan")
        {
            return new SedanRide();
        }
        else
        {
            cout << "Invalid booking type! " << endl;
            return NULL;
        }
    }
};


#endif
