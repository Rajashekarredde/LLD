#include<iostream>
using namespace std;

/*
The Factory Design Pattern is a creational design pattern that provides an interface 
for creating objects in a superclass, while allowing subclasses to alter the type of 
objects that will be created. This pattern promotes loose coupling between classes 
and allows for greater flexibility and easier maintenance.
*/

class vehicle
{
    public :
        virtual void status() = 0;
};


class car : public vehicle
{
    public :
         
        void status() override
        {
            cout<<"creating a car"<<endl;
        }
};

class bike : public vehicle
{
    public :
        void status() override
        {
            cout<<"creating a bike"<<endl;
        }
};


class vehicleType
{
    public:
        static vehicle* getVehicleType( string vehicleType )
        {
            vehicle *v;
            
            if( vehicleType == "car" )
            {
                v = new car();
            }
            else if( vehicleType == "bike" )
            {
                v = new bike();
            }
            return v;
        }
};

int main()
{
    
    vehicle *vt = vehicleType::getVehicleType("car");
    vt->status();
    
    vt = vehicleType::getVehicleType("bike");
    vt->status();
}
