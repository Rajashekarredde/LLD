#include<bits/stdc++.h>
#include "Player.hpp"
#include "Dice.hpp"
#include "Jumper.hpp"

class Gameboard
{
    private: 
        Dice dice;
        queue<Player> playerQ;
        unordered_map< string, int >playersCurrentPosition;
        vector<Jumper>snakes;
        vector<Jumper>ladders;
        int boardSize;
        bool isClimbed = false;

    public:
     Gameboard ( Dice dice, queue<Player> playerQ, vector<Jumper>snakes, vector<Jumper>ladders, 
                      unordered_map<string, int> playersCurrentPosition, int boardSize) 
    {
        this->dice = dice;
        this->playerQ = playerQ;
        this->snakes = snakes;
        this->ladders = ladders;
        this->playersCurrentPosition = playersCurrentPosition;
        this->boardSize = boardSize;
    }
    
    void startGame()
    {
        while( playerQ.size() > 1  )
        {
            Player p = playerQ.front();
            playerQ.pop();
            isClimbed = true;
            
            int currentPos = playersCurrentPosition[ p.getName() ];
            int dicedNum = dice.roll();
            
            if( dicedNum + currentPos > boardSize )
            {
                playerQ.push( p );
            }
            else if( dicedNum + currentPos == boardSize )
            {
                cout<<p.getName()<<" has won the game"<<endl;
            }
            else
            {
                int calPos = dicedNum + currentPos;
                for( auto it : snakes )
                {
                    if( it.startPoint == calPos )
                    {
                        calPos = it.endPoint;
                    }
                }
                
               if( calPos != (dicedNum+currentPos) )
                    cout<<p.getName()<<" has bitten by the snake & present at "<<calPos<<endl;

                for( auto it : ladders )
                {
                    if( it.startPoint == calPos )
                    {
                        calPos = it.endPoint;
                        isClimbed = true;
                    }
                }
                
                if( calPos != (dicedNum+currentPos) && isClimbed )
                    cout<<p.getName()<<" has climbed the ladder & present at "<<calPos<<endl;
                    
                if( calPos == boardSize )
                    cout<<p.getName()<<" has won the game"<<endl;
                else
                {
                    playersCurrentPosition[p.getName()] = calPos;
                    cout<<p.getName()<<" is at the currentPos "<<calPos<<endl;
                    playerQ.push(p);
                }
            }
        }
    }
};
