#include <bits/stdc++.h>
#include "logger.hpp"
using namespace std;

int main()
{
    logger* logM = logger::getInstance();
    
    logM->debug("hello");
    return 0;
}