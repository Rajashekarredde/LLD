#include<bits/stdc++.h>
#include "abstractlogger.hpp"
using namespace std;
#pragma once

class infoLogger : public abstractLogger
{
    public :
        infoLogger() {}
        infoLogger(int level)
        {
            this->level = level;
        }
        
        void display(string msg, logSubject *l)
        {
            string s = "INFO : "+ msg;
            l->notify(level, s);
        }
};