#ifndef FARE_DECORATOR_H
#define FARE_DECORATOR_H

#include <iostream>
#include "./FareCalculation.h"
using namespace std;

class FareCalculator{
public:
    int finalPrice;
    FareCalculator(){}
    void getTotal(char &s , char &f,string type){
        FareCalculation* fc = new FareCalculation();
        this->finalPrice = fc->getTotalFare(s,f,type);
        delete fc;
    }
    virtual int getFinalFare()=0;

};
class Fare : public FareCalculator {
public:
    int getFinalFare()  { 
            
            return finalPrice;
        
    }
};

class FareDecorator : public FareCalculator{
protected:
    FareCalculator *farecalculator;
public:
    FareDecorator(FareCalculator* f){
        this->farecalculator = f;
    }
};

class Discount : public FareDecorator{
public:
    Discount(FareCalculator* f):FareDecorator(f){}
    int getFinalFare() override{
        if(finalPrice>0){
            finalPrice = 0.95*finalPrice;
            return finalPrice;
        }
        else return 0;
    }
};

class SurplusCharge : public FareDecorator{
public:
    SurplusCharge(FareCalculator* f):FareDecorator(f){}
    int getFinalFare() override{
        if(finalPrice>0){
            finalPrice = 1.10*finalPrice;
            return finalPrice;
        }
        else return 0;
    }
};

#endif