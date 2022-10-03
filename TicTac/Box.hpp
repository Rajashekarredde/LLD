#include<bits/stdc++.h>
using namespace std;

class Box
{
    private:
        int x;
        int y;
        char sign = ' ';
    
    public :
        Box( int _x, int _y, char ch )
        {
            x = _x;
            y = _y;
            sign = ch;
        }
        
        int getX() { return x; }
        int getY() { return y; }
        char getSign() { return sign; }
        void setSign( char ch)
        {
            this->sign = ch;
        }
};
