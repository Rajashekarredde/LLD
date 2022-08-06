#include<bits/stdc++.h>
using namespace std;

class logger
{
    static int count;
    static mutex mtx;
    logger()
    {
        count++;
        cout<<"new instance created "<<count<<endl;
    }
    logger( const logger&);
    logger operator= (const logger& );
    
    public :
    
    static logger *loggerInstance;
    
    /*inner if condition is required to make sure that only one instance will be created 
    incase of more than one thread is trying to get the single instance.

    Ex: Suppose there is no instance created as of now. If thread1 and thread2 entered 
    the first nullptr check simultaneously then suppose thread1 acquired the lock first 
    and created the instance. Now thread2 is checking if the instance is nullptr(using second nullptr check)
    then only it goes ahead and create the instance. If the inner if condition will not be there then 
    it might endup creating two instance then it could cause memory leak as well (as a repurcussions).*/
    
    static logger * getInstance( )
    {
        if( loggerInstance == nullptr )
        {
          mtx.lock();
          if( loggerInstance == nullptr )
          {
              loggerInstance = new logger();
          }
          mtx.unlock();
        }
        return loggerInstance;
    }
};
