#include <iostream>
#include "Board.hpp"
using namespace std;
int main()
{
    Player p("sunny", 1);
    Board b(4, 16, p);
    b.initialize();
    b.startGame();
    return 0;
}
