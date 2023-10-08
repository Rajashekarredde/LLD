#include<bits/stdc++.h>
#include "abstractlogger.hpp"
#include "infologger.hpp"
#include "errorlogger.hpp"
#include "debuglogger.hpp"
#include "logsubject.hpp"
using namespace std;
#pragma once

class logManager
{
    logManager(){}
    public:
        static abstractLogger* buildChainOfResponsibility()
        {
            abstractLogger* info = new infoLogger(1);
            abstractLogger* error = new errorLogger(2);
            abstractLogger* debug = new debugLogger(3);
            
            info->setNextLoggingLevel(error);
            error->setNextLoggingLevel(debug);
            
            return info;
        }
        
        static logSubject* buildSubject()
        {
           logSubject *l = new logSubject();
           
           consoleLogger * console = new consoleLogger();
           fileLogger *file = new fileLogger();
           
            l->addObserver(1, console);
            l->addObserver(2, console);
            l->addObserver(3, console);
            
            l->addObserver(2, file);

            return l;
        }
};