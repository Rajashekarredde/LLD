#include<bits/stdc++.h>
#include "logobserver.hpp"
using namespace std;
#pragma once

class logSubject
{
    map<int, vector<logObserver*>>mp;
    
    public :
        void addObserver(int level, logObserver *l)
        {
            mp[level].push_back(l);
        }
        
        void notify(int level, string msg)
        {
            for(auto it : mp)
            {
                if( it.first == level )
                {
                    for( auto p : it.second )
                        p->logMsg(msg);
                }
            }
        }
};