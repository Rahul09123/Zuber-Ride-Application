#ifndef DRIVER_MANAGER_H
#define DRIVER_MANAGER_H

#include <vector>
#include <iostream>
#include <set>
#include "../models/Driver.h"
#include "../models/Rider.h"


using namespace std;

class DriverManager {
private:

    vector<Driver*>drivers;
    set<string>uniqueVehicles;
    static DriverManager* instance;


    DriverManager() {
        // Private Constructor
    }

public:
    static DriverManager* getInstance() {
        if (!instance) {
            instance = new DriverManager();
        }
        return instance;
    }

    void addDriver(Driver* driver) {
        drivers.push_back(driver);
        uniqueVehicles.insert(driver->getVehicleType());
    }
    void listVehicles(){
        cout<<"Available Vehicles\n";
        cout<<"----------------------\n";
        int i = 1;
        for(string x : uniqueVehicles){
            cout<<i<<". "<<x<<"\n";
            i++;
        }
        cout<<"----------------------\n";
    }
    Driver* acceptRide(Rider* r){
        for(Driver* d : drivers){
            if(d->getVehicleType()==r->type){
                cout<<"Your Booking is Confirmed\n"<<endl;
                return d;
            }
        }
        cout<<"No Driver Available at this moment\n";
        return nullptr;
    }
    ~DriverManager(){}
};

DriverManager* DriverManager::instance = nullptr;

#endif 