#include<bits/stdc++.h>
using namespace std;

class Player
{
    private:
        string playerName;
        int playerId;
    
    public:
        Player( string _name, int _id )
        {
            this->playerName = _name;
            this->playerId = _id;
        }
        
        string getName()
        {
            return playerName;
        }
};
