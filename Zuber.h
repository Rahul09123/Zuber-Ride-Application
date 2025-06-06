#ifndef ZUBER_H
#define ZUBER_H

#include <iostream>
using namespace std;
#include "./services/Notification.h"
#include "./managers/driverManager.h"
#include "./models/Rider.h"
#include "./decorators/FareDecorator.h"
#include "./factories/Ride.h"
#include "./models/Driver.h"
#include "./strategies/BookRideStrategy.h"
#include "./strategies/BookRideByVehicleStrategy.h"
#include "./strategies/PaymentStrategy.h"

class Zuber
{
public:
   int totalFare;
   NotificationService *n;
   Zuber()
   {
      n = new NotificationService();
      initializeDrivers();
   }
   void initializeDrivers()
   {

      Driver *d1 = new Driver("Bhola", "91321465", "bike", "XYZ123");
      Driver *d2 = new Driver("Kalia", "789633452", "suv", "ABC456");
      Driver *d3 = new Driver("Raju", "963554271", "sedan", "PQR789");
      Driver *d4 = new Driver("Bablu", "7896636436", "carpool", "GHI896");
      DriverManager::getInstance()->addDriver(d1);
      DriverManager::getInstance()->addDriver(d2);
      DriverManager::getInstance()->addDriver(d3);
      DriverManager::getInstance()->addDriver(d4);
      DriverManager::getInstance()->listVehicles();
   }
   void FareCalculation(Rider *rider)
   {
      char startLoc = rider->getPickupLoc();
      char finalLoc = rider->getDropLoc();
      string rideType = rider->getType();
      FareCalculator *baseFare = new Fare();
      cout << "\n";
      baseFare->getTotal(startLoc, finalLoc, rideType);
      cout << "\n--- Calculating Fare for " << rideType << " from " << startLoc << " to " << finalLoc << " ---" << endl;
      cout << "Initial Base Fare: " << baseFare->getFinalFare() << endl;

      FareCalculator *discountedFare = new Discount(baseFare);
      discountedFare->getTotal(startLoc, finalLoc, rideType);
      if (discountedFare->getFinalFare() > 0)
         cout << "After Base Discount of 5% : " << discountedFare->getFinalFare() << endl;
      FareCalculator *surchargedFare = new SurplusCharge(discountedFare);
      surchargedFare->getTotal(startLoc, finalLoc, rideType);
      if (surchargedFare->getFinalFare() > 0)
      {
         cout << "After Surplus Charge of 10% : " << surchargedFare->getFinalFare() << endl;
         this->totalFare = surchargedFare->finalPrice;
      }
      delete baseFare;
      delete discountedFare;
      delete surchargedFare;
   }

   void bookRide(Rider *rider)
   {
      BookRideByVehicleStrategy *brs = new BookRideByVehicleStrategy();
      Driver *driverDetail = DriverManager::getInstance()->acceptRide(rider);
      brs->acceptRide(rider, driverDetail);
      delete brs;
   }
   void finishRide()
   {
      n->FinishRide();
   }

   void PayFare(PaymentStrategy *ps)
   {
      ps->pay(totalFare);
      n->notifySuccessfulPayment(totalFare);
   }

   // Deconstructor
   ~Zuber()
   {
      delete n;
   }
};

#endif