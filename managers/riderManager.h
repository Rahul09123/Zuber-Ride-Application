#ifndef RIDER_MANAGER_H
#define RIDER_MANAGER_H

#include <vector>
#include <iostream>
#include "../models/Rider.h"
#include "../services/Notification.h"
using namespace std;

class RiderManager {
private:
    vector<Rider*>riders;
    static RiderManager* instance;
    NotificationService* n;

    RiderManager() {
        // Private Constructor
    }

public:
    static RiderManager* getInstance() {
        if (!instance) {
            instance = new RiderManager();
        }
        return instance;
    }

    void addRider(Rider* rider) {
        riders.push_back(rider);
    }
    void listRiders(){
        for(Rider* r : riders){
            cout<<r->getName()<<" "<<r->getType()<<endl;
        }
    }
    ~RiderManager(){}
};

RiderManager* RiderManager::instance = nullptr;

#endif 