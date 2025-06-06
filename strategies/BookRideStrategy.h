#ifndef BOOK_RIDE_STRATEGY_H
#define BOOK_RIDE_STRATEGY_H
#include<iostream>
#include "../models/Rider.h"
#include "../models/Driver.h"

using namespace std;
class BookRideStrategy{

public:
    BookRideStrategy(){}
    virtual void acceptRide(Rider* r,Driver* d)=0;
    virtual void notify(Driver* d, Rider* r)=0;

    ~BookRideStrategy(){}
};

#endif