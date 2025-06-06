#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <iostream>
#include <string> 
#include "../models/Rider.h" 
#include "../models/Driver.h" 

using namespace std;

class NotificationService {
public:

    // Notifies the rider about their driver's status
     void notifyRider(Driver* driver) {
        if (driver == nullptr) {
            cerr << "Notification Error: Driver is null for rider notification." << endl;
            return;
        }
        cout << "\n-------Popup on Rider Screen--------" << endl;
        cout << "Your Ride is on the way!" << endl;
        cout << driver->getDriverName() << " is on the Way with Vehicle Type: "
        << driver->getVehicleType()<<" Vehicle no. "<<driver->getVehicleNo()<<endl;

    }

    // Notifies the driver about their pickup 
     void notifyDriver(Rider* rider) {
        if (rider == nullptr) {
            cerr << "Notification Error: Rider is null for driver notification." << endl;
            return;
        }
        cout << "\n-------Popup on Driver Screen--------" << endl;
        cout << "New Ride Request!" << endl;
        cout<<"Rider's Name: "<<rider->getName()<<endl;
        cout << "Pickup location: " << rider->getPickupLoc()<< endl;
        cout << "Drop-off location: " << rider->getDropLoc() << endl;
    }
    //Notify the rider that reached the destination
     void FinishRide(){
        cout << "\n-------Popup on Rider and Driver Screen--------" << endl;
         cout<<"You Succesfully arrived your destination\n";
    }
    //Notify the Driver after successfull payment
    void notifySuccessfulPayment(double amt){
        if(amt>0){
            cout << "\n-------Popup on Driver Screen--------" << endl;
            cout<<"Payment of ₹ "<<amt<<" recived Successfully!!"<<endl;
            
            cout << "\n-------Popup on Rider Screen--------" << endl;
            cout<<"Payment of ₹ "<<amt<<" Paid Successfully!!"<<endl;
        }
    } 
    ~NotificationService(){}
};

#endif 