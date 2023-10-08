#include <iostream>
#include <mutex>
#include "logmanager.hpp"
#include "logsubject.hpp"
using namespace std;
#pragma once

class logger
{
private:
    static int count;
    static mutex mtx;
    static logger* loggerInstance;
    static abstractLogger* absLoggerInstance;
    static logSubject* logSub;
    
    logger()
    {
        count++;
    }
    logger(const logger&);
    logger operator= (const logger&);
    
    void createLog(int level, string msg, logSubject *l)
    {
        absLoggerInstance->logMessage(level, msg, l);
    }

public:
    static logger* getInstance()
    {
        if (loggerInstance == nullptr)
        {
            mtx.lock();
            if (loggerInstance == nullptr)
            {
                loggerInstance = new logger();
                absLoggerInstance = logManager::buildChainOfResponsibility();
                logSub = logManager::buildSubject();
            }
            mtx.unlock();
        }
        return loggerInstance;
    }
    
    void info(string msg)
    {
        createLog(1, msg, logSub);
    }
    
    void error(string msg)
    {
        createLog(2, msg, logSub);
    }
    
    void debug(string msg)
    {
        createLog(3, msg, logSub);
    }
};

int logger::count = 0;
logger* logger::loggerInstance = nullptr;
abstractLogger* logger::absLoggerInstance = nullptr;
logSubject* logger::logSub = nullptr;
mutex logger::mtx;