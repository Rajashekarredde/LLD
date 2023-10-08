
#ifndef ABSTRACTLOGGER_HPP
#define ABSTRACTLOGGER_HPP

#include <bits/stdc++.h>
#include "logsubject.hpp"
using namespace std;
#pragma once

class abstractLogger
{
    public :
        int level;
        abstractLogger* nextLoggingLevel;
        
        void setNextLoggingLevel(abstractLogger *nextLoggingLevel)
        {
            this->nextLoggingLevel = nextLoggingLevel;
        }
        
        void logMessage(int level, string msg, logSubject* l)
        {
            if(this->level <= level )
            {
                display(msg, l);
            }
            
            if( nextLoggingLevel != NULL )
            {
                nextLoggingLevel->logMessage(level, msg, l);
            }
        }
        
        virtual void display(string msg, logSubject *l) = 0;
};

#endif // ABSTRACTLOGGER_HPP