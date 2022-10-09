#include <iostream>
#include "Board.hpp"
using namespace std;
int main()
{
    Board b(4, 16);
    b.initialize();
    b.startGame();
    return 0;
}
