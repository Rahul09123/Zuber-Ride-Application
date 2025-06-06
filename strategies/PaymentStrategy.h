#ifndef PAYMENT_STRATEGY_H
#define PAYMENT_STRATEGY_H
#include "../decorators/FareDecorator.h"

class PaymentStrategy{
    
public:
    virtual void pay(double amount) = 0;
    virtual ~PaymentStrategy() {}
};



#endif