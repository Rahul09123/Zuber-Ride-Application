#ifndef BOOK_RIDE_BY_VEHICLE_TYPE
#define BOOK_RIDE_BY_VEHICLE_TYPE
#include "./BookRideStrategy.h"
#include "../services/Notification.h"
#include "../factories/Ride.h"
#include "../models/Driver.h"
#include "../models/Rider.h"

class BookRideByVehicleStrategy : public BookRideStrategy{
public:
    
    BookRideByVehicleStrategy(){}
    void acceptRide(Rider* r ,Driver* d)override{
        string type = r->getType();
        RideFactory* myride = new RideFactory();
        Ride* ride = myride->createRide(type);
        ride->bookRide();
        //booking is successful so notifynig rider and driver
        notify(d,r);
        delete myride;
        delete ride;
    }
     void notify(Driver* d, Rider* r)override{
        NotificationService* notification =  new NotificationService();
        notification->notifyRider(d);
        notification->notifyDriver(r);
        delete notification;
    }
    ~BookRideByVehicleStrategy(){}
};
#endif