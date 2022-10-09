#include<bits/stdc++.h>
using namespace std;
class Player
{
    string name;
    int id;
    public:
        Player() {}
        Player( string _name, int _id )
        {
            this->name = _name;
            this->id = _id;
        }
        
        string getPlayeName()
        {
            return this->name;
        }
};
