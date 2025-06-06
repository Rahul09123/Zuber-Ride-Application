#ifndef RIDER_H
#define RIDER_H

using namespace std;

class Rider{
private:
    string name;
    string phone;
    char pickup,drop;
public:
    string type;
 
    Rider(){}
    Rider(string name,string phone,char pickup,char drop,string type){
        this->name = name;
        this->phone = phone;
        this->pickup = pickup;
        this->drop = drop;
        this->type = type;

   
    }
    string getName(){
        return name;
    }
    string getType(){
        return type;
    }
    char getPickupLoc(){
        return pickup;
    }
    char getDropLoc(){
        return drop;
    }
    ~Rider(){}
    
};
#endif