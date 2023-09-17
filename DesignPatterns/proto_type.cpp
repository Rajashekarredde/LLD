#include<bits/stdc++.h>
using namespace std;

class car
{

public:
    car( int model, string color):
    nModel(model),
    nColor(color) {}
    
    virtual unique_ptr<car> clone() = 0;
    
    virtual void print() = 0;
    
    void setColor( string color )
    {
        nColor = color;
    }
    
    public :
 int nModel;
 string nColor;
};

class racecar : public car
{
public:
    racecar( int model, string color, int maxSpeed):
    car(model, color),
    nMaxSpeed(maxSpeed)
    {
      
    }
    
    void print()
    {
        std::cout<<nModel<<" "<<nColor<<" "<<nMaxSpeed<<std::endl;
    }
    
    virtual unique_ptr<car> clone() override
    {
        return make_unique<racecar>(*this);
    }
    
    private :
        int nMaxSpeed;
};


int main()
{
    auto ptr = make_unique<racecar>(2, "red", 200);
    
    auto clo = ptr->clone();
    clo->setColor("blue");
    clo->print();
}
