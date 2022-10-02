#include<bits/stdc++.h>
#include "Gameboard.hpp"
using namespace std;

int main()
{
       Dice dice(1);
       
       Player p1("sunny",1);
       Player p2("bunny",2);
       
       queue<Player> allPlayers;
       allPlayers.push(p1);
       allPlayers.push(p2);
       
       Jumper snake1(10,2);
       Jumper snake2(99,12);
       vector<Jumper> snakes;
       snakes.push_back(snake1);
       snakes.push_back(snake2);
        
       Jumper ladder1(5,25);
       Jumper ladder2(40,89);
       vector<Jumper> ladders;
       ladders.push_back(ladder1);
       ladders.push_back(ladder2);
        
       unordered_map<string, int> playersCurrentPosition;
       playersCurrentPosition["sunny"] = 0;
       playersCurrentPosition["bunny"] = 0;
        
      Gameboard gb(dice,allPlayers,snakes,ladders,playersCurrentPosition,100);
      gb.startGame();
}
