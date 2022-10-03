#include<bits/stdc++.h>
using namespace std;

class Player
{
    private :
    
        string playerName;
        int id;
    public:
       Player(){}
       
       Player( string _name, int _id )
       {
           this->playerName = _name;
           this->id = _id;
       }
       
       string getPlayerName( )
       {
           return playerName;
       }
       
       int getPlayerId()
       {
           return id;
       }
};
