#include<bits/stdc++.h>
using namespace std;
class Player
{
    string name;
    int id;
    long long score;
    public:
        Player() {}
        Player( string _name, int _id )
        {
            this->name = _name;
            this->id = _id;
            this->score = 0;
        }
        
        string getPlayerName()
        {
            return this->name;
        }
        
        void addScore( int val )
        {
            score += val;
        }
        
        long long getScore()
        {
            return score;
        }
};
