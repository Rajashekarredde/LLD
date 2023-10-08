#include<bits/stdc++.h>
#include "abstractlogger.hpp"
using namespace std;
#pragma once

class debugLogger : public abstractLogger
{
    public :
        debugLogger() {}
        debugLogger(int level)
        {
            this->level = level;
        }
        
        void display(string msg, logSubject *l)
        {
            string s = "DEBUG : "+ msg;
            l->notify(level, s);
        }
};