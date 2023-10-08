#include<bits/stdc++.h>
#include "abstractlogger.hpp"
using namespace std;
#pragma once

class errorLogger : public abstractLogger
{
    public :
        errorLogger() {}
        errorLogger(int level)
        {
            this->level = level;
        }
        
        void display(string msg, logSubject *l)
        {
            string s = "ERROR : "+ msg;
            l->notify(level, s);
        }
};