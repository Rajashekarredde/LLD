#include<bits/stdc++.h>
#include "Gameboard.hpp"
using namespace std;
int main()
{
    Player p1("sunny", 1);
    Player p2("bunny", 2);
    
    queue<Player> allPlayers;
    allPlayers.push(p1);
    allPlayers.push(p2);
    
    int boardSize = 3;
    int totalCells = 3 * 3;
    
    Gameboard gb( allPlayers, boardSize, totalCells  );
    gb.initialize();
    gb.gameStart();
    
    return 0;
}
