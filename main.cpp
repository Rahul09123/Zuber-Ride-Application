#include<iostream>
using namespace std;
#include "./models/Rider.h"
#include "./Zuber.h"
#include "./strategies/PaymentStrategy.h"
#include "./strategies/upiPaymentStrategy.h"
#include "./strategies/creditCardPaymentStrategy.h"
#include "./strategies/BookRideStrategy.h"
#include "./strategies/BookRideByVehicleStrategy.h"

int main(){
    //Initialize the Drivers and our App Zuber
    Zuber* zuber = new Zuber();

    //Creating a Rider
    //Taken 'a' to 'z' as the locations for easy calculations
    //if change the sedan to bike other rider will be assigned
    Rider* rider1 = new Rider("Rahul","9538465132",'a','f',"sedan");

    //Rider books the Ride and Driver Accept it according to the VehicleType
    zuber->bookRide(rider1);

    zuber->finishRide();
    //Calculate the Fare for a Rider
    zuber->FareCalculation(rider1);
    
    //User Pays the money using Upi
    PaymentStrategy* ps = new UpiPaymentStrategy("9875632145");
    zuber->PayFare(ps);
    delete rider1;
    delete zuber;
    delete ps;
   return 0;
}