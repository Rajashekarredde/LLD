#include<bits/stdc++.h>
using namespace std;
#pragma once

class logObserver
{
    public:
        virtual void logMsg(string msg) = 0;
};

class consoleLogger : public logObserver
{
    public:
        void logMsg(string msg)
        {
            cout<<"CONSOLE: "<<msg<<endl;
        }
};

class fileLogger : public logObserver
{
    public:
        void logMsg(string msg)
        {
            cout<<"WRITE TO FILE: "<<msg<<endl;
        }
};