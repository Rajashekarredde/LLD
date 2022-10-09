#include <iostream>
using namespace std;
class Box
{
    int x;
    int y;
    int digit;
    public :
       Box() {}
       Box( int _x, int _y, int _num )
       {
           this->x = _x;
           this->y = _y;
           this->digit = _num;
       }
       
       int getX() 
       {
           return this->x;
       }
       
       int getY()
       {
           return this->y;
       }
       
       int currentDigit()
       {
           return this->digit;
       }
       
       void setDigit( int v )
       {
           this->digit = v;
       }
};
