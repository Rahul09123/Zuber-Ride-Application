#ifndef DRIVER_H
#define DRIVER_H

#include<iostream>
using namespace std;

class Driver{
private:
    string name;
    string phone;
    string vehicleNo;
    public:
    string vehicleType;
    int rating;

    Driver(string name,string phone,string vehicleType,string vehicleNo){
        this->name = name;
        this->phone = phone;
        this->vehicleType = vehicleType;
        this->vehicleNo = vehicleNo;
    }
    string getVehicleType(){
        return vehicleType;
    }
    string getDriverName(){
        return name;
    }
    string getVehicleNo(){
        return vehicleNo;
    }
    ~Driver(){}
};
#endif