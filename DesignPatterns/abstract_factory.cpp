#include<iostream>
using namespace std;

class carInterface
{
    public:
        virtual void showDescription() = 0;        
};

class hyundaiCar : public carInterface
{
    public :
        void showDescription() override
        {
            cout<<"hyundai car is getting created"<<endl;
        }
};

class toyotaCar : public carInterface
{
    public :
        void showDescription() override
        {
            cout<<"toyota car is getting created"<<endl;
        }
};

class bikeInterface
{
    public:
        virtual void showDescription() = 0;        
};

class hyundaiBike : public  bikeInterface
{
    public :
        void showDescription() override
        {
            cout<<"hyundai bike is getting created"<<endl;
        }
};

class toyotaBike : public  bikeInterface
{
    public :
        void showDescription() override
        {
            cout<<"toyota bike is getting created"<<endl;
        }
};

class vehicleFactory
{
    public :
        virtual carInterface* createCar() = 0;
        virtual bikeInterface *createBike() = 0;
};

class hyundaiFactory : public vehicleFactory
{
    public :
        carInterface *createCar()
        {
            return new hyundaiCar();
        }
        
        bikeInterface *createBike()
        {
            return new hyundaiBike();
        }
};

class toyotaFactory : public vehicleFactory
{
    public :
        carInterface *createCar()
        {
            return new toyotaCar();
        }
        
        bikeInterface *createBike()
        {
            return new toyotaBike();
        }
};

class factoryCreator
{
    public :
        static vehicleFactory* createFactory( string arg )
        {
             vehicleFactory *v;
            if( arg == "hyundai")
            {
                v = new hyundaiFactory();
            }
            else if( arg == "toyota" )
            {
                v = new toyotaFactory();
            }
            return v;
        };
};

int main()
{
    cout<<"Enter your factory type : ";
    string arg ;
    cin >> arg;
    vehicleFactory *v = factoryCreator::createFactory( arg );
    carInterface *c = v->createCar();
    bikeInterface *b = v->createBike();
    c->showDescription();
    b->showDescription();
}
