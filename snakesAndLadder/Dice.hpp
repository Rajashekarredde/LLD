#include<bits/stdc++.h>
using namespace std;

class Dice
{
    private:
        int diceNumber;
    
    public:
        Dice() {}
        Dice(int no )
        {
            this->diceNumber = no;
        }
        
        int roll()
        {
            return rand() % ((6*diceNumber) - (1*diceNumber) + 1 ) + (1*diceNumber);
        }
};
