#ifndef FARE_CALCULATION_H
#define FARE_CALCULATION_H
#include<string>
#include<iostream>
using namespace std;

class FareCalculation{
private:
    int finalFare;
public:
    FareCalculation(){}
    int getTotalFare(char s , char f,string vehicleType){
        int fixcharge = 20;
        // only taking 26 locations as of now
        s = tolower(s);
        f = tolower(f);
        if(!(s>= 'a' && s<='z') && !(f>= 'a' && f<='z')) return 0;
        int distCharge = abs(f-s);
        if(vehicleType =="bike"){
            distCharge *= 8;
        }
        else if(vehicleType =="suv"){
            distCharge *= 25;
        }
        else if(vehicleType =="sedan"){
            distCharge *= 15;
        }
        else if(vehicleType =="carpool"){
            distCharge *= 12;
        }
        else{
            return 0;
        }
        this->finalFare = distCharge+fixcharge;
        return finalFare;
    }
};
#endif