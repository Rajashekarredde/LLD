
#include <bits/stdc++.h>
#include "logger.hpp"

using namespace std;
void obj1()
{
    logger *log1 = logger::getInstance();
}

void obj2()
{
    logger *log12 = logger::getInstance();
}

int main()
{
    thread t1( obj1 );
    thread t2( obj2 );
    
    t1.join();
    t2.join();
    
    return 0;
}
